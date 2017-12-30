/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/


#ifndef TCPCONNECTIONELEMENT_H
#define TCPCONNECTIONELEMENT_H

#include <QObject>

class QTcpServer;
class QTcpSocket;

class TcpConnectionElement : public QObject
{
    Q_OBJECT

public:
    enum ConnectionType
    {
        Client,
        Server
    };

    TcpConnectionElement(ConnectionType connectionType = Server, int port = 4242, const QString &hostName = "127.0.0.1", QObject *parent = 0);

    /*
    void setConnectionType(ConnectionType connectionType);
    ConnectionType connectionType() const;

    void setPort(int port);
    int port() const;

    void setHostName(const QString &hostName);
    QString hostName() const;
    */

    void sendData(const QString &data);

Q_SIGNALS:
    void dataReceived(const QString &data);
    void portChanged();
    void hostNameChanged();
    void connectionTypeChanged();

private Q_SLOTS:
    void receivedData();
    void slotConnection();

private:
    /*
    int m_port;
    QString m_hostName;
    ConnectionType m_connectionType;
    */

    QTcpServer *m_tcpServer;
    QTcpSocket *m_tcpSocket;
};

#endif
