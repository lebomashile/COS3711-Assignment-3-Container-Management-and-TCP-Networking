#include "server.h"
#include <QDebug>
#include <QTcpSocket>

Server::Server() :


    server(new QTcpServer){

    connect(server,SIGNAL(newConnection()),this,SLOT(handleConnection()));

}

void Server::handleConnection()
{
        qDebug() << "New Connection...";
        QTcpSocket *clientSocket = server->nextPendingConnection();
        connect(clientSocket, &QTcpSocket::readyRead, this, &Server::readXmlData);


}

void Server::readXmlData()
{

    QTcpSocket *clientSocket = qobject_cast<QTcpSocket *>(sender());

    QByteArray data = clientSocket->readAll();



    emit broadcast(data);
}

void Server::startServer()
{
    if(!server->isListening())
    server->listen(QHostAddress::LocalHost, 6164);
    else
        qDebug() << "listening..";

}
