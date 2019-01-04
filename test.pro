#-------------------------------------------------
#
# Project created by QtCreator 2018-10-11T11:41:00
#
#-------------------------------------------------

QT       += core gui sql serialport network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addtype.cpp \
   readtype.cpp \
connection.cpp \
    ajoutert.cpp \
    supmodt.cpp \
    modifiert.cpp \
    tiroir.cpp \
    repas.cpp \
    crudfood.cpp \
    menufood.cpp \
    consulterfood.cpp \
    dialog.cpp \
    smtp.cpp \
    mail.cpp \
    securite.cpp

HEADERS  += mainwindow.h \
    addtype.h \
    readtype.h\
connection.h \
    ajoutert.h \
    consultert.h \
    supmodt.h \
    modifiert.h \
    tiroir.h \
    repas.h \
    crudfood.h \
    consulterfood.h \
    menufood.h \
    dialog.h \
    smtp.h \
    mail.h \
    securite.h

FORMS    += mainwindow.ui \
    addtype.ui \
    readtype.ui \
    ajoutert.ui \
    supmodt.ui \
    modifiert.ui \
    crudfood.ui \
    menufood.ui \
    consulterfood.ui \
    dialog.ui \
    mail.ui \
    securite.ui

RESOURCES += \
    image.qrc


