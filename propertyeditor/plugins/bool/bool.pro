TEMPLATE = lib

CONFIG += exceptions \
dll \
plugin \
  rtti

INCLUDEPATH += $$PWD/../..

TARGET = BoolProperty

macx{
	QMAKE_LFLAGS +=  -F$$PWD/../../lib
 	LIBS += -framework PropertyEditor
}else{
	LIBS += -L$$PWD/../../lib -lPropertyEditor 
}

DESTDIR =.

HEADERS += bool.h

SOURCES += bool.cpp

RESOURCES += resource.qrc

target.path = $$PWD/../../lib

INSTALLS += target

