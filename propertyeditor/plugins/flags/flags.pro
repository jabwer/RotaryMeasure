TEMPLATE = lib

CONFIG += exceptions \
dll \
plugin \
  rtti

HEADERS += flags.h \
 flagslist.h

SOURCES += flags.cpp \
 flagslist.cpp

FORMS += flagsList.ui

TARGET = FlagsProperty

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

