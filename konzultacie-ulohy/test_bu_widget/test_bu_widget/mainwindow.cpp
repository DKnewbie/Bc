#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "bu.h"
//#include "bu_global.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Bu bu;

    bu.test();

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
