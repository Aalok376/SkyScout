#include "intermediatewindow.h"
#include "ui_intermediatewindow.h"

intermediateWindow::intermediateWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::intermediateWindow)
{
    ui->setupUi(this);
    setWindowTitle("Sky Scout");
    setWindowIcon(QIcon(":/new/prefix1/image/projectLogo.png"));

    ui->return_btn->setIcon(QIcon(":/new/prefix1/image/return.png"));
    int y =ui->return_btn->height();
    ui->return_btn->setIconSize(QSize(y,y));

    connect(ui->return_btn, &QPushButton::clicked, this, &intermediateWindow::on_return_btn_clicked);
    resize(800,600);
    setFixedSize(size());


    if(checkLight==false)
    {
        ui->centralWidget->setStyleSheet("background-image: url(':/new/prefix1/image/dark_bg.png');");
    }
    else
    {

        ui->centralWidget->setStyleSheet("background-image: url(':/new/prefix1/image/background.png');");

    }

     str="Welcome! \n Stay updated with the current weather.";
     word = str.split(" ");
     CurrentWordIndex=0;
     timer= new QTimer(this);
     connect(timer ,&QTimer::timeout , this , &intermediateWindow::updateLabelText );
     timer->start(500);

}

intermediateWindow::~intermediateWindow()
{
    delete ui;
}
void intermediateWindow::updateLabelText(void){
    if(CurrentWordIndex<word.size()){
        ui->label->setText(ui->label->text()+" "+word[CurrentWordIndex]);
        CurrentWordIndex++;
    }
    else
    {
        CurrentWordIndex=0;
        ui->label->clear();
    }
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

presentGraph *pr;
void intermediateWindow::on_present_data_btn_clicked()
{
    pr = new presentGraph();
    connect(pr, &presentGraph::returnToIntermediateWindow, this, &intermediateWindow::showIntermediateWindowP);

    pr->show();

    this->hide();

    return;
}

void intermediateWindow::showIntermediateWindowP() {
    this->show();
    disconnect(pr, &presentGraph::returnToIntermediateWindow, this, &intermediateWindow::showIntermediateWindowP);
    pr->deleteLater();
    pr = nullptr;
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

