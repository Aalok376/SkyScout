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

    connect(ui->btnPast, &QPushButton::clicked, [this]() { slideToPage(0); });
    connect(ui->btnPresent, &QPushButton::clicked, [this]() { slideToPage(1); });
    connect(ui->btnFuture, &QPushButton::clicked, [this]() { slideToPage(2); });


    // Initially, show the first page
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->widget(0)->show();


     // str="Welcome! \n Stay updated with the current weather.";
     // word = str.split(" ");
     // CurrentWordIndex=0;
     // timer= new QTimer(this);
     // connect(timer ,&QTimer::timeout , this , &intermediateWindow::updateLabelText );
     // timer->start(500);

}

intermediateWindow::~intermediateWindow()
{
    delete ui;
}


void intermediateWindow::slideToPage(int index)
{


    //newFile::accessMainWindowUI();

    if (index == currentIndex) return;


    QWidget *currentWidget = ui->stackedWidget->widget(currentIndex);
    QWidget *nextWidget = ui->stackedWidget->widget(index);

    // Determine the direction of the slide
    bool slideLeft = index < currentIndex;
    int stackedWidth = ui->stackedWidget->geometry().width();

    // Set up the next widget position for animation
    nextWidget->setGeometry(slideLeft ? -stackedWidth : stackedWidth, 0, stackedWidth, nextWidget->geometry().height());
    nextWidget->show();



    // Animation for the current widget
    QPropertyAnimation *currentWidgetAnim = new QPropertyAnimation(currentWidget, "pos");
    currentWidgetAnim->setDuration(250); // 500 ms
    currentWidgetAnim->setStartValue(currentWidget->pos());
    currentWidgetAnim->setEndValue(QPoint(slideLeft ? stackedWidth : -stackedWidth, 0));

    // Animation for the next widget
    QPropertyAnimation *nextWidgetAnim = new QPropertyAnimation(nextWidget, "pos");
    nextWidgetAnim->setDuration(250); // 500 ms
    nextWidgetAnim->setStartValue(nextWidget->pos());
    nextWidgetAnim->setEndValue(QPoint(0, 0));

    // Group the animations together
    QParallelAnimationGroup *animationGroup = new QParallelAnimationGroup(this);
    animationGroup->addAnimation(currentWidgetAnim);
    animationGroup->addAnimation(nextWidgetAnim);

    // Connect to clean up after animation
    connect(animationGroup, &QParallelAnimationGroup::finished, [currentWidget, nextWidget, index, this]() {
        currentWidget->hide(); // Hide the current widget after the animation
        ui->stackedWidget->setCurrentIndex(index); // Update the stacked widget index
        currentIndex = index; // Update the current index
    });

    // Start the animations
    animationGroup->start(QAbstractAnimation::DeleteWhenStopped);




}


// void intermediateWindow::updateLabelText(void){
//     if(CurrentWordIndex<word.size()){
//         ui->label->setText(ui->label->text()+" "+word[CurrentWordIndex]);
//         CurrentWordIndex++;
//     }
//     else
//     {
//         CurrentWordIndex=0;
//         ui->label->clear();
//     }
// }
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

