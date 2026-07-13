#include "cylinder.h"

Cylinder::Cylinder()
:Container("unknown",0,0,0),
    m_Diameter(0){}

Cylinder::Cylinder(const QString &code, int weight, int height, int diameter, int newSn)
    :Container(code,weight,height,newSn),
    m_Diameter(diameter){

}

int Cylinder::Diameter() const
{
    return m_Diameter;
}

void Cylinder::setDiameter(int diameter)
{
    m_Diameter = diameter;
}

int Cylinder::calculateVolume(){

    return M_PI * m_Diameter * Container::getHeight() / 4;
}

QString Cylinder::toString() const
{
    return QString("Cylinder - Diameter:%1, Height:%2,Weight:%3,Code:%4,SN:%5")
    .arg(QString::number(m_Diameter),
         QString::number(Container::getHeight()),
         QString::number(Container::getWeight()),
         Container::getCode(), QString::number(Container::getSn()));
}
