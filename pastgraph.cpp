#include "pastgraph.h"
#include "ui_pastgraph.h"

pastGraph::pastGraph(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::pastGraph)
{
    ui->setupUi(this);
    setWindowTitle("Sky Scout");
    setWindowIcon(QIcon(":/new/prefix1/image/projectLogo.png"));

    ui->return_btn_2->setIcon(QIcon(":/new/prefix1/image/return.png"));
    int y =ui->return_btn_2->height();
    ui->return_btn_2->setIconSize(QSize(y,y));

    connect(ui->return_btn_2, &QPushButton::clicked, this, &pastGraph::on_return_btn_2_clicked);
    resize(800,600);
    setFixedSize(size());


    ui->pastplot->addGraph();
    ui->pastplot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->pastplot->graph(0)->setLineStyle(QCPGraph::lsLine);

    // Set axis labels
    ui->pastplot->xAxis->setLabel("Date");
    ui->pastplot->yAxis->setLabel("Temperature(°C)");

    // Customize axis range
    ui->pastplot->xAxis->setRange(24, 30); // Adjust the range to fit all labels
    ui->pastplot->yAxis->setRange(0, 100);

    // Set interactions
    ui->pastplot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);


    if(checkLight==false)
    {
        ui->centralWidget->setStyleSheet("background-image: url(':/new/prefix1/image/dark_bg.png');");
    }
    else
    {

        ui->centralWidget->setStyleSheet("background-image: url(':/new/prefix1/image/background.png');");

    }
    QSqlDatabase pastdb=QSqlDatabase::addDatabase("QSQLITE");
    pastdb.setDatabaseName(QCoreApplication::applicationDirPath()+"/database/weatherdb.db");
    pastdb.open();

    QSqlQuery query;
    QVector <double> temp;
    QVector <int> year;
    QVector <int> month;
    QVector <double> date;
   // int count =0;
    query.prepare("SELECT temperature,year,month,date FROM pastWeather");
    query.exec();
    while(query.next()) {
        temp.append(query.value(0).toDouble());
        year.append(query.value(1).toInt());
        month.append(query.value(2).toInt());
        date.append(query.value(3).toDouble());
       // count++;
    }
    // Your data
    //QVector<double> x = {25, 26, 27, 28, 29, 30}; // Use 30 to represent the 1st of the next month
    //QVector<double> y = {5, 3, 4, 7, 8, 5};

    QVector <double> copyDate = date;

    for(int i=0;i<temp.size();i++) {
        double testDate = date[i];
        int testMonth = month[i];

        if(testMonth!=month[0]) {
            testDate = logicMaths::noOfDays(month[0],year[0]) + date[i];
        }

        date[i] = testDate;

    }
    // Plot data
    ui->pastplot->graph(0)->setData(date, temp);

    // Customize x-axis to show date labels
    ui->pastplot->xAxis->setSubTicks(false);
    ui->pastplot->xAxis->setTickLength(0, 4);

    // Set custom tick labels
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    for(int i=0;i<temp.size();i++) {
        double testDate = date[i];
        //int testMonth = month[i];

        // if(testMonth!=month[0]) {
        //     testDate = logicMaths::noOfDays(month[0],year[0]) + date[i];
        // }

        textTicker->addTick(testDate, logicMaths::nameOfMonth(month[i])+" "+QString::number(copyDate[i]));
    }
    // textTicker->addTick(25, "July 25");
    // textTicker->addTick(26, "July 26");
    // textTicker->addTick(27, "July 27");
    // textTicker->addTick(28, "July 28");
    // textTicker->addTick(29, "July 29");
    // textTicker->addTick(30, "Aug 1"); // Label for the 1st of the next month
    ui->pastplot->xAxis->setTicker(textTicker);

    // Customize y-axis range if necessary
    ui->pastplot->yAxis->setRange(0, *std::max_element(temp.begin(), temp.end()) + 1);

    // Replot the graph
    ui->pastplot->rescaleAxes();
    ui->pastplot->replot();
    ui->pastplot->update();

    int lowestId = weatherData::findLowestId();

    query.prepare("SELECT city FROM pastWeather WHERE id = :lowestId");
    query.bindValue(":lowestId",lowestId);
    query.exec();
    query.next();
    QString city = query.value(0).toString();

    ui->location->setText("Location: "+city);
}

pastGraph::~pastGraph()
{
    delete ui;
}

void pastGraph::on_return_btn_2_clicked()
{
    emit returnToIntermediateWindow();
    this->close();
    return;
}

