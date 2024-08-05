#include "presentgraph.h"
#include "ui_presentgraph.h"

presentGraph::presentGraph(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::presentGraph)
{
    ui->setupUi(this);
    setWindowTitle("Sky Scout");
    setWindowIcon(QIcon(":/new/prefix1/image/projectLogo.png"));

    ui->return_btn_4->setIcon(QIcon(":/new/prefix1/image/return.png"));
    int y =ui->return_btn_4->height();
    ui->return_btn_4->setIconSize(QSize(y,y));

    connect(ui->return_btn_4, &QPushButton::clicked, this, &presentGraph::on_return_btn_4_clicked);
    resize(800,600);
    setFixedSize(size());

    ui->presentplot->addGraph();
    ui->presentplot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->presentplot->graph(0)->setLineStyle(QCPGraph::lsLine);

    // Set axis labels
    ui->presentplot->xAxis->setLabel("Time");
    ui->presentplot->yAxis->setLabel("Temperature(°C)");

    // Customize axis range
    ui->presentplot->xAxis->setRange(24, 30); // Adjust the range to fit all labels
    ui->presentplot->yAxis->setRange(0, 100);

    // Set interactions
    ui->presentplot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    if(checkLight==false)
    {
        ui->centralWidget->setStyleSheet("background-image: url(':/new/prefix1/image/dark_bg.png');");
    }
    else
    {

        ui->centralWidget->setStyleSheet("background-image: url(':/new/prefix1/image/background.png');");

    }
    QVector <double> temp;
    QVector <double> hr;
    QVector <double> min;


    QSqlDatabase cdb=QSqlDatabase::addDatabase("QSQLITE");
    cdb.setDatabaseName(QCoreApplication::applicationDirPath()+"/database/onedaydata.db");
    cdb.open();

    QSqlQuery query;
    query.prepare("SELECT temperature,hour,min FROM currentWeather");
    query.exec();

    while(query.next()) {
        temp.append(query.value(0).toDouble());
        hr.append(query.value(1).toDouble());
        min.append(query.value(2).toDouble());
    }

    QVector <double> preciseHr;
    for(int i=0;i<hr.size();i++) {
        preciseHr.append(hr[i]+min[i]/60);
    }
    ui->presentplot->graph(0)->setData(preciseHr, temp);

    // Customize x-axis to show date labels
    ui->presentplot->xAxis->setSubTicks(false);
    ui->presentplot->xAxis->setTickLength(0, 4);

    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    for(int i=0;i<temp.size();i++) {
        QString check_hr = logicMaths::checkDigit(hr[i]);
        QString check_min = logicMaths::checkDigit(min[i]);
        textTicker->addTick(preciseHr[i], check_hr+":"+check_min);
    }

    ui->presentplot->xAxis->setTicker(textTicker);

    // Customize y-axis range if necessary
    ui->presentplot->yAxis->setRange(0, *std::max_element(temp.begin(), temp.end()) + 1);

    ui->presentplot->rescaleAxes();
    ui->presentplot->replot();
    ui->presentplot->update();

    int lowestId = todaysWeather::findLowestId();
    query.prepare("SELECT city FROM currentWeather WHERE id=:lowestId");
    query.bindValue(":lowestId",lowestId);
    query.exec();
    query.next();
    QString city = query.value(0).toString();

    ui->location->setText("Location: "+city);
}

presentGraph::~presentGraph()
{
    delete ui;
}

void presentGraph::on_return_btn_4_clicked()
{
    emit returnToIntermediateWindow();
    this->close();
    return;

}

