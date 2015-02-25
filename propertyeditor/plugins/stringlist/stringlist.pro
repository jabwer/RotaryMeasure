TEMPLATE = lib

CONFIG += exceptions \
dll \
plugin \
  rtti


TARGET = StringListProperty

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

SOURCES += stringlist.cpp \
stringlisteditor.cpp
HEADERS += stringlisteditor.h \
stringlist.h
FORMS += stringlisteditor.ui

RESOURCES += stringlist.qrc

