#ifndef CONTAINERFACTORY_H
#define CONTAINERFACTORY_H

#include "container.h"
#include <QStringList>
class ContainerFactory
{
public:
    ContainerFactory();
    Container *createBox(int weight,int height,int length,int breadth);
    Container *createCylinder(int weight,int height,int diameter);
    int getSerialNumber() const;
private:
    static int serialNumber;
};

#endif // CONTAINERFACTORY_H
