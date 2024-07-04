#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QUrl>
#include<QJsonDocument>
#include<QJsonObject>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),networkManager(new QNetworkAccessManager(this))
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
    connect(networkManager,&QNetworkAccessManager::finished ,this , &MainWindow::onWeatherDataRecieved);
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

void onWeatherDataRecieved (QNetworkReply *reply)
{
    if(reply->error()==QNetworkReply::NoError)
    {
        QByteArray responseData = reply->readAll();
        QJsonDocument Jdoc = QJsonDocument::fromJson(responseData);
        if(!Jdoc.isNull())
        {
            QJsonObject JsonObj=Jdoc.object();
            QJsonObject mainObj=JsonObj.value("main").toObject();
        }
    }
}
void MainWindow::on_lineEdit_searchbar_returnPressed()
{
    ui->lineEdit_searchbar->clear();
    QString location=ui->lineEdit_searchbar->text();
    QString apiKey="410680a363d4c095792d7e19b0bf49cb";
    QString urlstring=QString("https://api.openweathermap.org/data/2.5/weather?q=%1&appid=%2").arg(location, apiKey);
    QUrl url(urlstring);
    QNetworkRequest request(url);
    networkManager->get(request);
}


void MainWindow::on_pushButton_search_clicked()
{
    ui->lineEdit_searchbar->clear();
}

