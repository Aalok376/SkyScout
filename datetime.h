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
};

#endif // DATETIME_H
