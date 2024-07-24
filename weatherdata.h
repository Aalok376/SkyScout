#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include<QDebug>

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include<QCoreApplication>

#include "datetime.h"

class weatherData
{
public:
    weatherData();
    static void databaseConnection(QString, double,double,double,double,int,int,int,int,int,int);
    static void insertInformation(QString, double,double,double,double,int,int,int,int,int,int);

    static int findLowestId();
};

#endif // WEATHERDATA_H
