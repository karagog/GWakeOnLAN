
#ifndef _DB_SELECTION_H
#define	_DB_SELECTION_H

#include "ui_db_login.h"
#include "db_browser.h"
#include "settings.h"
#include <QStringList>
#include <QSettings>

class creds_dialog : public QWidget
{
    Q_OBJECT
public:
    creds_dialog(QWidget * parent = 0, Qt::WindowFlags f = 0);
    ~creds_dialog();

protected:
    void showEvent(QShowEvent *);

signals:
    void update_host_info(QString, QString, QString, QString, e_databases);

private slots:
    void connect_clicked();
    void update_db_form(int index);

private:
    Ui::db_selector mine;
    db_browser * db_form;

    QString db_file;
    QString saved_password;

    GUtil::Qt::Settings *settings;
    QStringList get_hostname_list();
    void refresh_hostlist();
};

#endif
