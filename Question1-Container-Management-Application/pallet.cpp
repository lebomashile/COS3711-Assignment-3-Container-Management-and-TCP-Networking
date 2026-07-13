#include "pallet.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>
Pallet::Pallet() {}

bool Pallet::addContainer(Container *c, int num)
{

    QMapIterator<QString, int> i(palletNumber);

    while (i.hasNext()) {
        i.next();

        if(i.key() == c->getCode())
            return true;
    }

    palletNumber[c->getCode()] = num;
    containerList.append(c);

    return false;

}

QList<Container *> Pallet::getPallets() const
{
    return containerList;
}

Container *Pallet::getPalletAt(int i)
{
    return containerList.at(i);
}

int Pallet::getTotalWeight() const
{
    int weight = 0;
    foreach (Container *c, containerList)
        weight += c->getWeight();

    return weight;
}

int Pallet::getTotalHeight() const
{
    int height = 0;
    foreach (Container *c, containerList)
        height += c->getHeight();

    return height;
}

int Pallet::totalVolume() const
{
    int volume = 0;
    foreach (Container *c, containerList)
        volume += c->calculateVolume();

    return volume;
}

int Pallet::getPalletNumber(QString code) const
{
    return palletNumber[code];
}
