#-------------------------------------------------
#
# Project created by QtCreator 2012-02-13T13:52:43
#
#-------------------------------------------------

QT       += core gui widgets printsupport

CONFIG           += qwt qwtpolar

TARGET = RotaryMeasure
TEMPLATE = app

#QMAKE_LFLAGS = -enable-stdcall-fixup -Wl,-enable-auto-import -Wl,-enable-runtime-pseudo-reloc

include($$PWD/qextserialport/src/qextserialport.pri)

INCLUDEPATH += \
    $$PWD/visa/include \
    $$PWD/propertyeditor \
    $$PWD/qextserialport/src
    #$$PWD/qwt-6.1/src \
    #$$PWD/qwtpolar-1.1/qwtpolar/src

SOURCES += main.cpp\
        mainwindow.cpp \
    plot.cpp \
    instrument.cpp \
    misc.cpp

HEADERS  += mainwindow.h \
    plot.h \
    instrument.h \
    misc.h

FORMS    += mainwindow.ui

win32 {
    DEFINES += WINVER=0x0501
    LIBS += -lsetupapi -luuid -ladvapi32
}
unix:!macx {
    LIBS += -ludev
}

LIBS += \
    $$PWD/visa/lib/visa32.a \
    $$PWD/propertyeditor/lib/libPropertyEditor.a \
    $$PWD/qextserialport/debug/libQt5ExtSerialPortd1.a

#debug {
    LIBS += \
#    $$PWD/qwt-6.1/lib/libqwtd.a \
#    $$PWD/qwt2/lib/libqwtmathmld.a \
#    $$PWD/qwtpolar-1.1/qwtpolar/lib/libqwtpolard.a
#}

#release {
#    LIBS += \
#    $$PWD/qwt2/lib/libqwt.a \
#    $$PWD/qwt2/lib/libqwtmathml.a \
#    $$PWD/qwtpolar/lib/libqwtpolar.a
#}


