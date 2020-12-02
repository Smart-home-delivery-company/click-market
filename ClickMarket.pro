QT       += core gui printsupport charts \
            multimedia
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    admingui.cpp \
    agent.cpp \
    ajouterproduit.cpp \
    associerclient.cpp \
    client.cpp \
    clientclass.cpp \
    connection.cpp \
    facture.cpp \
    livreur.cpp \
    livreurclass.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    produit.cpp \
    stats.cpp

HEADERS += \
    admin.h \
    admingui.h \
    agent.h \
    ajouterproduit.h \
    associerclient.h \
    client.h \
    clientclass.h \
    connection.h \
    facture.h \
    livreur.h \
    livreurclass.h \
    login.h \
    mainwindow.h \
    produit.h \
    stats.h

FORMS += \
    admingui.ui \
    ajouterproduit.ui \
    associerclient.ui \
    client.ui \
    facture.ui \
    livreur.ui \
    login.ui \
    mainwindow.ui \
    stats.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
