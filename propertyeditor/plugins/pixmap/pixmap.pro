TEMPLATE = lib

CONFIG += exceptions \
dll \
plugin \
  rtti

FORMS += pixmapDialog.ui

SOURCES += pixmapdialog.cpp \
pixmap.cpp
HEADERS += pixmapdialog.h \
pixmap.h

TARGET = PixmapProperty

DESTDIR = .

INCLUDEPATH += $$PWD/../..

macx{
	QMAKE_LFLAGS +=  -F$$PWD/../../lib
 	LIBS += -framework PropertyEditor
}else{
	LIBS += -L$$PWD/../../lib -lPropertyEditor 
}


target.path = $$PWD/../../lib

INSTALLS += target

