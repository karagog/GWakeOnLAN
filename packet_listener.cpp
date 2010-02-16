/*
 * File:   packet_listener.cpp
 * Author: rootinc
 *
 * Created on January 1, 2010, 3:58 PM
 */

#include "packet_listener.h"
#include <QStringListModel>
#include <QMessageBox>
#include <QUdpSocket>

packet_listener::packet_listener(QWidget * parent, Qt::WindowFlags flags)
    : QWidget(parent, flags)
{
    widget.setupUi(this);

    sock = new QUdpSocket(this);
    data = new QStringListModel(this);

    widget.listView->setModel(data);
}

packet_listener::~packet_listener() {
}

void packet_listener::start_listening()
{
    bool res = false;
    int port = widget.lineEdit->text().toInt(&res);

    if(res == false)
    {
        QMessageBox::information(this, "Invalid port", "You must enter a valid port number");
    }

    if(!sock->bind(port))
    {
        QMessageBox::information(this, "Bind failed", "Unable to bind to the specified port");
    }

    connect(sock, SIGNAL(readyRead()), this, SLOT(packet_in()));
}

void packet_listener::clear_results()
{
    data->removeRows(0, data->rowCount());
}

void packet_listener::packet_in()
{
    int size, rsize;
    QByteArray temp;

    while(sock->hasPendingDatagrams())
    {
        // Read in pending datagram
        size = sock->pendingDatagramSize();
        temp.resize(size);
        rsize = sock->read(temp.data(), size);

        if(size != rsize)
        {
            QMessageBox::warning(this, "Corrupt Packet", "I was unable to read the full contents of the packet I received...");
            return;
        }

        // Parse it to see if it's a magic packet.



        // If it is magic, then put it on the end of the list of magic packets received
        
    }
}
