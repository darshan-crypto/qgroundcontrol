#ifndef MYUDPSOCKET_H
#define MYUDPSOCKET_H


#include <QObject>
#include <QQmlEngine>
#include<QUdpSocket>

class MyUdpSocket : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit MyUdpSocket(QObject *parent = nullptr);
    Q_INVOKABLE void connectToServer();
    Q_INVOKABLE void disconnectServer();
    Q_INVOKABLE void sendData(QString);
private:
    int port = 8554;
    QString ip = "192.168.144.25";
    QUdpSocket *socket;

};

#endif // MYUDPSOCKET_H
