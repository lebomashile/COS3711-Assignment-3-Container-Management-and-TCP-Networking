#include "unallocatedlist.h"
#include <QDebug>

UnallocatedList::UnallocatedList() {}

void UnallocatedList::addContainer(Container *c, int sn)
{

    if(searchBySN(sn))
    {
        qDebug() << "Item already added..Code:" << c->getCode();
        return;
    }

    codeAndSN[sn] = c->getCode();
    unallocatedList.append(c);
}

int UnallocatedList::getSize() const
{
    return unallocatedList.size();
}

QList<Container *> UnallocatedList::getUnallocatedList() const
{
    return unallocatedList;
}

Container *UnallocatedList::getContainer(QString code)
{
    if(searchByCode(code)){

        QMapIterator<int, QString> i(codeAndSN);

        int k = 0;

        while (i.hasNext()) {
            i.next();
            if(i.value() == code)
                return unallocatedList.at(k);

            k++;
        }
    }

    return nullptr;
}

void UnallocatedList::deleteItem(QString code)
{
    if(searchByCode(code)){

        QMapIterator<int, QString> i(codeAndSN);

        int k = 0;

        while (i.hasNext()) {
            i.next();
            if(i.value() == code){
            unallocatedList.removeAt(k);
                codeAndSN.remove(i.key());
                return;
            }


            k++;
        }
    }
}

bool UnallocatedList::searchByCode(QString code) const
{
    QMapIterator<int, QString> i(codeAndSN);

    while (i.hasNext()) {
        i.next();
        if(i.value() == code)
            return true;
    }
    return false;
}

bool UnallocatedList::searchBySN(int sn) const
{
    QMapIterator<int, QString> i(codeAndSN);

    while (i.hasNext()) {
        i.next();
        if(i.key() == sn)
            return true;
    }

    return false;
}

