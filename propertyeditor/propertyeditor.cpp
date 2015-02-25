/***************************************************************************
 *   This file is part of the propertyEditor project                       *
 *   Copyright (C) 2008 by BogDan Vatra                                    *
 *   bog_dan_ro@yahoo.com                                                  *
 **                   GNU General Public License Usage                    **
 *                                                                         *
 *   This library is free software: you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation, either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 *                                                                         *
 **                  GNU Lesser General Public License                    **
 *                                                                         *
 *   This library is free software: you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License as        * 
 *   published by the Free Software Foundation, either version 3 of the    *
 *   License, or (at your option) any later version.                       *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 ****************************************************************************/

#include <QDebug>
#include <QMetaProperty>
#include <QPluginLoader>
#include <QDir>
#include <QMetaClassInfo>
#include <QApplication>

#include "propertyeditor.h"
#include "propertyinterface.h"
#include "propertymodel.h"
#include "propertydelegate.h"

#include "numbers/numbers.h"
#include "bool/bool.h"
#include "brush/brush.h"
#include "color/color.h"
#include "date/date.h"
#include "dateTime/dateTime.h"
#include "enums/enums.h"
#include "flags/flags.h"
#include "font/font.h"
#include "metricfont/metricfont.h"
#include "numbers/numbers.h"
#include "pen/pen.h"
#include "pixmap/pixmap.h"
#include "rect/rect.h"
#include "rectf/rectf.h"
#include "size/size.h"
#include "sizef/sizef.h"
#include "strings/strings.h"
#include "stringlist/stringlist.h"
#include "time/timeprop.h"
#include "dir/dir.h"
#include "comboboxlist/comboboxlist.h"

#ifndef LIB_INSTALL_DIR
    #define LIB_INSTALL_DIR "../lib"
#endif

namespace PropertyEditor
{

PropertyEditor::PropertyEditor(QWidget *parent)
		: QTreeView(parent), m_object(0), m_model(0), m_delegate(0)
{
	setAlternatingRowColors(true);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	loadPlugins();
	m_delegate = new PropertyDelegate(this);
	setItemDelegate(m_delegate);
	m_model = new PropertyModel(this, 0, &m_plugins);
	setModel(m_model);
	setSelectionMode(QTreeView::SingleSelection);
	setSelectionBehavior(QTreeView::SelectRows);
	setRootIsDecorated(true);

	setEditTriggers(QAbstractItemView::CurrentChanged | QAbstractItemView::SelectedClicked);
}

void PropertyEditor::loadPlugins()
{
	/*Dir pluginsDir = QDir(qApp->applicationDirPath());
	pluginsDir.cd("plugins");

	foreach(QString fileName, pluginsDir.entryList(QDir::Files))
	{
		QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
		loader.setLoadHints(QLibrary::ResolveAllSymbolsHint);
		QObject *plugin = loader.instance();
		if (plugin && dynamic_cast<PropertyInterface*>(plugin))
			m_plugins.push_back(dynamic_cast<PropertyInterface*>(plugin));
		else
			qCritical() << plugin << loader.errorString();
	}*/
	
	m_plugins.push_back(new Numbers());
	m_plugins.push_back(new Bool());
	m_plugins.push_back(new Brush());
	m_plugins.push_back(new Color());
	m_plugins.push_back(new Date());
	m_plugins.push_back(new DateTime());
	m_plugins.push_back(new Enums());
	m_plugins.push_back(new Flags());
	m_plugins.push_back(new Font());
	m_plugins.push_back(new MetricFont());
	m_plugins.push_back(new Numbers());
	m_plugins.push_back(new Pen());
	m_plugins.push_back(new Pixmap());
	m_plugins.push_back(new Rect());
	m_plugins.push_back(new RectF());
	m_plugins.push_back(new Size());
	m_plugins.push_back(new SizeF());
	m_plugins.push_back(new StringList());
	m_plugins.push_back(new Strings());
	m_plugins.push_back(new TimeProp());
	m_plugins.push_back(new Dir());
	m_plugins.push_back(new ComboBoxList());
}

PropertyEditor::~PropertyEditor()
{
}

void PropertyEditor::setValidator(QVariant::Type type, PropertyValidator * validator)
{
	m_validators[type]=validator;
}

PropertyValidator* PropertyEditor::validator(QVariant::Type type)
{
	return m_validators[type];
}

void PropertyEditor::clearValidators()
{
	m_validators.clear();
}

void PropertyEditor::setObject(QObject * object)
{
	if (object == m_object)
		return;
	m_object = object;
	if (m_model)
		m_model->setObject(object);
	emit(objectChanged(object));
}

void PropertyEditor::resetProperties()
{
	if (m_model)
		m_model->resetModel();
}

QObject *PropertyEditor::object() const
{
	return m_object;
}
}
