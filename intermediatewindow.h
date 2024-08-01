#ifndef INTERMEDIATEWINDOW_H
#define INTERMEDIATEWINDOW_H

#include <QDialog>
#include "mainwindow.h"
#include "pastgraph.h"
#include "presentgraph.h"
#include "futuregraph.h"
#include "modecheck.h"
#include<QIcon>
#include<QTimer>
#include <QPropertyAnimation>
#include <QStackedWidget>
#include <QParallelAnimationGroup>
#include<qstringlist.h>
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
    void slideToPage(int index);
    //void updateLabelText(void);

private:
    Ui::intermediateWindow *ui;
    QTimer *timer;
    QString str;
    QStringList word;
    int CurrentWordIndex;
    int currentIndex;
};

#endif // INTERMEDIATEWINDOW_H
