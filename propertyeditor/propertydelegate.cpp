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

#include <QPainter>
#include <QModelIndex>
#include <QApplication>
#include <QtCore>

#include "propertydelegate.h"
#include "propertyinterface.h"

namespace PropertyEditor
{

enum { BrushRole = 33 };

PropertyDelegate::PropertyDelegate(QObject *parent)
		: QItemDelegate(parent)
{
}


PropertyDelegate::~PropertyDelegate()
{
}

void PropertyDelegate::parseEditorHints(QObject* object, const QString& editorHints) const
{
	if (object && !editorHints.isEmpty())
	{
		object->blockSignals(true);
		// Parse for property values
		QRegExp rx("(.*)(=\\s*)(.*)(;{1})");
		rx.setMinimal(true);
		int pos = 0;
		while ((pos = rx.indexIn(editorHints, pos)) != -1) 
		{
			//qDebug("%Setting %s to %s of %s", qPrintable(rx.cap(1)), qPrintable(rx.cap(3)), object->metaObject()->className());
			object->setProperty(qPrintable(rx.cap(1).trimmed()), rx.cap(3).trimmed());				
			pos += rx.matchedLength();
		}
		object->blockSignals(false);
	}
}

QWidget * PropertyDelegate::createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	Q_UNUSED(option);
	if (index.isValid()) {
	    PropertyInterface *pi = reinterpret_cast<PropertyInterface*>(index.internalPointer());
		QWidget *editor = pi->createEditor(parent, index);
		
		int ciIndex = -1;
		if((ciIndex = pi->object()->metaObject()->indexOfClassInfo(pi->object()->metaObject()->property(pi->objectProperty()).name())) != -1)
			pi->editorHints = QString::fromLatin1(pi->object()->metaObject()->classInfo(ciIndex).value());
		
		parseEditorHints(editor, pi->editorHints);
		
		return editor;
	}
	return 0;
}

void PropertyDelegate::paint(QPainter * painter, const QStyleOptionViewItem & opt, const QModelIndex & index) const
{
	QStyleOptionViewItem option = opt;

	if (index.column())
		option.font.setBold(true);

    QBrush br = index.model()->data(index, BrushRole).value<QBrush>();

	if (br.style() == Qt::LinearGradientPattern ||
	        br.style() == Qt::RadialGradientPattern ||
	        br.style() == Qt::ConicalGradientPattern)
	{
		painter->save();
		painter->translate(option.rect.x(), option.rect.y());
		painter->scale(option.rect.width(), option.rect.height());
		QGradient gr = *(br.gradient());
		gr.setCoordinateMode(QGradient::LogicalMode);
		br = QBrush(gr);
		painter->fillRect(0, 0, 1, 1, br);
		painter->restore();
	}
	else
	{
		painter->save();
		painter->setBrushOrigin(option.rect.x(), option.rect.y());
		painter->fillRect(option.rect, br);
		painter->restore();
	}

	QItemDelegate::paint(painter, option, index);
	const QColor color = static_cast<QRgb>(QApplication::style()->styleHint(QStyle::SH_Table_GridLineColor, &option));
	const QPen oldPen = painter->pen();
	painter->setPen(QPen(color));

	painter->drawLine(option.rect.right(), option.rect.y(),
	                  option.rect.right(), option.rect.bottom());
	painter->drawLine(option.rect.x(), option.rect.bottom(),
	                  option.rect.right(), option.rect.bottom());
	painter->setPen(oldPen);
}

void PropertyDelegate::setEditorData(QWidget * editor, const QModelIndex & index) const
{
	if (index.isValid())
		reinterpret_cast<PropertyInterface*>(index.internalPointer())->setEditorData(editor, index);
}

QSize PropertyDelegate::sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	return QItemDelegate::sizeHint(option, index) + QSize(2, 2);
}

}
