#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

#include<QNetworkAccessManager> // for sending network request
#include<QNetworkReply> // for recieving responce
#include<fetchcurrentaddress.h>
#include<QUrl>
#include<QJsonDocument>
#include<QJsonObject>
#include<QMessageBox>
#include<QJsonArray>
#include<QPixmap>
#include<QDebug>
#include<QCompleter>
#include<qstringlistmodel.h>
#include<QtCore>
#include "datetime.h"
#include "logicmaths.h"
#include "weatherdata.h"
#include "todaysweather.h"
#include "futureweather.h"
#include "intermediatewindow.h"

// #include "futuredata.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
           // void resizeEvent(QResizeEvent *event) override ;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void updateMap(QVariant latitude, QVariant longitude);
private slots:
    void on_pushButton_flag_clicked();

    void on_lineEdit_searchbar_returnPressed();

    void on_pushButton_search_clicked();
    void onWeatherDataRecieved(QNetworkReply *reply);
    void onCurrentLocationFetched(QString);

    void onLocationRecieved(QNetworkReply *reply);
    void on_lineEdit_searchbar_textChanged(const QString &arg1);

    void on_seemore_btn_clicked();
    void showMainWindow();

private:
    Ui::MainWindow *ui;
    bool check =true;
    QNetworkAccessManager *networkManager;
    QNetworkAccessManager *NetworkManager;
    QCompleter *completer;
    QStringListModel *model;
    //intermediateWindow *intermediate;
// public:
//    static Ui* getUi(Ui* ui){
//         return ui;
//     }
};
#endif // MAINWINDOW_H
