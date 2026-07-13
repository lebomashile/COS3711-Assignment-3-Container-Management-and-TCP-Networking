#include "container.h"

Container::Container() {}

Container::Container(const QString &code, int weight, int height,int newSn)
    :m_Code(code),
    m_Weight(weight),
    m_Height(height),
    m_SerialNumber(newSn){

}

QString Container::getCode() const
{
    return m_Code;
}

void Container::setCode(const QString &code)
{
    m_Code = code;
}

int Container::getWeight() const
{
    return m_Weight;
}

void Container::setWeight(int weight)
{
    m_Weight = weight;
}

int Container::getHeight() const
{
    return m_Height;
}

void Container::setHeight(int height)
{
    m_Height = height;
}

int Container::getSn() const
{
    return m_SerialNumber;
}

void Container::setSn(int newSn)
{
    m_SerialNumber = newSn;
}
