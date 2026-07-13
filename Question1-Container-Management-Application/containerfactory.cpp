#include "containerfactory.h"
#include <QDateEdit>
#include "box.h"
#include "cylinder.h"
#include <QDebug>

int ContainerFactory::serialNumber = 0;

ContainerFactory::ContainerFactory() {

}

Container *ContainerFactory::createBox( int weight, int height, int length, int breadth)
{

    QDate currentDate = QDate::currentDate();
    int year = currentDate.year();
    QString code;

    serialNumber++;

    if(serialNumber > 9999){
        serialNumber = 9999;
        qDebug() << "Maximum serial number reached";
        return nullptr;
    }

    if (year >= 2000 && year <= 2099) {
         code = QString("%1/%2/B%3")
        .arg(year)
            .arg(currentDate.month(), 2, 10, QChar('0'))
            .arg(QString::number(serialNumber));
return new Box(code,weight,height,serialNumber,length,breadth);

    }
    else {
        qDebug() << "Date out of range (2000–2099)";
        return nullptr;
    }

}

Container *ContainerFactory::createCylinder(int weight, int diameter, int height)
{
    QDate currentDate = QDate::currentDate();
    int year = currentDate.year();
    QString code;

    serialNumber++;

    if(serialNumber > 9999){
        serialNumber = 9999;
        qDebug() << "Maximum serial number reached..exiting";
        return nullptr;
    }
    if (year >= 2000 && year <= 2099) {
        code = QString("%1/%2/C%3")
        .arg(year)
            .arg(currentDate.month(), 2, 10, QChar('0'))
            .arg(QString::number(serialNumber));

        return new Cylinder(code,weight,height,diameter,serialNumber);

    }
    else {
        qDebug() << "Date is out of range (2000–2099)";
        return nullptr;
    }
}

int ContainerFactory::getSerialNumber() const
{
    return serialNumber;
}
