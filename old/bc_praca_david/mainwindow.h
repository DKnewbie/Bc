#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_actionOpen_triggered();

    void on_vystup_pre_dialog_itemDoubleClicked(QListWidgetItem *item);

    void on_button_zmen_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
