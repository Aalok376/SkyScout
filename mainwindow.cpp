#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QThread>
#include<QGeoCoordinate>
#include<QQuickItem>
#include<QRegion>
QIcon icon ;
QString location;
int wt=80;
int ht=80;
int W=35;
int H=35;
FetchCurrentAddress *addressObj;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),networkManager(new QNetworkAccessManager(this)),NetworkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
    setWindowTitle("Sky Scout");
    setWindowIcon(QIcon(":/new/prefix1/image/projectLogo.png"));
    ui->pushButton_search->setIcon(QIcon(":/new/prefix1/image/search--v1.png"));
    ui->lineEdit_searchbar->setPlaceholderText("enter the location");

    ui->pushButton_flag->setIcon(QIcon(":/new/prefix1/image/Nepal.svg"));
    int x= ui->pushButton_flag->width();
    int y =ui->pushButton_flag->height();
    ui->pushButton_flag->setIconSize(QSize(y-4,y-4));
    //////////////////////////////////
    ui->light_btn->setIcon(QIcon(":/new/prefix1/image/dark.svg"));

    x= ui->light_btn->width();
    y =ui->light_btn->height();
    ui->light_btn->setIconSize(QSize(x,y));

    ui->seemore_btn->setIcon(QIcon(":/new/prefix1/image/more.svg"));
    //x= ui->seemore_btn->width();
    y =ui->seemore_btn->height();
    ui->seemore_btn->setIconSize(QSize(y,y));

    //sidebar
    QIcon wIcon = QIcon(":/new/prefix1/image/skyscout.png");
    ui->wIcon->setPixmap(wIcon.pixmap(QSize(27 , 25)));

    ui->map_btn->setIcon(QIcon(":/new/prefix1/image/mapIcon.svg"));
    y = ui->map_btn->height();
    ui->map_btn->setIconSize(QSize(y-4,y-4));

    /////// animation
    gifAnimation= new QMovie(":/new/prefix1/image/icons8-notification.gif");
    gifAnimation->setScaledSize(QSize(30,30));
    ui->label_gif->setMovie(gifAnimation);
    qDebug()<< ui->label_gif->height()<<"skfskdfskdfdskfkddskfksfdsjkkkkkkkk";
    qDebug()<< ui->label_gif->width()<<"skfskdfskdfdskfkddskfksfdsjkkkkkkkk";
    gifAnimation->start();



    addressObj = new FetchCurrentAddress(this);

    connect(addressObj, &FetchCurrentAddress::locationFetched, this, &MainWindow::onCurrentLocationFetched);
    connect(networkManager,&QNetworkAccessManager::finished ,this , &MainWindow::onWeatherDataRecieved);
    connect(NetworkManager, &QNetworkAccessManager::finished , this , &MainWindow::onLocationRecieved);
    //setting fixed size
    resize(920,600);
    setFixedSize(size());
    addressObj->fetchLocation();
    //setting up model for suggestion feature
    model=new QStringListModel(this);
    completer =new QCompleter(model , this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
        completer->setMaxVisibleItems(5);
    ui->lineEdit_searchbar->setCompleter(completer);

 // //   map integration
   ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/MapView.qml")));
    ui->quickWidget->show();
    int wid = 350,hei = 170;
      int radius = 12;
     //int wid=ui->widget_2->width();
      //int hei=ui->widget_2->height();
 //   qDebug()<<wid<<"skdfksdsjfksdfjsdkjfdskj";
 //     qDebug()<<hei;

    ui->quickWidget->setFixedSize(wid, hei);
 //  //  Create a QPainterPath for the rounded rectangle
     QPainterPath path;
    path.addRoundedRect(0, 0, wid, hei, radius, radius);

 // //    // Convert the QPainterPath to a QRegion and set it as the mask
     QRegion region(path.toFillPolygon().toPolygon());

     ui->quickWidget->setMask(region);
   //ui->horizontalLayout_28->addWidget(ui->quickWidget, 0, Qt::AlignCenter);



  auto rootObject = ui->quickWidget->rootObject();
 connect(this , SIGNAL(updateMap(QVariant,QVariant)) , rootObject , SLOT(updateMap(QVariant,QVariant)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onCurrentLocationFetched(QString l)
{
    location = l+", Nepal";
    // qDebug() << location;
     QString apiKey = "410680a363d4c095792d7e19b0bf49cb";
    // QString urlstring = QString("https://api.openweathermap.org/data/2.5/weather?q=%1&appid=%2").arg(location, apiKey);
    // QUrl url(urlstring);
    // QNetworkRequest request(url);
    // networkManager->get(request);

    QString urlStringCurrent = QString("https://api.openweathermap.org/data/2.5/weather?q=%1&appid=%2").arg(location, apiKey);
    QUrl urlCurrent(urlStringCurrent);
    QNetworkRequest requestCurrent(urlCurrent);
    networkManager->get(requestCurrent);

    // Second request for forecast weather
    QString urlStringForecast = QString("https://api.openweathermap.org/data/2.5/forecast?q=%1&appid=%2").arg(location, apiKey);
    QUrl urlForecast(urlStringForecast);
    QNetworkRequest requestForecast(urlForecast);
    networkManager->get(requestForecast);
}
void MainWindow::onWeatherDataRecieved(QNetworkReply *reply)
{
    QUrl url = reply->url();

    if(url.toString().contains("/forecast")) {

        if(reply->error()==QNetworkReply::NoError) {

            QByteArray responseData = reply->readAll();
            QJsonDocument Jdoc = QJsonDocument::fromJson(responseData);
            if(!Jdoc.isNull()) {
                QJsonObject JsonObj=Jdoc.object();
                QJsonArray List = JsonObj.value("list").toArray();
                //qDebug()<<"the size of the array is "<<weatherArr.size();
                int lim = 32;
                for(int i=0;i<lim;i++) {
                    QJsonObject ListObj = List.at(i).toObject();
                    int dt = ListObj.value("dt").toInt();
                   // qDebug()<<"display dt "<<dt;

                    int ft = dateTime::fetchDate(dt);
                    int ct = dateTime::currentDate();

                    if(ft!=ct) {

                        QJsonObject mainObj = ListObj.value("main").toObject();
                        double temp = mainObj.value("temp").toDouble();
                        double humidity = mainObj.value("humidity").toDouble();
                        QJsonArray weatherArr = ListObj.value("weather").toArray();
                        QJsonObject weatherSt = weatherArr.at(0).toObject();
                        QString status = weatherSt.value("main").toString();
                        QJsonObject cityObj = JsonObj.value("city").toObject();
                        QString city = cityObj.value("name").toString();
                        int sunrise = cityObj.value("sunrise").toInt();
                        int sunset = cityObj.value("sunset").toInt();
                        int ctime =dt;
                        int year = dateTime::fetchYear(dt);
                        int month = dateTime::fetchMonth(dt);
                        int date = dateTime::fetchDate(dt);
                        int hour = dateTime::fetchHour(dt);
                        int min = dateTime::fetchMin(dt);


                        futureWeather::databaseConnection(city,temp,humidity,status,sunrise,sunset,
                                                           ctime,year,month,date,hour,min);


                    } else {
                        lim++;
                    }
                }

            }else{
                QMessageBox::information(this ,"message","failed to parse data");
            }




        }else{
            QMessageBox::information(this ,"message","Error:"+reply->errorString());
        }



    }else if(url.toString().contains("/weather")){

        if(reply->error()==QNetworkReply::NoError)
        {
            QByteArray responseData = reply->readAll();
            QJsonDocument Jdoc = QJsonDocument::fromJson(responseData);
            if(!Jdoc.isNull())
            {
                QJsonObject JsonObj=Jdoc.object();
                    // code to set the current temperature
                QJsonObject mainObj=JsonObj.value("main").toObject();
                double temp=mainObj.value("temp").toDouble();
                temp = logicMaths::tempConversion(temp);

                double humidity=mainObj.value("humidity").toDouble();
                double feelsLike = mainObj.value("feels_like").toDouble();
                feelsLike = logicMaths::tempConversion(feelsLike);

                QJsonObject windObj = JsonObj.value("wind").toObject();
                double windSpeed = windObj.value("speed").toDouble();
                windSpeed = std::round(windSpeed*3.6);

                ui->label_temp->setText(QString::number(temp)+"°C");

                QJsonObject coordObj = JsonObj.value("coord").toObject();
                double lat = coordObj.value("lat").toDouble();
                double lon = coordObj.value("lon").toDouble();

                int ts = dateTime::getTimeZone(lat,lon);
               emit updateMap(lat , lon);

                QJsonObject sysObj = JsonObj.value("sys").toObject();
                int sunrise = sysObj.value("sunrise").toInt();
                int sunset = sysObj.value("sunset").toInt();
                int currentTime = JsonObj.value("dt").toInt();
                int year = dateTime::currentYear();
                int month = dateTime::currentMonth();
                int date = dateTime::currentDate();
                QString city = JsonObj.value("name").toString();


                QJsonArray weatherarr = JsonObj.value("weather").toArray();
                QJsonObject weatherobj = weatherarr.at(0).toObject();
                QString weatherStatus = weatherobj.value("main").toString();
                //QJsonObject weatherObj = JsonObj.value("weather").toObject();
                //QString status = weatherObj.value("main").toString();
                int hour = dateTime::currentHour();
                int min = dateTime::currentMin();
                // qDebug()<<city;
                weatherData::databaseConnection(city,temp,humidity,weatherStatus,lat,lon,sunrise,sunset,currentTime,year,month,date);
                todaysWeather::databaseConnection(city,temp,humidity,weatherStatus,lat,lon,sunrise,sunset,
                                                  currentTime,year,month,date,hour,min);
                // Debug output
                qDebug() << "Sunrise:" << sunrise;
                qDebug() << "Sunset:" << sunset;
                qDebug() << "Current Time:" << currentTime;
                if (!weatherarr.isEmpty())
                { // code to display the current weather status and set icons based on current weather
                    weatherobj = weatherarr.at(0).toObject();
                    weatherStatus = weatherobj.value("main").toString();
                    ui->label_currentWeather->setText(weatherStatus);
                    if(weatherStatus=="Clouds")
                    {
                        //int width=ui->label_weatherIcon->width();
                        //int height= ui->label_weatherIcon->height();
                        if (sunrise<=currentTime && currentTime<sunset)
                        {
                            icon= QIcon(":/new/prefix1/image/cloudy.png");
                            ui->label_alert->setText("It's a bit \n cloudy today");
                        }
                        else
                        {
                            icon= QIcon(":/new/prefix1/image/cloudy-night.png");
                            ui->label_alert->setText("Cloudy night \n ahead");
                        }
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(wt , ht)));//height , width
                    }
                    if(weatherStatus=="Thunderstorm")
                    {
                        //int width=ui->label_weatherIcon->width();
                        //int height= ui->label_weatherIcon->height();
                        icon=QIcon(":/new/prefix1/image/Thunderstorm.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(wt , ht)));
                        ui->label_alert->setText(" Avoid outdoor \n activities");
                    }
                    if(weatherStatus=="Drizzle")
                    {
                        //int width=ui->label_weatherIcon->width();
                        //int height= ui->label_weatherIcon->height();
                        if(sunrise<=currentTime && currentTime<sunset)
                        {
                            icon=QIcon(":/new/prefix1/image/weather.png");
                        }
                        else
                        {
                            icon=QIcon(":/new/prefix1/image/drizzle.png");
                        }
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(wt , ht)));
                        ui->label_alert->setText("Don't forget \n your raincoat");
                    }
                    if(weatherStatus=="Mist" || weatherStatus=="Haze" || weatherStatus=="Fog")
                    {
                        //int width=ui->label_weatherIcon->width();
                        //int height= ui->label_weatherIcon->height();
                        icon =QIcon(":/new/prefix1/image/haze.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(wt , ht)));
                        ui->label_alert->setText("Visibility is \n low");
                    }
                    if(weatherStatus=="Rain")
                    {
                        //int width=ui->label_weatherIcon->width();
                        //int height= ui->label_weatherIcon->height();
                        icon=QIcon(":/new/prefix1/image/Rain.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(wt , ht)));
                        ui->label_alert->setText("Don't forget \n your umbrella ! ");
                    }
                    if(weatherStatus=="Clear")
                    {
                        //int width=ui->label_weatherIcon->width();
                        //int height= ui->label_weatherIcon->height();
                        if (sunrise<=currentTime && currentTime<sunset)
                        {
                            icon=QIcon(":/new/prefix1/image/Clear.png");
                            ui->label_alert->setText("Enjoy the \n beautiful weather");
                        }
                        else
                        {
                            icon=QIcon(":/new/prefix1/image/full-moon.png");
                            ui->label_alert->setText("Clear skies \n tonight");
                        }
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(wt, ht)));
                    }
                    if(weatherStatus=="Smoke")
                    {
                        //int width=ui->label_weatherIcon->width();
                        //int height= ui->label_weatherIcon->height();
                        icon=QIcon(":/new/prefix1/image/Smoke.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(wt , ht)));
                        ui->label_alert->setText("Don't forget \n your mask !");
                    }
                    if(weatherStatus=="Snow")
                    {
                        //int width=ui->label_weatherIcon->width();
                        //int height= ui->label_weatherIcon->height();
                        icon=QIcon(":/new/prefix1/image/Snow.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(wt , ht)));
                        ui->label_alert->setText("Time for some \n winter fun.");
                    }
                    if(weatherStatus=="Dust" || weatherStatus=="Sand" || weatherStatus=="Ash")
                    {
                        //int width=ui->label_weatherIcon->width();
                        //int height= ui->label_weatherIcon->height();
                        icon=QIcon(":/new/prefix1/image/dust.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(wt ,ht)));
                        ui->label_alert->setText("Consider wearing \n a mask");
                    }
                    if(weatherStatus=="Tornado")
                    {
                        //int width=ui->label_weatherIcon->width();
                        //int height= ui->label_weatherIcon->height();
                        icon=QIcon(":/new/prefix1/image/Tornado.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(wt , ht)));
                        ui->label_alert->setText("Tornado alert! \n stay indoors");
                    }
                    if(weatherStatus=="Squall")
                    {
                        //int width=ui->label_weatherIcon->width();
                        //int height= ui->label_weatherIcon->height();
                        icon=QIcon(":/new/prefix1/image/Squall.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(wt , ht)));
                        ui->label_alert->setText("A squall is \n approaching");
                    }

                    //small icons
                    int iWidth = 27;
                    int iHeight = 25;
                    QPixmap smallIcon(":/new/prefix1/image/Humidity.png");
                    ui->humidity->setPixmap(smallIcon.scaled(iWidth,
                                             iHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                    smallIcon.load(":/new/prefix1/image/FeelsLike.png");
                    ui->feelslike->setPixmap(smallIcon.scaled(iWidth,
                                             iHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                    smallIcon.load(":/new/prefix1/image/WindSpeed.png");
                    ui->windspeed->setPixmap(smallIcon.scaled(iWidth,
                                             iHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation));

                    ui->humidity1->setText(QString::number(humidity)+"%");
                    ui->feelslike1->setText(QString::number(feelsLike)+"°C");
                    ui->windspeed1->setText(QString::number(windSpeed)+"km/h");

                    //bottom right
                    int chr = dateTime::fetchHour(ts);
                    QString current_hour = logicMaths::checkDigit(chr);

                    int cmin = dateTime::fetchMin(ts);
                    QString current_min = logicMaths::checkDigit(cmin);

                    ui->current_time->setText(current_hour+":"+current_min);
                    ui->currentlocation->setText(location);

                    QIcon cicon = logicMaths::getStatusIcon(weatherStatus,currentTime,sunrise,sunset);
                    //int cw = ui->currentsta->width();
                    //int che = ui->currentsta->height();
                    //qDebug()<<"hold on wait a minute"<<cw<<" and "<<che;
                    ui->currentsta->setPixmap(cicon.pixmap(QSize(65,40)));

                    ui->currentTemp_2->setText(QString::number(temp)+"°C");
                    ui->currentHum_2->setText(QString::number(humidity)+"%");
                    ui->currentfl_2->setText(QString::number(feelsLike)+"°C");
                    ui->currentlat_2->setText(QString::number(lat));
                    ui->currentlon_2->setText(QString::number(lon));
                    //qDebug()<<"the time begins here";
                    //qDebug()<<dateTime::fetchHour(ts);
                    //qDebug()<<dateTime::fetchMin(ts);


                }
                else
                {
                    QMessageBox::information(this ,"SkyScout","error to display weather");
                }
                ui->label_recentSearch->setText(location);


                //currentData

                int lowestId = todaysWeather::findLowestId();
                //qDebug()<<"the lowest Id is nothing but "<<lowestId;
                QString todaysLocation = todaysWeather::fetchCity(lowestId);
                ui->todaysLocation->setText(todaysLocation+", Nepal");

                QString weather1 = todaysWeather::fetchWeatherStatus(lowestId);
                //qDebug()<<"the weather status is "<<weather1;
                double temp1 = todaysWeather::fetchTemp(lowestId);
                int hour1 = todaysWeather::fetchHour(lowestId);
                int min1 = todaysWeather::fetchMin(lowestId);
                icon = todaysWeather::fetchIcon(lowestId);
                //qDebug()<<"temperature is "<<temp1;
                //qDebug()<<"hour is "<<hour1;

                if(weather1!=""){
                    ui->icon1->setPixmap(icon.pixmap(QSize(W, H)));
                    ui->weather1->setText(weather1);
                    ui->temp1->setText(QString::number(temp1)+"°C");

                    QString h1 = logicMaths::checkDigit(hour1);
                    QString m1 = logicMaths::checkDigit(min1);
                    ui->time1->setText(h1+":"+m1);
                    //qDebug()<<"minute is "<<min1;
                    //icon =
                }else{
                    ui->icon1->setText("");
                    ui->weather1->setText("-");
                    ui->temp1->setText("-");
                    ui->time1->setText("-");
                }

                //for 2nd

                QString weather2 = todaysWeather::fetchWeatherStatus(lowestId+1);
                //qDebug()<<"the weather status is "<<weather1;
                double temp2 = todaysWeather::fetchTemp(lowestId+1);
                int hour2 = todaysWeather::fetchHour(lowestId+1);
                int min2 = todaysWeather::fetchMin(lowestId+1);
                icon = todaysWeather::fetchIcon(lowestId+1);
                //qDebug()<<"temperature is "<<temp1;
                //qDebug()<<"hour is "<<hour1;

                if(weather2!=""){
                    ui->icon2->setPixmap(icon.pixmap(QSize(W,H)));
                    ui->weather2->setText(weather2);
                    ui->temp2->setText(QString::number(temp2)+"°C");

                    QString h2 = logicMaths::checkDigit(hour2);
                    QString m2 = logicMaths::checkDigit(min2);
                    ui->time2->setText(h2+":"+m2);
                }else{
                    ui->icon2->setText("");
                    ui->weather2->setText("-");
                    ui->temp2->setText("-");
                    ui->time2->setText("-");
                }
                // qDebug()<<"minute is "<<min2;

                //for 3rd

                QString weather3 = todaysWeather::fetchWeatherStatus(lowestId+2);
                //qDebug()<<"the weather status is "<<weather1;
                double temp3 = todaysWeather::fetchTemp(lowestId+2);
                int hour3 = todaysWeather::fetchHour(lowestId+2);
                int min3 = todaysWeather::fetchMin(lowestId+2);
                icon = todaysWeather::fetchIcon(lowestId+2);
                // qDebug()<<"weather status is nothing but "<<weather3;
                //qDebug()<<"temperature is "<<temp1;
                //qDebug()<<"hour is "<<hour1;

                if(weather3!=""){
                    ui->icon3->setPixmap(icon.pixmap(QSize(W,H)));
                    ui->weather3->setText(weather3);
                    ui->temp3->setText(QString::number(temp3)+"°C");

                    QString h3 = logicMaths::checkDigit(hour3);
                    QString m3 = logicMaths::checkDigit(min3);
                    ui->time3->setText(h3+":"+m3);
                    //qDebug()<<"minute is "<<min1;
                }else{
                    ui->icon3->setText("");
                    ui->weather3->setText("-");
                    ui->temp3->setText("-");
                    ui->time3->setText("-");
                }

                //4th
                QString weather4 = todaysWeather::fetchWeatherStatus(lowestId+3);
                //qDebug()<<"the weather status is "<<weather1;
                double temp4 = todaysWeather::fetchTemp(lowestId+3);
                int hour4 = todaysWeather::fetchHour(lowestId+3);
                int min4 = todaysWeather::fetchMin(lowestId+3);
                icon = todaysWeather::fetchIcon(lowestId+3);

                if(weather4!=""){
                    ui->icon4->setPixmap(icon.pixmap(QSize(W,H)));
                    ui->weather4->setText(weather4);
                    ui->temp4->setText(QString::number(temp4)+"°C");

                    QString h4 = logicMaths::checkDigit(hour4);
                    QString m4 = logicMaths::checkDigit(min4);
                    ui->time4->setText(h4+":"+m4);

                }else{
                    ui->icon4->setText("");
                    ui->weather4->setText("-");
                    ui->temp4->setText("-");
                    ui->time4->setText("-");
                }

                //5th
                QString weather5 = todaysWeather::fetchWeatherStatus(lowestId+4);
                //qDebug()<<"the weather status is "<<weather1;
                double temp5 = todaysWeather::fetchTemp(lowestId+4);
                int hour5 = todaysWeather::fetchHour(lowestId+4);
                int min5 = todaysWeather::fetchMin(lowestId+4);
                icon = todaysWeather::fetchIcon(lowestId+4);

                if(weather5!=""){
                    ui->icon5->setPixmap(icon.pixmap(QSize(W,H)));
                    ui->weather5->setText(weather5);
                    ui->temp5->setText(QString::number(temp5)+"°C");

                    QString h5 = logicMaths::checkDigit(hour5);
                    QString m5 = logicMaths::checkDigit(min5);
                    ui->time5->setText(h5+":"+m5);
                }else{
                    ui->icon5->setText("");
                    ui->weather5->setText("-");
                    ui->temp5->setText("-");
                    ui->time5->setText("-");
                }

                //futureData
                temp1 = futureWeather::fetchTemp(1);
                temp2 = futureWeather::fetchTemp(2);
                temp3 = futureWeather::fetchTemp(3);
                //qDebug()<<"The future temperature is ";
                //qDebug()<<temp1<<" "<<temp2<<" "<<temp3;

                weather1 = futureWeather::fetchStatus(1);
                weather2 = futureWeather::fetchStatus(2);
                weather3 = futureWeather::fetchStatus(3);
                //qDebug()<<"future status is";
                //qDebug()<<weather1<<" "<<weather2<<" "<<weather3;

                QString mon1 = futureWeather::fetchMonth(1);
                QString mon2 = futureWeather::fetchMonth(2);
                QString mon3 = futureWeather::fetchMonth(3);

                int date1 = futureWeather::fetchDate(1);
                int date2 = futureWeather::fetchDate(2);
                int date3 = futureWeather::fetchDate(3);

                //qDebug()<<mon1<<date1<<mon2<<date2<<mon3<<date3;

                QIcon icon1 = futureWeather::fetchIcon(1);
                QIcon icon2 = futureWeather::fetchIcon(2);
                QIcon icon3 = futureWeather::fetchIcon(3);

                ui->fIcon1->setPixmap(icon1.pixmap(QSize(W,H)));
                ui->fWeather1->setText(weather1);
                ui->fTemp1->setText(QString::number(temp1)+"°C");
                ui->fDate1->setText(mon1+" "+QString::number(date1));

                ui->fIcon2->setPixmap(icon2.pixmap(QSize(W,H)));
                ui->fWeather2->setText(weather2);
                ui->fTemp2->setText(QString::number(temp2)+"°C");
                ui->fDate2->setText(mon2+" "+QString::number(date2));

                ui->fIcon3->setPixmap(icon3.pixmap(QSize(W,H)));
                ui->fWeather3->setText(weather3);
                ui->fTemp3->setText(QString::number(temp3)+"°C");
                ui->fDate3->setText(mon3+" "+QString::number(date3));

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

}
void MainWindow::on_pushButton_flag_clicked()
{
    if(check)
    {
        ui->pushButton_flag->setIcon(QIcon(":/new/prefix1/image/Usa.svg"));
        check=false;
    }
    else
    {
        ui->pushButton_flag->setIcon(QIcon(":/new/prefix1/image/Nepal.svg"));
        check=true;
    }

}
void MainWindow::on_lineEdit_searchbar_returnPressed()
{
    if (completer->currentCompletion()!=""){
    location=completer->currentCompletion();
    }
    else
    {
        location=ui->lineEdit_searchbar->text();
    }
    ui->lineEdit_searchbar->clear();
    QString apiKey="410680a363d4c095792d7e19b0bf49cb";
    QString urlstring=QString("https://api.openweathermap.org/data/2.5/weather?q=%1&appid=%2").arg(location, apiKey);
    QUrl url(urlstring);
    QNetworkRequest request(url);
    networkManager->get(request);
}
void MainWindow::on_pushButton_search_clicked()
{
    on_lineEdit_searchbar_returnPressed();
}
// void MainWindow:: resizeEvent(QResizeEvent *event)
// {
//     // calling the base class implementation
//     QMainWindow::resizeEvent(event);
//     // Adjust the size of the weather icon
//     if (!icon.isNull()) {
//      you can recall with the same location id
//     }
// }

void MainWindow::on_lineEdit_searchbar_textChanged(const QString &str)
{
    QString location = QString("https://maps.googleapis.com/maps/api/place/autocomplete/json?input=%1&key=AIzaSyDZTOjo8YOEFGI7FodHX5fpfteFw_bQ9bg").arg(str);
    //qDebug() <<"location:" << location;
    QUrl url(location);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::UserAgentHeader, "MyApp/1.0 (MyOrganization)");
    request.setRawHeader("Accept", "application/json");
    NetworkManager->get(request);
}
void MainWindow::onLocationRecieved(QNetworkReply *reply)
{
    if(reply->error()==QNetworkReply::NoError)
    {
        QStringList locationlist;
        QByteArray rawdata = reply->readAll();
        QJsonDocument Jsondoc = QJsonDocument::fromJson(rawdata);
        if (!Jsondoc.isNull() && Jsondoc.isObject()) {
            QJsonObject rootObj = Jsondoc.object();
            if (rootObj.contains("predictions") && rootObj.value("predictions").isArray()) {
                QJsonArray Jsonarr = rootObj.value("predictions").toArray();
                for (const QJsonValue &jsonvalue : Jsonarr){
                    QJsonObject obj = jsonvalue.toObject();
                    locationlist << obj.value("description").toString();
                }
            }
        }
        //updating model with new StringList
        model->setStringList(QStringList());
        model->setStringList(locationlist);

    }
}

intermediateWindow *intermediate;

void MainWindow::on_seemore_btn_clicked()
{
    //QMessageBox::information(this,"clicked","you clicked");
    intermediate = new intermediateWindow();
    connect(intermediate, &intermediateWindow::returnToMainWindow, this, &MainWindow::showMainWindow);

    intermediate->show();

    this->hide();

    return;
}

void MainWindow::showMainWindow() {
    this->show();
    disconnect(intermediate, &intermediateWindow::returnToMainWindow, this, &MainWindow::showMainWindow);
    intermediate->deleteLater();
    intermediate = nullptr;
    return;
}

void MainWindow::on_light_btn_clicked()
{
    if(checkLight)
    {
        ui->light_btn->setIcon(QIcon(":/new/prefix1/image/light.svg"));
        ui->centralwidget->setStyleSheet("background-image: url(':/new/prefix1/image/maindarkbackground.png');");

        ui->label_18->setStyleSheet("color:#F0EFF9; background:transparent; font: 13pt 'Segoe UI';");
        ui->label_temp->setStyleSheet("color:#F0EFF9; background:transparent; font: 15pt 'Segoe UI'");
        ui->label_currentWeather->setStyleSheet("color:#F0EFF9; background:transparent; font: 15pt 'Segoe UI'");
        ui->label_alert->setStyleSheet("color:#F0EFF9; background:transparent; font: 9pt 'Segoe UI'");
        ui->label_recentSearch->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI'");
        ui->lineEdit_searchbar->setStyleSheet("background-color: rgb(217, 217, 217);color: #F0EFF9;"
                                              "border-top-right-radius:12%;border-bottom-right-radius:12%;");

        ui->humidity1->setStyleSheet("color:#F0EFF9;background:transparent;font: 8pt 'Segoe UI';");
        ui->feelslike1->setStyleSheet("color:#F0EFF9;background:transparent;font: 8pt 'Segoe UI';");
        ui->windspeed1->setStyleSheet("color:#F0EFF9;background:transparent;font: 8pt 'Segoe UI';");

        ui->todaysLocation->setStyleSheet("border-top-left-radius:12%;"
            "border-top-right-radius:12%;border -color: rgba(255, 255, 255, .2);background:rgba(255, 255, 255, .07);"
                                          "font: 10pt 'Segoe UI';color:#F0EFF9;padding-left:10px;");


        ui->weather1->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");
        ui->temp1->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");
        ui->time1->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");

        ui->weather2->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");
        ui->temp2->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");
        ui->time2->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");

        ui->weather3->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");
        ui->temp3->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");
        ui->time3->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");

        ui->weather4->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");
        ui->temp4->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");
        ui->time4->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");

        ui->weather5->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");
        ui->temp5->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");
        ui->time5->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");

        ui->fWeather1->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");
        ui->fTemp1->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");
        ui->fDate1->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");

        ui->fWeather2->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");
        ui->fTemp2->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");
        ui->fDate2->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");

        ui->fWeather3->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");
        ui->fTemp3->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");
        ui->fDate3->setStyleSheet("color:#F0EFF9; background:transparent; font: 10pt 'Segoe UI';");

        ui->currentlocation->setStyleSheet("color:#F0EFF9;background:transparent;font: 14pt 'Segoe UI';padding-left:15px;");
        ui->current_time->setStyleSheet("color:#F0EFF9;background:transparent;font: 13pt 'Segoe UI';padding-left:20px;");
        ui->currentTemp->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->currentTemp_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';padding-left:220px;");
        ui->currentHum->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->currentHum_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';padding-left:220px;");
        ui->currentfl->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->currentfl_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';padding-left:220px;");
        ui->currentlat->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->currentlat_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';padding-left:220px;");
        ui->currentlon->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->currentlon_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';padding-left:220px;");

        checkLight=false;
    }
    else
    {
        ui->light_btn->setIcon(QIcon(":/new/prefix1/image/dark.svg"));
        ui->centralwidget->setStyleSheet("background-image: url(':/new/prefix1/image/mainbackground.png');");

        ui->label_18->setStyleSheet("color:black; background:transparent; font: 13pt 'Segoe UI';");
        ui->label_temp->setStyleSheet("color:black; background:transparent; font: 15pt 'Segoe UI'");
        ui->label_currentWeather->setStyleSheet("color:black; background:transparent; font: 15pt 'Segoe UI'");
        ui->label_alert->setStyleSheet("color:black; background:transparent; font: 9pt 'Segoe UI'");
        ui->label_recentSearch->setStyleSheet("color:black; background:transparent; font: 10pt 'Segoe UI'");
        ui->lineEdit_searchbar->setStyleSheet("background-color: rgb(217, 217, 217);color: black;"
                                              "border-top-right-radius:12%;border-bottom-right-radius:12%;");

        ui->humidity1->setStyleSheet("color:black;background:transparent;font: 8pt 'Segoe UI';");
        ui->feelslike1->setStyleSheet("color:black;background:transparent;font: 8pt 'Segoe UI';");
        ui->windspeed1->setStyleSheet("color:black;background:transparent;font: 8pt 'Segoe UI';");

        ui->todaysLocation->setStyleSheet("border-top-left-radius:12%;"
    "border-top-right-radius:12%;border -color: rgba(255, 255, 255, .2);background:rgba(255, 255, 255, .07);"
                                          "font: 10pt 'Segoe UI';color:rgb(0, 0, 0);padding-left:10px;");

        ui->weather1->setStyleSheet("color:black;  background:transparent; font: 10pt 'Segoe UI';");
        ui->temp1->setStyleSheet("color:black;  background:transparent; font: 10pt 'Segoe UI';");
        ui->time1->setStyleSheet("color:black;  background:transparent; font: 10pt 'Segoe UI';");

        ui->weather2->setStyleSheet("color:black;  background:transparent; font: 10pt 'Segoe UI';");
        ui->temp2->setStyleSheet("color:black;  background:transparent; font: 10pt 'Segoe UI';");
        ui->time2->setStyleSheet("color:black;  background:transparent; font: 10pt 'Segoe UI';");

        ui->weather3->setStyleSheet("color:black;  background:transparent; font: 10pt 'Segoe UI';");
        ui->temp3->setStyleSheet("color:black;  background:transparent; font: 10pt 'Segoe UI';");
        ui->time3->setStyleSheet("color:black; background:transparent; font: 10pt 'Segoe UI';");

        ui->weather4->setStyleSheet("color:black; background:transparent; font: 10pt 'Segoe UI';");
        ui->temp4->setStyleSheet("color:black; background:transparent; font: 10pt 'Segoe UI';");
        ui->time4->setStyleSheet("color:black; background:transparent; font: 10pt 'Segoe UI';");

        ui->weather5->setStyleSheet("color:black; background:transparent; font: 10pt 'Segoe UI';");
        ui->temp5->setStyleSheet("color:black; background:transparent; font: 10pt 'Segoe UI';");
        ui->time5->setStyleSheet("color:black; background:transparent; font: 10pt 'Segoe UI';");

        ui->fWeather1->setStyleSheet("color:black; background:transparent; font: 10pt 'Segoe UI';");
        ui->fTemp1->setStyleSheet("color:black; background:transparent; font: 10pt 'Segoe UI';");
        ui->fDate1->setStyleSheet("color:black; background:transparent; font: 10pt 'Segoe UI';");

        ui->fWeather2->setStyleSheet("color:black; background:transparent; font: 10pt 'Segoe UI';");
        ui->fTemp2->setStyleSheet("color:black; background:transparent; font: 10pt 'Segoe UI';");
        ui->fDate2->setStyleSheet("color:black; background:transparent; font: 10pt 'Segoe UI';");

        ui->fWeather3->setStyleSheet("color:black; background:transparent; font: 10pt 'Segoe UI';");
        ui->fTemp3->setStyleSheet("color:black; background:transparent; font: 10pt 'Segoe UI';");
        ui->fDate3->setStyleSheet("color:black; background:transparent; font: 10pt 'Segoe UI';");

        ui->currentlocation->setStyleSheet("color:black;background:transparent;font: 14pt 'Segoe UI';padding-left:15px;");
        ui->current_time->setStyleSheet("color:black;background:transparent;font: 13pt 'Segoe UI';padding-left:20px;");
        ui->currentTemp->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->currentTemp_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';padding-left:220px;");
        ui->currentHum->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->currentHum_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';padding-left:220px;");
        ui->currentfl->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->currentfl_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';padding-left:220px;");
        ui->currentlat->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->currentlat_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';padding-left:220px;");
        ui->currentlon->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->currentlon_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';padding-left:220px;");

        checkLight=true;
    }
}

worldMap *wm;
void MainWindow::on_map_btn_clicked()
{
        wm = new worldMap();
        connect(wm, &worldMap::returnToMainWindow, this, &MainWindow::showMainWindowM);

        wm->show();

        this->hide();

        return;


}

void MainWindow::showMainWindowM() {
    this->show();
    disconnect(wm, &worldMap::returnToMainWindow, this, &MainWindow::showMainWindowM);
    wm->deleteLater();
    wm = nullptr;
    return;
}
