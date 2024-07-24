#ifndef INTERMEDIATEWINDOW_H
#define INTERMEDIATEWINDOW_H

#include <QDialog>
#include "mainwindow.h"
#include "pastgraph.h"
#include "presentgraph.h"
#include "futuregraph.h"

namespace Ui {
class intermediateWindow;
}

class intermediateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit intermediateWindow(QWidget *parent = nullptr);
    ~intermediateWindow();
signals:
    void returnToMainWindow();

private slots:
    void on_return_btn_clicked();

    void on_past_data_btn_clicked();
    void showIntermediateWindow();

    void on_present_data_btn_clicked();
    void showIntermediateWindowP();

    void on_future_data_btn_clicked();
    void showIntermediateWindowF();

private:
    Ui::intermediateWindow *ui;
};

#endif // INTERMEDIATEWINDOW_H
