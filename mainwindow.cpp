#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QThread>
#include<QGeoCoordinate>
#include<QQuickItem>
#include<QRegion>

//For current weather......
QString weatherStatus;
QString status_string;
int sunrise;
int sunset;
int currentTime;
QString temperature;
QString currenthour;
QString currentmin;
QString currentWindSpeed;
QString currentHumidity;
QString currentFeelslike;
QString CurrentLongitude;
QString currentLatitude;

//For 5 weather of todays.....
QString weather1;
QString Tempr1;
QString Hour1;
QString Min1;

QString weather2;
QString Tempr2;
QString Hour2;
QString Min2;

QString weather3;
QString Tempr3;
QString Hour3;
QString Min3;

QString weather4;
QString Tempr4;
QString Hour4;
QString Min4;

QString weather5;
QString Tempr5;
QString Hour5;
QString Min5;

//For future weather...
QString fweather1;
QString fweather2;
QString fweather3;

QString fTempr1;
QString fTempr2;
QString fTempr3;

QString mon1;
QString mon2;
QString mon3;

QString Date1;
QString Date2;
QString Date3;

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

    ui->pushButton_flag->setIcon(QIcon(":/new/prefix1/image/Usa.svg"));
    int x= ui->pushButton_flag->width();
    int y =ui->pushButton_flag->height();
    ui->pushButton_flag->setIconSize(QSize(y-4,y-4));


    ui->light_btn->setIcon(QIcon(":/new/prefix1/image/dark.svg"));
    x= ui->light_btn->width();
    y =ui->light_btn->height();
    ui->light_btn->setIconSize(QSize(y,y));

    ui->label_gif->setIcon(QIcon(":/new/prefix1/image/notification.png"));
    x=ui->label_gif->width();
    y=ui->label_gif->height();
    ui->label_gif->setIconSize(QSize(y,y));


    //Sidebar
    QIcon wIcon = QIcon(":/new/prefix1/image/skyscout.png");
    ui->wIcon->setPixmap(wIcon.pixmap(QSize(27 , 25)));

    ui->map_btn->setIcon(QIcon(":/new/prefix1/image/mapIcon.svg"));
    y = ui->map_btn->height();
    ui->map_btn->setIconSize(QSize(y-4,y-4));

    ui->seemore_btn->setIcon(QIcon(":/new/prefix1/image/more.svg"));
    y =ui->seemore_btn->height();
    ui->seemore_btn->setIconSize(QSize(y,y));

    //Animation
    // gifAnimation= new QMovie(":/new/prefix1/image/icons8-notification.gif");
    // gifAnimation->setScaledSize(QSize(30,30));
    // ui->label_gif->setMovie(gifAnimation);
    // qDebug()<< ui->label_gif->height()<<"skfskdfskdfdskfkddskfksfdsjkkkkkkkk";
    // qDebug()<< ui->label_gif->width()<<"skfskdfskdfdskfkddskfksfdsjkkkkkkkk";
    // gifAnimation->start();



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

    //Map integration
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/MapView.qml")));
    ui->quickWidget->show();
    int wid = 350,hei = 170;
    int radius = 12;
    ui->quickWidget->setFixedSize(wid, hei);

    //Create a QPainterPath for the rounded rectangle
    QPainterPath path;
    path.addRoundedRect(0, 0, wid, hei, radius, radius);

    //Convert the QPainterPath to a QRegion and set it as the mask
    QRegion region(path.toFillPolygon().toPolygon());
    ui->quickWidget->setMask(region);

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
    QString apiKey = "410680a363d4c095792d7e19b0bf49cb";

    QString urlStringCurrent = QString("https://api.openweathermap.org/data/2.5/weather?q=%1&appid=%2").arg(location, apiKey);
    QUrl urlCurrent(urlStringCurrent);
    QNetworkRequest requestCurrent(urlCurrent);
    networkManager->get(requestCurrent);

    //Second request for forecast weather
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
                int lim = 32;
                for(int i=0;i<lim;i++) {
                    QJsonObject ListObj = List.at(i).toObject();
                    int dt = ListObj.value("dt").toInt();

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
                QJsonObject mainObj=JsonObj.value("main").toObject();
                double temp=mainObj.value("temp").toDouble();
                temp = logicMaths::tempConversion(temp);
                temperature=QString::number(temp);

                double humidity=mainObj.value("humidity").toDouble();
                currentHumidity=QString::number(humidity);
                double feelsLike = mainObj.value("feels_like").toDouble();
                feelsLike = logicMaths::tempConversion(feelsLike);
                currentFeelslike=QString::number(feelsLike);

                QJsonObject windObj = JsonObj.value("wind").toObject();
                double windSpeed = windObj.value("speed").toDouble();
                windSpeed = std::round(windSpeed*3.6);
                currentWindSpeed=QString::number(windSpeed);

                QJsonObject coordObj = JsonObj.value("coord").toObject();
                double lat = coordObj.value("lat").toDouble();
                currentLatitude=QString::number(lat);
                double lon = coordObj.value("lon").toDouble();
                CurrentLongitude=QString::number(lon);

                int ts = dateTime::getTimeZone(lat,lon);
                emit updateMap(lat , lon);

                QJsonObject sysObj = JsonObj.value("sys").toObject();
                sunrise = sysObj.value("sunrise").toInt();
                sunset = sysObj.value("sunset").toInt();
                currentTime = JsonObj.value("dt").toInt();
                int year = dateTime::currentYear();
                int month = dateTime::currentMonth();
                int date = dateTime::currentDate();
                QString city = JsonObj.value("name").toString();


                QJsonArray weatherarr = JsonObj.value("weather").toArray();
                QJsonObject weatherobj = weatherarr.at(0).toObject();
                weatherStatus = weatherobj.value("main").toString();
                status_string = weatherStatus;
                int hour = dateTime::currentHour();
                int min = dateTime::currentMin();

                weatherData::databaseConnection(city,temp,humidity,weatherStatus,lat,lon,sunrise,sunset,currentTime,year,month,date);
                todaysWeather::databaseConnection(city,temp,humidity,weatherStatus,lat,lon,sunrise,sunset,
                                                  currentTime,year,month,date,hour,min);

                //Debug output
                qDebug() << "Sunrise:" << sunrise;
                qDebug() << "Sunset:" << sunset;
                qDebug() << "Current Time:" << currentTime;

                if (!weatherarr.isEmpty())
                {
                    // code to display the current weather status and set icons based on current weather

                    weatherobj = weatherarr.at(0).toObject();
                    weatherStatus = weatherobj.value("main").toString();

                    if(weatherStatus=="Clouds")
                    {
                        if (sunrise<=currentTime && currentTime<sunset)
                        {
                            icon= QIcon(":/new/prefix1/image/cloudy.png");
                        }
                        else
                        {
                            icon= QIcon(":/new/prefix1/image/cloudy-night.png");
                        }
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(wt , ht)));//height , width
                    }
                    if(weatherStatus=="Thunderstorm")
                    {
                        icon=QIcon(":/new/prefix1/image/Thunderstorm.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(wt , ht)));
                    }
                    if(weatherStatus=="Drizzle")
                    {
                        if(sunrise<=currentTime && currentTime<sunset)
                        {
                            icon=QIcon(":/new/prefix1/image/weather.png");
                        }
                        else
                        {
                            icon=QIcon(":/new/prefix1/image/drizzle.png");
                        }
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(wt , ht)));
                    }
                    if(weatherStatus=="Mist" || weatherStatus=="Haze" || weatherStatus=="Fog")
                    {
                        icon =QIcon(":/new/prefix1/image/haze.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(wt , ht)));
                    }
                    if(weatherStatus=="Rain")
                    {
                        icon=QIcon(":/new/prefix1/image/Rain.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(wt , ht)));
                    }
                    if(weatherStatus=="Clear")
                    {
                        if (sunrise<=currentTime && currentTime<sunset)
                        {
                            icon=QIcon(":/new/prefix1/image/Clear.png");
                        }
                        else
                        {
                            icon=QIcon(":/new/prefix1/image/full-moon.png");
                        }
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(wt, ht)));
                    }
                    if(weatherStatus=="Smoke")
                    {
                        icon=QIcon(":/new/prefix1/image/Smoke.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(wt , ht)));
                    }
                    if(weatherStatus=="Snow")
                    {
                        icon=QIcon(":/new/prefix1/image/Snow.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(wt , ht)));
                    }
                    if(weatherStatus=="Dust" || weatherStatus=="Sand" || weatherStatus=="Ash")
                    {
                        icon=QIcon(":/new/prefix1/image/dust.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(wt ,ht)));
                    }
                    if(weatherStatus=="Tornado")
                    {
                        icon=QIcon(":/new/prefix1/image/Tornado.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(wt , ht)));
                    }
                    if(weatherStatus=="Squall")
                    {
                        icon=QIcon(":/new/prefix1/image/Squall.png");
                        ui->label_weatherIcon->setPixmap(icon.pixmap(QSize(wt , ht)));
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

                    //bottom right
                    int chr = dateTime::fetchHour(ts);
                    QString current_hour = logicMaths::checkDigit(chr);
                    currenthour = logicMaths::checkDigit(chr);

                    int cmin = dateTime::fetchMin(ts);
                    QString current_min = logicMaths::checkDigit(cmin);
                    currentmin = logicMaths::checkDigit(cmin);

                    ui->currentlocation->setText(location);

                    QIcon cicon = logicMaths::getStatusIcon(weatherStatus,currentTime,sunrise,sunset);
                    ui->currentsta->setPixmap(cicon.pixmap(QSize(65,40)));
                }
                else
                {
                    QMessageBox::information(this ,"SkyScout","error to display weather");
                }
                ui->label_recentSearch->setText(location);

                //currentData

                int lowestId = todaysWeather::findLowestId();

                QString todaysCity = todaysWeather::fetchCity(lowestId);
                ui->todaysLocation->setText(todaysCity+", Nepal");

                weather1 = todaysWeather::fetchWeatherStatus(lowestId);
                double temp1 = todaysWeather::fetchTemp(lowestId);
                Tempr1=QString::number(temp1);
                int hour1 = todaysWeather::fetchHour(lowestId);
                int min1 = todaysWeather::fetchMin(lowestId);
                icon = todaysWeather::fetchIcon(lowestId);

                if(weather1!="")
                {
                    ui->icon1->setPixmap(icon.pixmap(QSize(W, H)));
                    Hour1 = logicMaths::checkDigit(hour1);
                    Min1= logicMaths::checkDigit(min1);
                }
                else
                {
                    ui->icon1->setText("");
                    ui->weather1->setText("-");
                    ui->temp1->setText("-");
                    ui->time1->setText("-");
                }

                //for 2nd

                weather2 = todaysWeather::fetchWeatherStatus(lowestId+1);
                double temp2 = todaysWeather::fetchTemp(lowestId+1);
                Tempr2=QString::number(temp2);
                int hour2 = todaysWeather::fetchHour(lowestId+1);
                int min2 = todaysWeather::fetchMin(lowestId+1);
                icon = todaysWeather::fetchIcon(lowestId+1);

                if(weather2!="")
                {
                    ui->icon2->setPixmap(icon.pixmap(QSize(W,H)));
                    Hour2= logicMaths::checkDigit(hour2);
                    Min2= logicMaths::checkDigit(min2);
                }
                else
                {
                    ui->icon2->setText("");
                    ui->weather2->setText("-");
                    ui->temp2->setText("-");
                    ui->time2->setText("-");
                }

                //for 3rd

                weather3 = todaysWeather::fetchWeatherStatus(lowestId+2);
                double temp3 = todaysWeather::fetchTemp(lowestId+2);
                Tempr3=QString::number(temp3);
                int hour3 = todaysWeather::fetchHour(lowestId+2);
                int min3 = todaysWeather::fetchMin(lowestId+2);
                icon = todaysWeather::fetchIcon(lowestId+2);

                if(weather3!="")
                {
                    ui->icon3->setPixmap(icon.pixmap(QSize(W,H)));
                    Hour3= logicMaths::checkDigit(hour3);
                    Min3= logicMaths::checkDigit(min3);
                }
                else
                {
                    ui->icon3->setText("");
                    ui->weather3->setText("-");
                    ui->temp3->setText("-");
                    ui->time3->setText("-");
                }

                //4th

                weather4 = todaysWeather::fetchWeatherStatus(lowestId+3);
                double temp4 = todaysWeather::fetchTemp(lowestId+3);
                Tempr4=QString::number(temp4);
                int hour4 = todaysWeather::fetchHour(lowestId+3);
                int min4 = todaysWeather::fetchMin(lowestId+3);
                icon = todaysWeather::fetchIcon(lowestId+3);

                if(weather4!="")
                {
                    ui->icon4->setPixmap(icon.pixmap(QSize(W,H)));
                    Hour4= logicMaths::checkDigit(hour4);
                    Min4= logicMaths::checkDigit(min4);
                }
                else
                {
                    ui->icon4->setText("");
                    ui->weather4->setText("-");
                    ui->temp4->setText("-");
                    ui->time4->setText("-");
                }

                //5th

                weather5 = todaysWeather::fetchWeatherStatus(lowestId+4);
                double temp5 = todaysWeather::fetchTemp(lowestId+4);
                Tempr5=QString::number(temp5);
                int hour5 = todaysWeather::fetchHour(lowestId+4);
                int min5 = todaysWeather::fetchMin(lowestId+4);
                icon = todaysWeather::fetchIcon(lowestId+4);

                if(weather5!="")
                {
                    ui->icon5->setPixmap(icon.pixmap(QSize(W,H)));
                    Hour5= logicMaths::checkDigit(hour5);
                    Min5= logicMaths::checkDigit(min5);
                }
                else
                {
                    ui->icon5->setText("");
                    ui->weather5->setText("-");
                    ui->temp5->setText("-");
                    ui->time5->setText("-");
                }

                //futureData

                double ftemp1 = futureWeather::fetchTemp(1);
                fTempr1=QString::number(ftemp1);
                double ftemp2 = futureWeather::fetchTemp(2);
                fTempr2=QString::number(ftemp2);
                double ftemp3 = futureWeather::fetchTemp(3);
                fTempr3=QString::number(ftemp3);

                fweather1 = futureWeather::fetchStatus(1);
                fweather2 = futureWeather::fetchStatus(2);
                fweather3 = futureWeather::fetchStatus(3);

                mon1 = futureWeather::fetchMonth(1);
                mon2 = futureWeather::fetchMonth(2);
                mon3 = futureWeather::fetchMonth(3);

                int date1 = futureWeather::fetchDate(1);
                Date1=QString::number(date1);
                int date2 = futureWeather::fetchDate(2);
                Date2=QString::number(date2);
                int date3 = futureWeather::fetchDate(3);
                Date3=QString::number(date3);

                QIcon icon1 = futureWeather::fetchIcon(1);
                QIcon icon2 = futureWeather::fetchIcon(2);
                QIcon icon3 = futureWeather::fetchIcon(3);

                ui->fIcon1->setPixmap(icon1.pixmap(QSize(W,H)));
                ui->fIcon2->setPixmap(icon2.pixmap(QSize(W,H)));
                ui->fIcon3->setPixmap(icon3.pixmap(QSize(W,H)));
            }
            else
            {
                QMessageBox::information(this ,"message","failed to parse data");
            }

            //Setting up the values for ui......
            if(check==false)
            {
                ui->pushButton_flag->setIcon(QIcon(":/new/prefix1/image/Nepal.svg"));
                ui->lineEdit_searchbar->setPlaceholderText("स्थान प्रविष्ट गर्नुहोस्");
                ui->labelFuture->setText("मौसम पूर्वानुमान");
                QString Tempr;
                for(int i=0;i<temperature.length();i++)
                {
                    if(temperature[i]=='0')
                    {
                        Tempr=Tempr+"०";
                    }
                    if(temperature[i]=='1')
                    {
                        Tempr=Tempr+"१";
                    }
                    if(temperature[i]=='2')
                    {
                        Tempr=Tempr+"२";
                    }
                    if(temperature[i]=='3')
                    {
                        Tempr=Tempr+"३";
                    }
                    if(temperature[i]=='4')
                    {
                        Tempr=Tempr+"४";
                    }
                    if(temperature[i]=='5')
                    {
                        Tempr=Tempr+"५";
                    }
                    if(temperature[i]=='6')
                    {
                        Tempr=Tempr+"६";
                    }
                    if(temperature[i]=='7')
                    {
                        Tempr=Tempr+"७";
                    }
                    if(temperature[i]=='8')
                    {
                        Tempr=Tempr+"८";
                    }
                    if(temperature[i]=='9')
                    {
                        Tempr=Tempr+"९";
                    }
                    if(temperature[i]=='.')
                    {
                        Tempr=Tempr+".";
                    }
                }
                ui->label_temp->setText(Tempr+"°C");
                ui->currentTemp_2->setText(Tempr+"°C");
                ui->currentTemp->setText("      तापक्रम");
                ui->currentHum->setText("      आर्द्रता");
                ui->currentfl->setText("      महसुस हुन्छ");
                ui->currentlat->setText("      अक्षांश");
                ui->currentlon->setText("      देशान्तर");

                if(weatherStatus=="Clouds")
                {
                    if (sunrise<=currentTime && currentTime<sunset)
                    {
                        ui->label_alert->setText("आज बादल  \n लागेको छ।");
                    }
                    else
                    {
                        ui->label_alert->setText("बादल लागेको \n छ।");
                    }
                    ui->label_currentWeather->setText("बादल");
                }
                if(weatherStatus=="Thunderstorm")
                {
                    ui->label_currentWeather->setText("चट्याङ");
                    ui->label_alert->setText("सम्भव भए बाहिरी  \n गतिविधिहरू नगर्नुहोस्");
                }
                if(weatherStatus=="Drizzle")
                {
                    ui->label_currentWeather->setText("मुसलधारे पानी");
                    ui->label_alert->setText("आफ्नो रेनकोट \n नबिर्सनुहोस्।");
                }
                if(weatherStatus=="Mist" || weatherStatus=="Haze" || weatherStatus=="Fog")
                {
                    ui->label_currentWeather->setText("कुहिरो");
                    ui->label_alert->setText("भिजिबिलिटी \n कम छ।");
                }
                if(weatherStatus=="Rain")
                {
                    ui->label_currentWeather->setText("वर्षा");
                    ui->label_alert->setText("आफ्नो छाता \n नबिर्सनुहोस् !");
                }
                if(weatherStatus=="Clear")
                {
                    if (sunrise<=currentTime && currentTime<sunset)
                    {
                        ui->label_alert->setText("सुन्दर मौसमको \n आनन्द लिनुहोस्।");
                    }
                    else
                    {
                        ui->label_alert->setText("आज राती \n सफा आकाश ।");
                    }
                    ui->label_currentWeather->setText("सफा मौसम");
                }
                if(weatherStatus=="Smoke")
                {
                    ui->label_currentWeather->setText("धुवाँ");
                    ui->label_alert->setText("आफ्नो मास्क \n नबिर्सनुहोस्!");
                }
                if(weatherStatus=="Snow")
                {
                    ui->label_currentWeather->setText("हिउँ");
                    ui->label_alert->setText("रमाइलो गर्ने \n समय।");
                }
                if(weatherStatus=="Dust" || weatherStatus=="Sand" || weatherStatus=="Ash")
                {
                    ui->label_currentWeather->setText("धुलो");
                    ui->label_alert->setText("मास्क लगाउने \n विचार गर्नुहोस्!");
                }
                if(weatherStatus=="Tornado")
                {
                    ui->label_currentWeather->setText("भुमरी");
                    ui->label_alert->setText("भुमरीको चेतावनी! \n घर भित्रै बस्नुहोस् !");
                }
                if(weatherStatus=="Squall")
                {
                    ui->label_currentWeather->setText("तूफान");
                    ui->label_alert->setText("तीव्र हावा र \n वर्षाको अपेक्षा !");
                }

                //For current time....
                QString cuh;
                for(int i=0;i<currenthour.length();i++)
                {
                    if(currenthour[i]=='0')
                    {
                        cuh=cuh+"०";
                    }
                    if(currenthour[i]=='1')
                    {
                        cuh=cuh+"१";
                    }
                    if(currenthour[i]=='2')
                    {
                        cuh=cuh+"२";
                    }
                    if(currenthour[i]=='3')
                    {
                        cuh=cuh+"३";
                    }
                    if(currenthour[i]=='4')
                    {
                        cuh=cuh+"४";
                    }
                    if(currenthour[i]=='5')
                    {
                        cuh=cuh+"५";
                    }
                    if(currenthour[i]=='6')
                    {
                        cuh=cuh+"६";
                    }
                    if(currenthour[i]=='7')
                    {
                        cuh=cuh+"७";
                    }
                    if(currenthour[i]=='8')
                    {
                        cuh=cuh+"८";
                    }
                    if(currenthour[i]=='9')
                    {
                        cuh=cuh+"९";
                    }
                }

                QString cum;
                for(int i=0;i<currentmin.length();i++)
                {
                    if(currentmin[i]=='0')
                    {
                        cum=cum+"०";
                    }
                    if(currentmin[i]=='1')
                    {
                        cum=cum+"१";
                    }
                    if(currentmin[i]=='2')
                    {
                        cum=cum+"२";
                    }
                    if(currentmin[i]=='3')
                    {
                        cum=cum+"३";
                    }
                    if(currentmin[i]=='4')
                    {
                        cum=cum+"४";
                    }
                    if(currentmin[i]=='5')
                    {
                        cum=cum+"५";
                    }
                    if(currentmin[i]=='6')
                    {
                        cum=cum+"६";
                    }
                    if(currentmin[i]=='7')
                    {
                        cum=cum+"७";
                    }
                    if(currentmin[i]=='8')
                    {
                        cum=cum+"८";
                    }
                    if(currentmin[i]=='9')
                    {
                        cum=cum+"९";
                    }
                }
                ui->current_time->setText(cuh+":"+cum);

                //For wind speed....
                QString cws;
                for(int i=0;i<currentWindSpeed.length();i++)
                {
                    if(currentWindSpeed[i]=='0')
                    {
                        cws=cws+"०";
                    }
                    if(currentWindSpeed[i]=='1')
                    {
                        cws=cws+"१";
                    }
                    if(currentWindSpeed[i]=='2')
                    {
                        cws=cws+"२";
                    }
                    if(currentWindSpeed[i]=='3')
                    {
                        cws=cws+"३";
                    }
                    if(currentWindSpeed[i]=='4')
                    {
                        cws=cws+"४";
                    }
                    if(currentWindSpeed[i]=='5')
                    {
                        cws=cws+"५";
                    }
                    if(currentWindSpeed[i]=='6')
                    {
                        cws=cws+"६";
                    }
                    if(currentWindSpeed[i]=='7')
                    {
                        cws=cws+"७";
                    }
                    if(currentWindSpeed[i]=='8')
                    {
                        cws=cws+"८";
                    }
                    if(currentWindSpeed[i]=='9')
                    {
                        cws=cws+"९";
                    }
                }
                ui->windspeed1->setText(cws+"कि/घ");

                //For humidity....
                QString hum;
                for(int i=0;i<currentHumidity.length();i++)
                {
                    if(currentHumidity[i]=='0')
                    {
                        hum=hum+"०";
                    }
                    if(currentHumidity[i]=='1')
                    {
                        hum=hum+"१";
                    }
                    if(currentHumidity[i]=='2')
                    {
                        hum=hum+"२";
                    }
                    if(currentHumidity[i]=='3')
                    {
                        hum=hum+"३";
                    }
                    if(currentHumidity[i]=='4')
                    {
                        hum=hum+"४";
                    }
                    if(currentHumidity[i]=='5')
                    {
                        hum=hum+"५";
                    }
                    if(currentHumidity[i]=='6')
                    {
                        hum=hum+"६";
                    }
                    if(currentHumidity[i]=='7')
                    {
                        hum=hum+"७";
                    }
                    if(currentHumidity[i]=='8')
                    {
                        hum=hum+"८";
                    }
                    if(currentHumidity[i]=='9')
                    {
                        hum=hum+"९";
                    }
                    if(currentHumidity[i]=='.')
                    {
                        hum=hum+".";
                    }
                }
                ui->humidity1->setText(hum+"%");
                ui->currentHum_2->setText(hum+"%");

                //For feelslike....
                QString fl;
                for(int i=0;i<currentFeelslike.length();i++)
                {
                    if(currentFeelslike[i]=='0')
                    {
                        fl=fl+"०";
                    }
                    if(currentFeelslike[i]=='1')
                    {
                        fl=fl+"१";
                    }
                    if(currentFeelslike[i]=='2')
                    {
                        fl=fl+"२";
                    }
                    if(currentFeelslike[i]=='3')
                    {
                        fl=fl+"३";
                    }
                    if(currentFeelslike[i]=='4')
                    {
                        fl=fl+"४";
                    }
                    if(currentFeelslike[i]=='5')
                    {
                        fl=fl+"५";
                    }
                    if(currentFeelslike[i]=='6')
                    {
                        fl=fl+"६";
                    }
                    if(currentFeelslike[i]=='7')
                    {
                        fl=fl+"७";
                    }
                    if(currentFeelslike[i]=='8')
                    {
                        fl=fl+"८";
                    }
                    if(currentFeelslike[i]=='9')
                    {
                        fl=fl+"९";
                    }
                    if(currentFeelslike[i]=='.')
                    {
                        fl=fl+".";
                    }
                }
                ui->feelslike1->setText(fl+"°C");
                ui->currentfl_2->setText(fl+"°C");

                //For current latitude....
                QString lati;
                for(int i=0;i<currentLatitude.length();i++)
                {
                    if(currentLatitude[i]=='0')
                    {
                        lati=lati+"०";
                    }
                    if(currentLatitude[i]=='1')
                    {
                        lati=lati+"१";
                    }
                    if(currentLatitude[i]=='2')
                    {
                        lati=lati+"२";
                    }
                    if(currentLatitude[i]=='3')
                    {
                        lati=lati+"३";
                    }
                    if(currentLatitude[i]=='4')
                    {
                        lati=lati+"४";
                    }
                    if(currentLatitude[i]=='5')
                    {
                        lati=lati+"५";
                    }
                    if(currentLatitude[i]=='6')
                    {
                        lati=lati+"६";
                    }
                    if(currentLatitude[i]=='7')
                    {
                        lati=lati+"७";
                    }
                    if(currentLatitude[i]=='8')
                    {
                        lati=lati+"८";
                    }
                    if(currentLatitude[i]=='9')
                    {
                        lati=lati+"९";
                    }
                    if(currentLatitude[i]=='.')
                    {
                        lati=lati+".";
                    }
                }
                ui->currentlat_2->setText(lati);

                //For current longitude....
                QString longi;
                for(int i=0;i<CurrentLongitude.length();i++)
                {
                    if(CurrentLongitude[i]=='0')
                    {
                        longi=longi+"०";
                    }
                    if(CurrentLongitude[i]=='1')
                    {
                        longi=longi+"१";
                    }
                    if(CurrentLongitude[i]=='2')
                    {
                        longi=longi+"२";
                    }
                    if(CurrentLongitude[i]=='3')
                    {
                        longi=longi+"३";
                    }
                    if(CurrentLongitude[i]=='4')
                    {
                        longi=longi+"४";
                    }
                    if(CurrentLongitude[i]=='5')
                    {
                        longi=longi+"५";
                    }
                    if(CurrentLongitude[i]=='6')
                    {
                        longi=longi+"६";
                    }
                    if(CurrentLongitude[i]=='7')
                    {
                        longi=longi+"७";
                    }
                    if(CurrentLongitude[i]=='8')
                    {
                        longi=longi+"८";
                    }
                    if(CurrentLongitude[i]=='9')
                    {
                        longi=longi+"९";
                    }
                    if(CurrentLongitude[i]=='.')
                    {
                        longi=longi+".";
                    }
                }
                ui->currentlon_2->setText(longi);

                //for future weather1....
                QString Ft1;
                for(int i=0;i<fTempr1.length();i++)
                {
                    if(fTempr1[i]=='0')
                    {
                        Ft1=Ft1+"०";
                    }
                    if(fTempr1[i]=='1')
                    {
                        Ft1=Ft1+"१";
                    }
                    if(fTempr1[i]=='2')
                    {
                        Ft1=Ft1+"२";
                    }
                    if(fTempr1[i]=='3')
                    {
                        Ft1=Ft1+"३";
                    }
                    if(fTempr1[i]=='4')
                    {
                        Ft1=Ft1+"४";
                    }
                    if(fTempr1[i]=='5')
                    {
                        Ft1=Ft1+"५";
                    }
                    if(fTempr1[i]=='6')
                    {
                        Ft1=Ft1+"६";
                    }
                    if(fTempr1[i]=='7')
                    {
                        Ft1=Ft1+"७";
                    }
                    if(fTempr1[i]=='8')
                    {
                        Ft1=Ft1+"८";
                    }
                    if(fTempr1[i]=='9')
                    {
                        Ft1=Ft1+"९";
                    }
                    if(fTempr1[i]=='.')
                    {
                        Ft1=Ft1+".";
                    }
                }
                ui->fTemp1->setText(Ft1+"°C");

                QString D1;
                for(int i=0;i<Date1.length();i++)
                {
                    if(Date1[i]=='0')
                    {
                        D1=D1+"०";
                    }
                    if(Date1[i]=='1')
                    {
                        D1=D1+"१";
                    }
                    if(Date1[i]=='2')
                    {
                        D1=D1+"२";
                    }
                    if(Date1[i]=='3')
                    {
                        D1=D1+"३";
                    }
                    if(Date1[i]=='4')
                    {
                        D1=D1+"४";
                    }
                    if(Date1[i]=='5')
                    {
                        D1=D1+"५";
                    }
                    if(Date1[i]=='6')
                    {
                        D1=D1+"६";
                    }
                    if(Date1[i]=='7')
                    {
                        D1=D1+"७";
                    }
                    if(Date1[i]=='8')
                    {
                        D1=D1+"८";
                    }
                    if(Date1[i]=='9')
                    {
                        D1=D1+"९";
                    }
                }
                if(mon1=="Jan")
                {
                    ui->fDate1->setText("जनवरी  "+D1);
                }
                if(mon1=="Feb")
                {
                    ui->fDate1->setText("फेब्रुअरी  "+D1);
                }
                if(mon1=="Mar")
                {
                    ui->fDate1->setText("मार्च  "+D1);
                }
                if(mon1=="Apr")
                {
                    ui->fDate1->setText("अप्रिल  "+D1);
                }
                if(mon1=="May")
                {
                    ui->fDate1->setText("मे  "+D1);
                }
                if(mon1=="June")
                {
                    ui->fDate1->setText("जून  "+D1);
                }
                if(mon1=="July")
                {
                    ui->fDate1->setText("जुलाई  "+D1);
                }
                if(mon1=="Aug")
                {
                    ui->fDate1->setText("अगस्ट  "+D1);
                }
                if(mon1=="Sep")
                {
                    ui->fDate1->setText("सेप्टेम्बर  "+D1);
                }
                if(mon1=="Oct")
                {
                    ui->fDate1->setText("अक्टोबर  "+D1);
                }
                if(mon1=="Nov")
                {
                    ui->fDate1->setText("नोभेम्बर  "+D1);
                }
                if(mon1=="Dec")
                {
                    ui->fDate1->setText("डिसेम्बर  "+D1);
                }

                if(fweather1=="Clouds")
                {
                    ui->fWeather1->setText("बादल");
                }
                if(fweather1=="Rain")
                {
                    ui->fWeather1->setText("वर्षा");
                }
                if(fweather1=="Thunderstorm")
                {
                    ui->fWeather1->setText("चट्याङ");
                }
                if(fweather1=="Drizzle")
                {
                    ui->fWeather1->setText("मुसलधारे पानी");
                }
                if(fweather1=="Mist"||fweather1=="Haze"||fweather1=="Fog")
                {
                    ui->fWeather1->setText("कुहिरो");
                }
                if(fweather1=="Clear")
                {
                    ui->fWeather1->setText("सफा मौसम");
                }
                if(fweather1=="Smoke")
                {
                    ui->fWeather1->setText("धुवाँ");
                }
                if(fweather1=="Snow")
                {
                    ui->fWeather1->setText("हिउँ");
                }
                if(fweather1=="Dust"||fweather1=="Sand"||fweather1=="Ash")
                {
                    ui->fWeather1->setText("धुलो");
                }
                if(fweather1=="Tornado")
                {
                    ui->fWeather1->setText("भुमरी");
                }
                if(fweather1=="Squall")
                {
                    ui->fWeather1->setText("तूफान");
                }

                //For future weather2.....

                QString Ft2;
                for(int i=0;i<fTempr2.length();i++)
                {
                    if(fTempr2[i]=='0')
                    {
                        Ft2=Ft2+"०";
                    }
                    if(fTempr2[i]=='1')
                    {
                        Ft2=Ft2+"१";
                    }
                    if(fTempr2[i]=='2')
                    {
                        Ft2=Ft2+"२";
                    }
                    if(fTempr2[i]=='3')
                    {
                        Ft2=Ft2+"३";
                    }
                    if(fTempr2[i]=='4')
                    {
                        Ft2=Ft2+"४";
                    }
                    if(fTempr2[i]=='5')
                    {
                        Ft2=Ft2+"५";
                    }
                    if(fTempr2[i]=='6')
                    {
                        Ft2=Ft2+"६";
                    }
                    if(fTempr2[i]=='7')
                    {
                        Ft2=Ft2+"७";
                    }
                    if(fTempr2[i]=='8')
                    {
                        Ft2=Ft2+"८";
                    }
                    if(fTempr2[i]=='9')
                    {
                        Ft2=Ft2+"९";
                    }
                    if(fTempr2[i]=='.')
                    {
                        Ft2=Ft2+".";
                    }
                }
                ui->fTemp2->setText(Ft2+"°C");

                QString D2;
                for(int i=0;i<Date2.length();i++)
                {
                    if(Date2[i]=='0')
                    {
                        D2=D2+"०";
                    }
                    if(Date2[i]=='1')
                    {
                        D2=D2+"१";
                    }
                    if(Date2[i]=='2')
                    {
                        D2=D2+"२";
                    }
                    if(Date2[i]=='3')
                    {
                        D2=D2+"३";
                    }
                    if(Date2[i]=='4')
                    {
                        D2=D2+"४";
                    }
                    if(Date2[i]=='5')
                    {
                        D2=D2+"५";
                    }
                    if(Date2[i]=='6')
                    {
                        D2=D2+"६";
                    }
                    if(Date2[i]=='7')
                    {
                        D2=D2+"७";
                    }
                    if(Date2[i]=='8')
                    {
                        D2=D2+"८";
                    }
                    if(Date2[i]=='9')
                    {
                        D2=D2+"९";
                    }
                }
                if(mon2=="Jan")
                {
                    ui->fDate2->setText("जनवरी  "+D2);
                }
                if(mon2=="Feb")
                {
                    ui->fDate2->setText("फेब्रुअरी  "+D2);
                }
                if(mon2=="Mar")
                {
                    ui->fDate2->setText("मार्च  "+D2);
                }
                if(mon2=="Apr")
                {
                    ui->fDate2->setText("अप्रिल  "+D2);
                }
                if(mon2=="May")
                {
                    ui->fDate2->setText("मे  "+D2);
                }
                if(mon2=="June")
                {
                    ui->fDate2->setText("जून  "+D2);
                }
                if(mon2=="July")
                {
                    ui->fDate2->setText("जुलाई  "+D2);
                }
                if(mon2=="Aug")
                {
                    ui->fDate2->setText("अगस्ट  "+D2);
                }
                if(mon2=="Sep")
                {
                    ui->fDate2->setText("सेप्टेम्बर  "+D2);
                }
                if(mon2=="Oct")
                {
                    ui->fDate2->setText("अक्टोबर  "+D2);
                }
                if(mon2=="Nov")
                {
                    ui->fDate2->setText("नोभेम्बर  "+D2);
                }
                if(mon2=="Dec")
                {
                    ui->fDate2->setText("डिसेम्बर  "+D2);
                }

                if(fweather2=="Clouds")
                {
                    ui->fWeather2->setText("बादल");
                }
                if(fweather2=="Rain")
                {
                    ui->fWeather2->setText("वर्षा");
                }
                if(fweather2=="Thunderstorm")
                {
                    ui->fWeather2->setText("चट्याङ");
                }
                if(fweather2=="Drizzle")
                {
                    ui->fWeather2->setText("मुसलधारे पानी");
                }
                if(fweather2=="Mist"||fweather2=="Haze"||fweather2=="Fog")
                {
                    ui->fWeather2->setText("कुहिरो");
                }
                if(fweather2=="Clear")
                {
                    ui->fWeather2->setText("सफा मौसम");
                }
                if(fweather2=="Smoke")
                {
                    ui->fWeather2->setText("धुवाँ");
                }
                if(fweather2=="Snow")
                {
                    ui->fWeather2->setText("हिउँ");
                }
                if(fweather2=="Dust"||fweather2=="Sand"||fweather2=="Ash")
                {
                    ui->fWeather2->setText("धुलो");
                }
                if(fweather2=="Tornado")
                {
                    ui->fWeather2->setText("भुमरी");
                }
                if(fweather2=="Squall")
                {
                    ui->fWeather2->setText("तूफान");
                }

                //For future weather3......

                QString Ft3;
                for(int i=0;i<fTempr3.length();i++)
                {
                    if(fTempr3[i]=='0')
                    {
                        Ft3=Ft3+"०";
                    }
                    if(fTempr3[i]=='1')
                    {
                        Ft3=Ft3+"१";
                    }
                    if(fTempr3[i]=='2')
                    {
                        Ft3=Ft3+"२";
                    }
                    if(fTempr3[i]=='3')
                    {
                        Ft3=Ft3+"३";
                    }
                    if(fTempr3[i]=='4')
                    {
                        Ft3=Ft3+"४";
                    }
                    if(fTempr3[i]=='5')
                    {
                        Ft3=Ft3+"५";
                    }
                    if(fTempr3[i]=='6')
                    {
                        Ft3=Ft3+"६";
                    }
                    if(fTempr3[i]=='7')
                    {
                        Ft3=Ft3+"७";
                    }
                    if(fTempr3[i]=='8')
                    {
                        Ft3=Ft3+"८";
                    }
                    if(fTempr3[i]=='9')
                    {
                        Ft3=Ft3+"९";
                    }
                    if(fTempr3[i]=='.')
                    {
                        Ft3=Ft3+".";
                    }
                }
                ui->fTemp3->setText(Ft3+"°C");

                QString D3;
                for(int i=0;i<Date3.length();i++)
                {
                    if(Date3[i]=='0')
                    {
                        D3=D3+"०";
                    }
                    if(Date3[i]=='1')
                    {
                        D3=D3+"१";
                    }
                    if(Date3[i]=='2')
                    {
                        D3=D3+"२";
                    }
                    if(Date3[i]=='3')
                    {
                        D3=D3+"३";
                    }
                    if(Date3[i]=='4')
                    {
                        D3=D3+"४";
                    }
                    if(Date3[i]=='5')
                    {
                        D3=D3+"५";
                    }
                    if(Date3[i]=='6')
                    {
                        D3=D3+"६";
                    }
                    if(Date3[i]=='7')
                    {
                        D3=D3+"७";
                    }
                    if(Date3[i]=='8')
                    {
                        D3=D3+"८";
                    }
                    if(Date3[i]=='9')
                    {
                        D3=D3+"९";
                    }
                }
                if(mon3=="Jan")
                {
                    ui->fDate3->setText("जनवरी  "+D3);
                }
                if(mon3=="Feb")
                {
                    ui->fDate3->setText("फेब्रुअरी  "+D3);
                }
                if(mon3=="Mar")
                {
                    ui->fDate3->setText("मार्च  "+D3);
                }
                if(mon3=="Apr")
                {
                    ui->fDate3->setText("अप्रिल  "+D3);
                }
                if(mon3=="May")
                {
                    ui->fDate3->setText("मे  "+D3);
                }
                if(mon3=="June")
                {
                    ui->fDate3->setText("जून  "+D3);
                }
                if(mon3=="July")
                {
                    ui->fDate3->setText("जुलाई  "+D3);
                }
                if(mon3=="Aug")
                {
                    ui->fDate3->setText("अगस्ट  "+D3);
                }
                if(mon3=="Sep")
                {
                    ui->fDate3->setText("सेप्टेम्बर  "+D3);
                }
                if(mon3=="Oct")
                {
                    ui->fDate3->setText("अक्टोबर  "+D3);
                }
                if(mon3=="Nov")
                {
                    ui->fDate3->setText("नोभेम्बर  "+D3);
                }
                if(mon3=="Dec")
                {
                    ui->fDate3->setText("डिसेम्बर  "+D3);
                }

                if(fweather3=="Clouds")
                {
                    ui->fWeather3->setText("बादल");
                }
                if(fweather3=="Rain")
                {
                    ui->fWeather3->setText("वर्षा");
                }
                if(fweather3=="Thunderstorm")
                {
                    ui->fWeather3->setText("चट्याङ");
                }
                if(fweather3=="Drizzle")
                {
                    ui->fWeather3->setText("मुसलधारे पानी");
                }
                if(fweather3=="Mist"||fweather3=="Haze"||fweather3=="Fog")
                {
                    ui->fWeather3->setText("कुहिरो");
                }
                if(fweather3=="Clear")
                {
                    ui->fWeather3->setText("सफा मौसम");
                }
                if(fweather3=="Smoke")
                {
                    ui->fWeather3->setText("धुवाँ");
                }
                if(fweather3=="Snow")
                {
                    ui->fWeather3->setText("हिउँ");
                }
                if(fweather3=="Dust"||fweather3=="Sand"||fweather3=="Ash")
                {
                    ui->fWeather3->setText("धुलो");
                }
                if(fweather3=="Tornado")
                {
                    ui->fWeather3->setText("भुमरी");
                }
                if(fweather3=="Squall")
                {
                    ui->fWeather3->setText("तूफान");
                }

                //For Present Weather1.....
                if(weather1!="")
                {
                    QString t1;
                    for(int i=0;i<Tempr1.length();i++)
                    {
                        if(Tempr1[i]=='0')
                        {
                            t1=t1+"०";
                        }
                        if(Tempr1[i]=='1')
                        {
                            t1=t1+"१";
                        }
                        if(Tempr1[i]=='2')
                        {
                            t1=t1+"२";
                        }
                        if(Tempr1[i]=='3')
                        {
                            t1=t1+"३";
                        }
                        if(Tempr1[i]=='4')
                        {
                            t1=t1+"४";
                        }
                        if(Tempr1[i]=='5')
                        {
                            t1=t1+"५";
                        }
                        if(Tempr1[i]=='6')
                        {
                            t1=t1+"६";
                        }
                        if(Tempr1[i]=='7')
                        {
                            t1=t1+"७";
                        }
                        if(Tempr1[i]=='8')
                        {
                            t1=t1+"८";
                        }
                        if(Tempr1[i]=='9')
                        {
                            t1=t1+"९";
                        }
                        if(Tempr1[i]=='.')
                        {
                            t1=t1+".";
                        }
                    }
                    ui->temp1->setText(t1+"°C");

                    QString h1;
                    for(int i=0;i<Hour1.length();i++)
                    {
                        if(Hour1[i]=='0')
                        {
                            h1=h1+"०";
                        }
                        if(Hour1[i]=='1')
                        {
                            h1=h1+"१";
                        }
                        if(Hour1[i]=='2')
                        {
                            h1=h1+"२";
                        }
                        if(Hour1[i]=='3')
                        {
                            h1=h1+"३";
                        }
                        if(Hour1[i]=='4')
                        {
                            h1=h1+"४";
                        }
                        if(Hour1[i]=='5')
                        {
                            h1=h1+"५";
                        }
                        if(Hour1[i]=='6')
                        {
                            h1=h1+"६";
                        }
                        if(Hour1[i]=='7')
                        {
                            h1=h1+"७";
                        }
                        if(Hour1[i]=='8')
                        {
                            h1=h1+"८";
                        }
                        if(Hour1[i]=='9')
                        {
                            h1=h1+"९";
                        }
                    }

                    QString m1;
                    for(int i=0;i<Min1.length();i++)
                    {
                        if(Min1[i]=='0')
                        {
                            m1=m1+"०";
                        }
                        if(Min1[i]=='1')
                        {
                            m1=m1+"१";
                        }
                        if(Min1[i]=='2')
                        {
                            m1=m1+"२";
                        }
                        if(Min1[i]=='3')
                        {
                            m1=m1+"३";
                        }
                        if(Min1[i]=='4')
                        {
                            m1=m1+"४";
                        }
                        if(Min1[i]=='5')
                        {
                            m1=m1+"५";
                        }
                        if(Min1[i]=='6')
                        {
                            m1=m1+"६";
                        }
                        if(Min1[i]=='7')
                        {
                            m1=m1+"७";
                        }
                        if(Min1[i]=='8')
                        {
                            m1=m1+"८";
                        }
                        if(Min1[i]=='9')
                        {
                            m1=m1+"९";
                        }
                    }
                    ui->time1->setText(h1+":"+m1);

                    if(weather1=="Clouds")
                    {
                        ui->weather1->setText("बादल");
                    }
                    if(weather1=="Rain")
                    {
                        ui->weather1->setText("वर्षा");
                    }
                    if(weather1=="Thunderstorm")
                    {
                        ui->weather1->setText("चट्याङ");
                    }
                    if(weather1=="Drizzle")
                    {
                        ui->weather1->setText("मुसलधारे पानी");
                    }
                    if(weather1=="Mist"||weather1=="Haze"||weather1=="Fog")
                    {
                        ui->weather1->setText("कुहिरो");
                    }
                    if(weather1=="Clear")
                    {
                        ui->weather1->setText("सफा मौसम");
                    }
                    if(weather1=="Smoke")
                    {
                        ui->weather1->setText("धुवाँ");
                    }
                    if(weather1=="Snow")
                    {
                        ui->weather1->setText("हिउँ");
                    }
                    if(weather1=="Dust"||weather1=="Sand"||weather1=="Ash")
                    {
                        ui->weather1->setText("धुलो");
                    }
                    if(weather1=="Tornado")
                    {
                        ui->weather1->setText("भुमरी");
                    }
                    if(weather1=="Squall")
                    {
                        ui->weather1->setText("तूफान");
                    }
                }
                else
                {
                    ui->weather1->setText("-");
                    ui->temp1->setText("-");
                    ui->time1->setText("-");
                }

                //For present weather2....
                if(weather2!="")
                {
                    QString t2;
                    for(int i=0;i<Tempr2.length();i++)
                    {
                        if(Tempr2[i]=='0')
                        {
                            t2=t2+"०";
                        }
                        if(Tempr2[i]=='1')
                        {
                            t2=t2+"१";
                        }
                        if(Tempr2[i]=='2')
                        {
                            t2=t2+"२";
                        }
                        if(Tempr2[i]=='3')
                        {
                            t2=t2+"३";
                        }
                        if(Tempr2[i]=='4')
                        {
                            t2=t2+"४";
                        }
                        if(Tempr2[i]=='5')
                        {
                            t2=t2+"५";
                        }
                        if(Tempr2[i]=='6')
                        {
                            t2=t2+"६";
                        }
                        if(Tempr2[i]=='7')
                        {
                            t2=t2+"७";
                        }
                        if(Tempr2[i]=='8')
                        {
                            t2=t2+"८";
                        }
                        if(Tempr2[i]=='9')
                        {
                            t2=t2+"९";
                        }
                        if(Tempr2[i]=='.')
                        {
                            t2=t2+".";
                        }
                    }
                    ui->temp2->setText(t2+"°C");

                    QString h2;
                    for(int i=0;i<Hour2.length();i++)
                    {
                        if(Hour2[i]=='0')
                        {
                            h2=h2+"०";
                        }
                        if(Hour2[i]=='1')
                        {
                            h2=h2+"१";
                        }
                        if(Hour2[i]=='2')
                        {
                            h2=h2+"२";
                        }
                        if(Hour2[i]=='3')
                        {
                            h2=h2+"३";
                        }
                        if(Hour2[i]=='4')
                        {
                            h2=h2+"४";
                        }
                        if(Hour2[i]=='5')
                        {
                            h2=h2+"५";
                        }
                        if(Hour2[i]=='6')
                        {
                            h2=h2+"६";
                        }
                        if(Hour2[i]=='7')
                        {
                            h2=h2+"७";
                        }
                        if(Hour2[i]=='8')
                        {
                            h2=h2+"८";
                        }
                        if(Hour2[i]=='9')
                        {
                            h2=h2+"९";
                        }
                    }

                    QString m2;
                    for(int i=0;i<Min2.length();i++)
                    {
                        if(Min2[i]=='0')
                        {
                            m2=m2+"०";
                        }
                        if(Min2[i]=='1')
                        {
                            m2=m2+"१";
                        }
                        if(Min2[i]=='2')
                        {
                            m2=m2+"२";
                        }
                        if(Min2[i]=='3')
                        {
                            m2=m2+"३";
                        }
                        if(Min2[i]=='4')
                        {
                            m2=m2+"४";
                        }
                        if(Min2[i]=='5')
                        {
                            m2=m2+"५";
                        }
                        if(Min2[i]=='6')
                        {
                            m2=m2+"६";
                        }
                        if(Min2[i]=='7')
                        {
                            m2=m2+"७";
                        }
                        if(Min2[i]=='8')
                        {
                            m2=m2+"८";
                        }
                        if(Min2[i]=='9')
                        {
                            m2=m2+"९";
                        }
                    }
                    ui->time2->setText(h2+":"+m2);

                    if(weather2=="Clouds")
                    {
                        ui->weather2->setText("बादल");
                    }
                    if(weather2=="Rain")
                    {
                        ui->weather2->setText("वर्षा");
                    }
                    if(weather2=="Thunderstorm")
                    {
                        ui->weather2->setText("चट्याङ");
                    }
                    if(weather2=="Drizzle")
                    {
                        ui->weather2->setText("मुसलधारे पानी");
                    }
                    if(weather2=="Mist"||weather2=="Haze"||weather2=="Fog")
                    {
                        ui->weather2->setText("कुहिरो");
                    }
                    if(weather2=="Clear")
                    {
                        ui->weather2->setText("सफा मौसम");
                    }
                    if(weather2=="Smoke")
                    {
                        ui->weather2->setText("धुवाँ");
                    }
                    if(weather2=="Snow")
                    {
                        ui->weather2->setText("हिउँ");
                    }
                    if(weather2=="Dust"||weather2=="Sand"||weather2=="Ash")
                    {
                        ui->weather2->setText("धुलो");
                    }
                    if(weather2=="Tornado")
                    {
                        ui->weather2->setText("भुमरी");
                    }
                    if(weather2=="Squall")
                    {
                        ui->weather2->setText("तूफान");
                    }
                }
                else
                {
                    ui->weather2->setText("-");
                    ui->temp2->setText("-");
                    ui->time2->setText("-");
                }

                //For present weather3.....
                if(weather3!="")
                {
                    QString t3;
                    for(int i=0;i<Tempr3.length();i++)
                    {
                        if(Tempr3[i]=='0')
                        {
                            t3=t3+"०";
                        }
                        if(Tempr3[i]=='1')
                        {
                            t3=t3+"१";
                        }
                        if(Tempr3[i]=='2')
                        {
                            t3=t3+"२";
                        }
                        if(Tempr3[i]=='3')
                        {
                            t3=t3+"३";
                        }
                        if(Tempr3[i]=='4')
                        {
                            t3=t3+"४";
                        }
                        if(Tempr3[i]=='5')
                        {
                            t3=t3+"५";
                        }
                        if(Tempr3[i]=='6')
                        {
                            t3=t3+"६";
                        }
                        if(Tempr3[i]=='7')
                        {
                            t3=t3+"७";
                        }
                        if(Tempr3[i]=='8')
                        {
                            t3=t3+"८";
                        }
                        if(Tempr3[i]=='9')
                        {
                            t3=t3+"९";
                        }
                        if(Tempr3[i]=='.')
                        {
                            t3=t3+".";
                        }
                    }
                    ui->temp3->setText(t3+"°C");

                    QString h3;
                    for(int i=0;i<Hour3.length();i++)
                    {
                        if(Hour3[i]=='0')
                        {
                            h3=h3+"०";
                        }
                        if(Hour3[i]=='1')
                        {
                            h3=h3+"१";
                        }
                        if(Hour3[i]=='2')
                        {
                            h3=h3+"२";
                        }
                        if(Hour3[i]=='3')
                        {
                            h3=h3+"३";
                        }
                        if(Hour3[i]=='4')
                        {
                            h3=h3+"४";
                        }
                        if(Hour3[i]=='5')
                        {
                            h3=h3+"५";
                        }
                        if(Hour3[i]=='6')
                        {
                            h3=h3+"६";
                        }
                        if(Hour3[i]=='7')
                        {
                            h3=h3+"७";
                        }
                        if(Hour3[i]=='8')
                        {
                            h3=h3+"८";
                        }
                        if(Hour3[i]=='9')
                        {
                            h3=h3+"९";
                        }
                    }

                    QString m3;
                    for(int i=0;i<Min3.length();i++)
                    {
                        if(Min3[i]=='0')
                        {
                            m3=m3+"०";
                        }
                        if(Min3[i]=='1')
                        {
                            m3=m3+"१";
                        }
                        if(Min3[i]=='2')
                        {
                            m3=m3+"२";
                        }
                        if(Min3[i]=='3')
                        {
                            m3=m3+"३";
                        }
                        if(Min3[i]=='4')
                        {
                            m3=m3+"४";
                        }
                        if(Min3[i]=='5')
                        {
                            m3=m3+"५";
                        }
                        if(Min3[i]=='6')
                        {
                            m3=m3+"६";
                        }
                        if(Min3[i]=='7')
                        {
                            m3=m3+"७";
                        }
                        if(Min3[i]=='8')
                        {
                            m3=m3+"८";
                        }
                        if(Min3[i]=='9')
                        {
                            m3=m3+"९";
                        }
                    }
                    ui->time3->setText(h3+":"+m3);

                    if(weather3=="Clouds")
                    {
                        ui->weather3->setText("बादल");
                    }
                    if(weather3=="Rain")
                    {
                        ui->weather3->setText("वर्षा");
                    }
                    if(weather3=="Thunderstorm")
                    {
                        ui->weather3->setText("चट्याङ");
                    }
                    if(weather3=="Drizzle")
                    {
                        ui->weather3->setText("मुसलधारे पानी");
                    }
                    if(weather3=="Mist"||weather3=="Haze"||weather3=="Fog")
                    {
                        ui->weather3->setText("कुहिरो");
                    }
                    if(weather3=="Clear")
                    {
                        ui->weather3->setText("सफा मौसम");
                    }
                    if(weather3=="Smoke")
                    {
                        ui->weather3->setText("धुवाँ");
                    }
                    if(weather3=="Snow")
                    {
                        ui->weather3->setText("हिउँ");
                    }
                    if(weather3=="Dust"||weather3=="Sand"||weather3=="Ash")
                    {
                        ui->weather3->setText("धुलो");
                    }
                    if(weather3=="Tornado")
                    {
                        ui->weather3->setText("भुमरी");
                    }
                    if(weather3=="Squall")
                    {
                        ui->weather3->setText("तूफान");
                    }
                }
                else
                {
                    ui->weather3->setText("-");
                    ui->temp3->setText("-");
                    ui->time3->setText("-");
                }

                //For present weather4.....
                if(weather4!="")
                {
                    QString t4;
                    for(int i=0;i<Tempr4.length();i++)
                    {
                        if(Tempr4[i]=='0')
                        {
                            t4=t4+"०";
                        }
                        if(Tempr4[i]=='1')
                        {
                            t4=t4+"१";
                        }
                        if(Tempr4[i]=='2')
                        {
                            t4=t4+"२";
                        }
                        if(Tempr4[i]=='3')
                        {
                            t4=t4+"३";
                        }
                        if(Tempr4[i]=='4')
                        {
                            t4=t4+"४";
                        }
                        if(Tempr4[i]=='5')
                        {
                            t4=t4+"५";
                        }
                        if(Tempr4[i]=='6')
                        {
                            t4=t4+"६";
                        }
                        if(Tempr4[i]=='7')
                        {
                            t4=t4+"७";
                        }
                        if(Tempr4[i]=='8')
                        {
                            t4=t4+"८";
                        }
                        if(Tempr4[i]=='9')
                        {
                            t4=t4+"९";
                        }
                        if(Tempr4[i]=='.')
                        {
                            t4=t4+".";
                        }
                    }
                    ui->temp4->setText(t4+"°C");

                    QString h4;
                    for(int i=0;i<Hour4.length();i++)
                    {
                        if(Hour4[i]=='0')
                        {
                            h4=h4+"०";
                        }
                        if(Hour4[i]=='1')
                        {
                            h4=h4+"१";
                        }
                        if(Hour4[i]=='2')
                        {
                            h4=h4+"२";
                        }
                        if(Hour4[i]=='3')
                        {
                            h4=h4+"३";
                        }
                        if(Hour4[i]=='4')
                        {
                            h4=h4+"४";
                        }
                        if(Hour4[i]=='5')
                        {
                            h4=h4+"५";
                        }
                        if(Hour4[i]=='6')
                        {
                            h4=h4+"६";
                        }
                        if(Hour4[i]=='7')
                        {
                            h4=h4+"७";
                        }
                        if(Hour4[i]=='8')
                        {
                            h4=h4+"८";
                        }
                        if(Hour4[i]=='9')
                        {
                            h4=h4+"९";
                        }
                    }

                    QString m4;
                    for(int i=0;i<Min4.length();i++)
                    {
                        if(Min4[i]=='0')
                        {
                            m4=m4+"०";
                        }
                        if(Min4[i]=='1')
                        {
                            m4=m4+"१";
                        }
                        if(Min4[i]=='2')
                        {
                            m4=m4+"२";
                        }
                        if(Min4[i]=='3')
                        {
                            m4=m4+"३";
                        }
                        if(Min4[i]=='4')
                        {
                            m4=m4+"४";
                        }
                        if(Min4[i]=='5')
                        {
                            m4=m4+"५";
                        }
                        if(Min4[i]=='6')
                        {
                            m4=m4+"६";
                        }
                        if(Min4[i]=='7')
                        {
                            m4=m4+"७";
                        }
                        if(Min4[i]=='8')
                        {
                            m4=m4+"८";
                        }
                        if(Min4[i]=='9')
                        {
                            m4=m4+"९";
                        }
                    }
                    ui->time4->setText(h4+":"+m4);

                    if(weather4=="Clouds")
                    {
                        ui->weather4->setText("बादल");
                    }
                    if(weather4=="Rain")
                    {
                        ui->weather4->setText("वर्षा");
                    }
                    if(weather4=="Thunderstorm")
                    {
                        ui->weather4->setText("चट्याङ");
                    }
                    if(weather4=="Drizzle")
                    {
                        ui->weather4->setText("मुसलधारे पानी");
                    }
                    if(weather4=="Mist"||weather4=="Haze"||weather4=="Fog")
                    {
                        ui->weather4->setText("कुहिरो");
                    }
                    if(weather4=="Clear")
                    {
                        ui->weather4->setText("सफा मौसम");
                    }
                    if(weather4=="Smoke")
                    {
                        ui->weather4->setText("धुवाँ");
                    }
                    if(weather4=="Snow")
                    {
                        ui->weather4->setText("हिउँ");
                    }
                    if(weather4=="Dust"||weather4=="Sand"||weather4=="Ash")
                    {
                        ui->weather4->setText("धुलो");
                    }
                    if(weather4=="Tornado")
                    {
                        ui->weather4->setText("भुमरी");
                    }
                    if(weather4=="Squall")
                    {
                        ui->weather4->setText("तूफान");
                    }
                }
                else
                {
                    ui->weather4->setText("-");
                    ui->temp4->setText("-");
                    ui->time4->setText("-");
                }

                //For present weather5....
                if(weather5!="")
                {
                    QString t5;
                    for(int i=0;i<Tempr5.length();i++)
                    {
                        if(Tempr5[i]=='0')
                        {
                            t5=t5+"०";
                        }
                        if(Tempr5[i]=='1')
                        {
                            t5=t5+"१";
                        }
                        if(Tempr5[i]=='2')
                        {
                            t5=t5+"२";
                        }
                        if(Tempr5[i]=='3')
                        {
                            t5=t5+"३";
                        }
                        if(Tempr5[i]=='4')
                        {
                            t5=t5+"४";
                        }
                        if(Tempr5[i]=='5')
                        {
                            t5=t5+"५";
                        }
                        if(Tempr5[i]=='6')
                        {
                            t5=t5+"६";
                        }
                        if(Tempr5[i]=='7')
                        {
                            t5=t5+"७";
                        }
                        if(Tempr5[i]=='8')
                        {
                            t5=t5+"८";
                        }
                        if(Tempr5[i]=='9')
                        {
                            t5=t5+"९";
                        }
                        if(Tempr5[i]=='.')
                        {
                            t5=t5+".";
                        }
                    }
                    ui->temp5->setText(t5+"°C");

                    QString h5;
                    for(int i=0;i<Hour5.length();i++)
                    {
                        if(Hour5[i]=='0')
                        {
                            h5=h5+"०";
                        }
                        if(Hour5[i]=='1')
                        {
                            h5=h5+"१";
                        }
                        if(Hour5[i]=='2')
                        {
                            h5=h5+"२";
                        }
                        if(Hour5[i]=='3')
                        {
                            h5=h5+"३";
                        }
                        if(Hour5[i]=='4')
                        {
                            h5=h5+"४";
                        }
                        if(Hour5[i]=='5')
                        {
                            h5=h5+"५";
                        }
                        if(Hour5[i]=='6')
                        {
                            h5=h5+"६";
                        }
                        if(Hour5[i]=='7')
                        {
                            h5=h5+"७";
                        }
                        if(Hour5[i]=='8')
                        {
                            h5=h5+"८";
                        }
                        if(Hour5[i]=='9')
                        {
                            h5=h5+"९";
                        }
                    }

                    QString m5;
                    for(int i=0;i<Min5.length();i++)
                    {
                        if(Min5[i]=='0')
                        {
                            m5=m5+"०";
                        }
                        if(Min5[i]=='1')
                        {
                            m5=m5+"१";
                        }
                        if(Min5[i]=='2')
                        {
                            m5=m5+"२";
                        }
                        if(Min5[i]=='3')
                        {
                            m5=m5+"३";
                        }
                        if(Min5[i]=='4')
                        {
                            m5=m5+"४";
                        }
                        if(Min5[i]=='5')
                        {
                            m5=m5+"५";
                        }
                        if(Min5[i]=='6')
                        {
                            m5=m5+"६";
                        }
                        if(Min5[i]=='7')
                        {
                            m5=m5+"७";
                        }
                        if(Min5[i]=='8')
                        {
                            m5=m5+"८";
                        }
                        if(Min5[i]=='9')
                        {
                            m5=m5+"९";
                        }
                    }
                    ui->time5->setText(h5+":"+m5);

                    if(weather5=="Clouds")
                    {
                        ui->weather5->setText("बादल");
                    }
                    if(weather5=="Rain")
                    {
                        ui->weather5->setText("वर्षा");
                    }
                    if(weather5=="Thunderstorm")
                    {
                        ui->weather5->setText("चट्याङ");
                    }
                    if(weather5=="Drizzle")
                    {
                        ui->weather5->setText("मुसलधारे पानी");
                    }
                    if(weather5=="Mist"||weather5=="Haze"||weather5=="Fog")
                    {
                        ui->weather5->setText("कुहिरो");
                    }
                    if(weather5=="Clear")
                    {
                        ui->weather5->setText("सफा मौसम");
                    }
                    if(weather5=="Smoke")
                    {
                        ui->weather5->setText("धुवाँ");
                    }
                    if(weather5=="Snow")
                    {
                        ui->weather5->setText("हिउँ");
                    }
                    if(weather5=="Dust"||weather5=="Sand"||weather5=="Ash")
                    {
                        ui->weather5->setText("धुलो");
                    }
                    if(weather5=="Tornado")
                    {
                        ui->weather5->setText("भुमरी");
                    }
                    if(weather5=="Squall")
                    {
                        ui->weather5->setText("तूफान");
                    }
                }
                else
                {
                    ui->weather5->setText("-");
                    ui->temp5->setText("-");
                    ui->time5->setText("-");
                }

                if(notCheck==false)
                {
                    if(status_string == "Clouds"){
                        ui->label_notification->setText("गम्भीर मौसमको अपेक्षा छैन।\nतापक्रम चिसो महसुस हुन सक्छ।");
                    }
                    if(status_string == "Thunderstorm")
                    {
                        ui->label_notification->setText("क्षेत्रमा मेघगर्जनको सम्भावना छ।\nभित्रै बस्नुहोस् र बाहिरी गतिविधिहरूबाट टाढा रहनुहोस्।");
                    }
                    if(status_string == "Drizzle")
                    {
                        ui->label_notification->setText("हल्का पानी पर्न सक्ने सम्भावना छ।\nछाता लिनुहोस्।\nसडकहरू चिप्लन सक्छन्।");
                    }
                    if(status_string == "Mist" || status_string == "Haze" || status_string == "Fog")
                    {
                        ui->label_notification->setText("दृश्यता थोरै घट्न सक्दछ।\nध्यानपूर्वक चलाउनुहोस्।");
                    }
                    if(status_string == "Rain")
                    {
                        ui->label_notification->setText("क्षेत्रमा मध्यम वर्षा भइरहेको छ।\nचिप्लने सडक र घटेको दृश्यताका लागि तयार रहनुहोस्।\nगाडी चलाउँदा सतर्क रहनुहोस्।");
                    }
                    if(status_string == "Clear")
                    {
                        ui->label_notification->setText("गम्भीर मौसमको अपेक्षा छैन।\nमौसमको मजा लिनुहोस्।");
                    }
                    if(status_string == "Smoke")
                    {
                        ui->label_notification->setText("क्षेत्रमा हल्का धुँवा छ।\n हवाई गुणस्तर प्रभावित हुन सक्दछ।\nबाहिरी गतिविधिहरू सीमित गर्नुहोस्।");
                    }
                    if(status_string == "Snow")
                    {
                        ui->label_notification->setText("चिप्लने सडकका लागि तयार हुनुहोस्।\nसावधानीपूर्वक गाडी चलाउनुहोस् र न्यानो लुगा लगाउनुहोस्।");
                    }
                    if(status_string=="Dust" || status_string=="Sand" || status_string=="Ash")
                    {
                        ui->label_notification->setText("क्षेत्रमा हल्का धूलो छ।\n हवाई गुणस्तर प्रभावित हुन सक्दछ।\nबाहिरी गतिविधिहरू सीमित गर्नुहोस्।");
                    }
                    if(status_string=="Tornado")
                    {
                        ui->label_notification->setText("तूफान निगरानी प्रभावी छ।\nसम्भावित तूफान का लागि तयार रहनुहोस्।\nमौसम अपडेटहरू अनुगमन गर्नुहोस् र आपतकालीन योजना तयार गर्नुहोस्।");
                    }
                    if(status_string=="Squall")
                    {
                        ui->label_notification->setText("हल्का तुफान नजिकै आइरहेको छ।\nसंक्षिप्त तीव्र हावा र सम्भावित वर्षाका लागि तयार हुनुहोस्।");
                    }
                }
                else
                {

                    ui->label_notification->setText("");
                    ui->label_notification->setStyleSheet("background:transparent;");
                }
            }
            else
            {
                ui->lineEdit_searchbar->setPlaceholderText("Enter the location");
                ui->labelFuture->setText("3 Days Forecast");
                ui->label_temp->setText(temperature+"°C");
                ui->currentTemp_2->setText(temperature+"°C");
                ui->currentTemp->setText("      Temperature");

                ui->currentHum->setText("      Humidity");
                ui->currentfl->setText("      Feels Like");
                ui->humidity1->setText(currentHumidity+"%");
                ui->feelslike1->setText(currentFeelslike+"°C");
                ui->currentHum_2->setText(currentHumidity+"%");
                ui->currentfl_2->setText(currentFeelslike+"°C");

                ui->currentlat->setText("      Latitude");
                ui->currentlon->setText("      Longitude");
                ui->currentlat_2->setText(currentLatitude);
                ui->currentlon_2->setText(CurrentLongitude);

                ui->windspeed1->setText(currentWindSpeed+"km/h");
                ui->current_time->setText(currenthour+":"+currentmin);

                if(notCheck==false)
                {
                    if(status_string == "Clouds"){
                        ui->label_notification->setText("No severe weather expected.\nTemperatures may feel cooler.");
                    }
                    if(status_string == "Thunderstorm")
                    {
                        ui->label_notification->setText("Thunderstorm in the area.\n"
                                                        "Stay indoors and avoid outdoor activities.");
                    }
                    if(status_string == "Drizzle")
                    {
                        ui->label_notification->setText("Light drizzle expected.\n"
                                                        "Carry an umbrella. Roads may be slippery.");
                    }
                    if(status_string == "Mist" || status_string == "Haze" || status_string == "Fog")
                    {
                        ui->label_notification->setText("Visibility may be slightly reduced.\nDrive carefully.");
                    }
                    if(status_string == "Rain")
                    {
                        ui->label_notification->setText("Moderate rain in the area.\n"
                                                        "Prepare for slippery roads and reduced visibility.\n"
                                                        "Be cautious while driving.");
                    }
                    if(status_string == "Clear")
                    {
                        ui->label_notification->setText("No severe weather expected.\nEnjoy the weather.");
                    }
                    if(status_string == "Smoke")
                    {
                        ui->label_notification->setText("Light smoke in the area.\n"
                                                        "Air quality may be affected.\n"
                                                        "Limit outdoor activities.");
                    }
                    if(status_string == "Snow")
                    {
                        ui->label_notification->setText("Prepare for slippery roads.\n"
                                                        "Drive cautiously and dress warmly.");
                    }
                    if(status_string=="Dust" || status_string=="Sand" || status_string=="Ash")
                    {
                        ui->label_notification->setText("Light dust in the area.\n"
                                                        "Air quality may be affected.\n"
                                                        "Limit outdoor activities.");
                    }
                    if(status_string=="Tornado")
                    {
                        ui->label_notification->setText("Tornado Watch in effect.\n"
                                                        "Be prepared for possible tornado.\n"
                                                        "Monitor weather updates and have an emergency plan in place.");
                    }
                    if(status_string=="Squall")
                    {
                        ui->label_notification->setText("Light squall approaching.\n"
                                                        "Prepare for brief gusty winds and possible rain.");
                    }
                }
                else
                {

                    ui->label_notification->setText("");
                    ui->label_notification->setStyleSheet("background:transparent;");
                }

                ui->pushButton_flag->setIcon(QIcon(":/new/prefix1/image/Usa.svg"));
                ui->label_currentWeather->setText(weatherStatus);
                if(weatherStatus=="Clouds")
                {
                    if (sunrise<=currentTime && currentTime<sunset)
                    {
                        ui->label_alert->setText("It's a bit \n cloudy today");
                    }
                    else
                    {
                        ui->label_alert->setText("Cloudy night \n ahead");
                    }
                }
                if(weatherStatus=="Thunderstorm")
                {
                    ui->label_alert->setText(" Avoid outdoor \n activities");
                }
                if(weatherStatus=="Drizzle")
                {
                    ui->label_alert->setText("Don't forget \n your raincoat");
                }
                if(weatherStatus=="Mist" || weatherStatus=="Haze" || weatherStatus=="Fog")
                {
                    ui->label_alert->setText("Visibility is \n low");
                }
                if(weatherStatus=="Rain")
                {
                    ui->label_alert->setText("Don't forget \n your umbrella !");
                }
                if(weatherStatus=="Clear")
                {
                    if (sunrise<=currentTime && currentTime<sunset)
                    {
                        ui->label_alert->setText("Enjoy the \n beautiful weather");
                    }
                    else
                    {
                        ui->label_alert->setText("Clear skies \n tonight.");
                    }
                }
                if(weatherStatus=="Smoke")
                {
                    ui->label_alert->setText("Don't forget\n your mask !");
                }
                if(weatherStatus=="Snow")
                {
                    ui->label_alert->setText("Time for some \n winter fun.");
                }
                if(weatherStatus=="Dust" || weatherStatus=="Sand" || weatherStatus=="Ash")
                {
                    ui->label_alert->setText("Consider wearing\n a mask");
                }
                if(weatherStatus=="Tornado")
                {
                    ui->label_alert->setText("Tornado alert! \n Stay indoors");
                }
                if(weatherStatus=="Squall")
                {
                    ui->label_alert->setText("A squall is \n approaching");
                }

                //For future weather1....
                ui->fWeather1->setText(fweather1);
                ui->fTemp1->setText(fTempr1+"°C");
                ui->fDate1->setText(mon1+" "+Date1);

                //For future weather2....
                ui->fWeather2->setText(fweather2);
                ui->fTemp2->setText(fTempr2+"°C");
                ui->fDate2->setText(mon2+" "+Date2);

                //For future weather3.....
                ui->fWeather3->setText(fweather3);
                ui->fTemp3->setText(fTempr3+"°C");
                ui->fDate3->setText(mon3+" "+Date3);

                //For present weather1...
                if(weather1!="")
                {
                    ui->weather1->setText(weather1);
                    ui->temp1->setText(Tempr1+"°C");
                    ui->time1->setText(Hour1+":"+Min1);
                }
                else
                {
                    ui->weather1->setText("-");
                    ui->temp1->setText("-");
                    ui->time1->setText("-");
                }

                //For present weather2....
                if(weather2!="")
                {
                    ui->weather2->setText(weather2);
                    ui->temp2->setText(Tempr2+"°C");
                    ui->time2->setText(Hour2+":"+Min2);
                }
                else
                {
                    ui->weather2->setText("-");
                    ui->temp2->setText("-");
                    ui->time2->setText("-");
                }

                //For present weather3...
                if(weather3!="")
                {
                    ui->weather3->setText(weather3);
                    ui->temp3->setText(Tempr3+"°C");
                    ui->time3->setText(Hour3+":"+Min3);
                }
                else
                {
                    ui->weather3->setText("-");
                    ui->temp3->setText("-");
                    ui->time3->setText("-");
                }

                //For present weather4....
                if(weather4!="")
                {
                    ui->weather4->setText(weather4);
                    ui->temp4->setText(Tempr4+"°C");
                    ui->time4->setText(Hour4+":"+Min4);
                }
                else
                {
                    ui->weather4->setText("-");
                    ui->temp4->setText("-");
                    ui->time4->setText("-");
                }

                //For present weather5.....
                if(weather5!="")
                {
                    ui->weather5->setText(weather5);
                    ui->temp5->setText(Tempr5+"°C");
                    ui->time5->setText(Hour5+":"+Min5);
                }
                else
                {
                    ui->weather5->setText("-");
                    ui->temp5->setText("-");
                    ui->time5->setText("-");
                }
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
        ui->pushButton_flag->setIcon(QIcon(":/new/prefix1/image/Nepal.svg"));
        ui->lineEdit_searchbar->setPlaceholderText("स्थान प्रविष्ट गर्नुहोस्");
        ui->labelFuture->setText("मौसम पूर्वानुमान");
        QString Tempr;
        for(int i=0;i<temperature.length();i++)
        {
            if(temperature[i]=='0')
            {
                Tempr=Tempr+"०";
            }
            if(temperature[i]=='1')
            {
                Tempr=Tempr+"१";
            }
            if(temperature[i]=='2')
            {
                Tempr=Tempr+"२";
            }
            if(temperature[i]=='3')
            {
                Tempr=Tempr+"३";
            }
            if(temperature[i]=='4')
            {
                Tempr=Tempr+"४";
            }
            if(temperature[i]=='5')
            {
                Tempr=Tempr+"५";
            }
            if(temperature[i]=='6')
            {
                Tempr=Tempr+"६";
            }
            if(temperature[i]=='7')
            {
                Tempr=Tempr+"७";
            }
            if(temperature[i]=='8')
            {
                Tempr=Tempr+"८";
            }
            if(temperature[i]=='9')
            {
                Tempr=Tempr+"९";
            }
            if(temperature[i]=='.')
            {
                Tempr=Tempr+".";
            }
        }
        ui->label_temp->setText(Tempr+"°C");
        ui->currentTemp_2->setText(Tempr+"°C");
        ui->currentTemp->setText("      तापक्रम");
        ui->currentHum->setText("      आर्द्रता");
        ui->currentfl->setText("      महसुस हुन्छ");
        ui->currentlat->setText("      अक्षांश");
        ui->currentlon->setText("      देशान्तर");

        if(weatherStatus=="Clouds")
        {
            if (sunrise<=currentTime && currentTime<sunset)
            {
                ui->label_alert->setText("आज बादल  \n लागेको छ।");
            }
            else
            {
                ui->label_alert->setText("बादल लागेको \n छ।");
            }
            ui->label_currentWeather->setText("बादल");
        }
        if(weatherStatus=="Thunderstorm")
        {
            ui->label_currentWeather->setText("चट्याङ");
            ui->label_alert->setText("सम्भव भए बाहिरी  \n गतिविधिहरू नगर्नुहोस्");
        }
        if(weatherStatus=="Drizzle")
        {
            ui->label_currentWeather->setText("मुसलधारे पानी");
            ui->label_alert->setText("आफ्नो रेनकोट \n नबिर्सनुहोस्।");
        }
        if(weatherStatus=="Mist" || weatherStatus=="Haze" || weatherStatus=="Fog")
        {
            ui->label_currentWeather->setText("कुहिरो");
            ui->label_alert->setText("भिजिबिलिटी \n कम छ।");
        }
        if(weatherStatus=="Rain")
        {
            ui->label_currentWeather->setText("वर्षा");
            ui->label_alert->setText("आफ्नो छाता \n नबिर्सनुहोस् !");
        }
        if(weatherStatus=="Clear")
        {
            if (sunrise<=currentTime && currentTime<sunset)
            {
                ui->label_alert->setText("सुन्दर मौसमको \n आनन्द लिनुहोस्।");
            }
            else
            {
                ui->label_alert->setText("आज राती \n सफा आकाश ।");
            }
            ui->label_currentWeather->setText("सफा मौसम");
        }
        if(weatherStatus=="Smoke")
        {
            ui->label_currentWeather->setText("धुवाँ");
            ui->label_alert->setText("आफ्नो मास्क \n नबिर्सनुहोस्!");
        }
        if(weatherStatus=="Snow")
        {
            ui->label_currentWeather->setText("हिउँ");
            ui->label_alert->setText("रमाइलो गर्ने \n समय।");
        }
        if(weatherStatus=="Dust" || weatherStatus=="Sand" || weatherStatus=="Ash")
        {
            ui->label_currentWeather->setText("धुलो");
            ui->label_alert->setText("मास्क लगाउने \n विचार गर्नुहोस्!");
        }
        if(weatherStatus=="Tornado")
        {
            ui->label_currentWeather->setText("भुमरी");
            ui->label_alert->setText("भुमरीको चेतावनी! \n घर भित्रै बस्नुहोस् !");
        }
        if(weatherStatus=="Squall")
        {
            ui->label_currentWeather->setText("तूफान");
            ui->label_alert->setText("तीव्र हावा र \n वर्षाको अपेक्षा !");
        }

        //For current time....
        QString cuh;
        for(int i=0;i<currenthour.length();i++)
        {
            if(currenthour[i]=='0')
            {
                cuh=cuh+"०";
            }
            if(currenthour[i]=='1')
            {
                cuh=cuh+"१";
            }
            if(currenthour[i]=='2')
            {
                cuh=cuh+"२";
            }
            if(currenthour[i]=='3')
            {
                cuh=cuh+"३";
            }
            if(currenthour[i]=='4')
            {
                cuh=cuh+"४";
            }
            if(currenthour[i]=='5')
            {
                cuh=cuh+"५";
            }
            if(currenthour[i]=='6')
            {
                cuh=cuh+"६";
            }
            if(currenthour[i]=='7')
            {
                cuh=cuh+"७";
            }
            if(currenthour[i]=='8')
            {
                cuh=cuh+"८";
            }
            if(currenthour[i]=='9')
            {
                cuh=cuh+"९";
            }
        }

        QString cum;
        for(int i=0;i<currentmin.length();i++)
        {
            if(currentmin[i]=='0')
            {
                cum=cum+"०";
            }
            if(currentmin[i]=='1')
            {
                cum=cum+"१";
            }
            if(currentmin[i]=='2')
            {
                cum=cum+"२";
            }
            if(currentmin[i]=='3')
            {
                cum=cum+"३";
            }
            if(currentmin[i]=='4')
            {
                cum=cum+"४";
            }
            if(currentmin[i]=='5')
            {
                cum=cum+"५";
            }
            if(currentmin[i]=='6')
            {
                cum=cum+"६";
            }
            if(currentmin[i]=='7')
            {
                cum=cum+"७";
            }
            if(currentmin[i]=='8')
            {
                cum=cum+"८";
            }
            if(currentmin[i]=='9')
            {
                cum=cum+"९";
            }
        }
        ui->current_time->setText(cuh+":"+cum);

        //For wind speed....
        QString cws;
        for(int i=0;i<currentWindSpeed.length();i++)
        {
            if(currentWindSpeed[i]=='0')
            {
                cws=cws+"०";
            }
            if(currentWindSpeed[i]=='1')
            {
                cws=cws+"१";
            }
            if(currentWindSpeed[i]=='2')
            {
                cws=cws+"२";
            }
            if(currentWindSpeed[i]=='3')
            {
                cws=cws+"३";
            }
            if(currentWindSpeed[i]=='4')
            {
                cws=cws+"४";
            }
            if(currentWindSpeed[i]=='5')
            {
                cws=cws+"५";
            }
            if(currentWindSpeed[i]=='6')
            {
                cws=cws+"६";
            }
            if(currentWindSpeed[i]=='7')
            {
                cws=cws+"७";
            }
            if(currentWindSpeed[i]=='8')
            {
                cws=cws+"८";
            }
            if(currentWindSpeed[i]=='9')
            {
                cws=cws+"९";
            }
        }
        ui->windspeed1->setText(cws+"कि/घ");

        //For humidity....
        QString hum;
        for(int i=0;i<currentHumidity.length();i++)
        {
            if(currentHumidity[i]=='0')
            {
                hum=hum+"०";
            }
            if(currentHumidity[i]=='1')
            {
                hum=hum+"१";
            }
            if(currentHumidity[i]=='2')
            {
                hum=hum+"२";
            }
            if(currentHumidity[i]=='3')
            {
                hum=hum+"३";
            }
            if(currentHumidity[i]=='4')
            {
                hum=hum+"४";
            }
            if(currentHumidity[i]=='5')
            {
                hum=hum+"५";
            }
            if(currentHumidity[i]=='6')
            {
                hum=hum+"६";
            }
            if(currentHumidity[i]=='7')
            {
                hum=hum+"७";
            }
            if(currentHumidity[i]=='8')
            {
                hum=hum+"८";
            }
            if(currentHumidity[i]=='9')
            {
                hum=hum+"९";
            }
            if(currentHumidity[i]=='.')
            {
                hum=hum+".";
            }
        }
        ui->humidity1->setText(hum+"%");
        ui->currentHum_2->setText(hum+"%");

        //For feelslike....
        QString fl;
        for(int i=0;i<currentFeelslike.length();i++)
        {
            if(currentFeelslike[i]=='0')
            {
                fl=fl+"०";
            }
            if(currentFeelslike[i]=='1')
            {
                fl=fl+"१";
            }
            if(currentFeelslike[i]=='2')
            {
                fl=fl+"२";
            }
            if(currentFeelslike[i]=='3')
            {
                fl=fl+"३";
            }
            if(currentFeelslike[i]=='4')
            {
                fl=fl+"४";
            }
            if(currentFeelslike[i]=='5')
            {
                fl=fl+"५";
            }
            if(currentFeelslike[i]=='6')
            {
                fl=fl+"६";
            }
            if(currentFeelslike[i]=='7')
            {
                fl=fl+"७";
            }
            if(currentFeelslike[i]=='8')
            {
                fl=fl+"८";
            }
            if(currentFeelslike[i]=='9')
            {
                fl=fl+"९";
            }
            if(currentFeelslike[i]=='.')
            {
                fl=fl+".";
            }
        }
        ui->feelslike1->setText(fl+"°C");
        ui->currentfl_2->setText(fl+"°C");

        //For current latitude....
        QString lati;
        for(int i=0;i<currentLatitude.length();i++)
        {
            if(currentLatitude[i]=='0')
            {
                lati=lati+"०";
            }
            if(currentLatitude[i]=='1')
            {
                lati=lati+"१";
            }
            if(currentLatitude[i]=='2')
            {
                lati=lati+"२";
            }
            if(currentLatitude[i]=='3')
            {
                lati=lati+"३";
            }
            if(currentLatitude[i]=='4')
            {
                lati=lati+"४";
            }
            if(currentLatitude[i]=='5')
            {
                lati=lati+"५";
            }
            if(currentLatitude[i]=='6')
            {
                lati=lati+"६";
            }
            if(currentLatitude[i]=='7')
            {
                lati=lati+"७";
            }
            if(currentLatitude[i]=='8')
            {
                lati=lati+"८";
            }
            if(currentLatitude[i]=='9')
            {
                lati=lati+"९";
            }
            if(currentLatitude[i]=='.')
            {
                lati=lati+".";
            }
        }
        ui->currentlat_2->setText(lati);

        //For current longitude....
        QString longi;
        for(int i=0;i<CurrentLongitude.length();i++)
        {
            if(CurrentLongitude[i]=='0')
            {
                longi=longi+"०";
            }
            if(CurrentLongitude[i]=='1')
            {
                longi=longi+"१";
            }
            if(CurrentLongitude[i]=='2')
            {
                longi=longi+"२";
            }
            if(CurrentLongitude[i]=='3')
            {
                longi=longi+"३";
            }
            if(CurrentLongitude[i]=='4')
            {
                longi=longi+"४";
            }
            if(CurrentLongitude[i]=='5')
            {
                longi=longi+"५";
            }
            if(CurrentLongitude[i]=='6')
            {
                longi=longi+"६";
            }
            if(CurrentLongitude[i]=='7')
            {
                longi=longi+"७";
            }
            if(CurrentLongitude[i]=='8')
            {
                longi=longi+"८";
            }
            if(CurrentLongitude[i]=='9')
            {
                longi=longi+"९";
            }
            if(CurrentLongitude[i]=='.')
            {
                longi=longi+".";
            }
        }
        ui->currentlon_2->setText(longi);

        //for future weather1....
        QString Ft1;
        for(int i=0;i<fTempr1.length();i++)
        {
            if(fTempr1[i]=='0')
            {
                Ft1=Ft1+"०";
            }
            if(fTempr1[i]=='1')
            {
                Ft1=Ft1+"१";
            }
            if(fTempr1[i]=='2')
            {
                Ft1=Ft1+"२";
            }
            if(fTempr1[i]=='3')
            {
                Ft1=Ft1+"३";
            }
            if(fTempr1[i]=='4')
            {
                Ft1=Ft1+"४";
            }
            if(fTempr1[i]=='5')
            {
                Ft1=Ft1+"५";
            }
            if(fTempr1[i]=='6')
            {
                Ft1=Ft1+"६";
            }
            if(fTempr1[i]=='7')
            {
                Ft1=Ft1+"७";
            }
            if(fTempr1[i]=='8')
            {
                Ft1=Ft1+"८";
            }
            if(fTempr1[i]=='9')
            {
                Ft1=Ft1+"९";
            }
            if(fTempr1[i]=='.')
            {
                Ft1=Ft1+".";
            }
        }
        ui->fTemp1->setText(Ft1+"°C");

        QString D1;
        for(int i=0;i<Date1.length();i++)
        {
            if(Date1[i]=='0')
            {
                D1=D1+"०";
            }
            if(Date1[i]=='1')
            {
                D1=D1+"१";
            }
            if(Date1[i]=='2')
            {
                D1=D1+"२";
            }
            if(Date1[i]=='3')
            {
                D1=D1+"३";
            }
            if(Date1[i]=='4')
            {
                D1=D1+"४";
            }
            if(Date1[i]=='5')
            {
                D1=D1+"५";
            }
            if(Date1[i]=='6')
            {
                D1=D1+"६";
            }
            if(Date1[i]=='7')
            {
                D1=D1+"७";
            }
            if(Date1[i]=='8')
            {
                D1=D1+"८";
            }
            if(Date1[i]=='9')
            {
                D1=D1+"९";
            }
        }
        if(mon1=="Jan")
        {
            ui->fDate1->setText("जनवरी  "+D1);
        }
        if(mon1=="Feb")
        {
            ui->fDate1->setText("फेब्रुअरी  "+D1);
        }
        if(mon1=="Mar")
        {
            ui->fDate1->setText("मार्च  "+D1);
        }
        if(mon1=="Apr")
        {
            ui->fDate1->setText("अप्रिल  "+D1);
        }
        if(mon1=="May")
        {
            ui->fDate1->setText("मे  "+D1);
        }
        if(mon1=="June")
        {
            ui->fDate1->setText("जून  "+D1);
        }
        if(mon1=="July")
        {
            ui->fDate1->setText("जुलाई  "+D1);
        }
        if(mon1=="Aug")
        {
            ui->fDate1->setText("अगस्ट  "+D1);
        }
        if(mon1=="Sep")
        {
            ui->fDate1->setText("सेप्टेम्बर  "+D1);
        }
        if(mon1=="Oct")
        {
            ui->fDate1->setText("अक्टोबर  "+D1);
        }
        if(mon1=="Nov")
        {
            ui->fDate1->setText("नोभेम्बर  "+D1);
        }
        if(mon1=="Dec")
        {
            ui->fDate1->setText("डिसेम्बर  "+D1);
        }

        if(fweather1=="Clouds")
        {
            ui->fWeather1->setText("बादल");
        }
        if(fweather1=="Rain")
        {
            ui->fWeather1->setText("वर्षा");
        }
        if(fweather1=="Thunderstorm")
        {
            ui->fWeather1->setText("चट्याङ");
        }
        if(fweather1=="Drizzle")
        {
            ui->fWeather1->setText("मुसलधारे पानी");
        }
        if(fweather1=="Mist"||fweather1=="Haze"||fweather1=="Fog")
        {
            ui->fWeather1->setText("कुहिरो");
        }
        if(fweather1=="Clear")
        {
            ui->fWeather1->setText("सफा मौसम");
        }
        if(fweather1=="Smoke")
        {
            ui->fWeather1->setText("धुवाँ");
        }
        if(fweather1=="Snow")
        {
            ui->fWeather1->setText("हिउँ");
        }
        if(fweather1=="Dust"||fweather1=="Sand"||fweather1=="Ash")
        {
            ui->fWeather1->setText("धुलो");
        }
        if(fweather1=="Tornado")
        {
            ui->fWeather1->setText("भुमरी");
        }
        if(fweather1=="Squall")
        {
            ui->fWeather1->setText("तूफान");
        }

        //For future weather2.....

        QString Ft2;
        for(int i=0;i<fTempr2.length();i++)
        {
            if(fTempr2[i]=='0')
            {
                Ft2=Ft2+"०";
            }
            if(fTempr2[i]=='1')
            {
                Ft2=Ft2+"१";
            }
            if(fTempr2[i]=='2')
            {
                Ft2=Ft2+"२";
            }
            if(fTempr2[i]=='3')
            {
                Ft2=Ft2+"३";
            }
            if(fTempr2[i]=='4')
            {
                Ft2=Ft2+"४";
            }
            if(fTempr2[i]=='5')
            {
                Ft2=Ft2+"५";
            }
            if(fTempr2[i]=='6')
            {
                Ft2=Ft2+"६";
            }
            if(fTempr2[i]=='7')
            {
                Ft2=Ft2+"७";
            }
            if(fTempr2[i]=='8')
            {
                Ft2=Ft2+"८";
            }
            if(fTempr2[i]=='9')
            {
                Ft2=Ft2+"९";
            }
            if(fTempr2[i]=='.')
            {
                Ft2=Ft2+".";
            }
        }
        ui->fTemp2->setText(Ft2+"°C");

        QString D2;
        for(int i=0;i<Date2.length();i++)
        {
            if(Date2[i]=='0')
            {
                D2=D2+"०";
            }
            if(Date2[i]=='1')
            {
                D2=D2+"१";
            }
            if(Date2[i]=='2')
            {
                D2=D2+"२";
            }
            if(Date2[i]=='3')
            {
                D2=D2+"३";
            }
            if(Date2[i]=='4')
            {
                D2=D2+"४";
            }
            if(Date2[i]=='5')
            {
                D2=D2+"५";
            }
            if(Date2[i]=='6')
            {
                D2=D2+"६";
            }
            if(Date2[i]=='7')
            {
                D2=D2+"७";
            }
            if(Date2[i]=='8')
            {
                D2=D2+"८";
            }
            if(Date2[i]=='9')
            {
                D2=D2+"९";
            }
        }
        if(mon2=="Jan")
        {
            ui->fDate2->setText("जनवरी  "+D2);
        }
        if(mon2=="Feb")
        {
            ui->fDate2->setText("फेब्रुअरी  "+D2);
        }
        if(mon2=="Mar")
        {
            ui->fDate2->setText("मार्च  "+D2);
        }
        if(mon2=="Apr")
        {
            ui->fDate2->setText("अप्रिल  "+D2);
        }
        if(mon2=="May")
        {
            ui->fDate2->setText("मे  "+D2);
        }
        if(mon2=="June")
        {
            ui->fDate2->setText("जून  "+D2);
        }
        if(mon2=="July")
        {
            ui->fDate2->setText("जुलाई  "+D2);
        }
        if(mon2=="Aug")
        {
            ui->fDate2->setText("अगस्ट  "+D2);
        }
        if(mon2=="Sep")
        {
            ui->fDate2->setText("सेप्टेम्बर  "+D2);
        }
        if(mon2=="Oct")
        {
            ui->fDate2->setText("अक्टोबर  "+D2);
        }
        if(mon2=="Nov")
        {
            ui->fDate2->setText("नोभेम्बर  "+D2);
        }
        if(mon2=="Dec")
        {
            ui->fDate2->setText("डिसेम्बर  "+D2);
        }

        if(fweather2=="Clouds")
        {
            ui->fWeather2->setText("बादल");
        }
        if(fweather2=="Rain")
        {
            ui->fWeather2->setText("वर्षा");
        }
        if(fweather2=="Thunderstorm")
        {
            ui->fWeather2->setText("चट्याङ");
        }
        if(fweather2=="Drizzle")
        {
            ui->fWeather2->setText("मुसलधारे पानी");
        }
        if(fweather2=="Mist"||fweather2=="Haze"||fweather2=="Fog")
        {
            ui->fWeather2->setText("कुहिरो");
        }
        if(fweather2=="Clear")
        {
            ui->fWeather2->setText("सफा मौसम");
        }
        if(fweather2=="Smoke")
        {
            ui->fWeather2->setText("धुवाँ");
        }
        if(fweather2=="Snow")
        {
            ui->fWeather2->setText("हिउँ");
        }
        if(fweather2=="Dust"||fweather2=="Sand"||fweather2=="Ash")
        {
            ui->fWeather2->setText("धुलो");
        }
        if(fweather2=="Tornado")
        {
            ui->fWeather2->setText("भुमरी");
        }
        if(fweather2=="Squall")
        {
            ui->fWeather2->setText("तूफान");
        }

        //For future weather3......

        QString Ft3;
        for(int i=0;i<fTempr3.length();i++)
        {
            if(fTempr3[i]=='0')
            {
                Ft3=Ft3+"०";
            }
            if(fTempr3[i]=='1')
            {
                Ft3=Ft3+"१";
            }
            if(fTempr3[i]=='2')
            {
                Ft3=Ft3+"२";
            }
            if(fTempr3[i]=='3')
            {
                Ft3=Ft3+"३";
            }
            if(fTempr3[i]=='4')
            {
                Ft3=Ft3+"४";
            }
            if(fTempr3[i]=='5')
            {
                Ft3=Ft3+"५";
            }
            if(fTempr3[i]=='6')
            {
                Ft3=Ft3+"६";
            }
            if(fTempr3[i]=='7')
            {
                Ft3=Ft3+"७";
            }
            if(fTempr3[i]=='8')
            {
                Ft3=Ft3+"८";
            }
            if(fTempr3[i]=='9')
            {
                Ft3=Ft3+"९";
            }
            if(fTempr3[i]=='.')
            {
                Ft3=Ft3+".";
            }
        }
        ui->fTemp3->setText(Ft3+"°C");

        QString D3;
        for(int i=0;i<Date3.length();i++)
        {
            if(Date3[i]=='0')
            {
                D3=D3+"०";
            }
            if(Date3[i]=='1')
            {
                D3=D3+"१";
            }
            if(Date3[i]=='2')
            {
                D3=D3+"२";
            }
            if(Date3[i]=='3')
            {
                D3=D3+"३";
            }
            if(Date3[i]=='4')
            {
                D3=D3+"४";
            }
            if(Date3[i]=='5')
            {
                D3=D3+"५";
            }
            if(Date3[i]=='6')
            {
                D3=D3+"६";
            }
            if(Date3[i]=='7')
            {
                D3=D3+"७";
            }
            if(Date3[i]=='8')
            {
                D3=D3+"८";
            }
            if(Date3[i]=='9')
            {
                D3=D3+"९";
            }
        }
        if(mon3=="Jan")
        {
            ui->fDate3->setText("जनवरी  "+D3);
        }
        if(mon3=="Feb")
        {
            ui->fDate3->setText("फेब्रुअरी  "+D3);
        }
        if(mon3=="Mar")
        {
            ui->fDate3->setText("मार्च  "+D3);
        }
        if(mon3=="Apr")
        {
            ui->fDate3->setText("अप्रिल  "+D3);
        }
        if(mon3=="May")
        {
            ui->fDate3->setText("मे  "+D3);
        }
        if(mon3=="June")
        {
            ui->fDate3->setText("जून  "+D3);
        }
        if(mon3=="July")
        {
            ui->fDate3->setText("जुलाई  "+D3);
        }
        if(mon3=="Aug")
        {
            ui->fDate3->setText("अगस्ट  "+D3);
        }
        if(mon3=="Sep")
        {
            ui->fDate3->setText("सेप्टेम्बर  "+D3);
        }
        if(mon3=="Oct")
        {
            ui->fDate3->setText("अक्टोबर  "+D3);
        }
        if(mon3=="Nov")
        {
            ui->fDate3->setText("नोभेम्बर  "+D3);
        }
        if(mon3=="Dec")
        {
            ui->fDate3->setText("डिसेम्बर  "+D3);
        }

        if(fweather3=="Clouds")
        {
            ui->fWeather3->setText("बादल");
        }
        if(fweather3=="Rain")
        {
            ui->fWeather3->setText("वर्षा");
        }
        if(fweather3=="Thunderstorm")
        {
            ui->fWeather3->setText("चट्याङ");
        }
        if(fweather3=="Drizzle")
        {
            ui->fWeather3->setText("मुसलधारे पानी");
        }
        if(fweather3=="Mist"||fweather3=="Haze"||fweather3=="Fog")
        {
            ui->fWeather3->setText("कुहिरो");
        }
        if(fweather3=="Clear")
        {
            ui->fWeather3->setText("सफा मौसम");
        }
        if(fweather3=="Smoke")
        {
            ui->fWeather3->setText("धुवाँ");
        }
        if(fweather3=="Snow")
        {
            ui->fWeather3->setText("हिउँ");
        }
        if(fweather3=="Dust"||fweather3=="Sand"||fweather3=="Ash")
        {
            ui->fWeather3->setText("धुलो");
        }
        if(fweather3=="Tornado")
        {
            ui->fWeather3->setText("भुमरी");
        }
        if(fweather3=="Squall")
        {
            ui->fWeather3->setText("तूफान");
        }

        //For Present Weather1.....
        if(weather1!="")
        {
            QString t1;
            for(int i=0;i<Tempr1.length();i++)
            {
                if(Tempr1[i]=='0')
                {
                    t1=t1+"०";
                }
                if(Tempr1[i]=='1')
                {
                    t1=t1+"१";
                }
                if(Tempr1[i]=='2')
                {
                    t1=t1+"२";
                }
                if(Tempr1[i]=='3')
                {
                    t1=t1+"३";
                }
                if(Tempr1[i]=='4')
                {
                    t1=t1+"४";
                }
                if(Tempr1[i]=='5')
                {
                    t1=t1+"५";
                }
                if(Tempr1[i]=='6')
                {
                    t1=t1+"६";
                }
                if(Tempr1[i]=='7')
                {
                    t1=t1+"७";
                }
                if(Tempr1[i]=='8')
                {
                    t1=t1+"८";
                }
                if(Tempr1[i]=='9')
                {
                    t1=t1+"९";
                }
                if(Tempr1[i]=='.')
                {
                    t1=t1+".";
                }
            }
            ui->temp1->setText(t1+"°C");

            QString h1;
            for(int i=0;i<Hour1.length();i++)
            {
                if(Hour1[i]=='0')
                {
                    h1=h1+"०";
                }
                if(Hour1[i]=='1')
                {
                    h1=h1+"१";
                }
                if(Hour1[i]=='2')
                {
                    h1=h1+"२";
                }
                if(Hour1[i]=='3')
                {
                    h1=h1+"३";
                }
                if(Hour1[i]=='4')
                {
                    h1=h1+"४";
                }
                if(Hour1[i]=='5')
                {
                    h1=h1+"५";
                }
                if(Hour1[i]=='6')
                {
                    h1=h1+"६";
                }
                if(Hour1[i]=='7')
                {
                    h1=h1+"७";
                }
                if(Hour1[i]=='8')
                {
                    h1=h1+"८";
                }
                if(Hour1[i]=='9')
                {
                    h1=h1+"९";
                }
            }

            QString m1;
            for(int i=0;i<Min1.length();i++)
            {
                if(Min1[i]=='0')
                {
                    m1=m1+"०";
                }
                if(Min1[i]=='1')
                {
                    m1=m1+"१";
                }
                if(Min1[i]=='2')
                {
                    m1=m1+"२";
                }
                if(Min1[i]=='3')
                {
                    m1=m1+"३";
                }
                if(Min1[i]=='4')
                {
                    m1=m1+"४";
                }
                if(Min1[i]=='5')
                {
                    m1=m1+"५";
                }
                if(Min1[i]=='6')
                {
                    m1=m1+"६";
                }
                if(Min1[i]=='7')
                {
                    m1=m1+"७";
                }
                if(Min1[i]=='8')
                {
                    m1=m1+"८";
                }
                if(Min1[i]=='9')
                {
                    m1=m1+"९";
                }
            }
            ui->time1->setText(h1+":"+m1);

            if(weather1=="Clouds")
            {
                ui->weather1->setText("बादल");
            }
            if(weather1=="Rain")
            {
                ui->weather1->setText("वर्षा");
            }
            if(weather1=="Thunderstorm")
            {
                ui->weather1->setText("चट्याङ");
            }
            if(weather1=="Drizzle")
            {
                ui->weather1->setText("मुसलधारे पानी");
            }
            if(weather1=="Mist"||weather1=="Haze"||weather1=="Fog")
            {
                ui->weather1->setText("कुहिरो");
            }
            if(weather1=="Clear")
            {
                ui->weather1->setText("सफा मौसम");
            }
            if(weather1=="Smoke")
            {
                ui->weather1->setText("धुवाँ");
            }
            if(weather1=="Snow")
            {
                ui->weather1->setText("हिउँ");
            }
            if(weather1=="Dust"||weather1=="Sand"||weather1=="Ash")
            {
                ui->weather1->setText("धुलो");
            }
            if(weather1=="Tornado")
            {
                ui->weather1->setText("भुमरी");
            }
            if(weather1=="Squall")
            {
                ui->weather1->setText("तूफान");
            }
        }
        else
        {
            ui->weather1->setText("-");
            ui->temp1->setText("-");
            ui->time1->setText("-");
        }

        //For present weather2....
        if(weather2!="")
        {
            QString t2;
            for(int i=0;i<Tempr2.length();i++)
            {
                if(Tempr2[i]=='0')
                {
                    t2=t2+"०";
                }
                if(Tempr2[i]=='1')
                {
                    t2=t2+"१";
                }
                if(Tempr2[i]=='2')
                {
                    t2=t2+"२";
                }
                if(Tempr2[i]=='3')
                {
                    t2=t2+"३";
                }
                if(Tempr2[i]=='4')
                {
                    t2=t2+"४";
                }
                if(Tempr2[i]=='5')
                {
                    t2=t2+"५";
                }
                if(Tempr2[i]=='6')
                {
                    t2=t2+"६";
                }
                if(Tempr2[i]=='7')
                {
                    t2=t2+"७";
                }
                if(Tempr2[i]=='8')
                {
                    t2=t2+"८";
                }
                if(Tempr2[i]=='9')
                {
                    t2=t2+"९";
                }
                if(Tempr2[i]=='.')
                {
                    t2=t2+".";
                }
            }
            ui->temp2->setText(t2+"°C");

            QString h2;
            for(int i=0;i<Hour2.length();i++)
            {
                if(Hour2[i]=='0')
                {
                    h2=h2+"०";
                }
                if(Hour2[i]=='1')
                {
                    h2=h2+"१";
                }
                if(Hour2[i]=='2')
                {
                    h2=h2+"२";
                }
                if(Hour2[i]=='3')
                {
                    h2=h2+"३";
                }
                if(Hour2[i]=='4')
                {
                    h2=h2+"४";
                }
                if(Hour2[i]=='5')
                {
                    h2=h2+"५";
                }
                if(Hour2[i]=='6')
                {
                    h2=h2+"६";
                }
                if(Hour2[i]=='7')
                {
                    h2=h2+"७";
                }
                if(Hour2[i]=='8')
                {
                    h2=h2+"८";
                }
                if(Hour2[i]=='9')
                {
                    h2=h2+"९";
                }
            }

            QString m2;
            for(int i=0;i<Min2.length();i++)
            {
                if(Min2[i]=='0')
                {
                    m2=m2+"०";
                }
                if(Min2[i]=='1')
                {
                    m2=m2+"१";
                }
                if(Min2[i]=='2')
                {
                    m2=m2+"२";
                }
                if(Min2[i]=='3')
                {
                    m2=m2+"३";
                }
                if(Min2[i]=='4')
                {
                    m2=m2+"४";
                }
                if(Min2[i]=='5')
                {
                    m2=m2+"५";
                }
                if(Min2[i]=='6')
                {
                    m2=m2+"६";
                }
                if(Min2[i]=='7')
                {
                    m2=m2+"७";
                }
                if(Min2[i]=='8')
                {
                    m2=m2+"८";
                }
                if(Min2[i]=='9')
                {
                    m2=m2+"९";
                }
            }
            ui->time2->setText(h2+":"+m2);

            if(weather2=="Clouds")
            {
                ui->weather2->setText("बादल");
            }
            if(weather2=="Rain")
            {
                ui->weather2->setText("वर्षा");
            }
            if(weather2=="Thunderstorm")
            {
                ui->weather2->setText("चट्याङ");
            }
            if(weather2=="Drizzle")
            {
                ui->weather2->setText("मुसलधारे पानी");
            }
            if(weather2=="Mist"||weather2=="Haze"||weather2=="Fog")
            {
                ui->weather2->setText("कुहिरो");
            }
            if(weather2=="Clear")
            {
                ui->weather2->setText("सफा मौसम");
            }
            if(weather2=="Smoke")
            {
                ui->weather2->setText("धुवाँ");
            }
            if(weather2=="Snow")
            {
                ui->weather2->setText("हिउँ");
            }
            if(weather2=="Dust"||weather2=="Sand"||weather2=="Ash")
            {
                ui->weather2->setText("धुलो");
            }
            if(weather2=="Tornado")
            {
                ui->weather2->setText("भुमरी");
            }
            if(weather2=="Squall")
            {
                ui->weather2->setText("तूफान");
            }
        }
        else
        {
            ui->weather2->setText("-");
            ui->temp2->setText("-");
            ui->time2->setText("-");
        }

        //For present weather3.....
        if(weather3!="")
        {
            QString t3;
            for(int i=0;i<Tempr3.length();i++)
            {
                if(Tempr3[i]=='0')
                {
                    t3=t3+"०";
                }
                if(Tempr3[i]=='1')
                {
                    t3=t3+"१";
                }
                if(Tempr3[i]=='2')
                {
                    t3=t3+"२";
                }
                if(Tempr3[i]=='3')
                {
                    t3=t3+"३";
                }
                if(Tempr3[i]=='4')
                {
                    t3=t3+"४";
                }
                if(Tempr3[i]=='5')
                {
                    t3=t3+"५";
                }
                if(Tempr3[i]=='6')
                {
                    t3=t3+"६";
                }
                if(Tempr3[i]=='7')
                {
                    t3=t3+"७";
                }
                if(Tempr3[i]=='8')
                {
                    t3=t3+"८";
                }
                if(Tempr3[i]=='9')
                {
                    t3=t3+"९";
                }
                if(Tempr3[i]=='.')
                {
                    t3=t3+".";
                }
            }
            ui->temp3->setText(t3+"°C");

            QString h3;
            for(int i=0;i<Hour3.length();i++)
            {
                if(Hour3[i]=='0')
                {
                    h3=h3+"०";
                }
                if(Hour3[i]=='1')
                {
                    h3=h3+"१";
                }
                if(Hour3[i]=='2')
                {
                    h3=h3+"२";
                }
                if(Hour3[i]=='3')
                {
                    h3=h3+"३";
                }
                if(Hour3[i]=='4')
                {
                    h3=h3+"४";
                }
                if(Hour3[i]=='5')
                {
                    h3=h3+"५";
                }
                if(Hour3[i]=='6')
                {
                    h3=h3+"६";
                }
                if(Hour3[i]=='7')
                {
                    h3=h3+"७";
                }
                if(Hour3[i]=='8')
                {
                    h3=h3+"८";
                }
                if(Hour3[i]=='9')
                {
                    h3=h3+"९";
                }
            }

            QString m3;
            for(int i=0;i<Min3.length();i++)
            {
                if(Min3[i]=='0')
                {
                    m3=m3+"०";
                }
                if(Min3[i]=='1')
                {
                    m3=m3+"१";
                }
                if(Min3[i]=='2')
                {
                    m3=m3+"२";
                }
                if(Min3[i]=='3')
                {
                    m3=m3+"३";
                }
                if(Min3[i]=='4')
                {
                    m3=m3+"४";
                }
                if(Min3[i]=='5')
                {
                    m3=m3+"५";
                }
                if(Min3[i]=='6')
                {
                    m3=m3+"६";
                }
                if(Min3[i]=='7')
                {
                    m3=m3+"७";
                }
                if(Min3[i]=='8')
                {
                    m3=m3+"८";
                }
                if(Min3[i]=='9')
                {
                    m3=m3+"९";
                }
            }
            ui->time3->setText(h3+":"+m3);

            if(weather3=="Clouds")
            {
                ui->weather3->setText("बादल");
            }
            if(weather3=="Rain")
            {
                ui->weather3->setText("वर्षा");
            }
            if(weather3=="Thunderstorm")
            {
                ui->weather3->setText("चट्याङ");
            }
            if(weather3=="Drizzle")
            {
                ui->weather3->setText("मुसलधारे पानी");
            }
            if(weather3=="Mist"||weather3=="Haze"||weather3=="Fog")
            {
                ui->weather3->setText("कुहिरो");
            }
            if(weather3=="Clear")
            {
                ui->weather3->setText("सफा मौसम");
            }
            if(weather3=="Smoke")
            {
                ui->weather3->setText("धुवाँ");
            }
            if(weather3=="Snow")
            {
                ui->weather3->setText("हिउँ");
            }
            if(weather3=="Dust"||weather3=="Sand"||weather3=="Ash")
            {
                ui->weather3->setText("धुलो");
            }
            if(weather3=="Tornado")
            {
                ui->weather3->setText("भुमरी");
            }
            if(weather3=="Squall")
            {
                ui->weather3->setText("तूफान");
            }
        }
        else
        {
            ui->weather3->setText("-");
            ui->temp3->setText("-");
            ui->time3->setText("-");
        }

        //For present weather4.....
        if(weather4!="")
        {
            QString t4;
            for(int i=0;i<Tempr4.length();i++)
            {
                if(Tempr4[i]=='0')
                {
                    t4=t4+"०";
                }
                if(Tempr4[i]=='1')
                {
                    t4=t4+"१";
                }
                if(Tempr4[i]=='2')
                {
                    t4=t4+"२";
                }
                if(Tempr4[i]=='3')
                {
                    t4=t4+"३";
                }
                if(Tempr4[i]=='4')
                {
                    t4=t4+"४";
                }
                if(Tempr4[i]=='5')
                {
                    t4=t4+"५";
                }
                if(Tempr4[i]=='6')
                {
                    t4=t4+"६";
                }
                if(Tempr4[i]=='7')
                {
                    t4=t4+"७";
                }
                if(Tempr4[i]=='8')
                {
                    t4=t4+"८";
                }
                if(Tempr4[i]=='9')
                {
                    t4=t4+"९";
                }
                if(Tempr4[i]=='.')
                {
                    t4=t4+".";
                }
            }
            ui->temp4->setText(t4+"°C");

            QString h4;
            for(int i=0;i<Hour4.length();i++)
            {
                if(Hour4[i]=='0')
                {
                    h4=h4+"०";
                }
                if(Hour4[i]=='1')
                {
                    h4=h4+"१";
                }
                if(Hour4[i]=='2')
                {
                    h4=h4+"२";
                }
                if(Hour4[i]=='3')
                {
                    h4=h4+"३";
                }
                if(Hour4[i]=='4')
                {
                    h4=h4+"४";
                }
                if(Hour4[i]=='5')
                {
                    h4=h4+"५";
                }
                if(Hour4[i]=='6')
                {
                    h4=h4+"६";
                }
                if(Hour4[i]=='7')
                {
                    h4=h4+"७";
                }
                if(Hour4[i]=='8')
                {
                    h4=h4+"८";
                }
                if(Hour4[i]=='9')
                {
                    h4=h4+"९";
                }
            }

            QString m4;
            for(int i=0;i<Min4.length();i++)
            {
                if(Min4[i]=='0')
                {
                    m4=m4+"०";
                }
                if(Min4[i]=='1')
                {
                    m4=m4+"१";
                }
                if(Min4[i]=='2')
                {
                    m4=m4+"२";
                }
                if(Min4[i]=='3')
                {
                    m4=m4+"३";
                }
                if(Min4[i]=='4')
                {
                    m4=m4+"४";
                }
                if(Min4[i]=='5')
                {
                    m4=m4+"५";
                }
                if(Min4[i]=='6')
                {
                    m4=m4+"६";
                }
                if(Min4[i]=='7')
                {
                    m4=m4+"७";
                }
                if(Min4[i]=='8')
                {
                    m4=m4+"८";
                }
                if(Min4[i]=='9')
                {
                    m4=m4+"९";
                }
            }
            ui->time4->setText(h4+":"+m4);

            if(weather4=="Clouds")
            {
                ui->weather4->setText("बादल");
            }
            if(weather4=="Rain")
            {
                ui->weather4->setText("वर्षा");
            }
            if(weather4=="Thunderstorm")
            {
                ui->weather4->setText("चट्याङ");
            }
            if(weather4=="Drizzle")
            {
                ui->weather4->setText("मुसलधारे पानी");
            }
            if(weather4=="Mist"||weather4=="Haze"||weather4=="Fog")
            {
                ui->weather4->setText("कुहिरो");
            }
            if(weather4=="Clear")
            {
                ui->weather4->setText("सफा मौसम");
            }
            if(weather4=="Smoke")
            {
                ui->weather4->setText("धुवाँ");
            }
            if(weather4=="Snow")
            {
                ui->weather4->setText("हिउँ");
            }
            if(weather4=="Dust"||weather4=="Sand"||weather4=="Ash")
            {
                ui->weather4->setText("धुलो");
            }
            if(weather4=="Tornado")
            {
                ui->weather4->setText("भुमरी");
            }
            if(weather4=="Squall")
            {
                ui->weather4->setText("तूफान");
            }
        }
        else
        {
            ui->weather4->setText("-");
            ui->temp4->setText("-");
            ui->time4->setText("-");
        }

        //For present weather5....
        if(weather5!="")
        {
            QString t5;
            for(int i=0;i<Tempr5.length();i++)
            {
                if(Tempr5[i]=='0')
                {
                    t5=t5+"०";
                }
                if(Tempr5[i]=='1')
                {
                    t5=t5+"१";
                }
                if(Tempr5[i]=='2')
                {
                    t5=t5+"२";
                }
                if(Tempr5[i]=='3')
                {
                    t5=t5+"३";
                }
                if(Tempr5[i]=='4')
                {
                    t5=t5+"४";
                }
                if(Tempr5[i]=='5')
                {
                    t5=t5+"५";
                }
                if(Tempr5[i]=='6')
                {
                    t5=t5+"६";
                }
                if(Tempr5[i]=='7')
                {
                    t5=t5+"७";
                }
                if(Tempr5[i]=='8')
                {
                    t5=t5+"८";
                }
                if(Tempr5[i]=='9')
                {
                    t5=t5+"९";
                }
                if(Tempr5[i]=='.')
                {
                    t5=t5+".";
                }
            }
            ui->temp5->setText(t5+"°C");

            QString h5;
            for(int i=0;i<Hour5.length();i++)
            {
                if(Hour5[i]=='0')
                {
                    h5=h5+"०";
                }
                if(Hour5[i]=='1')
                {
                    h5=h5+"१";
                }
                if(Hour5[i]=='2')
                {
                    h5=h5+"२";
                }
                if(Hour5[i]=='3')
                {
                    h5=h5+"३";
                }
                if(Hour5[i]=='4')
                {
                    h5=h5+"४";
                }
                if(Hour5[i]=='5')
                {
                    h5=h5+"५";
                }
                if(Hour5[i]=='6')
                {
                    h5=h5+"६";
                }
                if(Hour5[i]=='7')
                {
                    h5=h5+"७";
                }
                if(Hour5[i]=='8')
                {
                    h5=h5+"८";
                }
                if(Hour5[i]=='9')
                {
                    h5=h5+"९";
                }
            }

            QString m5;
            for(int i=0;i<Min5.length();i++)
            {
                if(Min5[i]=='0')
                {
                    m5=m5+"०";
                }
                if(Min5[i]=='1')
                {
                    m5=m5+"१";
                }
                if(Min5[i]=='2')
                {
                    m5=m5+"२";
                }
                if(Min5[i]=='3')
                {
                    m5=m5+"३";
                }
                if(Min5[i]=='4')
                {
                    m5=m5+"४";
                }
                if(Min5[i]=='5')
                {
                    m5=m5+"५";
                }
                if(Min5[i]=='6')
                {
                    m5=m5+"६";
                }
                if(Min5[i]=='7')
                {
                    m5=m5+"७";
                }
                if(Min5[i]=='8')
                {
                    m5=m5+"८";
                }
                if(Min5[i]=='9')
                {
                    m5=m5+"९";
                }
            }
            ui->time5->setText(h5+":"+m5);

            if(weather5=="Clouds")
            {
                ui->weather5->setText("बादल");
            }
            if(weather5=="Rain")
            {
                ui->weather5->setText("वर्षा");
            }
            if(weather5=="Thunderstorm")
            {
                ui->weather5->setText("चट्याङ");
            }
            if(weather5=="Drizzle")
            {
                ui->weather5->setText("मुसलधारे पानी");
            }
            if(weather5=="Mist"||weather5=="Haze"||weather5=="Fog")
            {
                ui->weather5->setText("कुहिरो");
            }
            if(weather5=="Clear")
            {
                ui->weather5->setText("सफा मौसम");
            }
            if(weather5=="Smoke")
            {
                ui->weather5->setText("धुवाँ");
            }
            if(weather5=="Snow")
            {
                ui->weather5->setText("हिउँ");
            }
            if(weather5=="Dust"||weather5=="Sand"||weather5=="Ash")
            {
                ui->weather5->setText("धुलो");
            }
            if(weather5=="Tornado")
            {
                ui->weather5->setText("भुमरी");
            }
            if(weather5=="Squall")
            {
                ui->weather5->setText("तूफान");
            }
        }
        else
        {
            ui->weather5->setText("-");
            ui->temp5->setText("-");
            ui->time5->setText("-");
        }

        if(notCheck==false)
        {
            if(status_string == "Clouds"){
                ui->label_notification->setText("गम्भीर मौसमको अपेक्षा छैन।\nतापक्रम चिसो महसुस हुन सक्छ।");
            }
            if(status_string == "Thunderstorm")
            {
                ui->label_notification->setText("क्षेत्रमा मेघगर्जनको सम्भावना छ।\nभित्रै बस्नुहोस् र बाहिरी गतिविधिहरूबाट टाढा रहनुहोस्।");
            }
            if(status_string == "Drizzle")
            {
                ui->label_notification->setText("हल्का पानी पर्न सक्ने सम्भावना छ।\nछाता लिनुहोस्।\nसडकहरू चिप्लन सक्छन्।");
            }
            if(status_string == "Mist" || status_string == "Haze" || status_string == "Fog")
            {
                ui->label_notification->setText("दृश्यता थोरै घट्न सक्दछ।\n ध्यानपूर्वक चलाउनुहोस्।");
            }
            if(status_string == "Rain")
            {
                ui->label_notification->setText("क्षेत्रमा मध्यम वर्षा भइरहेको छ।\nचिप्लने सडक र घटेको दृश्यताका लागि तयार रहनुहोस्।\nगाडी चलाउँदा सतर्क रहनुहोस्।");
            }
            if(status_string == "Clear")
            {
                ui->label_notification->setText("गम्भीर मौसमको अपेक्षा छैन।\nमौसमको मजा लिनुहोस्।");
            }
            if(status_string == "Smoke")
            {
                ui->label_notification->setText("क्षेत्रमा हल्का धुँवा छ।\nहवाई गुणस्तर प्रभावित हुन सक्दछ।\nबाहिरी गतिविधिहरू सीमित गर्नुहोस्।");
            }
            if(status_string == "Snow")
            {
                ui->label_notification->setText("चिप्लने सडकका लागि तयार हुनुहोस्।\nसावधानीपूर्वक गाडी चलाउनुहोस् र न्यानो लुगा लगाउनुहोस्।");
            }
            if(status_string=="Dust" || status_string=="Sand" || status_string=="Ash")
            {
                ui->label_notification->setText("क्षेत्रमा हल्का धूलो छ।\nहवाई गुणस्तर प्रभावित हुन सक्दछ।\nबाहिरी गतिविधिहरू सीमित गर्नुहोस्।");
            }
            if(status_string=="Tornado")
            {
                ui->label_notification->setText("तूफान निगरानी प्रभावी छ।\nसम्भावित तूफान का लागि तयार रहनुहोस्।\nमौसम अपडेटहरू अनुगमन गर्नुहोस् र आपतकालीन योजना तयार गर्नुहोस्।");
            }
            if(status_string=="Squall")
            {
                ui->label_notification->setText("हल्का तुफान नजिकै आइरहेको छ।\n संक्षिप्त तीव्र हावा र सम्भावित वर्षाका लागि तयार हुनुहोस्।");
            }
        }
        else
        {

            ui->label_notification->setText("");
            ui->label_notification->setStyleSheet("background:transparent;");
        }
        check=false;
    }
    else
    {
        ui->lineEdit_searchbar->setPlaceholderText("Enter the location");
        ui->labelFuture->setText("3 Days Forecast");
        ui->label_temp->setText(temperature+"°C");
        ui->currentTemp_2->setText(temperature+"°C");
        ui->currentTemp->setText("      Temperature");

        ui->currentHum->setText("      Humidity");
        ui->currentfl->setText("      Feels Like");
        ui->humidity1->setText(currentHumidity+"%");
        ui->feelslike1->setText(currentFeelslike+"°C");
        ui->currentHum_2->setText(currentHumidity+"%");
        ui->currentfl_2->setText(currentFeelslike+"°C");

        ui->currentlat->setText("      Latitude");
        ui->currentlon->setText("      Longitude");
        ui->currentlat_2->setText(currentLatitude);
        ui->currentlon_2->setText(CurrentLongitude);

        ui->windspeed1->setText(currentWindSpeed+"km/h");
        ui->current_time->setText(currenthour+":"+currentmin);

        if(notCheck==false)
        {
            if(status_string == "Clouds"){
                ui->label_notification->setText("No severe weather expected.\nTemperatures may feel cooler.");
            }
            if(status_string == "Thunderstorm")
            {
                ui->label_notification->setText("Thunderstorm in the area.\n"
                                                "Stay indoors and avoid outdoor activities.");
            }
            if(status_string == "Drizzle")
            {
                ui->label_notification->setText("Light drizzle expected.\n"
                                                "Carry an umbrella. Roads may be slippery.");
            }
            if(status_string == "Mist" || status_string == "Haze" || status_string == "Fog")
            {
                ui->label_notification->setText("Visibility may be slightly reduced.\nDrive carefully.");
            }
            if(status_string == "Rain")
            {
                ui->label_notification->setText("Moderate rain in the area.\n"
                                                "Prepare for slippery roads and reduced visibility.\n"
                                                "Be cautious while driving.");
            }
            if(status_string == "Clear")
            {
                ui->label_notification->setText("No severe weather expected.\nEnjoy the weather.");
            }
            if(status_string == "Smoke")
            {
                ui->label_notification->setText("Light smoke in the area.\n"
                                                "Air quality may be affected.\n"
                                                "Limit outdoor activities.");
            }
            if(status_string == "Snow")
            {
                ui->label_notification->setText("Prepare for slippery roads.\n"
                                                "Drive cautiously and dress warmly.");
            }
            if(status_string=="Dust" || status_string=="Sand" || status_string=="Ash")
            {
                ui->label_notification->setText("Light dust in the area.\n"
                                                "Air quality may be affected.\n"
                                                "Limit outdoor activities.");
            }
            if(status_string=="Tornado")
            {
                ui->label_notification->setText("Tornado Watch in effect.\n"
                                                "Be prepared for possible tornado.\n"
                                                "Monitor weather updates and have an emergency plan in place.");
            }
            if(status_string=="Squall")
            {
                ui->label_notification->setText("Light squall approaching.\n"
                                                "Prepare for brief gusty winds and possible rain.");
            }
        }
        else
        {

            ui->label_notification->setText("");
            ui->label_notification->setStyleSheet("background:transparent;");
        }

        ui->pushButton_flag->setIcon(QIcon(":/new/prefix1/image/Usa.svg"));
        ui->label_currentWeather->setText(weatherStatus);
        if(weatherStatus=="Clouds")
        {
            if (sunrise<=currentTime && currentTime<sunset)
            {
                ui->label_alert->setText("It's a bit \n cloudy today");
            }
            else
            {
                ui->label_alert->setText("Cloudy night \n ahead");
            }
        }
        if(weatherStatus=="Thunderstorm")
        {
            ui->label_alert->setText(" Avoid outdoor \n activities");
        }
        if(weatherStatus=="Drizzle")
        {
            ui->label_alert->setText("Don't forget \n your raincoat");
        }
        if(weatherStatus=="Mist" || weatherStatus=="Haze" || weatherStatus=="Fog")
        {
            ui->label_alert->setText("Visibility is \n low");
        }
        if(weatherStatus=="Rain")
        {
            ui->label_alert->setText("Don't forget \n your umbrella !");
        }
        if(weatherStatus=="Clear")
        {
            if (sunrise<=currentTime && currentTime<sunset)
            {
                ui->label_alert->setText("Enjoy the \n beautiful weather");
            }
            else
            {
                ui->label_alert->setText("Clear skies \n tonight.");
            }
        }
        if(weatherStatus=="Smoke")
        {
            ui->label_alert->setText("Don't forget\n your mask !");
        }
        if(weatherStatus=="Snow")
        {
            ui->label_alert->setText("Time for some \n winter fun.");
        }
        if(weatherStatus=="Dust" || weatherStatus=="Sand" || weatherStatus=="Ash")
        {
            ui->label_alert->setText("Consider wearing\n a mask");
        }
        if(weatherStatus=="Tornado")
        {
            ui->label_alert->setText("Tornado alert! \n Stay indoors");
        }
        if(weatherStatus=="Squall")
        {
            ui->label_alert->setText("A squall is \n approaching");
        }

        //For future weather1....
        ui->fWeather1->setText(fweather1);
        ui->fTemp1->setText(fTempr1+"°C");
        ui->fDate1->setText(mon1+" "+Date1);

        //For future weather2....
        ui->fWeather2->setText(fweather2);
        ui->fTemp2->setText(fTempr2+"°C");
        ui->fDate2->setText(mon2+" "+Date2);

        //For future weather3.....
        ui->fWeather3->setText(fweather3);
        ui->fTemp3->setText(fTempr3+"°C");
        ui->fDate3->setText(mon3+" "+Date3);

        //For present weather1...
        if(weather1!="")
        {
            ui->weather1->setText(weather1);
            ui->temp1->setText(Tempr1+"°C");
            ui->time1->setText(Hour1+":"+Min1);
        }
        else
        {
            ui->weather1->setText("-");
            ui->temp1->setText("-");
            ui->time1->setText("-");
        }

        //For present weather2....
        if(weather2!="")
        {
            ui->weather2->setText(weather2);
            ui->temp2->setText(Tempr2+"°C");
            ui->time2->setText(Hour2+":"+Min2);
        }
        else
        {
            ui->weather2->setText("-");
            ui->temp2->setText("-");
            ui->time2->setText("-");
        }

        //For present weather3...
        if(weather3!="")
        {
            ui->weather3->setText(weather3);
            ui->temp3->setText(Tempr3+"°C");
            ui->time3->setText(Hour3+":"+Min3);
        }
        else
        {
            ui->weather3->setText("-");
            ui->temp3->setText("-");
            ui->time3->setText("-");
        }

        //For present weather4....
        if(weather4!="")
        {
            ui->weather4->setText(weather4);
            ui->temp4->setText(Tempr4+"°C");
            ui->time4->setText(Hour4+":"+Min4);
        }
        else
        {
            ui->weather4->setText("-");
            ui->temp4->setText("-");
            ui->time4->setText("-");
        }

        //For present weather5.....
        if(weather5!="")
        {
            ui->weather5->setText(weather5);
            ui->temp5->setText(Tempr5+"°C");
            ui->time5->setText(Hour5+":"+Min5);
        }
        else
        {
            ui->weather5->setText("-");
            ui->temp5->setText("-");
            ui->time5->setText("-");
        }

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

        ui->labelFuture->setStyleSheet("color:#F0EFF9; background:transparent; font: 13pt 'Segoe UI';");
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

        if(!notCheck){
            ui->label_notification->setStyleSheet("background:rgba(255,255,255,0.1);font: 10pt 'Segoe UI';color:#F0EFF9;"
                                                  "border-radius:12%;padding-left:5px;padding-bottom:3px;"
                                                  "padding-top:1px;");
        }else{
            ui->label_notification->setStyleSheet("background:transparent;");
        }
        checkLight=false;
    }
    else
    {
        ui->light_btn->setIcon(QIcon(":/new/prefix1/image/dark.svg"));
        ui->centralwidget->setStyleSheet("background-image: url(':/new/prefix1/image/mainbackground.png');");

        ui->labelFuture->setStyleSheet("color:black; background:transparent; font: 13pt 'Segoe UI';");
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

        if(!notCheck){
            ui->label_notification->setStyleSheet("background:rgba(255,255,255,0.1);font: 10pt 'Segoe UI';color:black;"
                                                  "border-radius:12%;padding-left:5px;padding-bottom:3px;"
                                                  "padding-top:1px;");
        }else{
            ui->label_notification->setStyleSheet("background:transparent;");
        }
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

void MainWindow::on_label_gif_clicked()
{
    if(notCheck){
        if(check==false)
        {
            if(status_string == "Clouds"){
                ui->label_notification->setText("गम्भीर मौसमको अपेक्षा छैन।\n तापक्रम चिसो महसुस हुन सक्छ।");
            }
            if(status_string == "Thunderstorm")
            {
                ui->label_notification->setText("क्षेत्रमा मेघगर्जनको सम्भावना छ।\nभित्रै बस्नुहोस् र बाहिरी गतिविधिहरूबाट टाढा रहनुहोस्।");
            }
            if(status_string == "Drizzle")
            {
                ui->label_notification->setText("हल्का पानी पर्न सक्ने सम्भावना छ।\nछाता लिनुहोस्।\n सडकहरू चिप्लन सक्छन्।");
            }
            if(status_string == "Mist" || status_string == "Haze" || status_string == "Fog")
            {
                ui->label_notification->setText("दृश्यता थोरै घट्न सक्दछ।\n ध्यानपूर्वक चलाउनुहोस्।");
            }
            if(status_string == "Rain")
            {
                ui->label_notification->setText("क्षेत्रमा मध्यम वर्षा भइरहेको छ।\n चिप्लने सडक र घटेको दृश्यताका लागि तयार रहनुहोस्।\n गाडी चलाउँदा सतर्क रहनुहोस्।");
            }
            if(status_string == "Clear")
            {
                ui->label_notification->setText("गम्भीर मौसमको अपेक्षा छैन।\n मौसमको मजा लिनुहोस्।");
            }
            if(status_string == "Smoke")
            {
                ui->label_notification->setText("क्षेत्रमा हल्का धुँवा छ।\n हवाई गुणस्तर प्रभावित हुन सक्दछ।\n बाहिरी गतिविधिहरू सीमित गर्नुहोस्।");
            }
            if(status_string == "Snow")
            {
                ui->label_notification->setText("चिप्लने सडकका लागि तयार हुनुहोस्।\n सावधानीपूर्वक गाडी चलाउनुहोस् र न्यानो लुगा लगाउनुहोस्।");
            }
            if(status_string=="Dust" || status_string=="Sand" || status_string=="Ash")
            {
                ui->label_notification->setText("क्षेत्रमा हल्का धूलो छ।\n हवाई गुणस्तर प्रभावित हुन सक्दछ।\n बाहिरी गतिविधिहरू सीमित गर्नुहोस्।");
            }
            if(status_string=="Tornado")
            {
                ui->label_notification->setText("तूफान निगरानी प्रभावी छ।\n सम्भावित तूफान का लागि तयार रहनुहोस्।\n मौसम अपडेटहरू अनुगमन गर्नुहोस् र आपतकालीन योजना तयार गर्नुहोस्।");
            }
            if(status_string=="Squall")
            {
                ui->label_notification->setText("हल्का तुफान नजिकै आइरहेको छ। संक्षिप्त तीव्र हावा र सम्भावित वर्षाका लागि तयार हुनुहोस्।");
            }
        }
        else
        {
            if(status_string == "Clouds"){
                ui->label_notification->setText("No severe weather expected.\nTemperatures may feel cooler.");
            }
            if(status_string == "Thunderstorm")
            {
                ui->label_notification->setText("Thunderstorm in the area.\n"
                                                "Stay indoors and avoid outdoor activities.");
            }
            if(status_string == "Drizzle")
            {
                ui->label_notification->setText("Light drizzle expected.\n"
                                                "Carry an umbrella. Roads may be slippery.");
            }
            if(status_string == "Mist" || status_string == "Haze" || status_string == "Fog")
            {
                ui->label_notification->setText("Visibility may be slightly reduced.\nDrive carefully.");
            }
            if(status_string == "Rain")
            {
                ui->label_notification->setText("Moderate rain in the area.\n"
                                                "Prepare for slippery roads and reduced visibility.\n"
                                                "Be cautious while driving.");
            }
            if(status_string == "Clear")
            {
                ui->label_notification->setText("No severe weather expected.\nEnjoy the weather.");
            }
            if(status_string == "Smoke")
            {
                ui->label_notification->setText("Light smoke in the area.\n"
                                                "Air quality may be affected.\n"
                                                "Limit outdoor activities.");
            }
            if(status_string == "Snow")
            {
                ui->label_notification->setText("Prepare for slippery roads.\n"
                                                "Drive cautiously and dress warmly.");
            }
            if(status_string=="Dust" || status_string=="Sand" || status_string=="Ash")
            {
                ui->label_notification->setText("Light dust in the area.\n"
                                                "Air quality may be affected.\n"
                                                "Limit outdoor activities.");
            }
            if(status_string=="Tornado")
            {
                ui->label_notification->setText("Tornado Watch in effect.\n"
                                                "Be prepared for possible tornado.\n"
                                                "Monitor weather updates and have an emergency plan in place.");
            }
            if(status_string=="Squall")
            {
                ui->label_notification->setText("Light squall approaching.\n"
                                                "Prepare for brief gusty winds and possible rain.");
            }
        }

        if(!checkLight){
            ui->label_notification->setStyleSheet("background:rgba(255,255,255,0.1);font: 10pt 'Segoe UI';color:#F0EFF9;"
                                                  "border-radius:12%;padding-left:5px;padding-bottom:3px;"
                                                  "padding-top:1px;");
        }else{
            ui->label_notification->setStyleSheet("background:rgba(255,255,255,0.1);font: 10pt 'Segoe UI';color:black;"
                                                  "border-radius:12%;padding-left:5px;padding-bottom:3px;"
                                                  "padding-top:1px;");
        }
        notCheck=false;
    }else{
        ui->label_notification->setText("");
        ui->label_notification->setStyleSheet("background:transparent;");
        notCheck=true;
    }
}

