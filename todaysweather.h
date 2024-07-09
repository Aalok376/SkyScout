#ifndef TODAYSWEATHER_H
#define TODAYSWEATHER_H

#include<QDebug>

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

#include "datetime.h"

class todaysWeather
{
public:
    todaysWeather();
    static void databaseConnection(QString, double,double,QString,double,double,int,int,int,int,int,int,int,int);
    static void insertInformation(QString, double,double,QString,double,double,int,int,int,int,int,int,int,int);
};

#endif // TODAYSWEATHER_H
