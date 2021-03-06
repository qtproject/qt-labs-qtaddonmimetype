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

#ifndef MIME_TYPE_P_H_INCLUDED
#define MIME_TYPE_P_H_INCLUDED

#include <QtCore/QList>
#include <QtCore/QString>

// ------------------------------------------------------------------------------------------------

struct QMimeTypePrivate
{
    QMimeTypePrivate(const QMimeTypeName &theName,
                     const QString &theDisplayName,
                     const QString &theIconUrl,
                     const QList<QString> &theFilenameExtensions) :
            m_Name(theName),
            m_DisplayName(theDisplayName),
            m_IconUrl(theIconUrl),
            m_FilenameExtensions(theFilenameExtensions)
    {}

    bool operator==(const QMimeTypePrivate &other) const
    {
        return m_Name == other.m_Name &&
               m_DisplayName == other.m_DisplayName &&
               m_IconUrl == other.m_IconUrl &&
               m_FilenameExtensions == other.m_FilenameExtensions;
    }

    QMimeTypeName m_Name;
    QString m_DisplayName;
    QString m_IconUrl;
    QList<QString> m_FilenameExtensions;
};

#endif
