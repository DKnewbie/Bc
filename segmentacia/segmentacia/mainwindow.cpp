#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QFileDialog"
#include "QDebug"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

void normalizacia(cv::Mat img)
{
    cv::mean(img, img>1);
    //cv::imshow("mean", img);
}

void Normalize(cv::Mat & image)
{
    cv::Scalar mean, dev;
    cv::meanStdDev(image, mean, dev);
    double M = mean.val[0];
    double D = dev.val[0];
    qInfo() << "M" << M << " , V " << D;

    for(int i(0) ; i<image.rows ; i++)
    {
        for(int j(0) ; j<image.cols ; j++)
        {
            if(image.at<uchar>(i,j) > M)
                image.at<uchar>(i,j) = 100.0/255 + sqrt( 100.0/255*pow(image.at<uchar>(i,j)-M,2)/D );
            else
                image.at<uchar>(i,j) = 100.0/255 - sqrt( 100.0/255*pow(image.at<uchar>(i,j)-M,2)/D );
        }
    }
}

double stredna_hodnota(cv::Mat img, int x, int y, int W)
{
    int pom = 0;

    for (int x_w = x; x_w < x+W; x_w++) {
        for (int y_w = y; y_w < y+W; y_w++) {

            pom += img.at<uchar>(x_w,y_w);

        }
    }

    return pom/pow(W,2);
}

void variacia(cv::Mat img, int x, int y, int W, int T, cv::Mat matica_variacii)
{
    cv::imshow("img from variancia",img);
    int pom = 0;
    double M = stredna_hodnota(img,x,y,W), V;

    for (int x_w = x; x_w < x+W; x_w++) {
        for (int y_w = y; y_w < y+W; y_w++) {

            pom += pow(img.at<uchar>(x_w,y_w) - M, 2);

        }
    }

    V = pom/pow(W,2);

    for (int x_w = x; x_w < x+W; x_w++) {
        for (int y_w = y; y_w < y+W; y_w++) {

            matica_variacii.at<uchar>(x_w,y_w) = V;

        }
    }

    //return pom/pow(W,2);
}

void block(cv::Mat img, int x, int y, int W)
{
    for (int x_w = x; x_w < x+W; x_w++) {
        for (int y_w = y; y_w < y+W; y_w++) {
            img.at<uchar>(x_w,y_w)=0;
//            cv::imshow("hm", img);
//            cv::waitKey(20);
        }
    }

    cv::imshow("bloky", img);
}

void segmentacia(cv::Mat img, int W, int T)
{
    cv::Mat matica_variacii = cv::Mat(img.rows, img.cols, CV_8UC1);

    //cv::threshold(img, img, 0, 255, CV_THRESH_BINARY_INV | CV_THRESH_OTSU);
    //normalizacia(img);
    //cv::norm(img,img);
    Normalize(img);
    cv::imshow("odtlacok2", img);

    for (int x=0; x < img.rows-W; x+=W) {
        for (int y=0; y < img.cols-W; y+=W) {

            //block(img,x,y,W);

            variacia(img,x,y,W,0,matica_variacii);

        }
    }

    cv::imshow("variacia", matica_variacii);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open file", "/home/dk/bc/Odtlacky/");

    qInfo() << file_name;

    cv::Mat bu = cv::imread(file_name.toStdString(), CV_8UC1); // "/home/dk/bc/Odtlacky/FVC-2000/DB2_B/101_1.tif"

    cv::imshow("odtlacok", bu);

    int blockSize = 7;

    segmentacia(bu, blockSize, 0);
    //block(bu,bu.cols-14,bu.rows-14,14);

    Normalize(bu);
    //int height = mat.rows;
    //int width = mat.cols;
    //cv::Mat orientationMap;
    //orientation(bu, orientationMap, blockSize);
    //cv::imshow("konc",bu);
}
