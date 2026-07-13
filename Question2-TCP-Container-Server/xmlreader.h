#ifndef XMLREADER_H
#define XMLREADER_H

#include <QDomDocument>
#include <QObject>

class XmlReader : public QObject
{
    Q_OBJECT
public:
    XmlReader();
    bool checkCode(const QString &c)const;
signals:
    void sendItems(QStringList);
public slots:
    void parseXml(const QByteArray &xmlData);
};

#endif // XMLREADER_H
