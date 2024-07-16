#include "todaysweather.h"

todaysWeather::todaysWeather() {

}
void todaysWeather::databaseConnection(QString city, double temp,double humidity,QString status,double lat,double lon,
                                     int sunrise,int sunset,int ctime,int year,int month,int date,int hour,int min) {
    QSqlDatabase currentdb=QSqlDatabase::addDatabase("QSQLITE");
    currentdb.setDatabaseName("D:/Interessant/qtp/finalProject/database/onedaydata.db");


    currentdb.open();
    insertInformation(city,temp,humidity,status,lat,lon,sunrise,sunset,ctime,year,month,date,hour,min);

    return;
}
void todaysWeather::insertInformation(QString city, double temp,double humidity,QString status,double lat,double lon,
                                    int sunrise,int sunset,int ctime,int year,int month,int date,int hour,int min) {

    QSqlQuery query;

    query.prepare("SELECT * FROM currentWeather");
    query.exec();
    int rowCount=0;
    int largest;
    while (query.next()) {
        rowCount++;
        largest = query.value(0).toInt();
    }
    qDebug()<<"row count is"<<rowCount;
    int id;
    if(rowCount==0){
        id=1;
    }else{
        id=largest+1;
    }


    int previousId = id-1;
    QString previousCity;
    double prevT;
    int prevY;
    int prevM;
    int prevD;
    int prevH;

    // if(previousId==0){
    //     goto label;
    // }
    query.prepare("SELECT city,temperature,year,month,date,hour FROM currentWeather WHERE id=:previousId");
    query.bindValue(":previousId",previousId);

    if (query.exec()) {
        if (query.next()) {
            previousCity = query.value(0).toString();
            prevT = query.value(1).toDouble();
            prevY = query.value(2).toInt();
            prevM = query.value(3).toInt();
            prevD = query.value(4).toInt();
            prevH = query.value(5).toInt();
        } else {
            // Handle case where no results are returned
            qDebug() << "No results returned for id no. " << previousId;
        }
    } else {
        // Handle query execution error
        qDebug() << "Query error: " << query.lastError();
    }
    if(year!=prevY || month!=prevM || date!=prevD) {
        if(rowCount>0){
            query.prepare("DELETE FROM currentWeather");
            if(!query.exec()) {
                qDebug()<<"failed to delete previous day's data";
            }else{
                qDebug()<<"previous day's data deleted";
            }
        }
    }
    if(rowCount>0){
        if(city.toUpper()!=previousCity.toUpper()){
            return;
        }

        if(hour==prevH) {
            return;
        }
        if(temp==prevT){
            return;
        }
    }
    query.prepare("INSERT INTO currentWeather(id,city,temperature,humidity,status,lat,lon,sunrise,sunset,ctime,year,"
                    "month,date,hour,min)VALUES(:id,:city,:temp,:humidity,:status,:lat,:lon,:sunrise,:sunset,"
                     ":ctime,:year,:month,:date,:hour,:min)");
    query.bindValue(":id",id);
    query.bindValue(":temp", temp);
    query.bindValue(":humidity", humidity);
    query.bindValue(":status",status);
    query.bindValue(":lat", lat);
    query.bindValue(":lon", lon);
    query.bindValue(":city",city);
    query.bindValue(":sunrise",sunrise);
    query.bindValue(":sunset",sunset);
    query.bindValue(":ctime",ctime);
    query.bindValue(":year",year);
    query.bindValue(":month",month);
    query.bindValue(":date",date);
    query.bindValue(":hour",hour);
    query.bindValue(":min",min);

    if (!query.exec()) {
        qDebug() << "Error inserting data:" << query.lastError();
    } else {
        qDebug() << "Data inserted successfully!";
    }

    if(rowCount>5) {
        int delId = id-5;
        query.prepare("DELETE FROM currentWeather WHERE id = :delId");
        query.bindValue(":delId", delId);
        if(!query.exec()) {
            qDebug()<<"failed to delete today's data";
        }else{
            qDebug()<<"today's data deleted";
        }
    }
    //label:
    return;
}

int todaysWeather::findLowestId() {
    QSqlQuery query;
    query.prepare("SELECT id FROM currentWeather");
    query.exec();
    if(query.next()){
        return query.value(0).toInt();
    }else{
        qDebug()<<"no id found";
        return -1;
    }
}

