/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtMimeTypes addon of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qdeclarativeserviceaction_p.h"

#include <QtCore/QDebug>

// ------------------------------------------------------------------------------------------------

QDeclarativeServiceAction::QDeclarativeServiceAction(QObject *theParent) :
        QObject(theParent),
        m_ServiceAction()
{}

// ------------------------------------------------------------------------------------------------

QDeclarativeServiceAction::QDeclarativeServiceAction(const QServiceAction &other, QObject *theParent) :
        QObject(theParent),
        m_ServiceAction(other)
{}

// ------------------------------------------------------------------------------------------------

QDeclarativeServiceAction::~QDeclarativeServiceAction()
{
    //qDebug() << Q_FUNC_INFO << "name():" << name();
}

// ------------------------------------------------------------------------------------------------

void QDeclarativeServiceAction::assign(QDeclarativeServiceAction *other)
{
    if (other == 0) {
        qWarning() << Q_FUNC_INFO << "other:" << other;
        return;
    }

    m_ServiceAction = other->m_ServiceAction;
}

// ------------------------------------------------------------------------------------------------

bool QDeclarativeServiceAction::equals(QDeclarativeServiceAction *other) const
{
    if (other == 0) {
        qWarning() << Q_FUNC_INFO << "other:" << other;
        return false;
    }

    return m_ServiceAction == other->m_ServiceAction;
}

// ------------------------------------------------------------------------------------------------

QServiceAction QDeclarativeServiceAction::serviceAction() const
{
    return m_ServiceAction;
}

// ------------------------------------------------------------------------------------------------

bool QDeclarativeServiceAction::isValid() const
{
    return m_ServiceAction.isValid();
}

// ------------------------------------------------------------------------------------------------

const QServiceActionName &QDeclarativeServiceAction::name() const
{
    return m_ServiceAction.name();
}

// ------------------------------------------------------------------------------------------------

void QDeclarativeServiceAction::setName(const QServiceActionName &newName)
{
    m_ServiceAction = QServiceAction(newName, m_ServiceAction.displayName(), m_ServiceAction.iconUrl());
}

// ------------------------------------------------------------------------------------------------

QString QDeclarativeServiceAction::displayName() const
{
    return m_ServiceAction.displayName();
}

// ------------------------------------------------------------------------------------------------

void QDeclarativeServiceAction::setDisplayName(const QString &newDisplayName)
{
    m_ServiceAction = QServiceAction(m_ServiceAction.name(), newDisplayName, m_ServiceAction.iconUrl());
}

// ------------------------------------------------------------------------------------------------

QString QDeclarativeServiceAction::iconUrl() const
{
    return m_ServiceAction.iconUrl();
}

// ------------------------------------------------------------------------------------------------

void QDeclarativeServiceAction::setIconUrl(const QString &newIconUrl)
{
    m_ServiceAction = QServiceAction(m_ServiceAction.name(), m_ServiceAction.displayName(), newIconUrl);
}
