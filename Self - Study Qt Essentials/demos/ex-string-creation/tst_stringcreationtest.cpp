#include <QString>
#include <QtTest>

// Check QT_NO_CAST_FROM_ASCII is also defined in the .pro file
// if it is not commented out below
// #define QT_NO_CAST_FROM_ASCII_tst

class StringCreationTest : public QObject
{
    Q_OBJECT

public:
    StringCreationTest();

private Q_SLOTS:
    void basicCreation();
    void QStringToQStringComparison();
    void QStringTocharPtrComparison();
    void QStringToQStringLiteralComparison();
};

StringCreationTest::StringCreationTest()
{
}

void StringCreationTest::basicCreation()
{
    QString testString;
    QVERIFY(testString.isNull());
    QVERIFY(testString.isEmpty());

#ifndef QT_NO_CAST_FROM_ASCII_tst
    testString = "Test string";
#else
    testString = QString::fromUtf8("Test string");
#endif
    QVERIFY(!testString.isNull());
    QVERIFY(!testString.isEmpty());
}

void StringCreationTest::QStringToQStringComparison()
{
#ifndef QT_NO_CAST_FROM_ASCII_tst
    QString string("test");
    QBENCHMARK {
        if (string == QString("test"))
            ;
    }
#else
    QString string(QString::fromUtf8("test"));
    QBENCHMARK {
        if (string == QString::fromUtf8("test"))
            ;
    }
#endif
}

void StringCreationTest::QStringTocharPtrComparison()
{
#ifndef QT_NO_CAST_FROM_ASCII_tst
    QString string("test");
    QBENCHMARK {
        if (string == "test")
            ;
    }
#else
    QString string(QString::fromUtf8("test"));
    QBENCHMARK {
        if (string == QLatin1String("test"))
            ;
    }
#endif
}

void StringCreationTest::QStringToQStringLiteralComparison()
{
#ifndef QT_NO_CAST_FROM_ASCII_tst
    QString string("test");
#else
    QString string(QString::fromUtf8("test"));
#endif
    QBENCHMARK {
        if (string == QStringLiteral("test"))
            ;
    }
}

QTEST_APPLESS_MAIN(StringCreationTest)

#include "tst_stringcreationtest.moc"
