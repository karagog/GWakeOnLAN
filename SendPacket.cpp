/*
 * File:   SendPacket.cpp
 * Author: rootinc
 *
 * Created on December 24, 2009, 8:22 PM
 */

#include "SendPacket.h"
#include "db_browser.h"
#include "db_selection.h"
#include "helpers.h"
#include "packet_listener.h"
#include <QUdpSocket>
#include <QString>
#include <QMessageBox>
#include <QTimer>
#include <QFile>
//#include <cassert>

SendPacket::SendPacket() {
    widget.setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose, true);

    labelCount = 0;

    sock = new QUdpSocket(this);
    db_connection_form = new creds_dialog(this, Qt::Window);
    listen_form = new packet_listener(this, Qt::Window);


    // Connect up the actions in the file menu
    connect(widget.actionQuit, SIGNAL(triggered()), this, SLOT(close()));
    connect(widget.actionBrowse_MySQL_Database, SIGNAL(triggered()), this, SLOT(open_mysql_browser()));
    connect(widget.actionListen, SIGNAL(triggered()), this, SLOT(open_packet_listener()));
}

SendPacket::~SendPacket() {
}


void SendPacket::open_mysql_browser()
{
	db_connection_form->show();
}

void SendPacket::open_packet_listener()
{
    listen_form->show();
}

void SendPacket::update_mac_address(QString newaddr)
{
	widget.mac_in->setText(newaddr);
}

void SendPacket::send_packet()
{
	// Magic packet = 6 bytes of (0xff) followed by 16 repetitions of the target MAC address
	QByteArray mp(6, (char)0xff);
	QByteArray mac;
        QByteArray tempArray;

	QString smac = widget.mac_in->text();
	int count = 0;
	char t = 0;

	for(int i = 0; i < smac.size(); i++)
	{
		if(!char_to_hex(smac[i].toLower().toAscii(), t))
		{
			continue;
		}

		tempArray.append(t);
		count++;
	}

	if(count != 12)
	{
		show_message("You must enter a valid MAC address");
		return;
	}

        // Consolidate every two bytes into one byte (the bytes are really nibbles)
        for(int i = 0; i <= 8; i+=4)
        {
            char t1, t2;

            t1 = combine_nibbles(tempArray[i], tempArray[i + 1]);
            t2 = combine_nibbles(tempArray[i+2], tempArray[i + 3]);
            mac.append(t1);
            mac.append(t2);
            //Note: This doesn't make any sense to me why I have to append the second
                // char before the first, but it must be that way if it is to be in order
        }

	// Copy the mac address 16 times onto the magic packet
	for(int i = 0; i < 16; i++)
	{
		mp.append(mac);
	}

        
        QFile tf("temp.txt");
        tf.open(QIODevice::ReadWrite | QIODevice::Truncate);
        tf.write(mac);
        tf.close();
	//mp.append((char)0x00);

	// Now send it
	if(sock->writeDatagram(mp, QHostAddress::Broadcast, 9) != mp.size())
        {
            QMessageBox::warning(this, "Error Sending Magic Packet",
                                "I was unable to sent the packet for some reason");
            return;
        }


        widget.eventLabel->setText("Magic Packet Sent");
        labelCount++;

        QTimer::singleShot(2000, this, SLOT(clearLabel()));
}

void SendPacket::clearLabel()
{
    if((labelCount--) == 1)
    {
	widget.eventLabel->clear();
    }
}