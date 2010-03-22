HEADERS += SendPacket.h \
    packet_listener.h \
    helpers.h \
    db_selection.h \
    db_browser.h \
    about_window.h
SOURCES += SendPacket.cpp \
    packet_listener.cpp \
    main.cpp \
    helpers.cpp \
    db_selection.cpp \
    db_browser.cpp \
    about_window.cpp
FORMS += SendPacket.ui \
    packet_listener.ui \
    db_login.ui \
    db_browser.ui \
    about_window.ui
QT += sql \
    network

unix{
LIBS += -Wl,-rpath,/usr/local/lib/gwakeonlan
}