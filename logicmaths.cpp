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

