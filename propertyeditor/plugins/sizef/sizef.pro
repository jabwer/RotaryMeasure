TEMPLATE = lib

CONFIG += exceptions \
dll \
plugin \
  rtti

HEADERS += sizef.h

SOURCES += sizef.cpp

TARGET = SizeFProperty

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

