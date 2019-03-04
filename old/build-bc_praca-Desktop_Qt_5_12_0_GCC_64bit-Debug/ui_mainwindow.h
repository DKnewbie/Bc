/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionOpen;
    QWidget *centralWidget;
    QListWidget *vystup_pre_dialog;
    QLabel *obrazok_2;
    QLabel *obrazok_1;
    QTabWidget *nastavenia;
    QWidget *segmentacia;
    QLabel *label;
    QSpinBox *spin_W;
    QSpinBox *spin_T;
    QLabel *label_2;
    QPushButton *button_zmen;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(950, 620);
        MainWindow->setMinimumSize(QSize(950, 620));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        vystup_pre_dialog = new QListWidget(centralWidget);
        vystup_pre_dialog->setObjectName(QString::fromUtf8("vystup_pre_dialog"));
        vystup_pre_dialog->setGeometry(QRect(9, 9, 300, 551));
        vystup_pre_dialog->setMinimumSize(QSize(300, 0));
        obrazok_2 = new QLabel(centralWidget);
        obrazok_2->setObjectName(QString::fromUtf8("obrazok_2"));
        obrazok_2->setGeometry(QRect(640, 10, 300, 291));
        obrazok_2->setMinimumSize(QSize(0, 0));
        obrazok_1 = new QLabel(centralWidget);
        obrazok_1->setObjectName(QString::fromUtf8("obrazok_1"));
        obrazok_1->setGeometry(QRect(316, 11, 300, 291));
        obrazok_1->setMinimumSize(QSize(0, 0));
        nastavenia = new QTabWidget(centralWidget);
        nastavenia->setObjectName(QString::fromUtf8("nastavenia"));
        nastavenia->setGeometry(QRect(320, 320, 621, 241));
        nastavenia->setMinimumSize(QSize(620, 240));
        nastavenia->setTabShape(QTabWidget::Rounded);
        nastavenia->setElideMode(Qt::ElideNone);
        segmentacia = new QWidget();
        segmentacia->setObjectName(QString::fromUtf8("segmentacia"));
        label = new QLabel(segmentacia);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 10, 91, 16));
        spin_W = new QSpinBox(segmentacia);
        spin_W->setObjectName(QString::fromUtf8("spin_W"));
        spin_W->setGeometry(QRect(50, 40, 81, 22));
        spin_W->setAlignment(Qt::AlignCenter);
        spin_W->setMinimum(10);
        spin_W->setMaximum(35);
        spin_W->setValue(14);
        spin_T = new QSpinBox(segmentacia);
        spin_T->setObjectName(QString::fromUtf8("spin_T"));
        spin_T->setGeometry(QRect(190, 40, 81, 22));
        spin_T->setAlignment(Qt::AlignCenter);
        spin_T->setMinimum(80);
        spin_T->setMaximum(255);
        spin_T->setValue(200);
        label_2 = new QLabel(segmentacia);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(190, 10, 91, 16));
        button_zmen = new QPushButton(segmentacia);
        button_zmen->setObjectName(QString::fromUtf8("button_zmen"));
        button_zmen->setGeometry(QRect(50, 100, 75, 23));
        nastavenia->addTab(segmentacia, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 950, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setEnabled(true);
        mainToolBar->setMovable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        nastavenia->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
        obrazok_2->setText(QString());
        obrazok_1->setText(QString());
        label->setText(QApplication::translate("MainWindow", "10 <= W <= 35", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "80 <= T <= 255", nullptr));
        button_zmen->setText(QApplication::translate("MainWindow", "Zmen", nullptr));
        nastavenia->setTabText(nastavenia->indexOf(segmentacia), QApplication::translate("MainWindow", "Segment\303\241cia", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
