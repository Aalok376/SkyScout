#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Sky Scout");
    setWindowIcon(QIcon(":/new/prefix1/image/projectLogo.png"));
    ui->pushButton_search->setIcon(QIcon(":/new/prefix1/image/search--v1.png"));
    ui->lineEdit_searchbar->setPlaceholderText("enter the location");
    ui->pushButton_flag->setIcon(QIcon(":/new/prefix1/image/np.png"));
   int x= ui->pushButton_flag->width();
    int y =ui->pushButton_flag->height();
   ui->pushButton_flag->setIconSize(QSize(x,y));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_flag_clicked()
{
    if(check)
    {
        ui->pushButton_flag->setIcon(QIcon(":/new/prefix1/image/united-states-icon-96x72-b3zh47b5.png"));
        check=false;
    }
    else
    {
        ui->pushButton_flag->setIcon(QIcon(":/new/prefix1/image/np.png"));
        check=true;
    }

}


void MainWindow::on_lineEdit_searchbar_returnPressed()
{
    ui->lineEdit_searchbar->clear();
}


void MainWindow::on_pushButton_search_clicked()
{
    ui->lineEdit_searchbar->clear();
}

