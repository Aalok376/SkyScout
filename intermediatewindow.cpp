#include "intermediatewindow.h"
#include "ui_intermediatewindow.h"

QString pasttemp;
QString presenttemp;
QString futuretemp;

QString pasthumidity;
QString presenthumidity;
QString futurehumidity;

QString paststatus;
QString presentstatus;
QString futurestatus;

QString latitude;
QString longitude;

intermediateWindow::intermediateWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::intermediateWindow)
{
    ui->setupUi(this);
    setWindowTitle("Sky Scout");
    setWindowIcon(QIcon(":/new/prefix1/image/projectLogo.png"));

    ui->return_btn->setIcon(QIcon(":/new/prefix1/image/return.svg"));
    int y =ui->return_btn->height();
    ui->return_btn->setIconSize(QSize(y,y));

    connect(ui->return_btn, &QPushButton::clicked, this, &intermediateWindow::on_return_btn_clicked);
    resize(800,600);
    setFixedSize(size());


    if(checkLight==false)
    {
        ui->centralWidget->setStyleSheet("background-image: url(':/new/prefix1/image/dark_bg.png');");

        ui->btnPast->setStyleSheet("QPushButton{font: 10pt 'Segoe UI';color:#F0EFF9;"
                                    "background:rgba(255,255,255,.1);border-radius:12%;}"
                                   "QPushButton:hover{background:rgba(255,255,255,.3);}");

        ui->past_data_btn->setStyleSheet("QPushButton{ font: 10pt 'Segoe UI';color:#F0EFF9;"
                                         "background:rgba(255,255,255,.1);}"
                                         "QPushButton:hover{background:rgba(255,255,255,.3);}");

        ui->locationpast->setStyleSheet("background:transparent;font: 16pt 'Segoe UI';color:#F0EFF9;");
        ui->pastLocation->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastLocation_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastTemp->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastTemp_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastHumidity->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastHumidity_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastStatus->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastStatus_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastLat->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastLat_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastLon->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastLon_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");

        ui->btnPresent->setStyleSheet("QPushButton{font: 10pt 'Segoe UI';color:#F0EFF9;"
                                   "background:rgba(255,255,255,.1);border-radius:12%;}"
                                   "QPushButton:hover{background:rgba(255,255,255,.3);}");


        ui->present_data_btn->setStyleSheet("QPushButton{ font: 10pt 'Segoe UI';color:#F0EFF9;"
                                         "background:rgba(255,255,255,.1);}"
                                         "QPushButton:hover{background:rgba(255,255,255,.3);}");

        ui->locationpresent->setStyleSheet("background:transparent;font: 16pt 'Segoe UI';color:#F0EFF9;");
        ui->presentLocation->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentLocation_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentTemp->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentTemp_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentHumidity->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentHumidity_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentStatus->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentStatus_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentLat->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentLat_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentLon->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentLon_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");

        ui->btnFuture->setStyleSheet("QPushButton{font: 10pt 'Segoe UI';color:#F0EFF9;"
                                   "background:rgba(255,255,255,.1);border-radius:12%;}"
                                   "QPushButton:hover{background:rgba(255,255,255,.3);}");


        ui->future_data_btn->setStyleSheet("QPushButton{ font: 10pt 'Segoe UI';color:#F0EFF9;"
                                         "background:rgba(255,255,255,.1);}"
                                         "QPushButton:hover{background:rgba(255,255,255,.3);}");

        ui->locationfuture->setStyleSheet("background:transparent;font: 16pt 'Segoe UI';color:#F0EFF9;");
        ui->futureLocation->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureLocation_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureTemp->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureTemp_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureHumidity->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureHumidity_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureStatus->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureStatus_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureLat->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureLat_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureLon->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureLon_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");



    }
    else
    {

        ui->centralWidget->setStyleSheet("background-image: url(':/new/prefix1/image/background.png');");

        ui->btnPast->setStyleSheet("QPushButton{font: 10pt 'Segoe UI';color:black;"
                                   "background:rgba(255,255,255,.1);border-radius:12%;}"
                                   "QPushButton:hover{background:rgba(255,255,255,.3);}");


        ui->past_data_btn->setStyleSheet("QPushButton{ font: 10pt 'Segoe UI';color:black;"
                                         "background:rgba(255,255,255,.1);}"
                                         "QPushButton:hover{background:rgba(255,255,255,.3);}");

        ui->locationpast->setStyleSheet("background:transparent;font: 16pt 'Segoe UI';color:black;");
        ui->pastLocation->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastLocation_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastTemp->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastTemp_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastHumidity->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastHumidity_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastStatus->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastStatus_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastLat->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastLat_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastLon->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastLon_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");

        ui->btnPresent->setStyleSheet("QPushButton{font: 10pt 'Segoe UI';color:black;"
                                   "background:rgba(255,255,255,.1);border-radius:12%;}"
                                   "QPushButton:hover{background:rgba(255,255,255,.3);}");


        ui->past_data_btn->setStyleSheet("QPushButton{ font: 10pt 'Segoe UI';color:black;"
                                         "background:rgba(255,255,255,.1);}"
                                         "QPushButton:hover{background:rgba(255,255,255,.3);}");


        ui->locationpresent->setStyleSheet("background:transparent;font: 16pt 'Segoe UI';color:black;");
        ui->presentLocation->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentLocation_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentTemp->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentTemp_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentHumidity->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentHumidity_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentStatus->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentStatus_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentLat->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentLat_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentLon->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentLon_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");

        ui->btnFuture->setStyleSheet("QPushButton{font: 10pt 'Segoe UI';color:black;"
                                   "background:rgba(255,255,255,.1);border-radius:12%;}"
                                   "QPushButton:hover{background:rgba(255,255,255,.3);}");


        ui->past_data_btn->setStyleSheet("QPushButton{ font: 10pt 'Segoe UI';color:black;"
                                         "background:rgba(255,255,255,.1);}"
                                         "QPushButton:hover{background:rgba(255,255,255,.3);}");


        ui->locationfuture->setStyleSheet("background:transparent;font: 16pt 'Segoe UI';color:black;");
        ui->futureLocation->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureLocation_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureTemp->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureTemp_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureHumidity->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureHumidity_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureStatus->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureStatus_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureLat->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureLat_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureLon->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureLon_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");

    }

    connect(ui->btnPast, &QPushButton::clicked, [this]() { slideToPage(0); });
    connect(ui->btnPresent, &QPushButton::clicked, [this]() { slideToPage(1); });
    connect(ui->btnFuture, &QPushButton::clicked, [this]() { slideToPage(2); });


    // Initially, show the first page
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->widget(0)->show();


     // str="Welcome! \n Stay updated with the current weather.";
     // word = str.split(" ");
     // CurrentWordIndex=0;
     // timer= new QTimer(this);
     // connect(timer ,&QTimer::timeout , this , &intermediateWindow::updateLabelText );
     // timer->start(500);

    QString city;
    QVector<double> temp;
    QVector<double> humidity;
    QVector<QString> status;
    double lat;
    double lon;


    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(QCoreApplication::applicationDirPath()+"/database/weatherdb.db");

    mydb.open();

    QSqlQuery query;
    query.prepare("SELECT city,temperature,humidity,lat,lon,status FROM pastWeather");


    if(query.exec()){

        while(query.next()){
            city = query.value(0).toString();
            temp.append(query.value(1).toDouble());
            humidity.append(query.value(2).toDouble());
            lat = query.value(3).toDouble();
            latitude=QString::number(lat);
            lon = query.value(4).toDouble();
            longitude=QString::number(lon);
            status.append(query.value(5).toString());

        }
    }else{
        qDebug()<<"error";
    }

    double tem[temp.size()];
    for(int i=0;i<temp.size();i++){
        tem[i]=temp[i];
    }
    double hum[humidity.size()];
    for(int i=0;i<humidity.size();i++){
        hum[i]=humidity[i];
    }
     QString sta[status.size()];
     for(int i=0;i<status.size();i++){
         sta[i]=status[i];
    }

    double t = logicMaths::avgTemp(tem,temp.size());
    pasttemp=QString::number(t);
    double h = logicMaths::avgHumidity(hum,humidity.size());
    pasthumidity=QString::number(h);
    QString s = logicMaths::weatherMode(sta,status.size());
    paststatus=s;

    ui->locationpast->setText(city+", Nepal");
    QIcon icon = logicMaths::getStatusIcon(s);
    ui->iconpast->setPixmap(icon.pixmap(QSize(85,51)));

    ui->pastLocation_2->setText(city);
    t = logicMaths::twoDecimals(t);
    h = logicMaths::twoDecimals(h);
    ui->pastTemp_2->setText(QString::number(t)+"°C");
    ui->pastHumidity_2->setText(QString::number(h)+"%");
    ui->pastStatus_2->setText(s);
    ui->pastLat_2->setText(QString::number(lat));
    ui->pastLon_2->setText(QString::number(lon));

    //present data

    QVector<double> temp2;
    QVector<double> humidity2;
    QVector<QString> status2;
    mydb.setDatabaseName(QCoreApplication::applicationDirPath()+"/database/onedaydata.db");

    mydb.open();

    query.prepare("SELECT city,temperature,humidity,status,lat,lon FROM currentWeather");


    if(query.exec()){

        while(query.next()){
            city = query.value(0).toString();
            temp2.append(query.value(1).toDouble());
            humidity2.append(query.value(2).toDouble());
            status2.append(query.value(3).toString());
            lat = query.value(4).toDouble();
            lon = query.value(5).toDouble();
        }
    }else{
        qDebug()<<"error";
    }

     double tem0[temp2.size()];
    for(int i=0;i<temp2.size();i++){
        tem0[i]=temp2[i];
    }
    double hum0[humidity2.size()];
    for(int i=0;i<humidity2.size();i++){
        hum0[i]=humidity2[i];
    }
    QString sta0[status2.size()];
    for(int i=0;i<status2.size();i++){
        sta0[i]=status2[i];
    }

    t = logicMaths::avgTemp(tem0,temp2.size());
    t = logicMaths::twoDecimals(t);
    presenttemp=QString::number(t);
    h = logicMaths::avgHumidity(hum0,humidity2.size());
    h = logicMaths::twoDecimals(h);
    presenthumidity=QString::number(h);
    s = logicMaths::weatherMode(sta0,status2.size());
    presentstatus=s;

    ui->locationpresent->setText(city+", Nepal");
    icon = logicMaths::getStatusIcon(s);
    ui->iconpresent->setPixmap(icon.pixmap(QSize(85,51)));

    ui->presentLocation_2->setText(city);
    ui->presentTemp_2->setText(QString::number(t)+"°C");
    ui->presentHumidity_2->setText(QString::number(h)+"%");
    ui->presentStatus_2->setText(s);
    ui->presentLat_2->setText(QString::number(lat));
    ui->presentLon_2->setText(QString::number(lon));

    //future data

    QVector<double> temp3;
    QVector<double> humidity3;
    QVector<QString> status3;
    mydb.setDatabaseName(QCoreApplication::applicationDirPath()+"/database/futuredata.db");

    mydb.open();

    query.prepare("SELECT city,temperature,humidity,status FROM futureWeather");


    if(query.exec()){

        while(query.next()){
            city = query.value(0).toString();
            temp3.append(query.value(1).toDouble());
            humidity3.append(query.value(2).toDouble());
            status3.append(query.value(3).toString());

        }
    }else{
        qDebug()<<"error";
    }

    double tem1[temp3.size()];
    for(int i=0;i<temp3.size();i++){
        tem1[i]=temp3[i];
    }
    double hum1[humidity3.size()];
    for(int i=0;i<humidity3.size();i++){
        hum1[i]=humidity3[i];
    }
    QString sta1[status3.size()];
    for(int i=0;i<status3.size();i++){
        sta1[i]=status3[i];
    }

    t = logicMaths::avgTemp(tem1,temp3.size());
    t = logicMaths::tempConversion(t);
    t = logicMaths::twoDecimals(t);
    futuretemp=QString::number(t);

    h = logicMaths::avgHumidity(hum1,humidity3.size());
    h = logicMaths::twoDecimals(h);
    futurehumidity=QString::number(h);

    s = logicMaths::weatherMode(sta1,status3.size());
    futurestatus=s;

    ui->locationfuture->setText(city+", Nepal");
    icon = logicMaths::getStatusIcon(s);
    ui->iconfuture->setPixmap(icon.pixmap(QSize(85,51)));

    ui->futureLocation_2->setText(city);
    ui->futureTemp_2->setText(QString::number(t)+"°C");
    ui->futureHumidity_2->setText(QString::number(h)+"%");
    ui->futureStatus_2->setText(s);
    ui->futureLat_2->setText(QString::number(lat));
    ui->futureLon_2->setText(QString::number(lon));

    ui->btnPast->setText("Past Weather");
    ui->btnPresent->setText("Present Weather");
    ui->btnFuture->setText("Future Weather");

    ui->past_data_btn->setText("View Insights");
    ui->present_data_btn->setText("View Insights");
    ui->future_data_btn->setText("View Insights");

    ui->pastHumidity->setText("Humidity");
    ui->pastLat->setText("Latitude");
    ui->pastLocation->setText("Location");
    ui->pastLon->setText("Longitude");
    ui->pastStatus->setText("Status");
    ui->pastTemp->setText("Temperature");

    ui->presentHumidity->setText("Humidity");
    ui->presentLat->setText("Latitude");
    ui->presentLocation->setText("Location");
    ui->presentLon->setText("Longitude");
    ui->presentStatus->setText("Status");
    ui->presentTemp->setText("Temperature");

    ui->futureHumidity->setText("Humidity");
    ui->futureLat->setText("Latitude");
    ui->futureLocation->setText("Location");
    ui->futureLon->setText("Longitude");
    ui->futureStatus->setText("Status");
    ui->futureTemp->setText("Temperature");

    if(check==false)
    {
        ui->btnPast->setText("विगतको मौसम");
        ui->btnPresent->setText("वर्तमान मौसम");
        ui->btnFuture->setText("आगामी मौसम");

        ui->past_data_btn->setText("थप जानकारी");
        ui->present_data_btn->setText("थप जानकारी");
        ui->future_data_btn->setText("थप जानकारी");

        ui->pastHumidity->setText("आर्द्रता");
        ui->pastLat->setText("अक्षांश");
        ui->pastLocation->setText("स्थान");
        ui->pastLon->setText("देशान्तर");
        ui->pastStatus->setText("स्थिति");
        ui->pastTemp->setText("तापक्रम");

        ui->presentHumidity->setText("आर्द्रता");
        ui->presentLat->setText("अक्षांश");
        ui->presentLocation->setText("स्थान");
        ui->presentLon->setText("देशान्तर");
        ui->presentStatus->setText("स्थिति");
        ui->presentTemp->setText("तापक्रम");

        ui->futureHumidity->setText("आर्द्रता");
        ui->futureLat->setText("अक्षांश");
        ui->futureLocation->setText("स्थान");
        ui->futureLon->setText("देशान्तर");
        ui->futureStatus->setText("स्थिति");
        ui->futureTemp->setText("तापक्रम");

        //for past weather
        if(paststatus=="Clouds")
        {
            ui->pastStatus_2->setText("बादल");
        }
        if(paststatus=="Thunderstorm")
        {
            ui->pastStatus_2->setText("चट्याङ");
        }
        if(paststatus=="Drizzle")
        {
            ui->pastStatus_2->setText("मुसलधारे पानी");
        }
        if(paststatus=="Mist" || paststatus=="Haze" || paststatus=="Fog")
        {
            ui->pastStatus_2->setText("कुहिरो");
        }
        if(paststatus=="Rain")
        {
            ui->pastStatus_2->setText("वर्षा");
        }
        if(paststatus=="Clear")
        {
            ui->pastStatus_2->setText("सफा मौसम");
        }
        if(paststatus=="Smoke")
        {
            ui->pastStatus_2->setText("धुवाँ");
        }
        if(paststatus=="Snow")
        {
            ui->pastStatus_2->setText("हिउँ");
        }
        if(paststatus=="Dust" || paststatus=="Sand" || paststatus=="Ash")
        {
            ui->pastStatus_2->setText("धुलो");
        }
        if(paststatus=="Tornado")
        {
            ui->pastStatus_2->setText("भुमरी");
        }
        if(paststatus=="Squall")
        {
            ui->pastStatus_2->setText("तूफान");
        }

        QString Tempr;
        for(int i=0;i<pasttemp.length();i++)
        {
            if(pasttemp[i]=='0')
            {
                Tempr=Tempr+"०";
            }
            if(pasttemp[i]=='1')
            {
                Tempr=Tempr+"१";
            }
            if(pasttemp[i]=='2')
            {
                Tempr=Tempr+"२";
            }
            if(pasttemp[i]=='3')
            {
                Tempr=Tempr+"३";
            }
            if(pasttemp[i]=='4')
            {
                Tempr=Tempr+"४";
            }
            if(pasttemp[i]=='5')
            {
                Tempr=Tempr+"५";
            }
            if(pasttemp[i]=='6')
            {
                Tempr=Tempr+"६";
            }
            if(pasttemp[i]=='7')
            {
                Tempr=Tempr+"७";
            }
            if(pasttemp[i]=='8')
            {
                Tempr=Tempr+"८";
            }
            if(pasttemp[i]=='9')
            {
                Tempr=Tempr+"९";
            }
            if(pasttemp[i]=='.')
            {
                Tempr=Tempr+".";
            }
        }
        ui->pastTemp_2->setText(Tempr+"°C");

        //For humidity....
        QString hum0;
        for(int i=0;i<pasthumidity.length();i++)
        {
            if(pasthumidity[i]=='0')
            {
                hum0=hum0+"०";
            }
            if(pasthumidity[i]=='1')
            {
                hum0=hum0+"१";
            }
            if(pasthumidity[i]=='2')
            {
                hum0=hum0+"२";
            }
            if(pasthumidity[i]=='3')
            {
                hum0=hum0+"३";
            }
            if(pasthumidity[i]=='4')
            {
                hum0=hum0+"४";
            }
            if(pasthumidity[i]=='5')
            {
                hum0=hum0+"५";
            }
            if(pasthumidity[i]=='6')
            {
                hum0=hum0+"६";
            }
            if(pasthumidity[i]=='7')
            {
                hum0=hum0+"७";
            }
            if(pasthumidity[i]=='8')
            {
                hum0=hum0+"८";
            }
            if(pasthumidity[i]=='9')
            {
                hum0=hum0+"९";
            }
            if(pasthumidity[i]=='.')
            {
                hum0=hum0+".";
            }
        }
        ui->pastHumidity_2->setText(hum0+"%");

        QString lati;
        for(int i=0;i<latitude.length();i++)
        {
            if(latitude[i]=='0')
            {
                lati=lati+"०";
            }
            if(latitude[i]=='1')
            {
                lati=lati+"१";
            }
            if(latitude[i]=='2')
            {
                lati=lati+"२";
            }
            if(latitude[i]=='3')
            {
                lati=lati+"३";
            }
            if(latitude[i]=='4')
            {
                lati=lati+"४";
            }
            if(latitude[i]=='5')
            {
                lati=lati+"५";
            }
            if(latitude[i]=='6')
            {
                lati=lati+"६";
            }
            if(latitude[i]=='7')
            {
                lati=lati+"७";
            }
            if(latitude[i]=='8')
            {
                lati=lati+"८";
            }
            if(latitude[i]=='9')
            {
                lati=lati+"९";
            }
            if(latitude[i]=='.')
            {
                lati=lati+".";
            }
        }

        QString longi;
        for(int i=0;i<longitude.length();i++)
        {
            if(longitude[i]=='0')
            {
                longi=longi+"०";
            }
            if(longitude[i]=='1')
            {
                longi=longi+"१";
            }
            if(longitude[i]=='2')
            {
                longi=longi+"२";
            }
            if(longitude[i]=='3')
            {
                longi=longi+"३";
            }
            if(longitude[i]=='4')
            {
                longi=longi+"४";
            }
            if(longitude[i]=='5')
            {
                longi=longi+"५";
            }
            if(longitude[i]=='6')
            {
                longi=longi+"६";
            }
            if(longitude[i]=='7')
            {
                longi=longi+"७";
            }
            if(longitude[i]=='8')
            {
                longi=longi+"८";
            }
            if(longitude[i]=='9')
            {
                longi=longi+"९";
            }
            if(longitude[i]=='.')
            {
                longi=longi+".";
            }
        }
        ui->pastLat_2->setText(lati);
        ui->pastLon_2->setText(longi);
        ui->presentLat_2->setText(lati);
        ui->presentLon_2->setText(longi);
        ui->futureLat_2->setText(lati);
        ui->futureLon_2->setText(longi);

        //For present weather.....
        if(presentstatus=="Clouds")
        {
            ui->presentStatus_2->setText("बादल");
        }
        if(presentstatus=="Thunderstorm")
        {
            ui->presentStatus_2->setText("चट्याङ");
        }
        if(presentstatus=="Drizzle")
        {
            ui->presentStatus_2->setText("मुसलधारे पानी");
        }
        if(presentstatus=="Mist" || presentstatus=="Haze" || presentstatus=="Fog")
        {
            ui->presentStatus_2->setText("कुहिरो");
        }
        if(presentstatus=="Rain")
        {
            ui->presentStatus_2->setText("वर्षा");
        }
        if(presentstatus=="Clear")
        {
            ui->presentStatus_2->setText("सफा मौसम");
        }
        if(presentstatus=="Smoke")
        {
            ui->presentStatus_2->setText("धुवाँ");
        }
        if(presentstatus=="Snow")
        {
            ui->presentStatus_2->setText("हिउँ");
        }
        if(presentstatus=="Dust" || presentstatus=="Sand" || presentstatus=="Ash")
        {
            ui->presentStatus_2->setText("धुलो");
        }
        if(presentstatus=="Tornado")
        {
            ui->presentStatus_2->setText("भुमरी");
        }
        if(presentstatus=="Squall")
        {
            ui->presentStatus_2->setText("तूफान");
        }

        QString Temp;
        for(int i=0;i<presenttemp.length();i++)
        {
            if(presenttemp[i]=='0')
            {
                Temp=Temp+"०";
            }
            if(presenttemp[i]=='1')
            {
                Temp=Temp+"१";
            }
            if(presenttemp[i]=='2')
            {
                Temp=Temp+"२";
            }
            if(presenttemp[i]=='3')
            {
                Temp=Temp+"३";
            }
            if(presenttemp[i]=='4')
            {
                Temp=Temp+"४";
            }
            if(presenttemp[i]=='5')
            {
                Temp=Temp+"५";
            }
            if(presenttemp[i]=='6')
            {
                Temp=Temp+"६";
            }
            if(presenttemp[i]=='7')
            {
                Temp=Temp+"७";
            }
            if(presenttemp[i]=='8')
            {
                Temp=Temp+"८";
            }
            if(presenttemp[i]=='9')
            {
                Temp=Temp+"९";
            }
            if(presenttemp[i]=='.')
            {
                Temp=Temp+".";
            }
        }
        ui->presentTemp_2->setText(Temp+"°C");

        //For humidity....
        QString hum;
        for(int i=0;i<presenthumidity.length();i++)
        {
            if(presenthumidity[i]=='0')
            {
                hum=hum+"०";
            }
            if(presenthumidity[i]=='1')
            {
                hum=hum+"१";
            }
            if(presenthumidity[i]=='2')
            {
                hum=hum+"२";
            }
            if(presenthumidity[i]=='3')
            {
                hum=hum+"३";
            }
            if(presenthumidity[i]=='4')
            {
                hum=hum+"४";
            }
            if(presenthumidity[i]=='5')
            {
                hum=hum+"५";
            }
            if(presenthumidity[i]=='6')
            {
                hum=hum+"६";
            }
            if(presenthumidity[i]=='7')
            {
                hum=hum+"७";
            }
            if(presenthumidity[i]=='8')
            {
                hum=hum+"८";
            }
            if(presenthumidity[i]=='9')
            {
                hum=hum+"९";
            }
            if(presenthumidity[i]=='.')
            {
                hum=hum+".";
            }
        }
        ui->presentHumidity_2->setText(hum+"%");

        //For future weather.....
        if(futurestatus=="Clouds")
        {
            ui->futureStatus_2->setText("बादल");
        }
        if(futurestatus=="Thunderstorm")
        {
            ui->futureStatus_2->setText("चट्याङ");
        }
        if(futurestatus=="Drizzle")
        {
            ui->futureStatus_2->setText("मुसलधारे पानी");
        }
        if(futurestatus=="Mist" || futurestatus=="Haze" || futurestatus=="Fog")
        {
            ui->futureStatus_2->setText("कुहिरो");
        }
        if(futurestatus=="Rain")
        {
            ui->futureStatus_2->setText("वर्षा");
        }
        if(futurestatus=="Clear")
        {
            ui->futureStatus_2->setText("सफा मौसम");
        }
        if(futurestatus=="Smoke")
        {
            ui->futureStatus_2->setText("धुवाँ");
        }
        if(futurestatus=="Snow")
        {
            ui->futureStatus_2->setText("हिउँ");
        }
        if(futurestatus=="Dust" || futurestatus=="Sand" || futurestatus=="Ash")
        {
            ui->futureStatus_2->setText("धुलो");
        }
        if(futurestatus=="Tornado")
        {
            ui->futureStatus_2->setText("भुमरी");
        }
        if(futurestatus=="Squall")
        {
            ui->futureStatus_2->setText("तूफान");
        }

        QString Tem;
        for(int i=0;i<futuretemp.length();i++)
        {
            if(futuretemp[i]=='0')
            {
                Tem=Tem+"०";
            }
            if(futuretemp[i]=='1')
            {
                Tem=Tem+"१";
            }
            if(futuretemp[i]=='2')
            {
                Tem=Tem+"२";
            }
            if(futuretemp[i]=='3')
            {
                Tem=Tem+"३";
            }
            if(futuretemp[i]=='4')
            {
                Tem=Tem+"४";
            }
            if(futuretemp[i]=='5')
            {
                Tem=Tem+"५";
            }
            if(futuretemp[i]=='6')
            {
                Tem=Tem+"६";
            }
            if(futuretemp[i]=='7')
            {
                Tem=Tem+"७";
            }
            if(futuretemp[i]=='8')
            {
                Tem=Tem+"८";
            }
            if(futuretemp[i]=='9')
            {
                Tem=Tem+"९";
            }
            if(futuretemp[i]=='.')
            {
                Tem=Tem+".";
            }
        }
        ui->futureTemp_2->setText(Tem+"°C");

        //For humidity....
        QString hu;
        for(int i=0;i<futurehumidity.length();i++)
        {
            if(futurehumidity[i]=='0')
            {
                hu=hu+"०";
            }
            if(futurehumidity[i]=='1')
            {
                hu=hu+"१";
            }
            if(futurehumidity[i]=='2')
            {
                hu=hu+"२";
            }
            if(futurehumidity[i]=='3')
            {
                hu=hu+"३";
            }
            if(futurehumidity[i]=='4')
            {
                hu=hu+"४";
            }
            if(futurehumidity[i]=='5')
            {
                hu=hu+"५";
            }
            if(futurehumidity[i]=='6')
            {
                hu=hu+"६";
            }
            if(futurehumidity[i]=='7')
            {
                hu=hu+"७";
            }
            if(futurehumidity[i]=='8')
            {
                hu=hu+"८";
            }
            if(futurehumidity[i]=='9')
            {
                hu=hu+"९";
            }
            if(futurehumidity[i]=='.')
            {
                hu=hu+".";
            }
        }
        ui->futureHumidity_2->setText(hu+"%");

    }
    else
    {
        ui->btnPast->setText("Past Weather");
        ui->btnPresent->setText("Present Weather");
        ui->btnFuture->setText("Future Weather");

        ui->past_data_btn->setText("View Insights");
        ui->present_data_btn->setText("View Insights");
        ui->future_data_btn->setText("View Insights");

        ui->pastHumidity->setText("Humidity");
        ui->pastLat->setText("Latitude");
        ui->pastLocation->setText("Location");
        ui->pastLon->setText("Longitude");
        ui->pastStatus->setText("Status");
        ui->pastTemp->setText("Temperature");

        ui->presentHumidity->setText("Humidity");
        ui->presentLat->setText("Latitude");
        ui->presentLocation->setText("Location");
        ui->presentLon->setText("Longitude");
        ui->presentStatus->setText("Status");
        ui->presentTemp->setText("Temperature");

        ui->futureHumidity->setText("Humidity");
        ui->futureLat->setText("Latitude");
        ui->futureLocation->setText("Location");
        ui->futureLon->setText("Longitude");
        ui->futureStatus->setText("Status");
        ui->futureTemp->setText("Temperature");

        //for past weather.....
        ui->pastTemp_2->setText(pasttemp+"°C");
        ui->pastHumidity_2->setText(pasthumidity+"%");
        ui->pastStatus_2->setText(paststatus);
        ui->pastLat_2->setText(latitude);
        ui->pastLon_2->setText(longitude);

        //for present weather.....
        ui->presentTemp_2->setText(presenttemp+"°C");
        ui->presentHumidity_2->setText(presenthumidity+"%");
        ui->presentStatus_2->setText(presentstatus);
        ui->presentLat_2->setText(latitude);
        ui->presentLon_2->setText(longitude);

        //for future weather....
        ui->futureTemp_2->setText(futuretemp+"°C");
        ui->futureHumidity_2->setText(futurehumidity+"%");
        ui->futureStatus_2->setText(futurestatus);
        ui->futureLat_2->setText(latitude);
        ui->futureLon_2->setText(longitude);
    }
}

