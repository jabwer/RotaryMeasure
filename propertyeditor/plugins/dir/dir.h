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

#ifndef DIR_H
#define DIR_H

#include <QtCore>
#include <propertyinterface.h>

#include "changedir.h"

using namespace PropertyEditor;

/**
	@author BogDan Vatra <bogdan@licentia.eu>
*/

class Dir : public PropertyInterface
{
	Q_OBJECT
	Q_INTERFACES(PropertyEditor::PropertyInterface);
	Q_PROPERTY(QString filter READ filter WRITE setFilter)
	Q_PROPERTY(qint32 selectDir READ selectDir WRITE setSelectDir)
	
	QString m_filter;
	qint32 m_selectDir;
	ChangeDir *cf;
public:
	Dir(QObject* parent = 0, QObject* object = 0, int property = -1, const PropertyModel * propertyModel = 0);
	QWidget* createEditor(QWidget * parent, const QModelIndex & index);
	
	QVariant data(const QModelIndex & index);
	bool setData(QVariant data, const QModelIndex & index);
	void setEditorData(QWidget * editor, const QModelIndex & index);

	bool canHandle(QObject * object, int property)const;

	PropertyInterface* createInstance(QObject * object, int property, const PropertyModel * propertyModel) const;

	QString filter() const {
		return m_filter;
	}
	
	qint32 selectDir() const {
		return m_selectDir;
	}
public slots:
	void setValue(const QString& c);
	
	void setFilter(const QString &s) {
		m_filter = s;
	}
	
	void setSelectDir(const qint32 &s) {
		m_selectDir = s;
	}
};

#endif
