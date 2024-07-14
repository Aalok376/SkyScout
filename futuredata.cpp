// #include "futuredata.h"

// futureData::futureData():networkManager(new QNetworkAccessManager(this)) {
//     QString apiKey="410680a363d4c095792d7e19b0bf49cb";
//     QString urlstring=QString("https://api.openweathermap.org/data/2.5/weather?q=%1&appid=%2").arg(location, apiKey);
//     QUrl url(urlstring);
//     QNetworkRequest request(url);
//     networkManager->get(request);
//     getNetworkRequest();
// }
// void futureData::getNetworkRequest() {

//     connect(networkManager,&QNetworkAccessManager::finished ,this , &futureData::onFutureDataReceived);
//     return;
// }
// void futureData::onFutureDataReceived() {
//     if(reply->error()==QNetworkReply::NoError) {
//         qDebug()<<"nice work pal";
//     }else {
//         qDebug)()<<"hahahahhahahahhaha";
//     }
// }


