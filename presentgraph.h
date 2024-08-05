#ifndef PRESENTGRAPH_H
#define PRESENTGRAPH_H
#include"modecheck.h"
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

#include "todaysweather.h"
#include "logicmaths.h"


namespace Ui {
class presentGraph;
}

class presentGraph : public QDialog
{
    Q_OBJECT

signals:
    void returnToIntermediateWindow();

public:
    explicit presentGraph(QWidget *parent = nullptr);
    ~presentGraph();

private slots:
    void on_return_btn_4_clicked();

private:
    Ui::presentGraph *ui;
};

#endif // PRESENTGRAPH_H
