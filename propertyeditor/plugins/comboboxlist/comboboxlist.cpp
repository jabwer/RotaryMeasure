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
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library.                                      * 
 *   If not, see <http://www.gnu.org/licenses/>.                           *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 ****************************************************************************/

#include <QtCore>
#include <QMetaProperty>
#include <QMetaEnum>
#include "comboboxlist.h"

ComboBoxList::ComboBoxList(QObject* parent, QObject* object, int property, const PropertyModel* propertyModel): PropertyInterface(parent, object, property, propertyModel)
{
	refreshPropertis(propertyModel);
}


QWidget* ComboBoxList::createEditor(QWidget * parent, const QModelIndex & index)
{
	Q_UNUSED(index);
	Q_UNUSED(parent);
	return 0;
}

QVariant ComboBoxList::data(const QModelIndex & index)
{
	switch (index.column())
	{
		case 0:
			return object()->metaObject()->property(objectProperty()).name();
		case 1:
			return QString("[(%1,%2) %3,%4]").arg(value().toRect().x()).arg(value().toRect().y()).arg(value().toRect().width()).arg(value().toRect().height());
	}
	return QVariant();
}

bool ComboBoxList::setData(QVariant data, const QModelIndex & index)
{
	Q_UNUSED(data);
	Q_UNUSED(index);
	return false;
}

bool ComboBoxList::canHandle(QObject * object, int property) const
{
	if (object->metaObject()->property(property).isEnumType() || object->metaObject()->property(property).isFlagType())
		return false;

	switch (object->property(object->metaObject()->property(property).name()).type())
	{
		case QVariant::Rect:
			return true;
		default:
			return false;
	}
	return false;
}

int ComboBoxList::x()
{
	return value().toRect().x();
}

void ComboBoxList::setX(int x)
{
	QRect s = value().toRect();
	s.setX(x);
	setValue(s);
}

int ComboBoxList::y()
{
	return value().toRect().y();
}

void ComboBoxList::setY(int y)
{
	QRect s = value().toRect();
	s.setY(y);
	setValue(s);
}


int ComboBoxList::height()
{
	return value().toRect().height();
}

void ComboBoxList::setHeight(int height)
{
	QRect s = value().toRect();
	s.setHeight(height);
	setValue(s);
}

int ComboBoxList::width()
{
	return value().toRect().width();
}

void ComboBoxList::setWidth(int width)
{
	QRect s = value().toRect();
	s.setWidth(width);
	setValue(s);
}

Qt::ItemFlags ComboBoxList::flags(const QModelIndex &/*index*/)
{
	return Qt::ItemIsEnabled;
}

PropertyInterface* ComboBoxList::createInstance(QObject * object, int property, const PropertyModel * propertyModel) const
{
	return new ComboBoxList(parent(), object, property, propertyModel);
}
