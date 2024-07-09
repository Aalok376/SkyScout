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
    while (query.next()) {
        rowCount++;
    }
    qDebug()<<"row count is"<<rowCount;
    int id = rowCount+1;

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
            qDebug() << "No results returned for id:" << id;
        }
    } else {
        // Handle query execution error
        qDebug() << "Query error: " << query.lastError();
    }

    if(year!=prevY || month!=prevM || date!=prevD) {
        query.prepare("DELETE FROM currentWeather");
        if(!query.exec()) {
            qDebug()<<"failed to delete previous day's data";
        }else{
            qDebug()<<"previous day's data deleted";
        }
    }

    if(previousCity!=city){
        return;
    }

    if(hour==prevH) {
        return;
    }
    if(temp==prevT){
        return;
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
