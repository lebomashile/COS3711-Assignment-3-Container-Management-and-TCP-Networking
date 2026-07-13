#ifndef PALLET_H
#define PALLET_H

#include <QList>
#include "container.h"
#include <QMap>

class Pallet
{
public:
    Pallet();
    bool addContainer(Container *c, int num);
    QList<Container*> getPallets()const;
    Container *getPalletAt(int i);
    int getTotalWeight()const;
    int getTotalHeight()const;
    int totalVolume()const;
    int getPalletNumber(QString code) const;
private:
    QList<Container*> containerList;
    QMap<QString,int> palletNumber;


};

#endif // PALLET_H
