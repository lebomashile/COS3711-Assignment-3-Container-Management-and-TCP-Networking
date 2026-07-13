#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QSpinBox;
class QPushButton;
class QListWidget;
class QTextEdit;
#include "pallet.h"
#include "containerfactory.h"
#include "unallocatedlist.h"
#include "containermemento.h"
#include "client.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addItems();

private slots:
    void createBox();
    void createCylinder();
    void moveToPallet();
    void broadCastXml();
    void backupList();
public slots:
    void backUp();
    void restoreList();
private:
    Client tcpClient;
    UnallocatedList containerList;
    Pallet palletList;
    ContainerFactory cf;
    ContainerMemento memento;
    QSpinBox *box_breadth, *box_length, *box_height, *box_weight;
    QSpinBox *cylinder_diameter, *cylinder_height, *cylinder_weight;
    QPushButton *buttonAddBox, *buttonAddCylinder;
    QListWidget *displayUnallocated;
    QSpinBox *palletNumber;
    QPushButton *buttonMoveToPallet, *buttonBackupRestore;
    QPushButton *buttonPostXML;
    QTextEdit *displayPalletXML;
};

#endif // WIDGET_H