intermediateWindow::~intermediateWindow()
{
    delete ui;
}


void intermediateWindow::slideToPage(int index)
{


    //newFile::accessMainWindowUI();

    if (index == currentIndex) return;


    QWidget *currentWidget = ui->stackedWidget->widget(currentIndex);
    QWidget *nextWidget = ui->stackedWidget->widget(index);

    // Determine the direction of the slide
    bool slideLeft = index < currentIndex;
    int stackedWidth = ui->stackedWidget->geometry().width();

    // Set up the next widget position for animation
    nextWidget->setGeometry(slideLeft ? -stackedWidth : stackedWidth, 0, stackedWidth, nextWidget->geometry().height());
    nextWidget->show();



    // Animation for the current widget
    QPropertyAnimation *currentWidgetAnim = new QPropertyAnimation(currentWidget, "pos");
    currentWidgetAnim->setDuration(250); // 500 ms
    currentWidgetAnim->setStartValue(currentWidget->pos());
    currentWidgetAnim->setEndValue(QPoint(slideLeft ? stackedWidth : -stackedWidth, 0));

    // Animation for the next widget
    QPropertyAnimation *nextWidgetAnim = new QPropertyAnimation(nextWidget, "pos");
    nextWidgetAnim->setDuration(250); // 500 ms
    nextWidgetAnim->setStartValue(nextWidget->pos());
    nextWidgetAnim->setEndValue(QPoint(0, 0));

    // Group the animations together
    QParallelAnimationGroup *animationGroup = new QParallelAnimationGroup(this);
    animationGroup->addAnimation(currentWidgetAnim);
    animationGroup->addAnimation(nextWidgetAnim);

    // Connect to clean up after animation
    connect(animationGroup, &QParallelAnimationGroup::finished, [currentWidget, nextWidget, index, this]() {
        currentWidget->hide(); // Hide the current widget after the animation
        ui->stackedWidget->setCurrentIndex(index); // Update the stacked widget index
        currentIndex = index; // Update the current index
    });

    // Start the animations
    animationGroup->start(QAbstractAnimation::DeleteWhenStopped);




}


