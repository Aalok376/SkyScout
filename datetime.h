#ifndef DATETIME_H
#define DATETIME_H

#include<ctime>

class dateTime
{
public:
    dateTime();
    static int currentYear();
    static int currentMonth();
    static int currentDate();
    static int currentHour();
    static int currentMin();

    static int fetchYear(int);
    static int fetchMonth(int);
    static int fetchDate(int);
    static int fetchHour(int);
    static int fetchMin(int);
};

#endif // DATETIME_H
