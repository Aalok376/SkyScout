#include "logicmaths.h"

logicMaths::logicMaths() {

}
double logicMaths::tempConversion(double t) {
    return t-273.15;
}

double logicMaths::avgTemp(double *tempArray, int size) {
    double total = 0;
    for(int i=0;i<size;i++) {
        total+=tempArray[i];
    }
    double avg = total/size;
    return avg;
}

double logicMaths::avgHumidity(double *humidArray, int size) {
    double total = 0;
    for(int i=0;i<size;i++) {
        total+=humidArray[i];
    }
    double avg = total/size;
    return avg;
}

QString logicMaths::weatherMode(QString *statusArray, int size) {
    QString mode = statusArray[0];
    int count =0;
    for(int i=0;i<size;i++) {
        int c=1;
        for(int j=i+1;j<size;j++){
            if(statusArray[i]==statusArray[j]){
                c++;
            }
        }
        if(c>count) {
            mode = statusArray[i];
            count = c;
        }
    }
    return mode;
}

QString logicMaths::nameOfMonth(int mon) {
    QString month;
    switch(mon){
    case 1:
        month = "Jan";
        break;
    case 2:
        month = "Feb";
        break;
    case 3:
        month = "Mar";
        break;
    case 4:
        month = "Apr";
        break;
    case 5:
        month = "May";
        break;
    case 6:
        month = "June";
        break;
    case 7:
        month = "July";
        break;
    case 8:
        month = "Aug";
        break;
    case 9:
        month = "Sep";
        break;
    case 10:
        month = "Oct";
        break;
    case 11:
        month = "Nov";
        break;
    default:
        month = "Dec";
    }
    return month;
}

double logicMaths::twoDecimals(double t) {
    t*=100;
    int iTemp = (int)t;
    t = 1.0*iTemp/100;
    return t;
}

double logicMaths::noOfDays(int mon, int year) {
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    double days;
    if (mon == 2) {
        // Leap year check: divisible by 4, but not divisible by 100 unless also divisible by 400
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            days = 29; // Leap year has 29 days in February
        }
    }

    days = daysInMonth[mon - 1];
    return days;
}

QIcon logicMaths::getStatusIcon(QString status,int ctime,int sunrise,int sunset) {
    QIcon icon;
    if(status=="Clouds") {
        //int width=ui->label_weatherIcon->width();
        //int height= ui->label_weatherIcon->height();
        if (sunrise<=ctime && ctime<sunset) {
            icon= QIcon(":/new/prefix1/image/cloudy.png");
        }
        else {
            icon= QIcon(":/new/prefix1/image/cloudy-night.png");
        }
    }
    else if(status=="Drizzle") {

        if(sunrise<=ctime && ctime<sunset) {
            icon=QIcon(":/new/prefix1/image/weather.png");
        }
        else {
            icon=QIcon(":/new/prefix1/image/drizzle.png");
        }
    }
    else if(status=="Mist" || status=="Haze" || status=="Fog") {
        icon =QIcon(":/new/prefix1/image/haze.png");
    }
    else if(status=="Clear") {

        if (sunrise<=ctime && ctime<sunset) {
            icon=QIcon(":/new/prefix1/image/Clear.png");
        }
        else {
            icon=QIcon(":/new/prefix1/image/full-moon.png");
        }
    }
    else if(status=="Dust" || status=="Sand" || status=="Ash") {

        icon=QIcon(":/new/prefix1/image/dust.png");
    }
    else {
        icon=QIcon(":/new/prefix1/image/"+status+".png");
    }
    return icon;
}

QIcon logicMaths::getStatusIcon(QString status) {
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

QString logicMaths::checkDigit(int t){
    QString ts;
    if(t<10){
        ts = "0"+QString::number(t);
    }else{
        ts = QString::number(t);
    }
    return ts;
}
