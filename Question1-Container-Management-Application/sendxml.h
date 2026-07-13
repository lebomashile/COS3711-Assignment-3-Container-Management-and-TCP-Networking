#ifndef SENDXML_H
#define SENDXML_H

#include <QTcpSocket>
class SendXml
{
public:
    SendXml();
    ~SendXml();
    void postMessage(const QString &xmlData);
private:
    QTcpSocket *socket;
};

#endif // SENDXML_H
