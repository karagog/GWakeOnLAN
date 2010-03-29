#include "db_selection.h"
#include "db_browser.h"
#include <QFileDialog>
#include <QMessageBox>

#define MAX_HOST_HISTORY 10

creds_dialog::creds_dialog(QWidget * parent, Qt::WindowFlags f)
    : QWidget(parent, f)
{
    mine.setupUi(this);

    db_form = new db_browser(0, 0);
    connect(db_form, SIGNAL(notify_selection(QString)), parent, SLOT(update_mac_address(QString)));

    connect(this, SIGNAL(update_host_info(QString, QString, QString, QString, e_databases)), db_form, SLOT(set_host_data(QString, QString, QString, QString, e_databases)));



    if(!settings.Initialize("GWakeonLAN"))
//    if(settings.status() != QSettings::NoError)
    {

        QMessageBox::information(0, "poop","Can't save settings");
    }
}


creds_dialog::~creds_dialog(){}

void creds_dialog::refresh_hostlist()
{
    mine.host_in->clear();

    QStringList hn = get_hostname_list();
    for(int i = hn.count() - 1; i >= 0; i--)
    {
        mine.host_in->addItem(hn.at(i));
    }
    //mine.host_in->setCurrentIndex(0);

    mine.user_in->setText(settings.Value("lastusername"));
    mine.pass_in->setText(saved_password);
}

QStringList creds_dialog::get_hostname_list()
{
    QStringList ret;
    QString v = settings.Value("hostnames");

    if(v != "")
    {
        ret = v.split(',', QString::SkipEmptyParts);
    }

    return ret;
}

void creds_dialog::showEvent(QShowEvent *)
{
    refresh_hostlist();
}

void creds_dialog::connect_clicked()
{
    QString hn = mine.host_in->currentText();

    // Remember the history of hostnames
    QStringList names = get_hostname_list();

    // Remove all previous occurrences of this hostname
    for(int i = names.count() - 1; i >= 0; i--)
    {
        if(names.at(i).toLower() == hn)
            names.removeAt(i);
    }

    names.append(hn);
    while(names.count() > MAX_HOST_HISTORY)
        names.removeLast();

    QString names_cat = "";
    foreach(QString s, names)
        names_cat += (s + ",");
    if(names_cat.count() > 0)
        names_cat.resize(names_cat.length() - 1);

    saved_password = mine.pass_in->text();
    settings.SetValue("hostnames", names_cat);
    settings.SetValue("lastusername", mine.user_in->text());
    QString probe = settings.Value("hostnames");

    update_host_info(hn, mine.user_in->text(), mine.pass_in->text(), db_file, (e_databases)mine.comboBox->currentIndex());

    db_form->disconnect_from_database();

    if(!db_form->connect_to_database())
    {
        return;
    }

    if(!db_form->fill_data())
    {
        return;
    }

    db_form->show();
    hide();
}

void creds_dialog::update_db_form(int index)
{
    switch((e_databases)index)
    {
    case mysql:
        break;
    case sqlite:
        switch(QMessageBox::question(this, "Existing Database?",
                                     "Do you want to open an existing database or save a new one?",									QMessageBox::Open | QMessageBox::Save | QMessageBox::Cancel,									QMessageBox::Open))
        {
        case QMessageBox::Open:
            db_file = QFileDialog::getOpenFileName(this, tr("Select SQLite Database"),
                                                   QDir::currentPath(),
                                                   tr("SQLite Database (*.db)"));
            break;
        case QMessageBox::Save:
            db_file = QFileDialog::getSaveFileName(this, tr("Create a new SQLite Database"),
                                                   QDir::currentPath(),
                                                   tr("SQLite Database (*.db)"));
            break;
        default:
            db_file = "";
            break;
        }

        if(db_file != "")
        {
            hide();
            connect_clicked();
        }

        mine.comboBox->setCurrentIndex((int)mysql);
        break;
        default:
        throw new exception();
        break;
    }
}

