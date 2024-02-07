#include "MyUdpSocket.h"

MyUdpSocket::MyUdpSocket(QObject *parent)
    : QObject{parent}
{}

void MyUdpSocket::connectToServer()
{
    socket = new QUdpSocket(this);

}

void MyUdpSocket::disconnectServer()
{
    socket->close();
}

void MyUdpSocket::sendData(QString data)
{
    QByteArray ba;
    ba.append(data.toStdString().c_str());

    socket->writeDatagram(ba,QHostAddress(ip),port);

}
