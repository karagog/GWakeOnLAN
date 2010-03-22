/*
 * File:   db_browser.cpp
 * Author: rootinc
 *
 * Created on December 24, 2009, 9:59 PM
 */

#include "db_browser.h"
#include "helpers.h"
#include <cassert>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlQuery>
#include <QDateTime>
#include <QSqlError>
#include <QList>
#include <QMessageBox>
#include <QCloseEvent>
using namespace std;

db_browser::db_browser(QWidget * parent, Qt::WindowFlags flags)
    : QWidget(parent, flags)
{
    widget.setupUi(this);

    setDirty(false);

    //setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint);

    // Wire in the save/undo buttons
    connect(widget.undo_btn, SIGNAL(clicked()), this, SLOT(undo_changes()));
    connect(widget.save_btn, SIGNAL(clicked()), this, SLOT(commit_data()));
}

db_browser::~db_browser()
{
}

bool db_browser::check_table_exists()
{

    return true;
}

void db_browser::set_host_data(QString host, QString user, QString pass, QString file, e_databases which)
{
    hostn = host;
    usern = user;
    passw = pass;
    filen = file;
    which_db = which;
}

bool db_browser::connect_to_database()
{
    switch(which_db)
    {
    case mysql:
        dbase = QSqlDatabase::addDatabase("QMYSQL");
        dbase.setDatabaseName("GWakeonlan");
        dbase.setHostName(hostn);
        dbase.setUserName(usern);
        dbase.setPassword(passw);
        break;
    case sqlite:
        dbase = QSqlDatabase::addDatabase("QSQLITE");
        dbase.setDatabaseName(filen);
        break;
    }

    if(!dbase.open())
    {
        if(dbase.lastError().text().contains("unknown database", Qt::CaseInsensitive))
        {
            QMessageBox::information(
                    this, "Database not found",
                    "I connected with the server, but I didn't find a 'GWakonlan' database.  To use this functionality, create a database schema called 'GWakeonlan', and make sure your user has adequate permissions to create tables and read/write to them.\n\n...or you can skip MySQL and use an SQLite database.");
        }
        else
        {
            show_message("Could not connect to database\n\n"
                         + dbase.lastError().text());
        }

        return false;
    }

    return true;
}

void db_browser::disconnect_from_database()
{
    QString temp = dbase.connectionName();
    if(temp != "")
    {
        QSqlDatabase::removeDatabase(temp);
    }
}

bool db_browser::fill_data()
{
    data = new QSqlTableModel(this, dbase);
    data->setTable("MACs");
    data->setEditStrategy(QSqlTableModel::OnManualSubmit);

    if(!(data->select()))
    {
        //show_message(data->lastError().text());
        if(QMessageBox::question(this, "Table doesn't exist",
                                 "The table used by this program doesn't exist in the database.\n\nI can create it for you now if you click OK.",
                                 QMessageBox::Ok | QMessageBox::Cancel,
                                 QMessageBox::Ok) == QMessageBox::Ok)
        {
            // Run a query to create the missing table

            QString queryString;

            switch(which_db)
            {
            case mysql:
                queryString = "CREATE TABLE IF NOT EXISTS `GWakeonlan`.`MACs` ("
                              "`label` varchar(45) NOT NULL,"
                              "`address` varchar(17) NOT NULL,"
                              "`date` datetime NOT NULL,"
                              "PRIMARY KEY (`label`)"
                              ") ENGINE=InnoDB DEFAULT CHARSET=latin1;";
                break;
            case sqlite:
                queryString = "CREATE TABLE \"MACs\" ("
                              "\"label\" TEXT NOT NULL,"
                              "\"address\" TEXT NOT NULL,"
                              "\"date\" TEXT );";
                break;
            default:
                return false;
            }

            QSqlQuery cq(queryString, dbase);
            if(!cq.exec())
            {
                return false;
            }

            delete data;
            data = new QSqlTableModel(this, dbase);
            data->setTable("MACs");
            data->setEditStrategy(QSqlTableModel::OnManualSubmit);
            data->select();
        }
        else
        {
            return false;
        }
    }

    data->setHeaderData(0, Qt::Horizontal, tr("Label"));
    data->setHeaderData(1, Qt::Horizontal, tr("Address"));
    data->setHeaderData(2, Qt::Horizontal, tr("Date"));

    widget.tableView->setModel(data);
    widget.tableView->resizeColumnsToContents();
    widget.tableView->sortByColumn(data->fieldIndex("date"), Qt::DescendingOrder);

    connect(data, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(table_changed()));

    setDirty(false);

    return true;
}

