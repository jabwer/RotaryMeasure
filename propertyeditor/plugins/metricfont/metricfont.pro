TEMPLATE = lib

CONFIG += exceptions \
dll \
plugin \
  rtti

HEADERS += font.h \
changefont.h \
 metricfontdialog.h

SOURCES += font.cpp \
changefont.cpp \
 metricfontdialog.cpp

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

FORMS += metricfontdialog.ui

