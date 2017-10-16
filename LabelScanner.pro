#-------------------------------------------------
#
# Project created by QtCreator 2017-02-25T11:14:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LabelScanner
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tesseract.cpp \
    opencv.cpp

HEADERS  += mainwindow.h \
    tesseract.h \
    opencv.h \
    test.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/release/ -llept
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/debug/ -llept
else:unix: LIBS += -L$$PWD/../../../usr/local/lib/ -llept

INCLUDEPATH += $$PWD/../../../usr/local/include
DEPENDPATH += $$PWD/../../../usr/local/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/release/ -ltesseract
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/debug/ -ltesseract
else:unix: LIBS += -L$$PWD/../../../usr/local/lib/ -ltesseract

INCLUDEPATH += $$PWD/../../../usr/local/include
DEPENDPATH += $$PWD/../../../usr/local/include


CONFIG += link_pkgconfig
PKGCONFIG += opencv

DISTFILES += \
    ../../../usr/local/lib/libopencv_highgui.so.3.1.0
