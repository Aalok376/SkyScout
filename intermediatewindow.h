#ifndef INTERMEDIATEWINDOW_H
#define INTERMEDIATEWINDOW_H

#include <QDialog>
#include "mainwindow.h"

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

private:
    Ui::intermediateWindow *ui;
};

#endif // INTERMEDIATEWINDOW_H
