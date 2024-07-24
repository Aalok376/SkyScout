#ifndef PASTGRAPH_H
#define PASTGRAPH_H

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

#include "logicmaths.h"
#include "weatherdata.h"

namespace Ui {
class pastGraph;
}

class pastGraph : public QDialog
{
    Q_OBJECT

signals:
    void returnToIntermediateWindow();

public:
    explicit pastGraph(QWidget *parent = nullptr);
    ~pastGraph();

private slots:
    void on_return_btn_2_clicked();

private:
    Ui::pastGraph *ui;
};

#endif // PASTGRAPH_H
