#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>

class Client : public QObject {
    Q_OBJECT
public:
    Client() ;
    void broadcast(QByteArray xmlData);

private slots:
    void onConnected();
    void onReadyRead();

private:
    QTcpSocket socket;
};



#endif // CLIENT_H
