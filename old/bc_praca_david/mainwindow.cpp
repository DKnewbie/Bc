#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv/cv.h"
#include <QFileDialog>
#include <QDir>
#include <QStringList>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QPixmap>
#include <QDebug>

cv::Mat img(1, 256, CV_8UC1);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    
    ui->setupUi(this);

//    // read an image
//    cv::Mat image(CV_8UC1); //cv::imread("C://JetBrains//Projects//uloha_5//image//bg.jpg", 1);
//    // create image window named "My Image"
//    cv::namedWindow("My Image");
//    // show the image on window
//    cv::imshow("My Image", image);

}

MainWindow::~MainWindow()
{
    delete ui;
}

int M(int x, int y, int W, cv::Mat img)
{
    int pom = 0;

    for (int i = x; i < W; i++ )
        for (int j = y; j < W; j++)
        {
            pom += img.at<uchar>(j,i);    // pom += hodnota sivej farbz pre pixel [i,j] obrayka img
        }

    pom = pom/pow(W, 2.0);

    return pom;
}

int V(int x, int y, int W, cv::Mat img)
{
    int m = M(x, y, W, img);
    int pom = 0;

    for (int i = x; i < W; i++ )
        for (int j = y; j < W; j++)
        {
            pom += pow(img.at<uchar>(j,i) - m, 2.0);    // pom += hodnota sivej farbz pre pixel [i,j] obrayka img
        }

    pom = pom/pow(W, 2.0);

    return pom;
}

 cv::Mat normalizacia (int M0, int V0, int x, int y, int W, cv::Mat img, cv::Mat vys)
{
    int m = M(x, y, W, img);
    int v = V(x, y, W, img);
    int N;

    for (int i = x; i < img.cols; i++)
        for (int j = y; j < img.rows; j++)
        {
            if (img.at<uchar>(i,j) > m)
            {
                N = M0 + sqrt((V0 * pow((img.at<uchar>(i,j) - m), 2.0))/v);
            }
            else
            {
                N = M0 - sqrt((V0 * pow((img.at<uchar>(i,j) - m), 2.0))/v);
            }

            vys.at<uchar>(j,i) = N;
        }

    return vys;
}

void pozadie(int x, int y, int W, cv::Mat * p)
{
    for (int i = x; i < x+W; i++)
        for (int j = y; j < y+W; j++)
        {
            p->at<uchar>(i,j) = 0;
        }
}

cv::Mat segmentacia (int M0, int V0, int W, int T, cv::Mat img)
{
    int x = 0, y = 0, counter_y = 0, pom;
    cv::Mat vys = img;

    while (1)
    {
        int counter_x = 0;

        if ( (y + W) < img.cols )
        {
            while (1)
            {
                if ( (x + W) < img.rows )
                {
                    // ---------------------------------
                    vys += normalizacia(M0, V0, x-W, y-W, W, img, vys);
                    if (V(x-W, y-W, W, vys) < T)
                        pozadie(x-W, y-W, W, &vys);
                    // ---------------------------------
                }
                else
                {
                    pom = img.rows - (x - W);
                    x = img.rows - pom;

                    // ---------------------------------
                    vys += normalizacia(M0, V0, x, y, W, img, vys);
                    if (V(x, y, W, vys) < T)
                    {
                        pozadie(x, y, W, &vys);
                    }
                    // ---------------------------------

                    if (counter_x)
                        break;
                    counter_x++;
                }
            }
        }
        else
        {
            pom = img.cols - (y - W);
            y = img.cols - pom;

            while (1)
            {
                if ( (x + W) < img.rows )
                {
                    // ---------------------------------
                    vys += normalizacia(M0, V0, x-W, y, W, img, vys);
                    if (V(x-W, y, W, vys) < T)
                    {
                        pozadie(x-W, y, W, &vys);
                    }
                    // ---------------------------------
                }
                else
                {
                    pom = img.rows - (x - W);
                    x = img.rows - pom;

                    // ---------------------------------
                    vys += normalizacia(M0, V0, x, y, W, img, vys);
                    if (V(x, y, W, vys) < T)
                    {
                        pozadie(x, y, W, &vys);
                    }
                    // ---------------------------------

                    if (counter_x)
                        break;
                    counter_x++;
                }
            }

            if ( counter_y )
                break;
            counter_y++;
        }
    }

    for (int i = 0; i < img.rows; i++)
        for (int j = 0; j < img.cols; j++)
        {
            if(vys.at<uchar>(i,j) == 0)
                img.at<uchar>(i,j) = 0;
        }

    return img;
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionOpen_triggered()
{
    QString nazov_suboru = QFileDialog::getExistingDirectory(this, tr("Vyberte si adresár"), "C://");

    QDir adresar(nazov_suboru);

    ui->vystup_pre_dialog->clear();
    //int counter = 0;

    foreach (QFileInfo var, adresar.entryInfoList())
    {
        if(var.isFile()) //counter > 1
            ui->vystup_pre_dialog->addItem(var.absoluteFilePath());
        //counter++;
    }

    //QMessageBox::information(this, "title", adresar.absolutePath()); // cesta priecinka
}

void MainWindow::on_vystup_pre_dialog_itemDoubleClicked(QListWidgetItem *item)
{
//    QMessageBox::information(this, "dvoj-kliknute", item->text());
    img = cv::imread((item->text()).toStdString()); //"C:/Users/csgo/Desktop/Bakalarska praca/Odtlacky/FVC-2004/DB1_B/101_1.tif");
    //cv::imshow("My Image", img);
    //cv::cvtColor(img, img, CV_BGR2RGB); // CV_BGR2RGB
    cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
    //img.convertTo(img,CV_8UC1);
    qDebug() << img.depth() << " " << img.type();
    //QPixmap pic = QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_Grayscale8));
    //QPixmap picScaled(pic.scaled(ui->obrazok_1->width(), ui->obrazok_1->height(), Qt::IgnoreAspectRatio, Qt::FastTransformation));
    ui->obrazok_1->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.cols, QImage::Format_Grayscale8).scaled(ui->obrazok_1->width(), ui->obrazok_1->height(), Qt::KeepAspectRatio)));  qDebug() << img.step; //RGB888 , .scaledToWidth(ui->obrazok_1->width(), Qt::SmoothTransformation) - QImage, .scaled(ui->obrazok_1->width(), ui->obrazok_1->height(), Qt::KeepAspectRatio) - QPixmap
    ui->obrazok_2->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.cols, QImage::Format_Grayscale8).scaled(ui->obrazok_2->width(), ui->obrazok_2->height(), Qt::KeepAspectRatio))); //RGB888
    //ui->obrazok_1->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_Grayscale8)).scaledToWidth(ui->obrazok_1->width(), Qt::FastTransformation)); //qDebug() << ui->obrazok_1->width() << " " << ui->obrazok_1->height() << " : " << img.rows << " " << img.cols;
}

void MainWindow::on_button_zmen_clicked()
{
    cv::Mat seg = segmentacia(0, 1, ui->spin_W->value(), ui->spin_T->value(), img);
    ui->obrazok_2->setPixmap(QPixmap::fromImage(QImage(seg.data, seg.cols, seg.rows, seg.step, QImage::Format_RGB888).scaled(ui->obrazok_2->width(), ui->obrazok_2->height(), Qt::KeepAspectRatio)));
}
