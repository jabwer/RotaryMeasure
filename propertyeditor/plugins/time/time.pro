TEMPLATE = lib

CONFIG += exceptions \
dll \
plugin \
  rtti

HEADERS += timeprop.h

SOURCES += timeprop.cpp

TARGET = TimeProperty

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

