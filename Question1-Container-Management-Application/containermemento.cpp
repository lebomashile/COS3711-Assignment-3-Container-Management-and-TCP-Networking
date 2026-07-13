#include "containermemento.h"

ContainerMemento::ContainerMemento
    ()
    {
    savedState.clear();
    }

void ContainerMemento::saveState(const QList<Container *> &currentState)
{
    savedState = currentState;
}

QList<Container *> ContainerMemento::restore() const
{
    return savedState;
}
