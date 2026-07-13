#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
class Server : public QObject
{
    Q_OBJECT
public:
    Server();
private slots:
    void handleConnection();
    void readXmlData();
public slots:
    void startServer();
signals:
    void broadcast(QByteArray);
private:
    QTcpServer *server;
};

#endif // SERVER_H
