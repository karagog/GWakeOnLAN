
#ifndef _DB_SELECTION_H
#define	_DB_SELECTION_H

#include "ui_db_login.h"
#include "db_browser.h"

class creds_dialog : public QWidget
{
	Q_OBJECT
public:
	creds_dialog(QWidget * parent = 0, Qt::WindowFlags f = 0);
	~creds_dialog();

signals:
        void update_host_info(QString, QString, QString, QString, e_databases);

private slots:
	void connect_clicked();
	void update_db_form(int index);

private:
	Ui::Form mine;
        db_browser * db_form;

	QString db_file;
};

#endif
