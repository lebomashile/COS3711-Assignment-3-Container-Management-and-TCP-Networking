#include "sendxml.h"

SendXml::SendXml()
    :socket(new QTcpSocket){

    socket->connectToHost("127.0.0.1", 6164);
}

SendXml::~SendXml()
{
    delete socket;
}

void SendXml::postMessage(const QString &xmlData)
{

    if (socket->waitForConnected()) {
        socket->write(xmlData.);
        socket->flush();
        socket->waitForBytesWritten();
    }

}
