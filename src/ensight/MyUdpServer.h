#ifndef MYUDPSERVER_H
#define MYUDPSERVER_H

#include <QObject>
#include <QQmlEngine>
#include<QUdpSocket>
class MyUdpServer : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit MyUdpServer(QObject *parent = nullptr);
    Q_INVOKABLE void  startServer();
    Q_INVOKABLE void  stopServer();
signals:
    void dataReceived(QString);
private:
    int port = 8554;
    QUdpSocket *usocket = NULL;
public slots:
    void readPendingDatagrams();
};

#endif // MYUDPSERVER_H
