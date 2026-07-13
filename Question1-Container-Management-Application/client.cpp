#include "client.h"

Client::Client() {
    connect(&socket, &QTcpSocket::connected, this, &Client::onConnected);
    connect(&socket, &QTcpSocket::readyRead, this, &Client::onReadyRead);
    socket.connectToHost("127.0.0.1", 6164);

    qDebug() << "Please make sure Server is running before running Client code";

}

void Client::onConnected()
{
    qDebug() << "Connected to server";
}

void Client::onReadyRead()
{
    qDebug() << "Ready Read";

}

void Client::broadcast(QByteArray xmlData)
{
    if (socket.waitForConnected()) {
        socket.write(xmlData);
        socket.flush();
        socket.waitForBytesWritten();
    }

}
