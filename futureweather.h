#ifndef FUTUREWEATHER_H
#define FUTUREWEATHER_H

#include<QDebug>

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include<QIcon>

#include "datetime.h"


class futureWeather
{
public:
    futureWeather();

    static void databaseConnection(QString, double,double,QString,int,int,int,int,int,int,int,int);
    static void insertInformation(QString, double,double,QString,int,int,int,int,int,int,int,int);
};

#endif // FUTUREWEATHER_H
