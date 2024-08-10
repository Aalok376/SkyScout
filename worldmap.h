#ifndef WORLDMAP_H
#define WORLDMAP_H

#include <QDialog>
#include "mainwindow.h"

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

private slots:
    void on_pushButton_clicked();

private:
    Ui::worldMap *ui;
};

#endif // WORLDMAP_H
