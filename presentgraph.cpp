#include "presentgraph.h"
#include "ui_presentgraph.h"

presentGraph::presentGraph(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::presentGraph)
{
    ui->setupUi(this);
    setWindowTitle("Sky Scout");
    setWindowIcon(QIcon(":/new/prefix1/image/projectLogo.png"));

    ui->return_btn_4->setIcon(QIcon(":/new/prefix1/image/return.svg"));
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
        ui->label->setStyleSheet("background:transparent;color:#F0EFF9;font: 10pt 'Segoe UI';");
        ui->location->setStyleSheet("background:transparent;color:#F0EFF9;font: 10pt 'Segoe UI';");
    }
    else
    {

        ui->centralWidget->setStyleSheet("background-image: url(':/new/prefix1/image/background.png');");
        ui->label->setStyleSheet("background:transparent;color:black;font: 10pt 'Segoe UI';");
        ui->location->setStyleSheet("background:transparent;color:black;font: 10pt 'Segoe UI';");
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
    query.prepare("SELECT city,year,month,date FROM currentWeather WHERE id=:lowestId");
    query.bindValue(":lowestId",lowestId);
    query.exec();
    query.next();
    QString city = query.value(0).toString();
    int year = query.value(1).toInt();
    QString yearr=QString::number(year);
    int mon = query.value(2).toInt();
    int day = query.value(3).toInt();

    QString m = logicMaths::checkDigit(mon);
    QString d = logicMaths::checkDigit(day);

    // ui->location->setText("Location: "+city);
    // ui->label->setText(d+"/"+m+"/"+QString::number(year));

    QString D3;
    for(int i=0;i<m.length();i++)
    {
        if(m[i]=='0')
        {
            D3=D3+"०";
        }
        if(m[i]=='1')
        {
            D3=D3+"१";
        }
        if(m[i]=='2')
        {
            D3=D3+"२";
        }
        if(m[i]=='3')
        {
            D3=D3+"३";
        }
        if(m[i]=='4')
        {
            D3=D3+"४";
        }
        if(m[i]=='5')
        {
            D3=D3+"५";
        }
        if(m[i]=='6')
        {
            D3=D3+"६";
        }
        if(m[i]=='7')
        {
            D3=D3+"७";
        }
        if(m[i]=='8')
        {
            D3=D3+"८";
        }
        if(m[i]=='9')
        {
            D3=D3+"९";
        }
    }
    QString D;
    for(int i=0;i<d.length();i++)
    {
        if(d[i]=='0')
        {
            D=D+"०";
        }
        if(d[i]=='1')
        {
            D=D+"१";
        }
        if(d[i]=='2')
        {
            D=D+"२";
        }
        if(d[i]=='3')
        {
            D=D+"३";
        }
        if(d[i]=='4')
        {
            D=D+"४";
        }
        if(d[i]=='5')
        {
            D=D+"५";
        }
        if(d[i]=='6')
        {
            D=D+"६";
        }
        if(d[i]=='7')
        {
            D=D+"७";
        }
        if(d[i]=='8')
        {
            D=D+"८";
        }
        if(d[i]=='9')
        {
            D=D+"९";
        }
    }
    QString D31;
    for(int i=0;i<yearr.length();i++)
    {
        if(yearr[i]=='0')
        {
            D31=D31+"०";
        }
        if(yearr[i]=='1')
        {
            D31=D31+"१";
        }
        if(yearr[i]=='2')
        {
            D31=D31+"२";
        }
        if(yearr[i]=='3')
        {
            D31=D31+"३";
        }
        if(yearr[i]=='4')
        {
            D31=D31+"४";
        }
        if(yearr[i]=='5')
        {
            D31=D31+"५";
        }
        if(yearr[i]=='6')
        {
            D31=D31+"६";
        }
        if(yearr[i]=='7')
        {
            D31=D31+"७";
        }
        if(yearr[i]=='8')
        {
            D31=D31+"८";
        }
        if(yearr[i]=='9')
        {
            D31=D31+"९";
        }
    }

    if(check==false)
    {
    ui->location->setText("स्थान: "+city);
    ui->label->setText(D+"/"+D3+"/"+D31);
    }
    else
    {
    ui->location->setText("Location: "+city);
    ui->label->setText(d+"/"+m+"/"+QString::number(year));
    }
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

