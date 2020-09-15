/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionExit;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionFind;
    QAction *actionReplace;
    QAction *actionGroup;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionZoom_Factor;
    QAction *actionGrid;
    QAction *actionSnap;
    QAction *actionInput_Analyser;
    QAction *actionOutput_Analyser;
    QAction *actionScenario_Manager;
    QAction *actionOptimizaton;
    QAction *actionPreferences;
    QAction *actionCheck_Model;
    QAction *actionStart;
    QAction *actionStep;
    QAction *actionStop;
    QAction *actionRun_Control;
    QAction *actionComponents;
    QAction *actionElements;
    QAction *actionModels;
    QAction *actionConsole;
    QAction *actionProperties;
    QAction *actionEditor;
    QAction *actionDocumentation;
    QAction *actionSupport;
    QAction *actionAbout;
    QAction *actionTop;
    QAction *actionBottom;
    QAction *actionInformation;
    QAction *actionReport;
    QAction *actionComponents_2;
    QAction *actionElements_2;
    QAction *actionTrace;
    QAction *actionEvents;
    QAction *actionPause;
    QAction *actionReports;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuModel;
    QMenu *menuSimulation_2;
    QMenu *menuWindow;
    QMenu *menuHelp;
    QMenu *menuView;
    QMenu *menuArrange;
    QToolBar *toolBarModel;
    QStatusBar *statusBar;
    QToolBar *toolBarEdit;
    QToolBar *toolBar;
    QToolBar *toolBarSimulator;
    QToolBar *toolBarHelp;
    QDockWidget *dockWidgetPlugins;
    QWidget *dockWidgetContentsPlugins;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidgetPlugins;
    QDockWidget *dockWidgetProperties;
    QWidget *dockWidgetContentsProperties;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidgetProperties;
    QDockWidget *dockWidgetConsole;
    QWidget *dockWidgetContentsConsole;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *textEdit_Console;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1050, 637);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/resources/icons/pack2/png/24x24/60.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rec/resources/icons/pack2/png/24x24/52.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionClose->setEnabled(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Close.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon2);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon3);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionSave_as->setEnabled(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/rec/resources/icons/pack2/png/24x24/86.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_as->setIcon(icon4);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Door.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon5);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon6);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon7);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon8);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon9);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon10);
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind->setIcon(icon11);
        actionReplace = new QAction(MainWindow);
        actionReplace->setObjectName(QString::fromUtf8("actionReplace"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/View.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReplace->setIcon(icon12);
        actionGroup = new QAction(MainWindow);
        actionGroup->setObjectName(QString::fromUtf8("actionGroup"));
        actionZoom_In = new QAction(MainWindow);
        actionZoom_In->setObjectName(QString::fromUtf8("actionZoom_In"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Zoom.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_In->setIcon(icon13);
        actionZoom_Out = new QAction(MainWindow);
        actionZoom_Out->setObjectName(QString::fromUtf8("actionZoom_Out"));
        actionZoom_Out->setIcon(icon13);
        actionZoom_Factor = new QAction(MainWindow);
        actionZoom_Factor->setObjectName(QString::fromUtf8("actionZoom_Factor"));
        actionZoom_Factor->setIcon(icon13);
        actionGrid = new QAction(MainWindow);
        actionGrid->setObjectName(QString::fromUtf8("actionGrid"));
        actionSnap = new QAction(MainWindow);
        actionSnap->setObjectName(QString::fromUtf8("actionSnap"));
        actionInput_Analyser = new QAction(MainWindow);
        actionInput_Analyser->setObjectName(QString::fromUtf8("actionInput_Analyser"));
        actionOutput_Analyser = new QAction(MainWindow);
        actionOutput_Analyser->setObjectName(QString::fromUtf8("actionOutput_Analyser"));
        actionScenario_Manager = new QAction(MainWindow);
        actionScenario_Manager->setObjectName(QString::fromUtf8("actionScenario_Manager"));
        actionOptimizaton = new QAction(MainWindow);
        actionOptimizaton->setObjectName(QString::fromUtf8("actionOptimizaton"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        actionCheck_Model = new QAction(MainWindow);
        actionCheck_Model->setObjectName(QString::fromUtf8("actionCheck_Model"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/rec/resources/icons/pack2/png/24x24/58.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCheck_Model->setIcon(icon14);
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Play.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart->setIcon(icon15);
        actionStep = new QAction(MainWindow);
        actionStep->setObjectName(QString::fromUtf8("actionStep"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Next track.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStep->setIcon(icon16);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon17);
        actionRun_Control = new QAction(MainWindow);
        actionRun_Control->setObjectName(QString::fromUtf8("actionRun_Control"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Tune.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun_Control->setIcon(icon18);
        actionComponents = new QAction(MainWindow);
        actionComponents->setObjectName(QString::fromUtf8("actionComponents"));
        actionElements = new QAction(MainWindow);
        actionElements->setObjectName(QString::fromUtf8("actionElements"));
        actionModels = new QAction(MainWindow);
        actionModels->setObjectName(QString::fromUtf8("actionModels"));
        actionConsole = new QAction(MainWindow);
        actionConsole->setObjectName(QString::fromUtf8("actionConsole"));
        actionProperties = new QAction(MainWindow);
        actionProperties->setObjectName(QString::fromUtf8("actionProperties"));
        actionEditor = new QAction(MainWindow);
        actionEditor->setObjectName(QString::fromUtf8("actionEditor"));
        actionDocumentation = new QAction(MainWindow);
        actionDocumentation->setObjectName(QString::fromUtf8("actionDocumentation"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Help book.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDocumentation->setIcon(icon19);
        actionSupport = new QAction(MainWindow);
        actionSupport->setObjectName(QString::fromUtf8("actionSupport"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSupport->setIcon(icon20);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Help book 3d.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon21);
        actionTop = new QAction(MainWindow);
        actionTop->setObjectName(QString::fromUtf8("actionTop"));
        actionBottom = new QAction(MainWindow);
        actionBottom->setObjectName(QString::fromUtf8("actionBottom"));
        actionInformation = new QAction(MainWindow);
        actionInformation->setObjectName(QString::fromUtf8("actionInformation"));
        actionInformation->setEnabled(true);
        actionReport = new QAction(MainWindow);
        actionReport->setObjectName(QString::fromUtf8("actionReport"));
        actionComponents_2 = new QAction(MainWindow);
        actionComponents_2->setObjectName(QString::fromUtf8("actionComponents_2"));
        actionElements_2 = new QAction(MainWindow);
        actionElements_2->setObjectName(QString::fromUtf8("actionElements_2"));
        actionTrace = new QAction(MainWindow);
        actionTrace->setObjectName(QString::fromUtf8("actionTrace"));
        actionEvents = new QAction(MainWindow);
        actionEvents->setObjectName(QString::fromUtf8("actionEvents"));
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon22);
        actionReports = new QAction(MainWindow);
        actionReports->setObjectName(QString::fromUtf8("actionReports"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1050, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuModel = new QMenu(menuBar);
        menuModel->setObjectName(QString::fromUtf8("menuModel"));
        menuModel->setEnabled(true);
        menuSimulation_2 = new QMenu(menuModel);
        menuSimulation_2->setObjectName(QString::fromUtf8("menuSimulation_2"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuArrange = new QMenu(menuView);
        menuArrange->setObjectName(QString::fromUtf8("menuArrange"));
        MainWindow->setMenuBar(menuBar);
        toolBarModel = new QToolBar(MainWindow);
        toolBarModel->setObjectName(QString::fromUtf8("toolBarModel"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBarModel);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBarEdit = new QToolBar(MainWindow);
        toolBarEdit->setObjectName(QString::fromUtf8("toolBarEdit"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBarEdit);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBarSimulator = new QToolBar(MainWindow);
        toolBarSimulator->setObjectName(QString::fromUtf8("toolBarSimulator"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBarSimulator);
        toolBarHelp = new QToolBar(MainWindow);
        toolBarHelp->setObjectName(QString::fromUtf8("toolBarHelp"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBarHelp);
        dockWidgetPlugins = new QDockWidget(MainWindow);
        dockWidgetPlugins->setObjectName(QString::fromUtf8("dockWidgetPlugins"));
        dockWidgetPlugins->setMaximumSize(QSize(200, 524287));
        dockWidgetPlugins->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContentsPlugins = new QWidget();
        dockWidgetContentsPlugins->setObjectName(QString::fromUtf8("dockWidgetContentsPlugins"));
        verticalLayout = new QVBoxLayout(dockWidgetContentsPlugins);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        treeWidgetPlugins = new QTreeWidget(dockWidgetContentsPlugins);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(1, QString::fromUtf8("2"));
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidgetPlugins->setHeaderItem(__qtreewidgetitem);
        treeWidgetPlugins->setObjectName(QString::fromUtf8("treeWidgetPlugins"));
        treeWidgetPlugins->setDragEnabled(true);
        treeWidgetPlugins->setDragDropMode(QAbstractItemView::DragOnly);
        treeWidgetPlugins->setAlternatingRowColors(true);
        treeWidgetPlugins->setIndentation(4);
        treeWidgetPlugins->setSortingEnabled(true);
        treeWidgetPlugins->setHeaderHidden(true);
        treeWidgetPlugins->setColumnCount(2);
        treeWidgetPlugins->header()->setVisible(false);
        treeWidgetPlugins->header()->setCascadingSectionResizes(true);
        treeWidgetPlugins->header()->setMinimumSectionSize(30);
        treeWidgetPlugins->header()->setDefaultSectionSize(30);
        treeWidgetPlugins->header()->setHighlightSections(true);
        treeWidgetPlugins->header()->setProperty("showSortIndicator", QVariant(true));

        verticalLayout->addWidget(treeWidgetPlugins);

        dockWidgetPlugins->setWidget(dockWidgetContentsPlugins);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetPlugins);
        dockWidgetProperties = new QDockWidget(MainWindow);
        dockWidgetProperties->setObjectName(QString::fromUtf8("dockWidgetProperties"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dockWidgetProperties->sizePolicy().hasHeightForWidth());
        dockWidgetProperties->setSizePolicy(sizePolicy1);
        dockWidgetProperties->setMinimumSize(QSize(100, 107));
        dockWidgetProperties->setMaximumSize(QSize(200, 524287));
        dockWidgetProperties->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContentsProperties = new QWidget();
        dockWidgetContentsProperties->setObjectName(QString::fromUtf8("dockWidgetContentsProperties"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContentsProperties);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableWidgetProperties = new QTableWidget(dockWidgetContentsProperties);
        tableWidgetProperties->setObjectName(QString::fromUtf8("tableWidgetProperties"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableWidgetProperties->sizePolicy().hasHeightForWidth());
        tableWidgetProperties->setSizePolicy(sizePolicy2);
        tableWidgetProperties->setMinimumSize(QSize(0, 0));
        tableWidgetProperties->setBaseSize(QSize(0, 0));

        verticalLayout_3->addWidget(tableWidgetProperties);

        dockWidgetProperties->setWidget(dockWidgetContentsProperties);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetProperties);
        dockWidgetConsole = new QDockWidget(MainWindow);
        dockWidgetConsole->setObjectName(QString::fromUtf8("dockWidgetConsole"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(200);
        sizePolicy3.setHeightForWidth(dockWidgetConsole->sizePolicy().hasHeightForWidth());
        dockWidgetConsole->setSizePolicy(sizePolicy3);
        dockWidgetConsole->setMaximumSize(QSize(524287, 100));
        dockWidgetConsole->setFloating(false);
        dockWidgetConsole->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetVerticalTitleBar);
        dockWidgetConsole->setAllowedAreas(Qt::AllDockWidgetAreas);
        dockWidgetContentsConsole = new QWidget();
        dockWidgetContentsConsole->setObjectName(QString::fromUtf8("dockWidgetContentsConsole"));
        verticalLayout_4 = new QVBoxLayout(dockWidgetContentsConsole);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        textEdit_Console = new QTextEdit(dockWidgetContentsConsole);
        textEdit_Console->setObjectName(QString::fromUtf8("textEdit_Console"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(1);
        sizePolicy4.setHeightForWidth(textEdit_Console->sizePolicy().hasHeightForWidth());
        textEdit_Console->setSizePolicy(sizePolicy4);
        textEdit_Console->setMaximumSize(QSize(16777215, 16777215));
        textEdit_Console->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textEdit_Console->setLineWrapMode(QTextEdit::NoWrap);
        textEdit_Console->setReadOnly(true);
        textEdit_Console->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_4->addWidget(textEdit_Console);

        dockWidgetConsole->setWidget(dockWidgetContentsConsole);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetConsole);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuModel->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionClose);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addSeparator();
        menuEdit->addAction(actionFind);
        menuEdit->addAction(actionReplace);
        menuTools->addAction(actionInput_Analyser);
        menuTools->addAction(actionOutput_Analyser);
        menuTools->addAction(actionScenario_Manager);
        menuTools->addAction(actionOptimizaton);
        menuTools->addSeparator();
        menuTools->addAction(actionPreferences);
        menuModel->addAction(actionInformation);
        menuModel->addSeparator();
        menuModel->addAction(actionCheck_Model);
        menuModel->addAction(menuSimulation_2->menuAction());
        menuModel->addSeparator();
        menuModel->addAction(actionReport);
        menuSimulation_2->addAction(actionStart);
        menuSimulation_2->addAction(actionPause);
        menuSimulation_2->addAction(actionStep);
        menuSimulation_2->addAction(actionStop);
        menuSimulation_2->addSeparator();
        menuSimulation_2->addAction(actionRun_Control);
        menuWindow->addAction(actionComponents);
        menuWindow->addAction(actionConsole);
        menuWindow->addAction(actionProperties);
        menuWindow->addAction(actionReports);
        menuWindow->addSeparator();
        menuHelp->addAction(actionDocumentation);
        menuHelp->addAction(actionSupport);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);
        menuView->addAction(actionZoom_In);
        menuView->addAction(actionZoom_Out);
        menuView->addAction(actionZoom_Factor);
        menuView->addSeparator();
        menuView->addAction(actionGrid);
        menuView->addAction(actionSnap);
        menuView->addSeparator();
        menuView->addAction(menuArrange->menuAction());
        menuView->addAction(actionGroup);
        menuArrange->addAction(actionTop);
        menuArrange->addAction(actionBottom);
        toolBarModel->addAction(actionNew);
        toolBarModel->addAction(actionOpen);
        toolBarModel->addAction(actionClose);
        toolBarModel->addAction(actionSave);
        toolBarModel->addAction(actionSave_as);
        toolBarModel->addSeparator();
        toolBarModel->addAction(actionExit);
        toolBarEdit->addAction(actionUndo);
        toolBarEdit->addAction(actionRedo);
        toolBarEdit->addSeparator();
        toolBarEdit->addAction(actionCut);
        toolBarEdit->addAction(actionCopy);
        toolBarEdit->addAction(actionPaste);
        toolBarEdit->addSeparator();
        toolBarEdit->addAction(actionFind);
        toolBarEdit->addAction(actionReplace);
        toolBar->addAction(actionZoom_In);
        toolBar->addAction(actionZoom_Out);
        toolBar->addAction(actionZoom_Factor);
        toolBarSimulator->addAction(actionCheck_Model);
        toolBarSimulator->addAction(actionStart);
        toolBarSimulator->addAction(actionPause);
        toolBarSimulator->addAction(actionStep);
        toolBarSimulator->addAction(actionStop);
        toolBarSimulator->addAction(actionRun_Control);
        toolBarHelp->addAction(actionDocumentation);
        toolBarHelp->addAction(actionSupport);
        toolBarHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ReGenESyS -- Reborn Generic and Expansible System Simulator", nullptr));
        actionNew->setText(QApplication::translate("MainWindow", "New", nullptr));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "New simulation model", nullptr));
#endif // QT_NO_TOOLTIP
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionClose->setText(QApplication::translate("MainWindow", "Close", nullptr));
#ifndef QT_NO_SHORTCUT
        actionClose->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave_as->setText(QApplication::translate("MainWindow", "Save all", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave_as->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+F4", nullptr));
#endif // QT_NO_SHORTCUT
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", nullptr));
#ifndef QT_NO_SHORTCUT
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_NO_SHORTCUT
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Z", nullptr));
#endif // QT_NO_SHORTCUT
        actionCut->setText(QApplication::translate("MainWindow", "Cut", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_NO_SHORTCUT
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        actionFind->setText(QApplication::translate("MainWindow", "Find", nullptr));
#ifndef QT_NO_SHORTCUT
        actionFind->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        actionReplace->setText(QApplication::translate("MainWindow", "Replace", nullptr));
#ifndef QT_NO_SHORTCUT
        actionReplace->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", nullptr));
#endif // QT_NO_SHORTCUT
        actionGroup->setText(QApplication::translate("MainWindow", "Group", nullptr));
        actionZoom_In->setText(QApplication::translate("MainWindow", "Zoom In", nullptr));
#ifndef QT_NO_SHORTCUT
        actionZoom_In->setShortcut(QApplication::translate("MainWindow", "Ctrl+=", nullptr));
#endif // QT_NO_SHORTCUT
        actionZoom_Out->setText(QApplication::translate("MainWindow", "Zoom Out", nullptr));
#ifndef QT_NO_SHORTCUT
        actionZoom_Out->setShortcut(QApplication::translate("MainWindow", "Ctrl+-", nullptr));
#endif // QT_NO_SHORTCUT
        actionZoom_Factor->setText(QApplication::translate("MainWindow", "Zoom Factor", nullptr));
        actionGrid->setText(QApplication::translate("MainWindow", "Grid", nullptr));
        actionSnap->setText(QApplication::translate("MainWindow", "Snap", nullptr));
        actionInput_Analyser->setText(QApplication::translate("MainWindow", "Input Analyser", nullptr));
        actionOutput_Analyser->setText(QApplication::translate("MainWindow", "Output Analyser", nullptr));
        actionScenario_Manager->setText(QApplication::translate("MainWindow", "Scenario Manager", nullptr));
        actionOptimizaton->setText(QApplication::translate("MainWindow", "Optimizaton", nullptr));
        actionPreferences->setText(QApplication::translate("MainWindow", "Preferences", nullptr));
        actionCheck_Model->setText(QApplication::translate("MainWindow", "Check", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCheck_Model->setShortcut(QApplication::translate("MainWindow", "F4", nullptr));
#endif // QT_NO_SHORTCUT
        actionStart->setText(QApplication::translate("MainWindow", "Start", nullptr));
#ifndef QT_NO_SHORTCUT
        actionStart->setShortcut(QApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_NO_SHORTCUT
        actionStep->setText(QApplication::translate("MainWindow", "Step", nullptr));
#ifndef QT_NO_SHORTCUT
        actionStep->setShortcut(QApplication::translate("MainWindow", "F7", nullptr));
#endif // QT_NO_SHORTCUT
        actionStop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
#ifndef QT_NO_SHORTCUT
        actionStop->setShortcut(QApplication::translate("MainWindow", "F10", nullptr));
#endif // QT_NO_SHORTCUT
        actionRun_Control->setText(QApplication::translate("MainWindow", "Settings", nullptr));
        actionComponents->setText(QApplication::translate("MainWindow", "Plugins", nullptr));
        actionElements->setText(QApplication::translate("MainWindow", "Components", nullptr));
        actionModels->setText(QApplication::translate("MainWindow", "Models", nullptr));
        actionConsole->setText(QApplication::translate("MainWindow", "Console", nullptr));
        actionProperties->setText(QApplication::translate("MainWindow", "Properties", nullptr));
        actionEditor->setText(QApplication::translate("MainWindow", "Editor", nullptr));
        actionDocumentation->setText(QApplication::translate("MainWindow", "Documentation", nullptr));
#ifndef QT_NO_SHORTCUT
        actionDocumentation->setShortcut(QApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_NO_SHORTCUT
        actionSupport->setText(QApplication::translate("MainWindow", "Support", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSupport->setShortcut(QApplication::translate("MainWindow", "Ctrl+F1", nullptr));
#endif // QT_NO_SHORTCUT
        actionAbout->setText(QApplication::translate("MainWindow", "About...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionAbout->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+F1", nullptr));
#endif // QT_NO_SHORTCUT
        actionTop->setText(QApplication::translate("MainWindow", "Top", nullptr));
        actionBottom->setText(QApplication::translate("MainWindow", "Bottom", nullptr));
        actionInformation->setText(QApplication::translate("MainWindow", "Information", nullptr));
#ifndef QT_NO_SHORTCUT
        actionInformation->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_NO_SHORTCUT
        actionReport->setText(QApplication::translate("MainWindow", "Report", nullptr));
        actionComponents_2->setText(QApplication::translate("MainWindow", "Components", nullptr));
        actionElements_2->setText(QApplication::translate("MainWindow", "Elements", nullptr));
        actionTrace->setText(QApplication::translate("MainWindow", "Trace", nullptr));
        actionEvents->setText(QApplication::translate("MainWindow", "Events", nullptr));
        actionPause->setText(QApplication::translate("MainWindow", "Pause", nullptr));
        actionReports->setText(QApplication::translate("MainWindow", "Reports", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", nullptr));
        menuModel->setTitle(QApplication::translate("MainWindow", "Model", nullptr));
        menuSimulation_2->setTitle(QApplication::translate("MainWindow", "Simulation", nullptr));
        menuWindow->setTitle(QApplication::translate("MainWindow", "Window", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
        menuView->setTitle(QApplication::translate("MainWindow", "View", nullptr));
        menuArrange->setTitle(QApplication::translate("MainWindow", "Arrange", nullptr));
        toolBarEdit->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
        toolBarSimulator->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", nullptr));
        toolBarHelp->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", nullptr));
        dockWidgetPlugins->setWindowTitle(QApplication::translate("MainWindow", "Plugins", nullptr));
        dockWidgetProperties->setWindowTitle(QApplication::translate("MainWindow", "Properties", nullptr));
        dockWidgetConsole->setWindowTitle(QApplication::translate("MainWindow", "Console", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
