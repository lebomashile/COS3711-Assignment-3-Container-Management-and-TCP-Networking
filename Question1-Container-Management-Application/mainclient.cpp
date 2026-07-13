#include "mainclient.h"

#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QLayout>
#include <QStatusBar>
#include <QMessageBox>
#include <QCloseEvent>
MainClient::MainClient(QWidget *parent)
    : QMainWindow(parent),
    containerWindow(new MainWindow)
{
    // Setup actions
    setupActions();

    // Setup menu
    setupMenus();

    // Setup tool bar
    setupToolbar();

    // Connect Signals and Slots
    // Connect Signals and Slots as required
    connect(actAbout, &QAction::triggered, this, &MainClient::showAbout);
    connect(actHelp, &QAction::triggered, this, &MainClient::showHelp);
    connect(actExit, &QAction::triggered, this, &QWidget::close);
    connect(addContainer, &QAction::triggered, containerWindow, &MainWindow::show);
    connect(backupAct, &QAction::triggered, containerWindow, &MainWindow::backUp);
    connect(restoreAct, &QAction::triggered, containerWindow, &MainWindow::restoreList);

    // Initialize window
    //setCentralWidget(???);
    setWindowTitle("Main window");
   //setMaximumSize();
    setWindowState(Qt::WindowMaximized);
    statusBar()->showMessage("Ready");
}

MainClient::~MainClient()
{
    // Tidy up pointers, if required
}

void MainClient::showAbout()
{
    // Display 'About' information here
}

void MainClient::showHelp()
{
    // Display 'Help' information here
}

void MainClient::setupActions()
{
    // Set up QActions as required
    // Create resource file for images in sub-directory 'images'.
    addContainer = new QAction(QIcon(":/images/box_icon.ico"), "Add Container");
    actAbout = new QAction(QIcon(":/images/info.png"), "About");
    actHelp = new QAction(QIcon(":/images/help.png"), "Help");
    actExit = new QAction(QIcon(":/images/exit.png"), "Exit");
    backupAct = new QAction(QIcon(":/images/backup.png"), "Back up list");
    restoreAct = new QAction(QIcon(":/images/restore.png"), "Restore list");
    postXmlAct = new QAction(QIcon(":/images/server_icon.ico"), "Post XML to network");

}

void MainClient::setupMenus()
{
    // Set up QMenus as required

    mnuFile = menuBar()->addMenu("File");
    mnuFile->addAction(addContainer);
    mnuFile->addSeparator();
    mnuFile->addAction(actExit);

    mnuBackup = menuBar()->addMenu("Backup");
    mnuBackup->addAction(restoreAct);
    mnuBackup->addAction(backupAct);
    // Add items to Save and Restore containers

    mnuPost = menuBar()->addMenu("Post XML");
    mnuPost->addAction(postXmlAct);
    // Add item to post XML to server

    mnuHelp = menuBar()->addMenu("Help");
    mnuHelp->addAction(actAbout);
    mnuHelp->addAction(actHelp);
}

void MainClient::setupToolbar()
{
    toolbar = addToolBar("Main toolbar");
    toolbar->layout()->setSpacing(20);

    // Add actions as required
    // toolbar->addAction(???);
    toolbar->addAction(addContainer);
    toolbar->addAction(actExit);
    toolbar->addSeparator();
    toolbar->addAction(backupAct);
    toolbar->addAction(restoreAct);
    toolbar->addSeparator();
    toolbar->addAction(postXmlAct);
    toolbar->addSeparator();
    toolbar->addAction(actAbout);
    toolbar->addAction(actHelp);
}

void MainClient::closeEvent(QCloseEvent *event)
{
    if(containerWindow->isVisible())
        containerWindow->close();
    // Confirm that user wants to close the application
}
