#ifndef CONTAINERMEMENTO_H
#define CONTAINERMEMENTO_H

#include "container.h"
#include <QList>
class ContainerMemento
{
public:
    ContainerMemento();
    void saveState(const QList<Container*>& currentState);
    QList<Container*> restore() const;
private:
    QList<Container*> savedState;
};

#endif // CONTAINERMEMENTO_H
