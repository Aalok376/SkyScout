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

int dateTime::getTimeZone(double latitude, double longitude) {
    QNetworkAccessManager manager;
    QEventLoop loop;
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);

    // TimeZoneDB API endpoint and key
    QString apiKey = "api key"; // Replace with your API key
    QString requestUrl = QString("http://api.timezonedb.com/v2.1/get-time-zone?key=%1&format=json&by=position&lat=%2&lng=%3")
                             .arg(apiKey)
                             .arg(latitude)
                             .arg(longitude);

    // Create QUrl and QNetworkRequest
    QUrl url(requestUrl);
    QNetworkRequest request(url);

    // Make the network request
    QNetworkReply *reply = manager.get(request);
    loop.exec(); // Wait for the request to finish
    int timestamp;
    // Parse the response
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response_data = reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(response_data);
        QJsonObject jsonObject = jsonResponse.object();

        //QString timeZone = jsonObject["zoneName"].toString();
        //QString datetime = jsonObject["formatted"].toString();
        timestamp = jsonObject["timestamp"].toInt();

        //std::cout << "Time Zone: " << timeZone.toStdString() << std::endl;
        //qDebug() << "Local Time: " << datetime;
    } else {
        //std::cout << "Error: " << reply->errorString().toStdString() << std::endl;
        qDebug()<<"ahahaha";
        return -1;
    }
    reply->deleteLater();
    return timestamp;

}
