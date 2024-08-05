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

        ui->pastLocation->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastLocation_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastTemp->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastTemp_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastHumidity->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastHumidity_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastStatus->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastStatus_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastLat->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastLat_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastLon->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastLon_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");

        ui->presentLocation->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentLocation_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentTemp->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentTemp_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentHumidity->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentHumidity_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentStatus->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentStatus_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentLat->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentLat_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentLon->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentLon_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");

        ui->futureLocation->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureLocation_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureTemp->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureTemp_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureHumidity->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureHumidity_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureStatus->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureStatus_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureLat->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureLat_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureLon->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureLon_2->setStyleSheet("color:#F0EFF9;background:transparent;font: 10pt 'Segoe UI';");



    }
    else
    {

        ui->centralWidget->setStyleSheet("background-image: url(':/new/prefix1/image/background.png');");

        ui->pastLocation->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastLocation_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastTemp->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastTemp_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastHumidity->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastHumidity_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastStatus->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastStatus_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastLat->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastLat_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastLon->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->pastLon_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");

        ui->presentLocation->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentLocation_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentTemp->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentTemp_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentHumidity->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentHumidity_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentStatus->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentStatus_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentLat->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentLat_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentLon->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->presentLon_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");

        ui->futureLocation->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureLocation_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureTemp->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureTemp_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureHumidity->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureHumidity_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureStatus->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureStatus_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureLat->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureLat_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureLon->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");
        ui->futureLon_2->setStyleSheet("color:black;background:transparent;font: 10pt 'Segoe UI';");

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

    QString city;
    QVector<double> temp;
    QVector<double> humidity;
    QVector<QString> status;
    double lat;
    double lon;


    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(QCoreApplication::applicationDirPath()+"/database/weatherdb.db");

    mydb.open();

    QSqlQuery query;
    query.prepare("SELECT city,temperature,humidity,lat,lon,status FROM pastWeather");


    if(query.exec()){

        while(query.next()){
            city = query.value(0).toString();
            temp.append(query.value(1).toDouble());
            humidity.append(query.value(2).toDouble());
            lat = query.value(3).toDouble();
            lon = query.value(4).toDouble();
            status.append(query.value(5).toString());

        }
    }else{
        qDebug()<<"error";
    }

    double tem[temp.size()];
    for(int i=0;i<temp.size();i++){
        tem[i]=temp[i];
    }
    double hum[humidity.size()];
    for(int i=0;i<humidity.size();i++){
        hum[i]=humidity[i];
    }
     QString sta[status.size()];
     for(int i=0;i<status.size();i++){
         sta[i]=status[i];
    }

    double t = logicMaths::avgTemp(tem,temp.size());
    double h = logicMaths::avgHumidity(hum,humidity.size());
    QString s = logicMaths::weatherMode(sta,status.size());

    ui->locationpast->setText(city);
    QIcon icon = logicMaths::getStatusIcon(s);
    ui->iconpast->setPixmap(icon.pixmap(QSize(85,51)));

    ui->pastLocation_2->setText(city);
    t = logicMaths::twoDecimals(t);
    h = logicMaths::twoDecimals(h);
    ui->pastTemp_2->setText(QString::number(t)+"°C");
    ui->pastHumidity_2->setText(QString::number(h)+"%");
    ui->pastStatus_2->setText(s);
    ui->pastLat_2->setText(QString::number(lat));
    ui->pastLon_2->setText(QString::number(lon));

    //present data

    QVector<double> temp2;
    QVector<double> humidity2;
    QVector<QString> status2;
    mydb.setDatabaseName(QCoreApplication::applicationDirPath()+"/database/onedaydata.db");

    mydb.open();

    query.prepare("SELECT city,temperature,humidity,status,lat,lon FROM currentWeather");


    if(query.exec()){

        while(query.next()){
            city = query.value(0).toString();
            temp2.append(query.value(1).toDouble());
            humidity2.append(query.value(2).toDouble());
            status2.append(query.value(3).toString());
            lat = query.value(4).toDouble();
            lon = query.value(5).toDouble();
        }
    }else{
        qDebug()<<"error";
    }

     double tem0[temp2.size()];
    for(int i=0;i<temp2.size();i++){
        tem0[i]=temp2[i];
    }
    double hum0[humidity2.size()];
    for(int i=0;i<humidity2.size();i++){
        hum0[i]=humidity2[i];
    }
    QString sta0[status2.size()];
    for(int i=0;i<status2.size();i++){
        sta0[i]=status2[i];
    }

     t = logicMaths::avgTemp(tem0,temp2.size());
    t = logicMaths::twoDecimals(t);
     h = logicMaths::avgHumidity(hum0,humidity2.size());
    h = logicMaths::twoDecimals(h);
     s = logicMaths::weatherMode(sta0,status2.size());

    ui->locationpresent->setText(city);
    icon = logicMaths::getStatusIcon(s);
    ui->iconpresent->setPixmap(icon.pixmap(QSize(85,51)));

    ui->presentLocation_2->setText(city);
    ui->presentTemp_2->setText(QString::number(t)+"°C");
    ui->presentHumidity_2->setText(QString::number(h)+"%");
    ui->presentStatus_2->setText(s);
    ui->presentLat_2->setText(QString::number(lat));
    ui->presentLon_2->setText(QString::number(lon));

    //future data

    QVector<double> temp3;
    QVector<double> humidity3;
    QVector<QString> status3;
    mydb.setDatabaseName(QCoreApplication::applicationDirPath()+"/database/futuredata.db");

    mydb.open();

    query.prepare("SELECT city,temperature,humidity,status FROM futureWeather");


    if(query.exec()){

        while(query.next()){
            city = query.value(0).toString();
            temp3.append(query.value(1).toDouble());
            humidity3.append(query.value(2).toDouble());
            status3.append(query.value(3).toString());

        }
    }else{
        qDebug()<<"error";
    }

    double tem1[temp3.size()];
    for(int i=0;i<temp3.size();i++){
        tem1[i]=temp3[i];
    }
    double hum1[humidity3.size()];
    for(int i=0;i<humidity3.size();i++){
        hum1[i]=humidity3[i];
    }
    QString sta1[status3.size()];
    for(int i=0;i<status3.size();i++){
        sta1[i]=status3[i];
    }

    t = logicMaths::avgTemp(tem1,temp3.size());
    t = logicMaths::tempConversion(t);
    t = logicMaths::twoDecimals(t);
    h = logicMaths::avgHumidity(hum1,humidity3.size());
    h = logicMaths::twoDecimals(h);
     s = logicMaths::weatherMode(sta1,status3.size());

    ui->locationfuture->setText(city);
    icon = logicMaths::getStatusIcon(s);
    ui->iconfuture->setPixmap(icon.pixmap(QSize(85,51)));

    ui->futureLocation_2->setText(city);
    ui->futureTemp_2->setText(QString::number(t)+"°C");
    ui->futureHumidity_2->setText(QString::number(h)+"%");
    ui->futureStatus_2->setText(s);
    ui->futureLat_2->setText(QString::number(lat));
    ui->futureLon_2->setText(QString::number(lon));

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

