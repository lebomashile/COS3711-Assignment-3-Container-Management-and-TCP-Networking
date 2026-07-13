#ifndef CYLINDER_H
#define CYLINDER_H

#include "container.h"
#include <QObject>

class Cylinder : public Container
{
    Q_OBJECT
public:
    Cylinder();
    Cylinder(const QString &code, int weight,int height,int diameter,int newSn);
    int Diameter() const;
    void setDiameter(int diameter);
    int calculateVolume();
    QString toString()const;

private:
    int m_Diameter;
};

#endif // CYLINDER_H
