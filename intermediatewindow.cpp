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

pastGraph *pg;
void intermediateWindow::on_past_data_btn_clicked()
{
    pg = new pastGraph();
    connect(pg, &pastGraph::returnToIntermediateWindow, this, &intermediateWindow::showIntermediateWindow);

    pg->show();

    this->hide();

    return;
}

void intermediateWindow::showIntermediateWindow() {
    this->show();
    disconnect(pg, &pastGraph::returnToIntermediateWindow, this, &intermediateWindow::showIntermediateWindow);
    pg->deleteLater();
    pg = nullptr;
    return;
}

presentGraph *prg;
void intermediateWindow::on_present_data_btn_clicked()
{
    prg = new presentGraph();
    connect(prg, &presentGraph::returnToIntermediateWindow, this, &intermediateWindow::showIntermediateWindowP);

    prg->show();

    this->hide();

    return;
}

void intermediateWindow::showIntermediateWindowP() {
    this->show();
    disconnect(prg, &presentGraph::returnToIntermediateWindow, this, &intermediateWindow::showIntermediateWindowP);
    prg->deleteLater();
    prg = nullptr;
    return;
}

futureGraph *fg;
void intermediateWindow::on_future_data_btn_clicked()
{
    fg = new futureGraph();
    connect(fg, &futureGraph::returnToIntermediateWindow, this, &intermediateWindow::showIntermediateWindowF);

    fg->show();

    this->hide();

    return;
}

void intermediateWindow::showIntermediateWindowF() {
    this->show();
    disconnect(fg, &futureGraph::returnToIntermediateWindow, this, &intermediateWindow::showIntermediateWindowF);
    fg->deleteLater();
    fg = nullptr;
    return;
}

