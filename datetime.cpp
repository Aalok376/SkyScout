#include "datetime.h"

dateTime::dateTime() {

}


int dateTime::currentYear() {
  std::time_t now = std::time(0);
  std::tm* localTime = std::localtime(&now);
  int year = 1900 + localTime->tm_year;  // Years since 1900
  return year;
}
int dateTime::currentMonth() {
    std::time_t now = std::time(0);
    std::tm* localTime = std::localtime(&now);
    int month = 1 + localTime->tm_mon;     // Months since January (0-11), add 1 for 1-12
    return month;
}
int dateTime::currentDate() {
    std::time_t now = std::time(0);
    std::tm* localTime = std::localtime(&now);
    int day = localTime->tm_mday;
    return day;
}

int dateTime::currentHour() {
    std::time_t now = std::time(0);
    std::tm* localTime = std::localtime(&now);
    int hour = localTime->tm_hour;
    return hour;
}

int dateTime::currentMin() {
    std::time_t now = std::time(0);
    std::tm* localTime = std::localtime(&now);
    int min = localTime->tm_min;
    return min;
}

