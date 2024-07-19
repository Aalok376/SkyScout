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
#include<QCoreApplication>

#include "datetime.h"
#include "logicmaths.h"


class futureWeather
{
public:
    futureWeather();

    static void databaseConnection(QString, double,double,QString,int,int,int,int,int,int,int,int);
    static void insertInformation(QString, double,double,QString,int,int,int,int,int,int,int,int);
    static double fetchTemp(int);
    static QString fetchStatus(int);
    static QString fetchMonth(int);
    static int fetchDate(int);

    static QIcon fetchIcon(int);
};

#endif // FUTUREWEATHER_H
