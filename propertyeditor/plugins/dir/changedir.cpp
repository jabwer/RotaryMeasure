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

#include <QFileDialog>
#include <QtCore>

#include "changedir.h"

ChangeDir::ChangeDir(QWidget *parent): QWidget(parent) {
	
	horizontalLayout = new QHBoxLayout(this);
	lineEdit = new QLineEdit(this);
	pushButton = new QPushButton(this);
	pushButton->setText(tr("..."));
	pushButton->resize(18, 18);
	
	horizontalLayout->addWidget(lineEdit);	
	horizontalLayout->setSpacing(0);
	horizontalLayout->setContentsMargins(0, 0, 0, 0);
	
	

	horizontalLayout->addWidget(pushButton);
	
	connect(pushButton, SIGNAL(pressed()), this, SLOT(onClick()));
}


void ChangeDir::onClick()
{
	QString path;
	if(selectDir())
		path = QFileDialog::getExistingDirectory(this, "Select Directory", dir());
	else path = QFileDialog::getOpenFileName(this, QString("Select '%1')").arg(filter()), dir(), filter());
	
	if (!path.isEmpty())
	{
		m_dir = path;
		if(lineEdit) lineEdit->setText(path);
		emit(dirChanged(path));
	}
}

void ChangeDir::setDir(QString d)
{
	m_dir = d;
	if(lineEdit) lineEdit->setText(d);
}

QString ChangeDir::dir()
{
	return m_dir;
}
