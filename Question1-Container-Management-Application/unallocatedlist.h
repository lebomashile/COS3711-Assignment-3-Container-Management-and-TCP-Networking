#ifndef UNALLOCATEDLIST_H
#define UNALLOCATEDLIST_H

#include "container.h"
#include <QList>
#include <QMap>
class UnallocatedList
{
public:
    UnallocatedList();
    void addContainer(Container *c, int sn);
    int getSize()const;
    QList<Container*> getUnallocatedList()const;
    Container *getContainer(QString code);
    void deleteItem(QString code);
    bool searchByCode(QString code)const;
    bool searchBySN(int sn)const;


private:
    QList<Container*> unallocatedList;
    QMap<int,QString> codeAndSN;
};

#endif // UNALLOCATEDLIST_H
