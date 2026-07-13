#include "box.h"

Box::Box()
:Container("unknown",0,0,0),
    m_Length(0),
    m_Breadth(0){

}

Box::Box(const QString &code, int weight, int height, int newSn, int length, int breadth)
    :Container(code,weight,height,newSn),
      m_Length(length),
      m_Breadth(breadth){

}

int Box::Length() const
{
    return m_Length;
}

void Box::setLength(int length)
{
    m_Length = length;
}

int Box::Breadth() const
{
    return m_Breadth;
}

void Box::setBreadth(int breadth)
{
    m_Breadth = breadth;
}

int Box::calculateVolume()
{
    return m_Length * m_Breadth * Container::getHeight();
}

QString Box::toString() const
{
    return QString("Box - Length:%1, Breadth:%2, Height:%3,Weight:%4,Code:%5,SN:%6")
               .arg(QString::number(m_Length),
             QString::number(m_Breadth),
             QString::number(Container::getHeight()),
             QString::number(Container::getWeight()),
             Container::getCode()),
           QString::number(Container::getSn());
}
