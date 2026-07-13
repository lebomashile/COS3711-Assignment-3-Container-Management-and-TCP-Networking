#include <QApplication>
#include "mainclient.h"
#include "widget.h"
#include "box.h"
#include "cylinder.h"
#include "containerfactory.h"
#include "unallocatedlist.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainClient mc;
    mc.show();


    return a.exec();
}