QString todaysWeather::fetchWeatherStatus(int id) {
    QSqlQuery query;
    QString status;
    query.prepare("SELECT status FROM currentWeather WHERE id = :id");
    query.bindValue(":id",id);
    if(query.exec()){
        if(query.next()){
            status = query.value(0).toString();
        }
    }else{
        qDebug()<<"error in fetching status";
    }
    return status;
}

double todaysWeather::fetchTemp(int id) {
    QSqlQuery query;
    double temp;
    query.prepare("SELECT temperature FROM currentWeather WHERE id = :id");
    query.bindValue(":id",id);
    if(query.exec()){
        if(query.next()){
            temp = query.value(0).toDouble();
        }
    }else{
        qDebug()<<"error in fetching temperature";
    }
    return temp;
}

int todaysWeather::fetchHour(int id) {
    QSqlQuery query;
    int hour;
    query.prepare("SELECT hour FROM currentWeather WHERE id = :id");
    query.bindValue(":id",id);
    if(query.exec()){
        if(query.next()){
            hour = query.value(0).toInt();
        }
    }else{
        qDebug()<<"error in fetching hour";
    }
    return hour;
}

int todaysWeather::fetchMin(int id) {
    QSqlQuery query;
    int min;
    query.prepare("SELECT min FROM currentWeather WHERE id = :id");
    query.bindValue(":id",id);
    if(query.exec()){
        if(query.next()){
            min = query.value(0).toInt();
        }
    }else{
        qDebug()<<"error in fetching min";
    }
    return min;
}

int todaysWeather::fetchSunrise(int id) {
    QSqlQuery query;
    int sunrise;
    query.prepare("SELECT sunrise FROM currentWeather WHERE id = :id");
    query.bindValue(":id",id);
    if(query.exec()){
        if(query.next()){
            sunrise = query.value(0).toInt();
        }
    }else{
        qDebug()<<"error in fetching sunrise";
    }
    return sunrise;
}

int todaysWeather::fetchSunset(int id) {
    QSqlQuery query;
    int sunset;
    query.prepare("SELECT sunset FROM currentWeather WHERE id = :id");
    query.bindValue(":id",id);
    if(query.exec()){
        if(query.next()){
            sunset = query.value(0).toInt();
        }
    }else{
        qDebug()<<"error in fetching sunset";
    }
    return sunset;
}

int todaysWeather::fetchCtime(int id) {
    QSqlQuery query;
    int ctime;
    query.prepare("SELECT ctime FROM currentWeather WHERE id = :id");
    query.bindValue(":id",id);
    if(query.exec()){
        if(query.next()){
            ctime = query.value(0).toInt();
        }
    }else{
        qDebug()<<"error in fetching ctime";
    }
    return ctime;
}

QIcon todaysWeather::fetchIcon(int id) {
    QSqlQuery query;
    QIcon icon;
    QString status;
    query.prepare("SELECT status FROM currentWeather WHERE id = :id");
    query.bindValue(":id",id);
    if(query.exec()){
        if(query.next()){
            status = query.value(0).toString();
        }
    }else{
        qDebug()<<"error in fetching status";
    }

    if(status=="Clouds") {
        //int width=ui->label_weatherIcon->width();
        //int height= ui->label_weatherIcon->height();
        if (fetchSunrise(id)<=fetchCtime(id) && fetchCtime(id)<fetchSunset(id)) {
            icon= QIcon(":/new/prefix1/image/cloudy.png");
        }
        else {
            icon= QIcon(":/new/prefix1/image/cloudy-night.png");
        }
    }
    else if(status=="Drizzle") {

        if(fetchSunrise(id)<=fetchCtime(id) && fetchCtime(id)<fetchSunset(id)) {
            icon=QIcon(":/new/prefix1/image/weather.png");
        }
        else {
            icon=QIcon(":/new/prefix1/image/drizzle.png");
        }
    }
    else if(status=="Mist" || status=="Haze" || status=="Fog") {
        icon =QIcon(":/new/prefix1/image/haze.png");
    }
    else if(status=="Clear") {

        if (fetchSunrise(id)<=fetchCtime(id) && fetchCtime(id)<fetchSunset(id)) {
            icon=QIcon(":/new/prefix1/image/Clear.png");
        }
        else {
            icon=QIcon(":/new/prefix1/image/full-moon.png");
        }
    }
    else if(status=="Dust" || status=="Sand" || status=="Ash") {

        icon=QIcon(":/new/prefix1/image/dust.png");
    }
    else {
        icon=QIcon(":/new/prefix1/image/"+status+".png");
    }
    return icon;
}
