#include "weatherdata.h"

weatherData::weatherData() {

}
void weatherData::databaseConnection(QString city, double temp,double humidity,double lat,double lon,
                                     int sunrise,int sunset,int ctime,int year,int month,int date) {
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/Interessant/qtp/finalProject/database/weatherdb.db");


    mydb.open();
    insertInformation(city,temp,humidity,lat,lon,sunrise,sunset,ctime,year,month,date);


    return;
}


void weatherData::insertInformation(QString city, double temp,double humidity,double lat,double lon,
                                    int sunrise,int sunset,int ctime,int year,int month,int date) {
    QSqlQuery query;
    //QString countQuery = "SELECT * FROM pastWeather";

    int id=2;
    //while()
    int previousId=id-1;
    QString previousCity;
    int prevY;
    int prevM;
    int prevD;
    query.prepare("SELECT city,year,month,date FROM pastWeather WHERE id=:previousId");
    query.bindValue(":previousId",previousId);

    if (query.exec()) {
        if (query.next()) {
            previousCity = query.value(0).toString();
            prevY = query.value(1).toInt();
            prevM = query.value(2).toInt();
            prevD = query.value(3).toInt();
        } else {
            // Handle case where no results are returned
            qDebug() << "No results returned for id:" << id;
        }
    } else {
        // Handle query execution error
        qDebug() << "Query error: " << query.lastError();
    }
    qDebug()<<previousCity;
    qDebug()<<city;
    qDebug()<<prevY;
    qDebug()<<prevM;
    qDebug()<<prevD;
    if(city!=previousCity){
        return;
    }
    if(year==prevY && month==prevM && date==prevD) {
        return;
    }

    query.prepare("INSERT INTO pastWeather(id,city,temperature,humidity,lat,lon,sunrise,sunset,ctime,year,month,date)"
                  "VALUES(:id,:city,:temp,:humidity,:lat,:lon,:sunrise,:sunset,:ctime,:year,:month,:date)");
    query.bindValue(":id",id);
    query.bindValue(":temp", temp);
    query.bindValue(":humidity", humidity);
    query.bindValue(":lat", lat);
    query.bindValue(":lon", lon);
    query.bindValue(":city",city);
    query.bindValue(":sunrise",sunrise);
    query.bindValue(":sunset",sunset);
    query.bindValue(":ctime",ctime);
    query.bindValue(":year",year);
    query.bindValue(":month",month);
    query.bindValue(":date",date);

    if (!query.exec()) {
        qDebug() << "Error inserting data:" << query.lastError();
    } else {
        qDebug() << "Data inserted successfully!";
    }
    query.prepare("SELECT * FROM pastWeather");
    query.exec();
    int rowCount=0;
    while (query.next()) {
        rowCount++;
    }


    if(rowCount>10) {
        int delId = id-10;
        query.prepare("DELETE FROM pastWeather WHERE id = :delId");
        query.bindValue(":delId", delId);
        if(!query.exec()) {
            qDebug()<<"failed to delete data";
        }else{
            qDebug()<<"data deleted";
        }
    }
    //qDebug()<<rowCount;

    return;
}
