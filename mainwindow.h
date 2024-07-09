#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

#include<QNetworkAccessManager> // for sending network request
#include<QNetworkReply> // for recieving responce

#include<QUrl>
#include<QJsonDocument>
#include<QJsonObject>
#include<QMessageBox>
#include<QJsonArray>
#include<QPixmap>
#include<QDebug>

#include "logicmaths.h"
#include "weatherdata.h"

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

private slots:
    void on_pushButton_flag_clicked();

    void on_lineEdit_searchbar_returnPressed();

    void on_pushButton_search_clicked();
    void onWeatherDataRecieved(QNetworkReply *reply);
    void onCurrentLocationFetched(QString);
private:
    Ui::MainWindow *ui;
    bool check =true;
    QNetworkAccessManager *networkManager;
};
#endif // MAINWINDOW_H
