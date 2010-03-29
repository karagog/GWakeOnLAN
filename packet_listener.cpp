/*
 * File:   packet_listener.cpp
 * Author: rootinc
 *
 * Created on January 1, 2010, 3:58 PM
 */

#include "packet_listener.h"
#include "helpers.h"
#include <QStringListModel>
#include <QMessageBox>
#include <QUdpSocket>
#include <QDateTime>

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
    int size;

    while(sock->hasPendingDatagrams())
    {
        // Read in pending datagram
        size = sock->pendingDatagramSize();

        char *dat = new char[size];
        size = sock->readDatagram(dat, size);
        QByteArray temp(dat, size);
        delete dat;

        if(size == -1)
        {
            QMessageBox::information(0, "Damn", sock->errorString());
            return;
        }

        //int j =5;
        //        if(size != rsize)
        //        {
        //            QMessageBox::warning(this, "Corrupt Packet", "I was unable to read the full contents of the packet I received...");
        //            return;
        //        }

        // Parse it to see if it's a magic packet.
        bool res = true;
        int i = 0;
        for(; i < 6; i++)
        {
            if(temp.at(i) != (char)0xff)
            {
                res = false;
                break;
            }
        }

        QString mac_address = "xxxxxxxxxxxx";
        for(int j = 0; res && j < 16; j++)
        {
            for(int k = 0;k < mac_address.length(); k+=2)
            {
                // If we didn't receive enough bytes to constitute a magic packet
                if(i == temp.length())
                {
                    res = false;
                    break;
                }

                char bt = temp.at(i++);
                char ret[2] = {'n', 'o'};

                if(!hex_to_char(bt, ret))
                {
                    res = false;
                    break;
                }

                if(j == 0)
                {
                    mac_address.replace(k, 1, ret[1]);
                    mac_address.replace(k + 1, 1, ret[0]);
                }
                else
                {
                    if(mac_address.at(k) != ret[1] ||
                       mac_address.at(k + 1) != ret[0])
                    {
                        res = false;
                        break;
                    }
                }
            }
        }

        //Note: Even if there are more bytes to be read here, it's still a magic packet
        //  if the conditions above were satisfied

        // Dress up the mac address:
        for(int j = 5; j > 0; j--)
        {
            mac_address.insert(2 *j, ":");
        }

        mac_address.append(" - " + QDateTime::currentDateTime().toString("h:m 'and' s.z") + " seconds");

        // If it is magic, then put it on the end of the list of magic packets received
        QStringList sl = data->stringList();
        sl.insert(0, mac_address);
        data->setStringList(sl);

    }
}
