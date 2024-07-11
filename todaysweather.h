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
#include<QIcon>

#include "datetime.h"

class todaysWeather
{
public:
    todaysWeather();
    static void databaseConnection(QString, double,double,QString,double,double,int,int,int,int,int,int,int,int);
    static void insertInformation(QString, double,double,QString,double,double,int,int,int,int,int,int,int,int);

    static int findLowestId();

    static QString fetchWeatherStatus(int);
    static double fetchTemp(int);
    static int fetchHour(int);
    static int fetchMin(int);

    static int fetchSunrise(int);
    static int fetchSunset(int);
    static int fetchCtime(int);

    static QIcon fetchIcon(int);
};

#endif // TODAYSWEATHER_H
