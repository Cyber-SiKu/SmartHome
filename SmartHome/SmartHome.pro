#-------------------------------------------------
#
# Project created by QtCreator 2017-07-06T14:43:57
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartHome
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
		mainwidget.cpp \
	mainframe.cpp \
	tempframe.cpp \
	moistureframe.cpp \
	smokeframe.cpp \
	airconditionframe.cpp \
	lightframe.cpp \
	alarmframe.cpp \
	buzzercontrol.cpp \
	ledcontrol.cpp \
	getstatuethread.cpp \
    yeelinkconnect.cpp

HEADERS  += mainwidget.h \
	mainframe.h \
	framesetting.h \
	tempframe.h \
	moistureframe.h \
	smokeframe.h \
	airconditionframe.h \
	lightframe.h \
	alarmframe.h \
	buzzercontrol.h \
	ledcontrol.h \
	getstatuethread.h \
	devicessetting.h \
    yeelinkconnect.h

FORMS    += mainwidget.ui \
	mainframe.ui \
	tempframe.ui \
	moistureframe.ui \
	somkeframe.ui \
	airconditionframe.ui \
	lightframe.ui \
	alarmframe.ui

RESOURCES += \
	image.qrc

INCLUDEPATH += /siku

LIBS += -L/siku \
		-lyeelink_lzy


#QMAKE_CXXFLAGS += -std=c++11
