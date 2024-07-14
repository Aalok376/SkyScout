#include "futureweather.h"

futureWeather::futureWeather() {

}

void futureWeather::databaseConnection(QString city, double temp,double humidity,QString status,
                                       int sunrise,int sunset,int ctime,int year,int month,int date,int hour,int min) {
    QSqlDatabase futuredb=QSqlDatabase::addDatabase("QSQLITE");
    futuredb.setDatabaseName("D:/Interessant/qtp/finalProject/database/futuredata.db");


    futuredb.open();
    insertInformation(city,temp,humidity,status,sunrise,sunset,ctime,year,month,date,hour,min);

    return;
}

void futureWeather::insertInformation(QString city, double temp,double humidity,QString status,
                                      int sunrise,int sunset,int ctime,int year,int month,int date,int hour,int min) {

    QSqlQuery query;
    query.prepare("SELECT * FROM futureWeather");
    query.exec();
    int rowCount=0;
    int largest;
    while (query.next()) {
        rowCount++;
        largest = query.value(0).toInt();
    }
    //qDebug()<<"row count is"<<rowCount;
    int id;
    if(rowCount==0){
        id=1;
    }else{
        id=largest+1;
    }

    if(rowCount==24) {
        query.prepare("DELETE FROM futureWeather");
        if(!query.exec()) {
            qDebug()<<"failed to delete future data";
        }else{
            qDebug()<<"future data deleted";
        }
        id=1;
    }

    query.prepare("INSERT INTO futureWeather(id,city,temperature,humidity,status,sunrise,sunset,ctime,year,"
                  "month,date,hour,min)VALUES(:id,:city,:temp,:humidity,:status,:sunrise,:sunset,"
                  ":ctime,:year,:month,:date,:hour,:min)");
    query.bindValue(":id",id);
    query.bindValue(":temp", temp);
    query.bindValue(":humidity", humidity);
    query.bindValue(":status",status);
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
    return;
}
