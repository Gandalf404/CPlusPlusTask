QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    src/database/database.cpp \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    include/database/database.h \
    include/mainwindow.h

FORMS += \
    mainwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
