#include "gui.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

Gui::Gui(QWidget *parent)
    : QWidget(parent),
    model(new QStandardItemModel(this)),
    tableView(new QTableView(this))
{
    QGridLayout *mainLayout = new QGridLayout(this);
    QLabel *portLabel = new QLabel("Listening on port 6164");
    QPushButton *listenButton = new QPushButton("Start Listening");
    this->setMinimumSize(710,400);
    model->setHorizontalHeaderLabels({"Pallet","Container","Code", "Height", "Breadth/Diameter", "Length","Weight"});

    tableView->setModel(model);

    mainLayout->addWidget(listenButton,0,0);
    mainLayout->addWidget(portLabel,0,1);
    mainLayout->addWidget(tableView,1,0,1,2);


    connect(&server,SIGNAL(broadcast(QByteArray)),&xmlReader,SLOT(parseXml(QByteArray)));
    connect(&xmlReader,SIGNAL(sendItems(QStringList)),this,SLOT(updateTable(QStringList)));
    connect(listenButton,SIGNAL(clicked()),&server,SLOT(startServer()));

    setLayout(mainLayout);


}

Gui::~Gui()
{
}

void Gui::updateTable(const QStringList &items)
{

    QList<QStandardItem *> rowItems;
    rowItems << new QStandardItem(items.at(0))
             << new QStandardItem(items.at(1))
             << new QStandardItem(items.at(2))
             << new QStandardItem(items.at(3))
             << new QStandardItem(items.at(4))
    << new QStandardItem(items.at(5))
             << new QStandardItem(items.at(6));

    model->appendRow(rowItems);

}

