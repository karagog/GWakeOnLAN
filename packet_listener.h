/*
 * File:   packet_listener.h
 * Author: rootinc
 *
 * Created on January 1, 2010, 3:58 PM
 */

#ifndef _PACKET_LISTENER_H
#define	_PACKET_LISTENER_H

#include "ui_packet_listener.h"

class QUdpSocket;
class QStringListModel;

class packet_listener : public QWidget {
    Q_OBJECT
public:
    packet_listener(QWidget * parent, Qt::WindowFlags flags);
    virtual ~packet_listener();

private slots:
    void start_listening();
    void stop_listening();

    void packet_in();
    void clear_results();

private:
    Ui::packet_listener widget;
    QUdpSocket * sock;
    QStringListModel * data;
};

#endif	/* _PACKET_LISTENER_H */
