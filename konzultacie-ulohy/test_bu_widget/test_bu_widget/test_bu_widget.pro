#-------------------------------------------------
#
# Project created by QtCreator 2019-03-01T17:13:23
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test_bu_widget
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

INCLUDEPATH += /home/dk/bc/konzultacie-ulohy/bu/bu

#LIBS += -L"/home/dk/bc/konzultacie-ulohy/bu/build-bu-Desktop_Qt_5_12_0_GCC_64bit-Debug" -lbu
#LIBS += -L"/home/dk/bc/konzultacie-ulohy/bu/build-bu-Desktop_Qt_5_12_0_GCC_64bit-Release" -lbu

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../bu/build-bu-Desktop_Qt_5_12_0_GCC_64bit-Debug/release/ -lbu
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../bu/build-bu-Desktop_Qt_5_12_0_GCC_64bit-Debug/debug/ -lbu
else:unix: LIBS += -L$$PWD/../../bu/build-bu-Desktop_Qt_5_12_0_GCC_64bit-Debug/ -lbu

INCLUDEPATH += $$PWD/../../bu/build-bu-Desktop_Qt_5_12_0_GCC_64bit-Debug
DEPENDPATH += $$PWD/../../bu/build-bu-Desktop_Qt_5_12_0_GCC_64bit-Debug

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../bu/build-bu-Desktop_Qt_5_12_0_GCC_64bit-Release/release/ -lbu
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../bu/build-bu-Desktop_Qt_5_12_0_GCC_64bit-Release/debug/ -lbu
else:unix: LIBS += -L$$PWD/../../bu/build-bu-Desktop_Qt_5_12_0_GCC_64bit-Release/ -lbu

INCLUDEPATH += $$PWD/../../bu/build-bu-Desktop_Qt_5_12_0_GCC_64bit-Release
DEPENDPATH += $$PWD/../../bu/build-bu-Desktop_Qt_5_12_0_GCC_64bit-Release


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

