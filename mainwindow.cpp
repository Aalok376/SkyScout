#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QThread>
#include<QGeoCoordinate>
#include<QQuickItem>
#include<QRegion>
QIcon icon ;
QString location;
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
    ui->pushButton_flag->setIcon(QIcon(":/new/prefix1/image/np.png"));
    int x= ui->pushButton_flag->width();
    int y =ui->pushButton_flag->height();
    ui->pushButton_flag->setIconSize(QSize(x,y));
    addressObj = new FetchCurrentAddress(this);

    connect(addressObj, &FetchCurrentAddress::locationFetched, this, &MainWindow::onCurrentLocationFetched);
    connect(networkManager,&QNetworkAccessManager::finished ,this , &MainWindow::onWeatherDataRecieved);
    connect(NetworkManager, &QNetworkAccessManager::finished , this , &MainWindow::onLocationRecieved);
    //setting fixed size
    resize(800,600);
    setFixedSize(size());
    addressObj->fetchLocation();

    //setting up model for suggestion feature
    model=new QStringListModel(this);
    completer =new QCompleter(model , this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
        completer->setMaxVisibleItems(5);
    ui->lineEdit_searchbar->setCompleter(completer);

    // map integration
   ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/MapView.qml")));
    ui->quickWidget->show();
   int dia = 250;
    ui->quickWidget->setFixedSize(dia, dia);
    QRegion region(0, 0, dia, dia, QRegion::Ellipse);
    ui->quickWidget->setMask(region);
    ui->verticalLayout_8->addWidget(ui->quickWidget, 0, Qt::AlignCenter);

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
                for(int i=0;i<List.size();i++) {
                    QJsonObject ListObj = List.at(i).toObject();
                    int dt = ListObj.value("dt").toInt();
                   // qDebug()<<"display dt "<<dt;
                    if(dateTime::fetchDate(dt)-dateTime::currentDate()>0&&
                        dateTime::fetchDate(dt)-dateTime::currentDate()<5) {

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
                        if(dateTime::fetchDate(dt)-dateTime::currentDate()!=0){
                            break;
                        }
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
                ui->label_temp->setText(QString::number(temp)+"°C");

                QJsonObject coordObj = JsonObj.value("coord").toObject();
                double lat = coordObj.value("lat").toDouble();
                double lon = coordObj.value("lon").toDouble();
                qDebug()<<"latitude"<<lat;
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
                weatherData::databaseConnection(city,temp,humidity,lat,lon,sunrise,sunset,currentTime,year,month,date);
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
                            ui->label_alert->setText("It's a bit cloudy today. \n A good day for a walk in the park");
                        }
                        else
                        {
                            icon= QIcon(":/new/prefix1/image/cloudy-night.png");
                            ui->label_alert->setText("Cloudy night ahead. \n Drive safely ");
                        }
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(182 , 175)));//height , width
                    }
                    if(weatherStatus=="Thunderstorm")
                    {
                        //int width=ui->label_weatherIcon->width();
                        //int height= ui->label_weatherIcon->height();
                        icon=QIcon(":/new/prefix1/image/Thunderstorm.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(182 , 175)));
                        ui->label_alert->setText("Thunderstorms expected \n Avoid outdoor activities if possible");
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
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(182 , 175)));
                        ui->label_alert->setText("Light drizzle outside \n Don't forget your raincoat");
                    }
                    if(weatherStatus=="Mist" || weatherStatus=="Haze" || weatherStatus=="Fog")
                    {
                        //int width=ui->label_weatherIcon->width();
                        //int height= ui->label_weatherIcon->height();
                        icon =QIcon(":/new/prefix1/image/haze.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(182 , 175)));
                        ui->label_alert->setText("Visibility is low \n take precautions");
                    }
                    if(weatherStatus=="Rain")
                    {
                        //int width=ui->label_weatherIcon->width();
                        //int height= ui->label_weatherIcon->height();
                        icon=QIcon(":/new/prefix1/image/Rain.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(182 , 175)));
                        ui->label_alert->setText("Don't forget your umbrella ! ");
                    }
                    if(weatherStatus=="Clear")
                    {
                        //int width=ui->label_weatherIcon->width();
                        //int height= ui->label_weatherIcon->height();
                        if (sunrise<=currentTime && currentTime<sunset)
                        {
                            icon=QIcon(":/new/prefix1/image/Clear.png");
                            ui->label_alert->setText("It's a clear day! \n Enjoy the beautiful weather");
                        }
                        else
                        {
                            icon=QIcon(":/new/prefix1/image/full-moon.png");
                            ui->label_alert->setText("Clear skies tonight \n Ideal for stargazing!");
                        }
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(182 , 175)));
                    }
                    if(weatherStatus=="Smoke")
                    {
                        //int width=ui->label_weatherIcon->width();
                        //int height= ui->label_weatherIcon->height();
                        icon=QIcon(":/new/prefix1/image/Smoke.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(182 , 175)));
                        ui->label_alert->setText("Don't forget your mask !");
                    }
                    if(weatherStatus=="Snow")
                    {
                        //int width=ui->label_weatherIcon->width();
                        //int height= ui->label_weatherIcon->height();
                        icon=QIcon(":/new/prefix1/image/Snow.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(182 , 175)));
                        ui->label_alert->setText("Snow is falling! \n Time for some winter fun.");
                    }
                    if(weatherStatus=="Dust" || weatherStatus=="Sand" || weatherStatus=="Ash")
                    {
                        //int width=ui->label_weatherIcon->width();
                        //int height= ui->label_weatherIcon->height();
                        icon=QIcon(":/new/prefix1/image/dust.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(182 , 175)));
                        ui->label_alert->setText("Consider wearing a mask \n if you're heading out");
                    }
                    if(weatherStatus=="Tornado")
                    {
                        //int width=ui->label_weatherIcon->width();
                        //int height= ui->label_weatherIcon->height();
                        icon=QIcon(":/new/prefix1/image/Tornado.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(182 , 175)));
                        ui->label_alert->setText("Tornado alert! stay indoors");
                    }
                    if(weatherStatus=="Squall")
                    {
                        //int width=ui->label_weatherIcon->width();
                        //int height= ui->label_weatherIcon->height();
                        icon=QIcon(":/new/prefix1/image/Squall.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(182 , 175)));
                        ui->label_alert->setText("A squall is approaching \n Expect strong winds and rain");
                    }

                }
                else
                {
                    QMessageBox::information(this ,"SkyScout","error to display weather");
                }
                ui->label_recentSearch->setText(location);


                //currentData

                int lowestId = todaysWeather::findLowestId();
                //qDebug()<<"the lowest Id is nothing but "<<lowestId;

                QString weather1 = todaysWeather::fetchWeatherStatus(lowestId);
                //qDebug()<<"the weather status is "<<weather1;
                double temp1 = todaysWeather::fetchTemp(lowestId);
                int hour1 = todaysWeather::fetchHour(lowestId);
                int min1 = todaysWeather::fetchMin(lowestId);
                icon = todaysWeather::fetchIcon(lowestId);
                //qDebug()<<"temperature is "<<temp1;
                //qDebug()<<"hour is "<<hour1;

                if(weather1!=""){
                    ui->icon1->setPixmap(icon.pixmap(QSize(85, 60)));
                    ui->weather1->setText(weather1);
                    ui->temp1->setText(QString::number(temp1)+"°C");
                    ui->time1->setText(QString::number(hour1)+":"+QString::number(min1));
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
                    ui->icon2->setPixmap(icon.pixmap(QSize(85,60)));
                    ui->weather2->setText(weather2);
                    ui->temp2->setText(QString::number(temp2)+"°C");
                    ui->time2->setText(QString::number(hour2)+":"+QString::number(min2));
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
                    ui->icon3->setPixmap(icon.pixmap(QSize(85,60)));
                    ui->weather3->setText(weather3);
                    ui->temp3->setText(QString::number(temp3)+"°C");
                    ui->time3->setText(QString::number(hour3)+":"+QString::number(min3));
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
                    ui->icon4->setPixmap(icon.pixmap(QSize(85,60)));
                    ui->weather4->setText(weather4);
                    ui->temp4->setText(QString::number(temp4)+"°C");
                    ui->time4->setText(QString::number(hour4)+":"+QString::number(min4));
                    //qDebug()<<"minute is "<<min1;
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
                    ui->icon5->setPixmap(icon.pixmap(QSize(85,60)));
                    ui->weather5->setText(weather5);
                    ui->temp5->setText(QString::number(temp5)+"°C");
                    ui->time5->setText(QString::number(hour5)+":"+QString::number(min5));
                    //qDebug()<<"minute is "<<min1;
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

                ui->fIcon1->setPixmap(icon1.pixmap(QSize(85,60)));
                ui->fWeather1->setText(weather1);
                ui->fTemp1->setText(QString::number(temp1)+"°C");
                ui->fDate1->setText(mon1+" "+QString::number(date1));

                ui->fIcon2->setPixmap(icon2.pixmap(QSize(85,60)));
                ui->fWeather2->setText(weather2);
                ui->fTemp2->setText(QString::number(temp2)+"°C");
                ui->fDate2->setText(mon2+" "+QString::number(date2));

                ui->fIcon3->setPixmap(icon3.pixmap(QSize(85,60)));
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
