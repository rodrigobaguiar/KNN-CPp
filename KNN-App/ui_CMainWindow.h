/********************************************************************************
** Form generated from reading UI file 'CMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMAINWINDOW_H
#define UI_CMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "src_QCustomPlot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_CMainWindow
{
public:
    QAction *actionOpen;
    QAction *actionClose;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QComboBox *CBModel;
    QGroupBox *GBKNNSetup;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *LENumberOfTests;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *LENumberOfNeighbors;
    QGroupBox *GBProcessingType;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *RBSerial;
    QRadioButton *RBParallel;
    QRadioButton *RBCuda;
    QRadioButton *RBAllTypes;
    QGroupBox *GroupBoxResults;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_7;
    QLabel *LBHardwareThreads;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_11;
    QLabel *LBUsedThreads;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QLabel *LBTreinedCases;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QLabel *LBTestCases;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QLabel *LBMatchs;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QLabel *LBAccuracy;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_5;
    QLabel *LBProcessingTime;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_10;
    QLabel *LBDifference;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *PBClear;
    QSpacerItem *horizontalSpacer;
    QPushButton *PBRun;
    QVBoxLayout *verticalLayout;
    QCustomPlot *DataSetDataPlot;
    QCustomPlot *PlotProcessingTime;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CMainWindow)
    {
        if (CMainWindow->objectName().isEmpty())
            CMainWindow->setObjectName(QString::fromUtf8("CMainWindow"));
        CMainWindow->resize(1083, 662);
        actionOpen = new QAction(CMainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionClose = new QAction(CMainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        centralwidget = new QWidget(CMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMaximumSize(QSize(250, 16777215));
        scrollArea->setFrameShape(QFrame::Box);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 246, 595));
        verticalLayout_5 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        CBModel = new QComboBox(scrollAreaWidgetContents);
        CBModel->addItem(QString());
        CBModel->addItem(QString());
        CBModel->addItem(QString());
        CBModel->setObjectName(QString::fromUtf8("CBModel"));

        horizontalLayout_3->addWidget(CBModel);


        verticalLayout_5->addLayout(horizontalLayout_3);

        GBKNNSetup = new QGroupBox(scrollAreaWidgetContents);
        GBKNNSetup->setObjectName(QString::fromUtf8("GBKNNSetup"));
        verticalLayout_2 = new QVBoxLayout(GBKNNSetup);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(GBKNNSetup);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        LENumberOfTests = new QLineEdit(GBKNNSetup);
        LENumberOfTests->setObjectName(QString::fromUtf8("LENumberOfTests"));

        horizontalLayout_4->addWidget(LENumberOfTests);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(GBKNNSetup);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        LENumberOfNeighbors = new QLineEdit(GBKNNSetup);
        LENumberOfNeighbors->setObjectName(QString::fromUtf8("LENumberOfNeighbors"));

        horizontalLayout_5->addWidget(LENumberOfNeighbors);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout_5->addWidget(GBKNNSetup);

        GBProcessingType = new QGroupBox(scrollAreaWidgetContents);
        GBProcessingType->setObjectName(QString::fromUtf8("GBProcessingType"));
        verticalLayout_3 = new QVBoxLayout(GBProcessingType);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        RBSerial = new QRadioButton(GBProcessingType);
        RBSerial->setObjectName(QString::fromUtf8("RBSerial"));
        RBSerial->setChecked(true);

        verticalLayout_3->addWidget(RBSerial);

        RBParallel = new QRadioButton(GBProcessingType);
        RBParallel->setObjectName(QString::fromUtf8("RBParallel"));

        verticalLayout_3->addWidget(RBParallel);

        RBCuda = new QRadioButton(GBProcessingType);
        RBCuda->setObjectName(QString::fromUtf8("RBCuda"));

        verticalLayout_3->addWidget(RBCuda);

        RBAllTypes = new QRadioButton(GBProcessingType);
        RBAllTypes->setObjectName(QString::fromUtf8("RBAllTypes"));

        verticalLayout_3->addWidget(RBAllTypes);


        verticalLayout_5->addWidget(GBProcessingType);

        GroupBoxResults = new QGroupBox(scrollAreaWidgetContents);
        GroupBoxResults->setObjectName(QString::fromUtf8("GroupBoxResults"));
        verticalLayout_4 = new QVBoxLayout(GroupBoxResults);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_7 = new QLabel(GroupBoxResults);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_12->addWidget(label_7);

        LBHardwareThreads = new QLabel(GroupBoxResults);
        LBHardwareThreads->setObjectName(QString::fromUtf8("LBHardwareThreads"));

        horizontalLayout_12->addWidget(LBHardwareThreads);


        verticalLayout_4->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_11 = new QLabel(GroupBoxResults);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_13->addWidget(label_11);

        LBUsedThreads = new QLabel(GroupBoxResults);
        LBUsedThreads->setObjectName(QString::fromUtf8("LBUsedThreads"));

        horizontalLayout_13->addWidget(LBUsedThreads);


        verticalLayout_4->addLayout(horizontalLayout_13);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_4 = new QLabel(GroupBoxResults);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_7->addWidget(label_4);

        LBTreinedCases = new QLabel(GroupBoxResults);
        LBTreinedCases->setObjectName(QString::fromUtf8("LBTreinedCases"));

        horizontalLayout_7->addWidget(LBTreinedCases);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_6 = new QLabel(GroupBoxResults);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_8->addWidget(label_6);

        LBTestCases = new QLabel(GroupBoxResults);
        LBTestCases->setObjectName(QString::fromUtf8("LBTestCases"));

        horizontalLayout_8->addWidget(LBTestCases);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(GroupBoxResults);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_9->addWidget(label_8);

        LBMatchs = new QLabel(GroupBoxResults);
        LBMatchs->setObjectName(QString::fromUtf8("LBMatchs"));

        horizontalLayout_9->addWidget(LBMatchs);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_9 = new QLabel(GroupBoxResults);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_10->addWidget(label_9);

        LBAccuracy = new QLabel(GroupBoxResults);
        LBAccuracy->setObjectName(QString::fromUtf8("LBAccuracy"));

        horizontalLayout_10->addWidget(LBAccuracy);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_5 = new QLabel(GroupBoxResults);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_11->addWidget(label_5);

        LBProcessingTime = new QLabel(GroupBoxResults);
        LBProcessingTime->setObjectName(QString::fromUtf8("LBProcessingTime"));

        horizontalLayout_11->addWidget(LBProcessingTime);


        verticalLayout_4->addLayout(horizontalLayout_11);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_10 = new QLabel(GroupBoxResults);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_14->addWidget(label_10);

        LBDifference = new QLabel(GroupBoxResults);
        LBDifference->setObjectName(QString::fromUtf8("LBDifference"));

        horizontalLayout_14->addWidget(LBDifference);


        verticalLayout_4->addLayout(horizontalLayout_14);


        verticalLayout_5->addWidget(GroupBoxResults);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        PBClear = new QPushButton(scrollAreaWidgetContents);
        PBClear->setObjectName(QString::fromUtf8("PBClear"));

        horizontalLayout_6->addWidget(PBClear);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        PBRun = new QPushButton(scrollAreaWidgetContents);
        PBRun->setObjectName(QString::fromUtf8("PBRun"));

        horizontalLayout_6->addWidget(PBRun);


        verticalLayout_5->addLayout(horizontalLayout_6);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        DataSetDataPlot = new QCustomPlot(centralwidget);
        DataSetDataPlot->setObjectName(QString::fromUtf8("DataSetDataPlot"));

        verticalLayout->addWidget(DataSetDataPlot);

        PlotProcessingTime = new QCustomPlot(centralwidget);
        PlotProcessingTime->setObjectName(QString::fromUtf8("PlotProcessingTime"));

        verticalLayout->addWidget(PlotProcessingTime);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        CMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1083, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        CMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CMainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);

        retranslateUi(CMainWindow);

        QMetaObject::connectSlotsByName(CMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CMainWindow)
    {
        CMainWindow->setWindowTitle(QCoreApplication::translate("CMainWindow", "KNN-Cpp", nullptr));
        actionOpen->setText(QCoreApplication::translate("CMainWindow", "Open", nullptr));
        actionClose->setText(QCoreApplication::translate("CMainWindow", "Close", nullptr));
        label->setText(QCoreApplication::translate("CMainWindow", "Model:", nullptr));
        CBModel->setItemText(0, QCoreApplication::translate("CMainWindow", "Choose...", nullptr));
        CBModel->setItemText(1, QCoreApplication::translate("CMainWindow", "k-nearst neighbors", nullptr));
        CBModel->setItemText(2, QCoreApplication::translate("CMainWindow", "Perceptron", nullptr));

        GBKNNSetup->setTitle(QCoreApplication::translate("CMainWindow", "KNN Setup", nullptr));
        label_2->setText(QCoreApplication::translate("CMainWindow", "Number of Tests:", nullptr));
        LENumberOfTests->setText(QCoreApplication::translate("CMainWindow", "5", nullptr));
        label_3->setText(QCoreApplication::translate("CMainWindow", "Neighbors:", nullptr));
        LENumberOfNeighbors->setText(QCoreApplication::translate("CMainWindow", "3", nullptr));
        GBProcessingType->setTitle(QCoreApplication::translate("CMainWindow", "Processing Type", nullptr));
        RBSerial->setText(QCoreApplication::translate("CMainWindow", "Serial", nullptr));
        RBParallel->setText(QCoreApplication::translate("CMainWindow", "Parallel", nullptr));
        RBCuda->setText(QCoreApplication::translate("CMainWindow", "Cuda", nullptr));
        RBAllTypes->setText(QCoreApplication::translate("CMainWindow", "All types", nullptr));
        GroupBoxResults->setTitle(QCoreApplication::translate("CMainWindow", "Results:", nullptr));
        label_7->setText(QCoreApplication::translate("CMainWindow", "System threads:", nullptr));
        LBHardwareThreads->setText(QCoreApplication::translate("CMainWindow", "0", nullptr));
        label_11->setText(QCoreApplication::translate("CMainWindow", "Used threads:", nullptr));
        LBUsedThreads->setText(QCoreApplication::translate("CMainWindow", "0", nullptr));
        label_4->setText(QCoreApplication::translate("CMainWindow", "Trained Cases:", nullptr));
        LBTreinedCases->setText(QCoreApplication::translate("CMainWindow", "0", nullptr));
        label_6->setText(QCoreApplication::translate("CMainWindow", "Test Cases:", nullptr));
        LBTestCases->setText(QCoreApplication::translate("CMainWindow", "0", nullptr));
        label_8->setText(QCoreApplication::translate("CMainWindow", "Matchs:", nullptr));
        LBMatchs->setText(QCoreApplication::translate("CMainWindow", "0", nullptr));
        label_9->setText(QCoreApplication::translate("CMainWindow", "Accuracy (%):", nullptr));
        LBAccuracy->setText(QCoreApplication::translate("CMainWindow", "0", nullptr));
        label_5->setText(QCoreApplication::translate("CMainWindow", "Time (s):", nullptr));
        LBProcessingTime->setText(QCoreApplication::translate("CMainWindow", "0", nullptr));
        label_10->setText(QCoreApplication::translate("CMainWindow", "Difference time (%):", nullptr));
        LBDifference->setText(QCoreApplication::translate("CMainWindow", "0", nullptr));
        PBClear->setText(QCoreApplication::translate("CMainWindow", "Clear", nullptr));
        PBRun->setText(QCoreApplication::translate("CMainWindow", "Run", nullptr));
        menuFile->setTitle(QCoreApplication::translate("CMainWindow", "File", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("CMainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CMainWindow: public Ui_CMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMAINWINDOW_H
