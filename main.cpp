#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QMainWindow>
#include <QTimer>
#include <QPixmap>
#include <QQuickWidget>
#include <QQmlContext>
#include <QQmlEngine>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     QPixmap pixmap(":/new/prefix1/image/splash.png");

     QSplashScreen splash(pixmap);
     splash.show();
     splash.showMessage(
         "<html><body style='font-size: 15px; color: white; font-family: arial;'>Loading weather data...</body></html>",
                        Qt::AlignBottom | Qt::AlignCenter);
     QTimer::singleShot(3000, &splash, &QSplashScreen::close);
     MainWindow w;
     QTimer::singleShot(3000, &w, &QMainWindow::show);
    //w.show();
    return a.exec();
}
