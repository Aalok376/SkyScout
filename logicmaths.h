#ifndef LOGICMATHS_H
#define LOGICMATHS_H

#include<QString>

class logicMaths
{
public:
    logicMaths();
    //private slots:
    static double tempConversion(double);
    static double avgTemp(double*,int);
    static QString weatherMode(QString*,int);
    static QString nameOfMonth(int);
    static double noOfDays(int,int);
    static double npOfDays(QString,int);
    static double twoDecimals(double);
};

#endif // LOGICMATHS_H
