#include "MyUdpServer.h"

MyUdpServer::MyUdpServer(QObject *parent)
    : QObject{parent}
{}



void MyUdpServer::startServer()
{
    usocket = new QUdpSocket(this);
    usocket->bind(QHostAddress::Any,port);
    connect(usocket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));

}

void MyUdpServer::stopServer()
{
    disconnect(usocket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
    usocket->close();
}


void MyUdpServer::readPendingDatagrams()
{
    qDebug() << "function called\n";
    while(usocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(usocket->pendingDatagramSize());

        QHostAddress sender;
        quint16 senderPort;

        usocket->readDatagram(datagram.data(), datagram.size(),
                              &sender, &senderPort);
        qInfo() << datagram.data();
        QString s(datagram.data());
        emit dataReceived(s);
    }
}