// void intermediateWindow::updateLabelText(void){
//     if(CurrentWordIndex<word.size()){
//         ui->label->setText(ui->label->text()+" "+word[CurrentWordIndex]);
//         CurrentWordIndex++;
//     }
//     else
//     {
//         CurrentWordIndex=0;
//         ui->label->clear();
//     }
// }
void intermediateWindow::on_return_btn_clicked()
{
    //MainWindow *mainWindow = new MainWindow();
    //mainWindow->show();
    //this->hide();
    emit returnToMainWindow();
    this->close();
    return;
}

pastGraph *pg;
void intermediateWindow::on_past_data_btn_clicked()
{
    pg = new pastGraph();
    connect(pg, &pastGraph::returnToIntermediateWindow, this, &intermediateWindow::showIntermediateWindow);

    pg->show();

    this->hide();

    return;
}

void intermediateWindow::showIntermediateWindow() {
    this->show();
    disconnect(pg, &pastGraph::returnToIntermediateWindow, this, &intermediateWindow::showIntermediateWindow);
    pg->deleteLater();
    pg = nullptr;
    return;
}

presentGraph *pr;
void intermediateWindow::on_present_data_btn_clicked()
{
    pr = new presentGraph();
    connect(pr, &presentGraph::returnToIntermediateWindow, this, &intermediateWindow::showIntermediateWindowP);

    pr->show();

    this->hide();

    return;
}

void intermediateWindow::showIntermediateWindowP() {
    this->show();
    disconnect(pr, &presentGraph::returnToIntermediateWindow, this, &intermediateWindow::showIntermediateWindowP);
    pr->deleteLater();
    pr = nullptr;
    return;
}

futureGraph *fg;
void intermediateWindow::on_future_data_btn_clicked()
{
    fg = new futureGraph();
    connect(fg, &futureGraph::returnToIntermediateWindow, this, &intermediateWindow::showIntermediateWindowF);

    fg->show();

    this->hide();

    return;
}

void intermediateWindow::showIntermediateWindowF() {
    this->show();
    disconnect(fg, &futureGraph::returnToIntermediateWindow, this, &intermediateWindow::showIntermediateWindowF);
    fg->deleteLater();
    fg = nullptr;
    return;
}

