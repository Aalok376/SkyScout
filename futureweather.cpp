#include "futureweather.h"

futureWeather::futureWeather() {

}

void futureWeather::databaseConnection(QString city, double temp,double humidity,QString status,
                                       int sunrise,int sunset,int ctime,int year,int month,int date,int hour,int min) {
    QSqlDatabase futuredb=QSqlDatabase::addDatabase("QSQLITE");
    futuredb.setDatabaseName(QCoreApplication::applicationDirPath()+"/database/futuredata.db");
    //futuredb.setDatabaseName("D:/Interessant/qtp/finalProject/database/futuredata.db");


    futuredb.open();
    insertInformation(city,temp,humidity,status,sunrise,sunset,ctime,year,month,date,hour,min);

    futuredb.close();
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
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

    if(rowCount==32) {
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

double futureWeather::fetchTemp(int count) {

    QSqlDatabase fdb=QSqlDatabase::addDatabase("QSQLITE");
    fdb.setDatabaseName(QCoreApplication::applicationDirPath()+"/database/futuredata.db");
    //fdb.setDatabaseName("D:/Interessant/qtp/finalProject/database/futuredata.db");
    fdb.open();
    QSqlQuery query;

    double tempArray[8];
    if (count == 1) {
        for(int id=1;id<=8;id++) {
            query.prepare("SELECT temperature FROM futureWeather WHERE id = :id");
            query.bindValue(":id",id);
            if(query.exec()) {
                if(query.next()){
                    tempArray[id-1] = query.value(0).toDouble();
                }
            }
        }
        double avgTemperature = logicMaths::avgTemp(tempArray,8);
        avgTemperature = logicMaths::tempConversion(avgTemperature);
        avgTemperature = logicMaths::twoDecimals(avgTemperature);
        return avgTemperature;
    }
    else if(count == 2) {
        for(int id=9;id<=16;id++) {
            query.prepare("SELECT temperature FROM futureWeather WHERE id = :id");
            query.bindValue(":id",id);
            if(query.exec()) {
                if(query.next()){
                    tempArray[id-9] = query.value(0).toDouble();
                }
            }
        }
        double avgTemperature = logicMaths::avgTemp(tempArray,8);

        avgTemperature = logicMaths::tempConversion(avgTemperature);
        avgTemperature = logicMaths::twoDecimals(avgTemperature);
        return avgTemperature;
    }
    else if(count == 3) {
        for(int id=17;id<=24;id++) {
            query.prepare("SELECT temperature FROM futureWeather WHERE id = :id");
            query.bindValue(":id",id);
            if(query.exec()) {
                if(query.next()){
                    tempArray[id-17] = query.value(0).toDouble();
                }
            }
        }

        double avgTemperature = logicMaths::avgTemp(tempArray,8);
        avgTemperature = logicMaths::tempConversion(avgTemperature);
        avgTemperature = logicMaths::twoDecimals(avgTemperature);
        return avgTemperature;
    }
    else if(count == 4) {
        for(int id=25;id<=32;id++) {
            query.prepare("SELECT temperature FROM futureWeather WHERE id = :id");
            query.bindValue(":id",id);
            if(query.exec()) {
                if(query.next()){
                    tempArray[id-25] = query.value(0).toDouble();
                }
            }
        }

        double avgTemperature = logicMaths::avgTemp(tempArray,8);
        avgTemperature = logicMaths::tempConversion(avgTemperature);
        avgTemperature = logicMaths::twoDecimals(avgTemperature);
        return avgTemperature;
    }
}

QString futureWeather::fetchStatus(int count) {
    QSqlDatabase fdb=QSqlDatabase::addDatabase("QSQLITE");
    fdb.setDatabaseName(QCoreApplication::applicationDirPath()+"/database/futuredata.db");
    //fdb.setDatabaseName("D:/Interessant/qtp/finalProject/database/futuredata.db");
    fdb.open();
    QSqlQuery query;

    QString statusArray[8];

    if(count ==1 ) {
        for(int id=1;id<=8;id++){
            query.prepare("SELECT status FROM futureWeather WHERE id = :id");
            query.bindValue(":id",id);
            if(query.exec()){
                if(query.next()){
                    statusArray[id-1] = query.value(0).toString();
                }
            }
        }
        QString status = logicMaths::weatherMode(statusArray,8);
        return status;
    }
    else if(count == 2) {
        for(int id=9;id<=16;id++){
            query.prepare("SELECT status FROM futureWeather WHERE id = :id");
            query.bindValue(":id",id);
            if(query.exec()){
                if(query.next()){
                    statusArray[id-9] = query.value(0).toString();
                }
            }
        }
        QString status = logicMaths::weatherMode(statusArray,8);
        return status;
    }
    else if(count == 3) {
        for(int id=17;id<=24;id++){
            query.prepare("SELECT status FROM futureWeather WHERE id = :id");
            query.bindValue(":id",id);
            if(query.exec()){
                if(query.next()){
                    statusArray[id-17] = query.value(0).toString();
                }
            }
        }
        QString status = logicMaths::weatherMode(statusArray,8);
        return status;
    }
}

int futureWeather::fetchYear(int count) {
    QSqlDatabase fdb=QSqlDatabase::addDatabase("QSQLITE");
    fdb.setDatabaseName(QCoreApplication::applicationDirPath()+"/database/futuredata.db");
    //fdb.setDatabaseName("D:/Interessant/qtp/finalProject/database/futuredata.db");
    fdb.open();
    QSqlQuery query;

    if(count == 1) {
        query.prepare("SELECT year FROM futureWeather WHERE id = 1");
        query.bindValue("1",1);
        int year;
        if(query.exec()){
            if(query.next()){
                year = query.value(0).toInt();
            }
        }
        return year;

    }
    else if(count == 2) {
        query.prepare("SELECT year FROM futureWeather WHERE id = 9");
        query.bindValue("9",9);
        int year;
        if(query.exec()){
            if(query.next()){
                year = query.value(0).toInt();
            }
        }
        return year;
    }
    else if(count == 3) {
        query.prepare("SELECT year FROM futureWeather WHERE id = 17");
        query.bindValue("17",17);
        int year;
        if(query.exec()){
            if(query.next()){
                year = query.value(0).toInt();
            }
        }
        return year;
    }
    else if(count == 4) {
        query.prepare("SELECT year FROM futureWeather WHERE id = 25");
        query.bindValue("25",25);
        int year;
        if(query.exec()){
            if(query.next()){
                year = query.value(0).toInt();
            }
        }
        return year;
    }
}

int futureWeather::fetchIntMonth(int count) {
    QSqlDatabase fdb=QSqlDatabase::addDatabase("QSQLITE");
    fdb.setDatabaseName(QCoreApplication::applicationDirPath()+"/database/futuredata.db");
    //fdb.setDatabaseName("D:/Interessant/qtp/finalProject/database/futuredata.db");
    fdb.open();
    QSqlQuery query;

    if(count == 1) {
        query.prepare("SELECT month FROM futureWeather WHERE id = 1");
        query.bindValue("1",1);
        int mon;
        if(query.exec()){
            if(query.next()){
                mon = query.value(0).toInt();
            }
        }
        return mon;

    }
    else if(count == 2) {
        query.prepare("SELECT month FROM futureWeather WHERE id = 9");
        query.bindValue("9",9);
        int mon;
        if(query.exec()){
            if(query.next()){
                mon = query.value(0).toInt();
            }
        }
        return mon;
    }
    else if(count == 3) {
        query.prepare("SELECT month FROM futureWeather WHERE id = 17");
        query.bindValue("17",17);
        int mon;
        if(query.exec()){
            if(query.next()){
                mon = query.value(0).toInt();
            }
        }
        return mon;
    }
    else if(count == 4) {
        query.prepare("SELECT month FROM futureWeather WHERE id = 25");
        query.bindValue("25",25);
        int mon;
        if(query.exec()){
            if(query.next()){
                mon = query.value(0).toInt();
            }
        }
        return mon;
    }
}

QString futureWeather::fetchMonth(int count) {
    QSqlDatabase fdb=QSqlDatabase::addDatabase("QSQLITE");
    fdb.setDatabaseName(QCoreApplication::applicationDirPath()+"/database/futuredata.db");
    //fdb.setDatabaseName("D:/Interessant/qtp/finalProject/database/futuredata.db");
    fdb.open();
    QSqlQuery query;

    if(count == 1) {
        query.prepare("SELECT month FROM futureWeather WHERE id = 1");
        query.bindValue("1",1);
        int mon;
        if(query.exec()){
            if(query.next()){
                mon = query.value(0).toInt();
            }
        }
        QString month = logicMaths::nameOfMonth(mon);
        return month;

    }
    else if(count == 2) {
        query.prepare("SELECT month FROM futureWeather WHERE id = 9");
        query.bindValue("9",9);
        int mon;
        if(query.exec()){
            if(query.next()){
                mon = query.value(0).toInt();
            }
        }
        QString month = logicMaths::nameOfMonth(mon);
        return month;
    }
    else if(count == 3) {
        query.prepare("SELECT month FROM futureWeather WHERE id = 17");
        query.bindValue("17",17);
        int mon;
        if(query.exec()){
            if(query.next()){
                mon = query.value(0).toInt();
            }
        }
        QString month = logicMaths::nameOfMonth(mon);
        return month;
    }
    else if(count == 4) {
        query.prepare("SELECT month FROM futureWeather WHERE id = 25");
        query.bindValue("25",25);
        int mon;
        if(query.exec()){
            if(query.next()){
                mon = query.value(0).toInt();
            }
        }
        QString month = logicMaths::nameOfMonth(mon);
        return month;
    }
}

int futureWeather::fetchDate(int count) {
    QSqlDatabase fdb=QSqlDatabase::addDatabase("QSQLITE");
    fdb.setDatabaseName(QCoreApplication::applicationDirPath()+"/database/futuredata.db");
    //fdb.setDatabaseName("D:/Interessant/qtp/finalProject/database/futuredata.db");
    fdb.open();
    QSqlQuery query;

    if(count == 1) {
        query.prepare("SELECT date FROM futureWeather WHERE id = 1");
        query.bindValue("1",1);
        int date;
        if(query.exec()){
            if(query.next()){
                date = query.value(0).toInt();
            }
        }
        return date;
    }
    else if(count == 2) {
        query.prepare("SELECT date FROM futureWeather WHERE id = 9");
        query.bindValue("9",9);
        int date;
        if(query.exec()){
            if(query.next()){
                date = query.value(0).toInt();
            }
        }
        return date;
    }
    else if(count == 3) {
        query.prepare("SELECT date FROM futureWeather WHERE id = 17");
        query.bindValue("17",17);
        int date;
        if(query.exec()){
            if(query.next()){
                date = query.value(0).toInt();
            }
        }
        return date;
    }
    else if(count == 4) {
        query.prepare("SELECT date FROM futureWeather WHERE id = 25");
        query.bindValue("25",25);
        int date;
        if(query.exec()){
            if(query.next()){
                date = query.value(0).toInt();
            }
        }
        return date;
    }
}

QIcon futureWeather::fetchIcon(int count) {

    QString status = fetchStatus(count);
    QIcon icon;
    if(status=="Clouds") {
        icon= QIcon(":/new/prefix1/image/cloudy.png");
    }
    else if(status=="Drizzle") {
            icon=QIcon(":/new/prefix1/image/weather.png");
    }
    else if(status=="Mist" || status=="Haze" || status=="Fog") {
        icon =QIcon(":/new/prefix1/image/haze.png");
    }
    else if(status=="Clear") {
            icon=QIcon(":/new/prefix1/image/Clear.png");
    }
    else if(status=="Dust" || status=="Sand" || status=="Ash") {

        icon=QIcon(":/new/prefix1/image/dust.png");
    }
    else {
        icon=QIcon(":/new/prefix1/image/"+status+".png");
    }
    return icon;
}

