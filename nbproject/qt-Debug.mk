#############################################################################
# Makefile for building: dist/Debug/GNU-Linux-x86/GWakeonlan
# Generated by qmake (2.01a) (Qt 4.5.2) on: Wed Jan 6 17:39:55 2010
# Project:  nbproject/qt-Debug.pro
# Template: app
# Command: /usr/bin/qmake -unix VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_SQL_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -Inbproject -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtNetwork -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtSql -I/usr/include/qt4 -I/usr/include/mysql -I/usr/include/qt4/Qt -I. -I. -Inbproject -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtSql -lQtGui -lQtNetwork -lQtCore -lpthread
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = build/Debug/GNU-Linux-x86/

####### Files

SOURCES       = packet_listener.cpp \
		SendPacket.cpp \
		helpers.cpp \
		db_selection.cpp \
		main.cpp \
		db_browser.cpp moc_db_selection.cpp \
		moc_packet_listener.cpp \
		moc_SendPacket.cpp \
		moc_db_browser.cpp
OBJECTS       = build/Debug/GNU-Linux-x86/packet_listener.o \
		build/Debug/GNU-Linux-x86/SendPacket.o \
		build/Debug/GNU-Linux-x86/helpers.o \
		build/Debug/GNU-Linux-x86/db_selection.o \
		build/Debug/GNU-Linux-x86/main.o \
		build/Debug/GNU-Linux-x86/db_browser.o \
		build/Debug/GNU-Linux-x86/moc_db_selection.o \
		build/Debug/GNU-Linux-x86/moc_packet_listener.o \
		build/Debug/GNU-Linux-x86/moc_SendPacket.o \
		build/Debug/GNU-Linux-x86/moc_db_browser.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		nbproject/qt-Debug.pro
QMAKE_TARGET  = GWakeonlan
DESTDIR       = dist/Debug/GNU-Linux-x86/
TARGET        = dist/Debug/GNU-Linux-x86/GWakeonlan

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: qttmp-Debug.mk $(TARGET)

$(TARGET): ui_packet_listener.h ui_db_browser.h ui_db_login.h ui_SendPacket.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) dist/Debug/GNU-Linux-x86/ || $(MKDIR) dist/Debug/GNU-Linux-x86/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

qttmp-Debug.mk: nbproject/qt-Debug.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtSql.prl \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtNetwork.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -unix VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtSql.prl:
/usr/lib/libQtGui.prl:
/usr/lib/libQtNetwork.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro

dist: 
	@$(CHK_DIR_EXISTS) nbproject/build/Debug/GNU-Linux-x86/GWakeonlan1.0.0 || $(MKDIR) nbproject/build/Debug/GNU-Linux-x86/GWakeonlan1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) nbproject/build/Debug/GNU-Linux-x86/GWakeonlan1.0.0/ && $(COPY_FILE) --parents db_selection.h packet_listener.h SendPacket.h helpers.h db_browser.h nbproject/build/Debug/GNU-Linux-x86/GWakeonlan1.0.0/ && $(COPY_FILE) --parents packet_listener.cpp SendPacket.cpp helpers.cpp db_selection.cpp main.cpp db_browser.cpp nbproject/build/Debug/GNU-Linux-x86/GWakeonlan1.0.0/ && $(COPY_FILE) --parents packet_listener.ui db_browser.ui db_login.ui SendPacket.ui nbproject/build/Debug/GNU-Linux-x86/GWakeonlan1.0.0/ && (cd `dirname nbproject/build/Debug/GNU-Linux-x86/GWakeonlan1.0.0` && $(TAR) GWakeonlan1.0.0.tar GWakeonlan1.0.0 && $(COMPRESS) GWakeonlan1.0.0.tar) && $(MOVE) `dirname nbproject/build/Debug/GNU-Linux-x86/GWakeonlan1.0.0`/GWakeonlan1.0.0.tar.gz . && $(DEL_FILE) -r nbproject/build/Debug/GNU-Linux-x86/GWakeonlan1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) qttmp-Debug.mk


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_db_selection.cpp moc_packet_listener.cpp moc_SendPacket.cpp moc_db_browser.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_db_selection.cpp moc_packet_listener.cpp moc_SendPacket.cpp moc_db_browser.cpp
moc_db_selection.cpp: ui_db_login.h \
		db_selection.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) db_selection.h -o moc_db_selection.cpp

moc_packet_listener.cpp: ui_packet_listener.h \
		packet_listener.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) packet_listener.h -o moc_packet_listener.cpp

moc_SendPacket.cpp: ui_SendPacket.h \
		SendPacket.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) SendPacket.h -o moc_SendPacket.cpp

moc_db_browser.cpp: ui_db_browser.h \
		db_browser.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) db_browser.h -o moc_db_browser.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_packet_listener.h ui_db_browser.h ui_db_login.h ui_SendPacket.h
compiler_uic_clean:
	-$(DEL_FILE) ui_packet_listener.h ui_db_browser.h ui_db_login.h ui_SendPacket.h
ui_packet_listener.h: packet_listener.ui
	/usr/bin/uic-qt4 packet_listener.ui -o ui_packet_listener.h

ui_db_browser.h: db_browser.ui
	/usr/bin/uic-qt4 db_browser.ui -o ui_db_browser.h

ui_db_login.h: db_login.ui
	/usr/bin/uic-qt4 db_login.ui -o ui_db_login.h

ui_SendPacket.h: SendPacket.ui
	/usr/bin/uic-qt4 SendPacket.ui -o ui_SendPacket.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

build/Debug/GNU-Linux-x86/packet_listener.o: packet_listener.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/packet_listener.o packet_listener.cpp

build/Debug/GNU-Linux-x86/SendPacket.o: SendPacket.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/SendPacket.o SendPacket.cpp

build/Debug/GNU-Linux-x86/helpers.o: helpers.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/helpers.o helpers.cpp

build/Debug/GNU-Linux-x86/db_selection.o: db_selection.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/db_selection.o db_selection.cpp

build/Debug/GNU-Linux-x86/main.o: main.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/main.o main.cpp

build/Debug/GNU-Linux-x86/db_browser.o: db_browser.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/db_browser.o db_browser.cpp

build/Debug/GNU-Linux-x86/moc_db_selection.o: moc_db_selection.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_db_selection.o moc_db_selection.cpp

build/Debug/GNU-Linux-x86/moc_packet_listener.o: moc_packet_listener.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_packet_listener.o moc_packet_listener.cpp

build/Debug/GNU-Linux-x86/moc_SendPacket.o: moc_SendPacket.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_SendPacket.o moc_SendPacket.cpp

build/Debug/GNU-Linux-x86/moc_db_browser.o: moc_db_browser.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_db_browser.o moc_db_browser.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

