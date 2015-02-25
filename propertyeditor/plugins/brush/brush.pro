TEMPLATE = lib

CONFIG += exceptions \
dll \
plugin \
  rtti

HEADERS += brush.h

SOURCES += brush.cpp

TARGET = BrushProperty

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
