#ifndef FETCHCURRENTADDRESS_H
#define FETCHCURRENTADDRESS_H
#include <QObject>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QJsonDocument>
#include<QJsonObject>
#include<QNetworkRequest>
#include<QUrl>
#include<QMessageBox>
#include<QDebug>
//Parent (QObject or QApplication) -> GeolocationWorker_obj -> QNetworkAccessManager , setting parent child relationship
class FetchCurrentAddress : public QObject
{
    Q_OBJECT
    QNetworkAccessManager *NetworkManager;
public:
    explicit FetchCurrentAddress(QObject *parent=nullptr):QObject(parent)
    {
       NetworkManager = new QNetworkAccessManager(this);
       connect(NetworkManager , &QNetworkAccessManager::finished , this , &FetchCurrentAddress:: onNetworkReply);
    }
public slots:
    void fetchLocation(void)
    {
      QNetworkRequest request(QUrl("http://ip-api.com/json"));

        NetworkManager->get(request);
    }
signals:
   void locationFetched(QString currentLocation);

private slots:
    void onNetworkReply(QNetworkReply *reply)
    {
        if(reply->error()==QNetworkReply::NoError)
        {
            QByteArray Arr = reply->readAll();
            QJsonDocument JsonDoc = QJsonDocument::fromJson(Arr);
            if(!JsonDoc.isNull())
            {
                QJsonObject Jsonobj = JsonDoc.object();
                QString cityName = Jsonobj.value("city").toString();
                emit locationFetched(cityName);
            }
        }
        else{
            qDebug()<<"error in fetching current address";
        }
    }
};
#endif // FETCHCURRENTADDRESS_H

