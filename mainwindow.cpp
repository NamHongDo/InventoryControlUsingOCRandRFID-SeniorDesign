#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tesseract.h"
#include "opencv.h"
#include <string>
#include<QtCore/QFile>
#include<QtCore/QTextStream>
#include <QProcess>
#include <QPushButton>
#include<QMessageBox>


using namespace std;

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


void MainWindow::on_button1_clicked()
{
    shootit();
    doit();

    QFile file("/home/namdo/build-LabelScanner-Desktop_Qt_5_7_0_GCC_64bit-Debug/result.txt");
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"info",file.errorString());
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());

}
