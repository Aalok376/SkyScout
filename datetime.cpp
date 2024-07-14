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

int dateTime::fetchYear(int t) {
    std::time_t timestamp = t;

    // Convert to tm struct
    std::tm *time_info = std::gmtime(&timestamp);

    // Extract the year
    int year = time_info->tm_year + 1900;
    return year;
}

int dateTime::fetchMonth(int t) {
    std::time_t timestamp = t;

    // Convert to tm struct
    std::tm *time_info = std::gmtime(&timestamp);

    // Extract the month
    int month = time_info->tm_mon + 1;
    return month;
}

int dateTime::fetchDate(int t) {
    std::time_t timestamp = t;

    // Convert to tm struct
    std::tm *time_info = std::gmtime(&timestamp);

    // Extract the date
    int date = time_info->tm_mday;
    return date;
}
int dateTime::fetchHour(int t) {
    std::time_t timestamp = t;

    // Convert to tm struct
    std::tm *time_info = std::gmtime(&timestamp);

    // Extract the hour
    int hour = time_info->tm_hour;
    return hour;
}

int dateTime::fetchMin(int t) {
    std::time_t timestamp = t;

    // Convert to tm struct
    std::tm *time_info = std::gmtime(&timestamp);

    // Extract minute
    int min = time_info->tm_min;
    return min;
}

