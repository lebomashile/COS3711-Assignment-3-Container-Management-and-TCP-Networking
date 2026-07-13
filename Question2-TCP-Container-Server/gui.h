#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QStandardItemModel>
#include <QTableView>
#include "server.h"
#include "xmlreader.h"

class Gui : public QWidget
{
    Q_OBJECT

public:
    Gui(QWidget *parent = nullptr);
    ~Gui();
private slots:
    void updateTable(const QStringList &items);
private:
    QStandardItemModel *model ;
    QTableView *tableView;
    Server server;
    XmlReader xmlReader;
};
#endif // GUI_H
