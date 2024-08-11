#include "worldmap.h"
#include "ui_worldmap.h"

worldMap::worldMap(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::worldMap)
{
    ui->setupUi(this);
    setWindowTitle("Sky Scout");
    setWindowIcon(QIcon(":/new/prefix1/image/projectLogo.png"));

    ui->pushButton->setIcon(QIcon(":/new/prefix1/image/return.svg"));
    int y =ui->pushButton->height();
    ui->pushButton->setIconSize(QSize(y,y));

    connect(ui->pushButton, &QPushButton::clicked, this, &worldMap::on_pushButton_clicked);
    resize(800,600);
    setFixedSize(size());
    // //   map integration
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/MapView.qml")));
    ui->quickWidget->show();
  //  int wid = 350,hei = 170;
  //  int radius = 12;
    //int wid=ui->widget_2->width();
    //int hei=ui->widget_2->height();
    //   qDebug()<<wid<<"skdfksdsjfksdfjsdkjfdskj";
    //     qDebug()<<hei;

 //   ui->quickWidget->setFixedSize(wid, hei);
    //  //  Create a QPainterPath for the rounded rectangle
  //  QPainterPath path;
  //  path.addRoundedRect(0, 0, wid, hei, radius, radius);

    // //    // Convert the QPainterPath to a QRegion and set it as the mask
   // QRegion region(path.toFillPolygon().toPolygon());

 //   ui->quickWidget->setMask(region);
    //ui->horizontalLayout_28->addWidget(ui->quickWidget, 0, Qt::AlignCenter);



    auto rootObject = ui->quickWidget->rootObject();
    connect(this , SIGNAL(updateMap(QVariant,QVariant)) , rootObject , SLOT(updateMap(QVariant,QVariant)));
    //emit( 1,1 );
}

worldMap::~worldMap()
{
    delete ui;
}

void worldMap::on_pushButton_clicked()
{
        emit returnToMainWindow();
        this->close();
        return;
}

