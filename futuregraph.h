#ifndef FUTUREGRAPH_H
#define FUTUREGRAPH_H

#include <QDialog>
#include "intermediatewindow.h"

#include<QVector>

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include<QIcon>
#include<QCoreApplication>
#include<QDebug>

#include "futureweather.h"
#include "logicmaths.h"


namespace Ui {
class futureGraph;
}

class futureGraph : public QDialog
{
    Q_OBJECT

signals:
    void returnToIntermediateWindow();

public:
    explicit futureGraph(QWidget *parent = nullptr);
    ~futureGraph();

private slots:
    void on_return_btn_3_clicked();

private:
    Ui::futureGraph *ui;
};

#endif // FUTUREGRAPH_H
