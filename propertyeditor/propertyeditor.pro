TEMPLATE = lib

CONFIG += exceptions
CONFIG += rtti  
CONFIG += staticlib
CONFIG += debug_and_release

QT += widgets

macx{
	CONFIG += lib_bundle
}

INCLUDEPATH+= $$PWD \
	$$PWD/plugins

HEADERS += propertyeditor.h \
	propertymodel.h \
	propertyinterface.h \
	propertydelegate.h \
	$$PWD/plugins/bool/bool.h \
	$$PWD/plugins/brush/brush.h \
	$$PWD/plugins/color/changecolor.h \
	$$PWD/plugins/color/color.h \
	$$PWD/plugins/dir/changedir.h \
	$$PWD/plugins/dir/dir.h \
	$$PWD/plugins/date/date.h \
	$$PWD/plugins/dateTime/datetime.h \
	$$PWD/plugins/enums/enums.h \
	$$PWD/plugins/flags/flags.h \
	$$PWD/plugins/flags/flagslist.h \
	$$PWD/plugins/font/changefont.h \
	$$PWD/plugins/font/font.h \
	$$PWD/plugins/metricfont/changefont.h \
	$$PWD/plugins/metricfont/metricfont.h \
	$$PWD/plugins/metricfont/metricfontdialog.h \
	$$PWD/plugins/numbers/numbers.h \
	$$PWD/plugins/pen/pen.h \
	$$PWD/plugins/pixmap/pixmap.h \
	$$PWD/plugins/pixmap/pixmapdialog.h \
	$$PWD/plugins/rect/rect.h \
	$$PWD/plugins/rectf/rectf.h \
	$$PWD/plugins/size/size.h \
	$$PWD/plugins/sizef/sizef.h \
	$$PWD/plugins/stringlist/stringlist.h \
	$$PWD/plugins/stringlist/stringlisteditor.h \
	$$PWD/plugins/strings/strings.h \
	$$PWD/plugins/time/timeprop.h \
	$$PWD/plugins/comboboxlist/comboboxlist.h
	

SOURCES += propertyeditor.cpp \
	propertymodel.cpp \
	propertyinterface.cpp \
	propertydelegate.cpp \
	$$PWD/plugins/bool/bool.cpp \
	$$PWD/plugins/brush/brush.cpp \
	$$PWD/plugins/color/changecolor.cpp \
	$$PWD/plugins/color/color.cpp \
	$$PWD/plugins/dir/changedir.cpp \
	$$PWD/plugins/dir/dir.cpp \
	$$PWD/plugins/date/date.cpp \
	$$PWD/plugins/dateTime/datetime.cpp \
	$$PWD/plugins/enums/enums.cpp \
	$$PWD/plugins/flags/flags.cpp \
	$$PWD/plugins/flags/flagslist.cpp \
	$$PWD/plugins/font/changefont.cpp \
	$$PWD/plugins/font/font.cpp \
	$$PWD/plugins/metricfont/changefont.cpp \
	$$PWD/plugins/metricfont/metricfont.cpp \
	$$PWD/plugins/metricfont/metricfontdialog.cpp \
	$$PWD/plugins/numbers/numbers.cpp \
	$$PWD/plugins/pen/pen.cpp \
	$$PWD/plugins/pixmap/pixmap.cpp \
	$$PWD/plugins/pixmap/pixmapdialog.cpp \
	$$PWD/plugins/rect/rect.cpp \
	$$PWD/plugins/rectf/rectf.cpp \
	$$PWD/plugins/size/size.cpp \
	$$PWD/plugins/sizef/sizef.cpp \
	$$PWD/plugins/stringlist/stringlist.cpp \
	$$PWD/plugins/stringlist/stringlisteditor.cpp \
	$$PWD/plugins/strings/strings.cpp \
	$$PWD/plugins/time/timeprop.cpp \
	$$PWD/plugins/comboboxlist/comboboxlist.cpp


TARGET = PropertyEditor

RESOURCES += $$PWD/plugins/bool/resource.qrc \
	$$PWD/plugins/stringlist/stringlist.qrc \

FORMS += $$PWD/plugins/flags/flagsList.ui \
	$$PWD/plugins/metricfont/metricfontdialog.ui \
	$$PWD/plugins/pixmap/pixmapDialog.ui \
	$$PWD/plugins/stringlist/stringlisteditor.ui

DESTDIR = $$PWD/lib

