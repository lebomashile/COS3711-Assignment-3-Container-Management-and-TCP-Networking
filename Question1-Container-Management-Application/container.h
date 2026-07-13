#ifndef CONTAINER_H
#define CONTAINER_H

#include <QString>
#include <QObject>

class Container : public QObject
{
    Q_OBJECT
public:
    Container();
    Container(const QString &code, int weight, int height,int newSn);
    virtual int calculateVolume() = 0;
    QString getCode() const;
    void setCode(const QString &code);
    int getWeight() const;
    void setWeight(int weight);
    int getHeight() const;
    void setHeight(int height);
    int getSn() const;
    void setSn(int newSn);
    virtual QString toString()const = 0;

private:
    QString m_Code;
    int m_Weight;
    int m_Height;
    int m_SerialNumber;

};

#endif // CONTAINER_H
