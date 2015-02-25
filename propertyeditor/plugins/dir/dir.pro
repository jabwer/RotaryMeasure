TEMPLATE = lib

CONFIG += exceptions \
dll \
plugin \
  rtti

HEADERS += dir.h \
changedir.h

SOURCES += dir.cpp \
changedir.cpp

TARGET = DirProperty

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

