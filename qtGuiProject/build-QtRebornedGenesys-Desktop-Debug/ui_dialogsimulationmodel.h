/********************************************************************************
** Form generated from reading UI file 'dialogsimulationmodel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSIMULATIONMODEL_H
#define UI_DIALOGSIMULATIONMODEL_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogSimulationModel
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tabGraphics;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsViewModel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSlider *horizontalSliderZoom;
    QLabel *labelZoom;
    QLabel *labelPercent;
    QSpacerItem *horizontalSpacer;
    QLabel *labelMousePosition;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QLabel *labelReplicationNumber;
    QLabel *labelSimulatedTime;
    QWidget *tabBlocks;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidgetText;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *labelNumberOfComponents;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_3;
    QLabel *labelNumberOfElements;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tabTrace;
    QVBoxLayout *verticalLayout_3;
    QGraphicsView *graphicsViewTrace;
    QWidget *tabReport;
    QVBoxLayout *verticalLayout_4;
    QTextBrowser *textReport;

    void setupUi(QDialog *DialogSimulationModel)
    {
        if (DialogSimulationModel->objectName().isEmpty())
            DialogSimulationModel->setObjectName(QString::fromUtf8("DialogSimulationModel"));
        DialogSimulationModel->resize(607, 441);
        DialogSimulationModel->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        horizontalLayout = new QHBoxLayout(DialogSimulationModel);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(DialogSimulationModel);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setDocumentMode(false);
        tabWidget->setMovable(true);
        tabWidget->setTabBarAutoHide(true);
        tabGraphics = new QWidget();
        tabGraphics->setObjectName(QString::fromUtf8("tabGraphics"));
        verticalLayout = new QVBoxLayout(tabGraphics);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsViewModel = new QGraphicsView(tabGraphics);
        graphicsViewModel->setObjectName(QString::fromUtf8("graphicsViewModel"));
        graphicsViewModel->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        graphicsViewModel->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        verticalLayout->addWidget(graphicsViewModel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(tabGraphics);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSliderZoom = new QSlider(tabGraphics);
        horizontalSliderZoom->setObjectName(QString::fromUtf8("horizontalSliderZoom"));
        horizontalSliderZoom->setMinimum(5);
        horizontalSliderZoom->setMaximum(400);
        horizontalSliderZoom->setSingleStep(5);
        horizontalSliderZoom->setValue(100);
        horizontalSliderZoom->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSliderZoom);

        labelZoom = new QLabel(tabGraphics);
        labelZoom->setObjectName(QString::fromUtf8("labelZoom"));

        horizontalLayout_2->addWidget(labelZoom);

        labelPercent = new QLabel(tabGraphics);
        labelPercent->setObjectName(QString::fromUtf8("labelPercent"));

        horizontalLayout_2->addWidget(labelPercent);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        labelMousePosition = new QLabel(tabGraphics);
        labelMousePosition->setObjectName(QString::fromUtf8("labelMousePosition"));

        horizontalLayout_2->addWidget(labelMousePosition);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_2 = new QLabel(tabGraphics);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        labelReplicationNumber = new QLabel(tabGraphics);
        labelReplicationNumber->setObjectName(QString::fromUtf8("labelReplicationNumber"));

        horizontalLayout_2->addWidget(labelReplicationNumber);

        labelSimulatedTime = new QLabel(tabGraphics);
        labelSimulatedTime->setObjectName(QString::fromUtf8("labelSimulatedTime"));

        horizontalLayout_2->addWidget(labelSimulatedTime);


        verticalLayout->addLayout(horizontalLayout_2);

        tabWidget->addTab(tabGraphics, QString());
        tabBlocks = new QWidget();
        tabBlocks->setObjectName(QString::fromUtf8("tabBlocks"));
        verticalLayout_2 = new QVBoxLayout(tabBlocks);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableWidgetText = new QTableWidget(tabBlocks);
        tableWidgetText->setObjectName(QString::fromUtf8("tableWidgetText"));

        verticalLayout_2->addWidget(tableWidgetText);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(tabBlocks);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        labelNumberOfComponents = new QLabel(tabBlocks);
        labelNumberOfComponents->setObjectName(QString::fromUtf8("labelNumberOfComponents"));

        horizontalLayout_3->addWidget(labelNumberOfComponents);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label_3 = new QLabel(tabBlocks);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        labelNumberOfElements = new QLabel(tabBlocks);
        labelNumberOfElements->setObjectName(QString::fromUtf8("labelNumberOfElements"));

        horizontalLayout_3->addWidget(labelNumberOfElements);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        tabWidget->addTab(tabBlocks, QString());
        tabTrace = new QWidget();
        tabTrace->setObjectName(QString::fromUtf8("tabTrace"));
        verticalLayout_3 = new QVBoxLayout(tabTrace);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        graphicsViewTrace = new QGraphicsView(tabTrace);
        graphicsViewTrace->setObjectName(QString::fromUtf8("graphicsViewTrace"));

        verticalLayout_3->addWidget(graphicsViewTrace);

        tabWidget->addTab(tabTrace, QString());
        tabReport = new QWidget();
        tabReport->setObjectName(QString::fromUtf8("tabReport"));
        verticalLayout_4 = new QVBoxLayout(tabReport);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        textReport = new QTextBrowser(tabReport);
        textReport->setObjectName(QString::fromUtf8("textReport"));

        verticalLayout_4->addWidget(textReport);

        tabWidget->addTab(tabReport, QString());

        horizontalLayout->addWidget(tabWidget);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(horizontalSliderZoom);
#endif // QT_NO_SHORTCUT

        retranslateUi(DialogSimulationModel);
        QObject::connect(horizontalSliderZoom, SIGNAL(valueChanged(int)), labelZoom, SLOT(setNum(int)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DialogSimulationModel);
    } // setupUi

    void retranslateUi(QDialog *DialogSimulationModel)
    {
        DialogSimulationModel->setWindowTitle(QApplication::translate("DialogSimulationModel", "Dialog", nullptr));
        label->setText(QApplication::translate("DialogSimulationModel", "Zoom:", nullptr));
        labelZoom->setText(QApplication::translate("DialogSimulationModel", "100", nullptr));
        labelPercent->setText(QApplication::translate("DialogSimulationModel", "%", nullptr));
        labelMousePosition->setText(QApplication::translate("DialogSimulationModel", "[0,0]", nullptr));
        label_2->setText(QApplication::translate("DialogSimulationModel", "Replication", nullptr));
        labelReplicationNumber->setText(QApplication::translate("DialogSimulationModel", "0/1", nullptr));
        labelSimulatedTime->setText(QApplication::translate("DialogSimulationModel", "(0 s)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabGraphics), QApplication::translate("DialogSimulationModel", "Graphics", nullptr));
        label_4->setText(QApplication::translate("DialogSimulationModel", "Components:", nullptr));
        labelNumberOfComponents->setText(QApplication::translate("DialogSimulationModel", "0", nullptr));
        label_3->setText(QApplication::translate("DialogSimulationModel", "Elements:", nullptr));
        labelNumberOfElements->setText(QApplication::translate("DialogSimulationModel", "0", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabBlocks), QApplication::translate("DialogSimulationModel", "Blocks", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTrace), QApplication::translate("DialogSimulationModel", "Trace", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabReport), QApplication::translate("DialogSimulationModel", "Results", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSimulationModel: public Ui_DialogSimulationModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSIMULATIONMODEL_H