void db_browser::commit_data()
{
    if(data->submitAll())
    {
        setDirty(false);
    }
    else
    {
        show_message("Unabled to save to database\n\n"
                     + data->lastError().text());
    }
}

void db_browser::undo_changes()
{
    data->revertAll();
    setDirty(false);
}

void db_browser::insert_row()
{
    QSqlRecord rec;
    QSqlField lab("label", QVariant::String);
    QSqlField ma("address", QVariant::String);
    QSqlField dt("date", QVariant::DateTime);

    lab.setValue(widget.label_in->text());
    ma.setValue(widget.mac_in->text());
    dt.setValue(QDateTime::currentDateTime());

    rec.append(lab);
    rec.append(ma);
    rec.append(dt);

    data->insertRecord(0, rec);
    widget.tableView->resizeColumnsToContents();

    widget.label_in->clear();
    widget.mac_in->clear();

    setDirty(true);
}

void db_browser::edit_row()
{
    QModelIndexList temp = widget.tableView->selectionModel()->selectedRows();
    if(temp.count() != 1)
    {
        show_message("Please select exactly one row to edit");
        return;
    }

    widget.tableView->edit(temp.at(0));
}

void db_browser::delete_row()
{
    if(dirty)
    {
        show_message("You must first save all pending changes to the database before you can delete an entry");
        return;
    }

    QMessageBox msgBox;
    msgBox.setText("WARNING: This cannot be undone!");
    msgBox.setInformativeText("Do you really want to delete the row of information?");
    msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Cancel);

    if(msgBox.exec() != (int)QMessageBox::Ok)
    {
        return;
    }

    QModelIndexList temp = widget.tableView->selectionModel()->selectedRows();
    if(temp.count() != 1)
    {
        show_message("You must select exactly one item.  You selected " + QString::number(temp.count()) + " items");
        return;
    }

    data->removeRows(temp.at(0).row(), 1);
    commit_data();
}

void db_browser::table_changed()
{
    if(!dirty)
    {
        setDirty(true);
    }
}

void db_browser::select_mac()
{
    QModelIndexList temp = widget.tableView->selectionModel()->selection().indexes();
    if((temp.count() / data->columnCount()) != 1)
    {
        show_message("You must select exactly one item.  You selected " + QString::number(temp.count()/data->columnCount()) + " items");
        return;
    }

    notify_selection(temp.at(data->fieldIndex("address")).data(Qt::DisplayRole).toString());
    close();
}

void db_browser::setDirty(bool val)
{
    dirty = val;
    widget.save_btn->setEnabled(val);
    widget.undo_btn->setEnabled(val);
}

void db_browser::closeEvent(QCloseEvent *ev)
{
    if(dirty)
    {
        QMessageBox msg;
        msg.setText("WARNING: You have changes pending!");
        msg.setInformativeText("Do you want to save your changes before closing this form?");
        msg.setStandardButtons(QMessageBox::Cancel | QMessageBox::No | QMessageBox::Ok);
        msg.setDefaultButton(QMessageBox::Ok);

        int res = msg.exec();
        switch(res)
        {
        case (int)QMessageBox::Ok:
            commit_data();
            break;
        case (int) QMessageBox::No:
            break;
        default:
            ev->ignore();
            return;
        }
    }

    // Close the database connection
    dbase.close();
    ev->accept();
}


