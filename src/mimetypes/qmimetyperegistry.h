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

#ifndef QT_MIMETYPES_H_INCLUDED
#define QT_MIMETYPES_H_INCLUDED

#include "qmimetype.h"
#include "qmimetypesfwd.h"
#include "qserviceaction.h"

#include <QtCore/QList>
#include <QtCore/QPair>

class QMimeTypeRegistryPrivate;

class QByteArray;

// ------------------------------------------------------------------------------------------------

class QMimeTypeRegistry
{
public:
    QMimeTypeRegistry();

    ~QMimeTypeRegistry();

    // --------------------------------------------------------------------------------------------

    QList<QMimeTypeName> mimeTypes() const;

    QMimeType findMimeType (
                  const QMimeTypeName &mimeTypeName
              ) const;

    // --------------------------------------------------------------------------------------------

    QList<QString> filenameExtensions() const;

    QString extractFilenameExtension (
                 const QString &fileName
            ) const;

    QList<QMimeTypeName> findMimeTypes (
                             const QString &filenameExtension
                         ) const;

    // --------------------------------------------------------------------------------------------

    QMimeTypeName determineMimeType (
                      const QByteArray &data
                  ) const;

    // --------------------------------------------------------------------------------------------

    QList<QServiceActionName> serviceActions() const;

    QServiceAction findServiceAction (
                       const QServiceActionName &serviceActionName
                   );

    // --------------------------------------------------------------------------------------------

    bool userAlwaysSelectsApplication (
             const QServiceActionName &serviceActionName,
             const QMimeTypeName &mimeTypeName
         ) const;

    void setUserAlwaysSelectsApplication (
             const QServiceActionName &serviceActionName,
             const QMimeTypeName &mimeTypeName,
             const bool newSetting
         );

    // --------------------------------------------------------------------------------------------

    void increaseApplicationPreference (
             const QApplicationId &applicationId,
             const QServiceActionName &serviceActionName,
             const QMimeTypeName &mimeTypeName
         );

    void decreaseApplicationPreference (
             const QApplicationId &applicationId,
             const QServiceActionName &serviceActionName,
             const QMimeTypeName &mimeTypeName
         );

    QList<QPair<QApplicationId, QServiceActionName> > findApplications (
                                                          const QMimeTypeName &mimeTypeName
                                                      ) const;

    QList<QApplicationId> findApplications (
                              const QServiceActionName &serviceActionName,
                              const QMimeTypeName &mimeTypeName
                          ) const;

    // --------------------------------------------------------------------------------------------

private:
    QMimeTypeRegistryPrivate *d_ptr;
};

#endif   // QT_MIMETYPES_H_INCLUDED
