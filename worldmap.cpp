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

