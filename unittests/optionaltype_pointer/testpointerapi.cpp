/****************************************************************************
** Copyright (C) 2014-2018 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com.
** All rights reserved.
**
** Author: Ville Voutilainen <ville.voutilainen gmail.com>
**
** This file is part of the KD Soap library.
**
** Licensees holding valid commercial KD Soap licenses may use this file in
** accordance with the KD Soap Commercial License Agreement provided with
** the Software.
**
** This file may be distributed and/or modified under the terms of the
** GNU Lesser General Public License version 2.1 and version 3 as published by the
** Free Software Foundation and appearing in the file LICENSE.LGPL.txt included.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** Contact info@kdab.com if any conditions of this licensing are not
** clear to you.
**
**********************************************************************/

#include "testpointerapi.h"
#include <QTest>
#include <QDebug>
#include <QList>

TestPointerApi::TestPointerApi()
{
}

void TestPointerApi::test()
{
    TNS__TestOperationResponse1 resp;
    QCOMPARE(resp.out(), (QString *)0);
    QString newVal("newval");
    resp.setOut(newVal);
    QCOMPARE(*resp.out(), newVal);
}

void TestPointerApi::testOptionalArray()
{
    TNS__TestOperationResponse1 resp;
    QVERIFY(!resp.outOptionalArray());
    const QList<qint64> valIn(QList<qint64>() << 1 << 2 << 3);
    resp.setOutOptionalArray(valIn);

    TNS__TestOperationResponse1 resp2;
    resp2.deserialize(resp.serialize("array"));

    QVERIFY(resp2.outOptionalArray());
    QCOMPARE(valIn, *resp2.outOptionalArray());
}

QTEST_MAIN(TestPointerApi)
