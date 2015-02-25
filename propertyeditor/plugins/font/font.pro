TEMPLATE = lib

CONFIG += exceptions \
dll \
plugin \
  rtti

HEADERS += font.h \
changefont.h

SOURCES += font.cpp \
changefont.cpp

TARGET = FontProperty

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

