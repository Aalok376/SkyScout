#ifndef FUTUREDATA_H
#define FUTUREDATA_H

#include<QNetworkAccessManager> // for sending network request
#include<QNetworkReply> // for recieving responce
#include<QUrl>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include<QDebug>
#include <QObject>
#include<QNetworkRequest>

class futureData : public QObject
{
    Q_OBJECT;
    QNetworkAccessManager *NetworkManager;

public:
    explicit futureData(QObject *parent=nullptr):QObject(parent)
    {
        NetworkManager = new QNetworkAccessManager(this);
        connect(NetworkManager , &QNetworkAccessManager::finished , this , &futureData:: onNetworkReply);
    }

    //static void getNetworkRequest();
    //static void onFutureDataReceived();
public slots:
    void fetchFutureData(void)
    {
        QString apiKey = "410680a363d4c095792d7e19b0bf49cb";
QString urlstring = QString("https://api.openweathermap.org/data/2.5/weather?q=%1&appid=%2").arg("Kathmandu", apiKey);
        QUrl url(urlstring);
        QNetworkRequest request(url);
        NetworkManager->get(request);

    }
signals:
    void futureDataFetched(/*QString currentLocation*/);
private slots:
    void onNetworkReply(QNetworkReply *reply)
    {
        if(reply->error()==QNetworkReply::NoError)
        {
            // QByteArray Arr = reply->readAll();
            // QJsonDocument JsonDoc = QJsonDocument::fromJson(Arr);
            // if(!JsonDoc.isNull())
            // {
            //     QJsonObject Jsonobj = JsonDoc.object();
            //     QString cityName = Jsonobj.value("city").toString();
            //     emit locationFetched(cityName);
            // }
            qDebug()<<"good work";
        }
        else{
            qDebug()<<"error in fetching futureData";
        }
    }
};

#endif // FUTUREDATA_H
