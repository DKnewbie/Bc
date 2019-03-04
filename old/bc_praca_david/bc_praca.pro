#-------------------------------------------------
#
# Project created by QtCreator 2017-10-27T23:55:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bc_praca
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    segmentacia.cpp \
    normalizacia.cpp

HEADERS += \
        mainwindow.h \
    segmentacia.h \
    normalizacia.h

FORMS += \
        mainwindow.ui

INCLUDEPATH += /home/juraj/Dokumenty/opencv-debug/include
LIBS += /home/juraj/Dokumenty/opencv-debug/lib/libopencv_xfeatures2d.so.3.4.3
LIBS += /home/juraj/Dokumenty/opencv-debug/lib/libopencv_core.so.3.4.3
LIBS += /home/juraj/Dokumenty/opencv-debug/lib/libopencv_highgui.so.3.4.3
LIBS += /home/juraj/Dokumenty/opencv-debug/lib/libopencv_imgcodecs.so.3.4.3
LIBS += /home/juraj/Dokumenty/opencv-debug/lib/libopencv_imgproc.so.3.4.3
LIBS += /home/juraj/Dokumenty/opencv-debug/lib/libopencv_features2d.so.3.4.3
LIBS +=/home/juraj/Dokumenty/opencv-debug/lib/libopencv_calib3d.so.3.4.3
LIBS +=/home/juraj/Dokumenty/opencv-debug/lib/libopencv_imgproc.so.3.4.3

# more correct variant, how set includepath and libs for mingw
# add system variable: OPENCV_SDK_DIR=D:/opencv/build
# read http://doc.qt.io/qt-5/qmake-variable-reference.html#libs

#INCLUDEPATH += $$(OPENCV_SDK_DIR)/include

#LIBS += -L$$(OPENCV_SDK_DIR)/x86/mingw/lib \
#        -lopencv_core330        \
#        -lopencv_highgui330     \
#        -lopencv_imgcodecs330   \
#        -lopencv_imgproc330     \
#        -lopencv_features2d330  \
#        -lopencv_calib3d330
