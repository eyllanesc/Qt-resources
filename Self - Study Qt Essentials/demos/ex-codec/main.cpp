/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QApplication>
#include <QTabWidget>
#include <QLabel>
#include <QMap>
#include <QFile>
#include <QTextCodec>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMap<QString,QByteArray> encoding;
    encoding.insert("chinese", "Big5");
    encoding.insert("danish", "ISO8859-1");
    encoding.insert("japanese", "eucJP");
    encoding.insert("english", "ISO8859-1");
    encoding.insert("greek", "ISO8859-7");
    encoding.insert("japanese-wrong-encoding", "ISO8859-1");

    QTabWidget tab; 

    for (const QString& language : encoding.keys()) {
        QFile f(":/text-"+language);
        f.open(QIODevice::ReadOnly | QIODevice::Text);
        QByteArray data = f.readAll();
        QTextCodec *codec = QTextCodec::codecForName(encoding[language]);
        QString text = codec->toUnicode(data);
        QLabel *label = new QLabel(text);
        label->setWordWrap(true);

        tab.addTab(label, language);
    }

    tab.show();
    return app.exec();
}

