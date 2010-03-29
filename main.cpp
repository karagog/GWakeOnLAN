/*
 * File:   main.cpp
 * Author: rootinc
 *
 * Created on December 24, 2009, 8:17 PM
 */

#include <QtGui/QApplication>
#include "SendPacket.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    // create and show your widgets here
    SendPacket * main_form = new SendPacket();

    main_form->show();

    return app.exec();
}

