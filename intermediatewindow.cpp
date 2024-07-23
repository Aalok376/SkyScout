#include "intermediatewindow.h"
#include "ui_intermediatewindow.h"

intermediateWindow::intermediateWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::intermediateWindow)
{
    ui->setupUi(this);
    setWindowTitle("Sky Scout");
    setWindowIcon(QIcon(":/new/prefix1/image/projectLogo.png"));

    connect(ui->return_btn, &QPushButton::clicked, this, &intermediateWindow::on_return_btn_clicked);
    resize(800,600);
    setFixedSize(size());
}

intermediateWindow::~intermediateWindow()
{
    delete ui;
}

void intermediateWindow::on_return_btn_clicked()
{
    //MainWindow *mainWindow = new MainWindow();
    //mainWindow->show();
    //this->hide();
    emit returnToMainWindow();
    this->close();
    return;
}

