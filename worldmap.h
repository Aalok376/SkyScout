#ifndef WORLDMAP_H
#define WORLDMAP_H

#include <QDialog>
#include "mainwindow.h"
#include<QGeoCoordinate>
#include<QQuickItem>
#include<QRegion>
namespace Ui {
class worldMap;
}

class worldMap : public QDialog
{
    Q_OBJECT

public:
    explicit worldMap(QWidget *parent = nullptr);
    ~worldMap();
signals:
    void returnToMainWindow();
      void updateMap(QVariant latitude, QVariant longitude);
private slots:
    void on_pushButton_clicked();

private:
    Ui::worldMap *ui;
};

#endif // WORLDMAP_H
