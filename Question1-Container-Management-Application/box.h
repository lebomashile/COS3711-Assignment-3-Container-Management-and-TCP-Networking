#ifndef BOX_H
#define BOX_H

#include "container.h"
#include <QObject>

class Box : public Container
{
    Q_OBJECT
public:
    Box();
    Box(const QString &code, int weight,int height,int newSn,int length,int breadth);
    int Length() const;
    void setLength(int length);
    int Breadth() const;
    void setBreadth(int breadth);
    int calculateVolume();
    QString toString()const;


private:
    int m_Length;
    int m_Breadth;
};

#endif // BOX_H
