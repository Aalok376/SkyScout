#ifndef LOGICMATHS_H
#define LOGICMATHS_H

#include<QString>
#include<QIcon>

class logicMaths
{
public:
    logicMaths();
    //private slots:
    static double tempConversion(double);
    static double avgTemp(double*,int);
    static double avgHumidity(double*,int);
    static QString weatherMode(QString*,int);
    static QString nameOfMonth(int);
    static double noOfDays(int,int);
    static double twoDecimals(double);
    static QIcon getStatusIcon(QString,int,int,int);
    static QIcon getStatusIcon(QString);
    static QString checkDigit(int);
};

#endif // LOGICMATHS_H
