/* 
 * File:   db_browser.h
 * Author: rootinc
 *
 * Created on December 24, 2009, 9:59 PM
 */

#ifndef _DB_BROWSER_H
#define	_DB_BROWSER_H

#include "ui_db_browser.h"
#include <string>
#include <QSqlDatabase>
using namespace std;

enum e_databases
{
	mysql,
	sqlite
};

class QSqlTableModel;
class QCloseEvent;

class db_browser : public QWidget {
    Q_OBJECT
public:
    //db_browser(QWidget * parent, Qt::WindowFlags flags, QSqlDatabase * db);
	db_browser(QWidget * parent, Qt::WindowFlags flags);
    virtual ~db_browser();

	// Checks if database exists, and creates it if it doesn't
	bool check_table_exists();
	bool connect_to_database();
        void disconnect_from_database();
	bool fill_data();

protected:
	void closeEvent(QCloseEvent *ev);

signals:
	void notify_selection(QString);

public slots:
    void set_host_data(QString host, QString user, QString pass, QString file, e_databases which);

private slots:
	void commit_data();
	void undo_changes();
	void insert_row();
	void edit_row();
	void delete_row();
	void table_changed();
	void select_mac();

private:
	void setDirty(bool val);

    Ui::db_browser widget;

	QSqlDatabase dbase;
	QSqlTableModel * data;
	QString hostn, usern, passw;
	QString filen;
	bool dirty;
	e_databases which_db;
};

#endif	/* _DB_BROWSER_H */
