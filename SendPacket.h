/* 
 * File:   SendPacket.h
 * Author: rootinc
 *
 * Created on December 24, 2009, 8:22 PM
 */

#ifndef _SENDPACKET_H
#define	_SENDPACKET_H

#include "ui_SendPacket.h"

class QUdpSocket;
class creds_dialog;
class packet_listener;

class SendPacket : public QMainWindow {
    Q_OBJECT
public:
    SendPacket();
    virtual ~SendPacket();

public slots:
    void update_mac_address(QString newaddr);

private slots:
    void open_mysql_browser();
    void open_packet_listener();
    void send_packet();
    void clearLabel();

private:
    Ui::SendPacket widget;
    QUdpSocket * sock;
    creds_dialog * db_connection_form;
    packet_listener * listen_form;

    int labelCount;
};

#endif	/* _SENDPACKET_H */
