#include "db_selection.h"
#include "db_browser.h"
#include <QFileDialog>
#include <QMessageBox>
#include <cassert>

creds_dialog::creds_dialog(QWidget * parent, Qt::WindowFlags f)
	: QWidget(parent, f)
{
	mine.setupUi(this);
        
        db_form = new db_browser(0, 0);
        connect(db_form, SIGNAL(notify_selection(QString)), parent, SLOT(update_mac_address(QString)));

        connect(this, SIGNAL(update_host_info(QString, QString, QString, QString, e_databases)), db_form, SLOT(set_host_data(QString, QString, QString, QString, e_databases)));
}


creds_dialog::~creds_dialog(){}

void creds_dialog::connect_clicked()
{	
        update_host_info(mine.host_in->text(), mine.user_in->text(), mine.pass_in->text(), db_file, (e_databases)mine.comboBox->currentIndex());

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

