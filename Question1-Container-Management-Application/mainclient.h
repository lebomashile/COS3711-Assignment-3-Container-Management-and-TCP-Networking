#ifndef MAINCLIENT_H
#define MAINCLIENT_H

#include <QMainWindow>
class QAction;
class QMenu;
class QToolBar;
#include "widget.h"
class MainClient : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainClient(QWidget *parent = nullptr);
    ~MainClient();
    void closeEvent(QCloseEvent *event);

public slots:


private slots:
    void showAbout();
    void showHelp();

private:
    MainWindow *containerWindow;
    void setupActions();
    void setupMenus();
    void setupToolbar();

    // Add QAction items as required
    QAction *addContainer;
    QAction *actAbout;
    QAction *actHelp;
    QAction *actExit;
    QAction *backupAct;
    QAction *restoreAct;
    QAction *postXmlAct;

    // Add QMenu items as required
    QMenu *mnuFile;
    QMenu *mnuBackup;
    QMenu *mnuPost;
    QMenu *mnuHelp;

    QToolBar *toolbar;
};

#endif // MAINCLIENT_H
