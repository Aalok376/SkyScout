#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QUrl>
#include<QJsonDocument>
#include<QJsonObject>
#include<QMessageBox>
#include<QJsonArray>
#include<QPixmap>
QString location;
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
void MainWindow::onWeatherDataRecieved(QNetworkReply *reply)
{
    if(reply->error()==QNetworkReply::NoError)
    {
        QByteArray responseData = reply->readAll();
        QJsonDocument Jdoc = QJsonDocument::fromJson(responseData);
        if(!Jdoc.isNull())
        {
            QJsonObject JsonObj=Jdoc.object();
            { // code to set the current temperature
            QJsonObject mainObj=JsonObj.value("main").toObject();
            double temp=mainObj.value("temp").toDouble();
            ui->label_temp->setText(QString::number(temp-273.15)+"°C");
            }
            QJsonArray weatherarr = JsonObj.value("weather").toArray();
            if (!weatherarr.isEmpty())
            { // code to display the current weather status and set icons based on current weather
                QJsonObject weatherobj = weatherarr.at(0).toObject();
                QString weatherStatus = weatherobj.value("main").toString();
                ui->label_currentWeather->setText(weatherStatus);

                if(weatherStatus=="Clouds")
                {
                    int width=ui->label_weatherIcon->width();
                    int height= ui->label_weatherIcon->height();
                    QIcon icon(":/new/prefix1/image/cloudy.png");
                    ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(width , height)));
                    ui->label_alert->setText("It's a bit cloudy today. \n A good day for a walk in the park");
                }
                if(weatherStatus=="Thunderstorm")
                {
                    int width=ui->label_weatherIcon->width();
                    int height= ui->label_weatherIcon->height();
                    QIcon icon(":/new/prefix1/image/icons8-storm-94.png");
                    ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(width , height)));
                    ui->label_alert->setText("Thunderstorms expected \n Avoid outdoor activities if possible");
                }
                if(weatherStatus=="Drizzle")
                {
                    int width=ui->label_weatherIcon->width();
                    int height= ui->label_weatherIcon->height();
                    QIcon icon(":/new/prefix1/image/weather.png");
                    ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(width , height)));
                    ui->label_alert->setText("Light drizzle outside \n Don't forget your raincoat");
                }
                if(weatherStatus=="Mist" || weatherStatus=="Haze" || weatherStatus=="Fog")
                {
                    int width=ui->label_weatherIcon->width();
                    int height= ui->label_weatherIcon->height();
                    QIcon icon(":/new/prefix1/image/haze.png");
                    ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(width , height)));
                    ui->label_alert->setText("Visibility is low \n take precautions");
                }
                if(weatherStatus=="Rain")
                {
                    int width=ui->label_weatherIcon->width();
                    int height= ui->label_weatherIcon->height();
                    QIcon icon(":/new/prefix1/image/rainy-day.png");
                    ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(width , height)));
                    ui->label_alert->setText("Don't forget your umbrella ! ");
                }
                if(weatherStatus=="Clear")
                {
                    int width=ui->label_weatherIcon->width();
                    int height= ui->label_weatherIcon->height();
                    QIcon icon(":/new/prefix1/image/sun.png");
                    ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(width , height)));
                    ui->label_alert->setText("It's a clear day! \n Enjoy the beautiful weather");
                }
                if(weatherStatus=="Smoke")
                {
                    int width=ui->label_weatherIcon->width();
                    int height= ui->label_weatherIcon->height();
                    QIcon icon(":/new/prefix1/image/icons8-smoke-100.png");
                    ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(width , height)));
                    ui->label_alert->setText("Don't forget your mask !");
                }
                if(weatherStatus=="Snow")
                {
                    int width=ui->label_weatherIcon->width();
                    int height= ui->label_weatherIcon->height();
                    QIcon icon(":/new/prefix1/image/icons8-snow-94.png");
                    ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(width , height)));
                    ui->label_alert->setText("Snow is falling! \n Time for some winter fun.");
                }
                if(weatherStatus=="Dust" || weatherStatus=="Sand" || weatherStatus=="Ash")
                {
                    int width=ui->label_weatherIcon->width();
                    int height= ui->label_weatherIcon->height();
                    QIcon icon(":/new/prefix1/image/dust.png");
                    ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(width , height)));
                    ui->label_alert->setText("Consider wearing a mask \n if you're heading out");
                }
                if(weatherStatus=="Tornado")
                {
                    int width=ui->label_weatherIcon->width();
                    int height= ui->label_weatherIcon->height();
                    QIcon icon(":/new/prefix1/image/icons8-tornado-96.png");
                    ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(width , height)));
                    ui->label_alert->setText("Tornado alert! stay indoors");
                }
                if(weatherStatus=="Squall")
                {
                    int width=ui->label_weatherIcon->width();
                    int height= ui->label_weatherIcon->height();
                    QIcon icon(":/new/prefix1/image/icons8-air-96.png");
                    ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(width , height)));
                    ui->label_alert->setText("A squall is approaching \n Expect strong winds and rain");
                }

            }
            else
            {
                QMessageBox::information(this ,"SkyScout","error to display weather");
            }
            ui->label_recentSearch->setText("recently searched location : "+location);
        }
        else
        {
            QMessageBox::information(this ,"message","failed to parse data");
        }
    }
    else
    {
        QMessageBox::information(this ,"message","Error:"+reply->errorString());
    }
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
   location=ui->lineEdit_searchbar->text();
     ui->lineEdit_searchbar->clear();
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

