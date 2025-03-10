TEMPLATE = lib

CONFIG += exceptions \
dll \
plugin \
  rtti

HEADERS += color.h \
changecolor.h

SOURCES += color.cpp \
changecolor.cpp

TARGET = ColorProperty

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

