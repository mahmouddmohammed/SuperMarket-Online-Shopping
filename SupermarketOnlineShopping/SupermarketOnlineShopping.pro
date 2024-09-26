QT       += core gui
QT += svg
QT += network #you must write it to be able to include its header files
QT += core gui network
QT += sql
#QT += multimedia
#LIBS += -lqmessaging
#QT += messagingframework

#INCLUDEPATH += C:\xampp\mysql\mysql-connector-c-6.1.11-winx64\include
#LIBS += -LC:\xampp\mysql\mysql-connector-c-6.1.11-winx64\lib -lmysql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    main_.cpp \
    mainwindow.cpp \
    mainwindowhome.cpp \
    mainwindowlogin.cpp \
    mainwindowregister.cpp \
    sellerwindow.cpp

HEADERS += \
    main_.h \
    mainwindow.h \
    mainwindowhome.h \
    mainwindowlogin.h \
    mainwindowregister.h \
    sellerwindow.h

FORMS += \
    mainwindow.ui \
    mainwindowhome.ui \
    mainwindowlogin.ui \
    mainwindowregister.ui \
    sellerwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

#win32: LIBS += -L$$PWD/../lib/ -llibmysql

INCLUDEPATH += $$PWD/../
DEPENDPATH += $$PWD/../
