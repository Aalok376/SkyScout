/********************************************************************************
** Form generated from reading UI file 'intermediatewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERMEDIATEWINDOW_H
#define UI_INTERMEDIATEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_intermediateWindow
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *return_btn;
    QPushButton *btnPast;
    QPushButton *btnPresent;
    QPushButton *btnFuture;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *past_data_btn;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;
    QLabel *pastLocation;
    QLabel *pastTemp;
    QLabel *pastHumidity;
    QLabel *pastLat;
    QLabel *pastLon;
    QLabel *pastStatus;
    QLabel *pastLocation_2;
    QLabel *pastTemp_2;
    QLabel *pastHumidity_2;
    QLabel *pastStatus_2;
    QLabel *pastLat_2;
    QLabel *pastLon_2;
    QLabel *locationpast;
    QLabel *iconpast;
    QWidget *page_2;
    QPushButton *present_data_btn;
    QFrame *line_8;
    QFrame *line_9;
    QFrame *line_10;
    QFrame *line_11;
    QFrame *line_12;
    QFrame *line_13;
    QFrame *line_14;
    QLabel *presentLocation;
    QLabel *presentTemp;
    QLabel *presentHumidity;
    QLabel *presentStatus;
    QLabel *presentLat;
    QLabel *presentLon;
    QLabel *presentLocation_2;
    QLabel *presentTemp_2;
    QLabel *presentHumidity_2;
    QLabel *presentStatus_2;
    QLabel *presentLat_2;
    QLabel *presentLon_2;
    QLabel *locationpresent;
    QLabel *iconpresent;
    QWidget *page_3;
    QPushButton *future_data_btn;
    QFrame *line_15;
    QFrame *line_16;
    QFrame *line_17;
    QFrame *line_18;
    QFrame *line_19;
    QFrame *line_20;
    QFrame *line_21;
    QLabel *futureLocation;
    QLabel *futureTemp;
    QLabel *futureHumidity;
    QLabel *futureStatus;
    QLabel *futureLat;
    QLabel *futureLon;
    QLabel *futureLocation_2;
    QLabel *futureTemp_2;
    QLabel *futureHumidity_2;
    QLabel *futureStatus_2;
    QLabel *futureLat_2;
    QLabel *futureLon_2;
    QLabel *locationfuture;
    QLabel *iconfuture;

    void setupUi(QDialog *intermediateWindow)
    {
        if (intermediateWindow->objectName().isEmpty())
            intermediateWindow->setObjectName("intermediateWindow");
        intermediateWindow->resize(753, 434);
        intermediateWindow->setStyleSheet(QString::fromUtf8("background-image: url(\":/new/prefix1/image/background.png\");"));
        horizontalLayout_2 = new QHBoxLayout(intermediateWindow);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        centralWidget = new QWidget(intermediateWindow);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        return_btn = new QPushButton(centralWidget);
        return_btn->setObjectName("return_btn");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(return_btn->sizePolicy().hasHeightForWidth());
        return_btn->setSizePolicy(sizePolicy);
        return_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background:rgba(255,255,255,.1);\n"
"	border-radius:12%;\n"
"}\n"
"QPushButton:hover{\n"
"	background:rgba(255,255,255,.3);\n"
"}"));

        horizontalLayout_4->addWidget(return_btn);

        btnPast = new QPushButton(centralWidget);
        btnPast->setObjectName("btnPast");
        sizePolicy.setHeightForWidth(btnPast->sizePolicy().hasHeightForWidth());
        btnPast->setSizePolicy(sizePolicy);
        btnPast->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 10pt 'Segoe UI';\n"
"	color:black;\n"
"	background:rgba(255,255,255,.1);\n"
"	border-radius:12%;\n"
"}\n"
"QPushButton:hover{\n"
"	background:rgba(255,255,255,.3);\n"
"}"));

        horizontalLayout_4->addWidget(btnPast);

        btnPresent = new QPushButton(centralWidget);
        btnPresent->setObjectName("btnPresent");
        sizePolicy.setHeightForWidth(btnPresent->sizePolicy().hasHeightForWidth());
        btnPresent->setSizePolicy(sizePolicy);
        btnPresent->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 10pt 'Segoe UI';\n"
"	color:black;\n"
"	background:rgba(255,255,255,.1);\n"
"	border-radius:12%;\n"
"}\n"
"QPushButton:hover{\n"
"	background:rgba(255,255,255,.3);\n"
"}"));

        horizontalLayout_4->addWidget(btnPresent);

        btnFuture = new QPushButton(centralWidget);
        btnFuture->setObjectName("btnFuture");
        sizePolicy.setHeightForWidth(btnFuture->sizePolicy().hasHeightForWidth());
        btnFuture->setSizePolicy(sizePolicy);
        btnFuture->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 10pt 'Segoe UI';\n"
"	color:black;\n"
"	background:rgba(255,255,255,.1);\n"
"	border-radius:12%;\n"
"}\n"
"QPushButton:hover{\n"
"	background:rgba(255,255,255,.3);\n"
"}"));

        horizontalLayout_4->addWidget(btnFuture);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 5);
        horizontalLayout_4->setStretch(2, 5);
        horizontalLayout_4->setStretch(3, 5);

        verticalLayout_2->addLayout(horizontalLayout_4);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("background:rgba(255,255,255,0.05);\n"
"border-radius:12%;"));
        page = new QWidget();
        page->setObjectName("page");
        past_data_btn = new QPushButton(page);
        past_data_btn->setObjectName("past_data_btn");
        past_data_btn->setGeometry(QRect(560, 30, 141, 51));
        sizePolicy.setHeightForWidth(past_data_btn->sizePolicy().hasHeightForWidth());
        past_data_btn->setSizePolicy(sizePolicy);
        past_data_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 10pt 'Segoe UI';\n"
"	color:black;\n"
"	background:rgba(255,255,255,.1);\n"
"}\n"
"QPushButton:hover{\n"
"	background:rgba(255,255,255,.3);\n"
"}"));
        line = new QFrame(page);
        line->setObjectName("line");
        line->setGeometry(QRect(30, 100, 671, 4));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(page);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(30, 140, 671, 4));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        line_3 = new QFrame(page);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(30, 180, 671, 4));
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        line_4 = new QFrame(page);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(30, 220, 671, 4));
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);
        line_5 = new QFrame(page);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(30, 260, 671, 4));
        line_5->setFrameShape(QFrame::Shape::HLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);
        line_6 = new QFrame(page);
        line_6->setObjectName("line_6");
        line_6->setGeometry(QRect(30, 300, 671, 4));
        line_6->setFrameShape(QFrame::Shape::HLine);
        line_6->setFrameShadow(QFrame::Shadow::Sunken);
        line_7 = new QFrame(page);
        line_7->setObjectName("line_7");
        line_7->setGeometry(QRect(30, 340, 671, 4));
        line_7->setFrameShape(QFrame::Shape::HLine);
        line_7->setFrameShadow(QFrame::Shadow::Sunken);
        pastLocation = new QLabel(page);
        pastLocation->setObjectName("pastLocation");
        pastLocation->setGeometry(QRect(40, 110, 71, 21));
        pastLocation->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        pastTemp = new QLabel(page);
        pastTemp->setObjectName("pastTemp");
        pastTemp->setGeometry(QRect(40, 150, 81, 21));
        pastTemp->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        pastHumidity = new QLabel(page);
        pastHumidity->setObjectName("pastHumidity");
        pastHumidity->setGeometry(QRect(40, 190, 71, 21));
        pastHumidity->setStyleSheet(QString::fromUtf8("font: 10pt 'Segoe UI';\n"
"background:transparent;"));
        pastLat = new QLabel(page);
        pastLat->setObjectName("pastLat");
        pastLat->setGeometry(QRect(40, 270, 71, 21));
        pastLat->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        pastLon = new QLabel(page);
        pastLon->setObjectName("pastLon");
        pastLon->setGeometry(QRect(40, 310, 71, 21));
        pastLon->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        pastStatus = new QLabel(page);
        pastStatus->setObjectName("pastStatus");
        pastStatus->setGeometry(QRect(40, 230, 71, 21));
        pastStatus->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        pastLocation_2 = new QLabel(page);
        pastLocation_2->setObjectName("pastLocation_2");
        pastLocation_2->setGeometry(QRect(600, 110, 91, 21));
        pastLocation_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        pastTemp_2 = new QLabel(page);
        pastTemp_2->setObjectName("pastTemp_2");
        pastTemp_2->setGeometry(QRect(600, 150, 91, 21));
        pastTemp_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        pastHumidity_2 = new QLabel(page);
        pastHumidity_2->setObjectName("pastHumidity_2");
        pastHumidity_2->setGeometry(QRect(600, 190, 91, 21));
        pastHumidity_2->setStyleSheet(QString::fromUtf8("font: 10pt 'Segoe UI';\n"
"background:transparent;"));
        pastStatus_2 = new QLabel(page);
        pastStatus_2->setObjectName("pastStatus_2");
        pastStatus_2->setGeometry(QRect(600, 230, 91, 21));
        pastStatus_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        pastLat_2 = new QLabel(page);
        pastLat_2->setObjectName("pastLat_2");
        pastLat_2->setGeometry(QRect(600, 270, 91, 21));
        pastLat_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        pastLon_2 = new QLabel(page);
        pastLon_2->setObjectName("pastLon_2");
        pastLon_2->setGeometry(QRect(600, 310, 91, 21));
        pastLon_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        locationpast = new QLabel(page);
        locationpast->setObjectName("locationpast");
        locationpast->setGeometry(QRect(40, 40, 191, 51));
        locationpast->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 16pt 'Segoe UI';\n"
"color:black;"));
        iconpast = new QLabel(page);
        iconpast->setObjectName("iconpast");
        iconpast->setGeometry(QRect(220, 20, 151, 71));
        iconpast->setStyleSheet(QString::fromUtf8("background:transparent;"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        present_data_btn = new QPushButton(page_2);
        present_data_btn->setObjectName("present_data_btn");
        present_data_btn->setGeometry(QRect(560, 30, 141, 51));
        sizePolicy.setHeightForWidth(present_data_btn->sizePolicy().hasHeightForWidth());
        present_data_btn->setSizePolicy(sizePolicy);
        present_data_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 10pt 'Segoe UI';\n"
"	color:black;\n"
"	background:rgba(255,255,255,.1);\n"
"}\n"
"QPushButton:hover{\n"
"	background:rgba(255,255,255,.3);\n"
"}"));
        line_8 = new QFrame(page_2);
        line_8->setObjectName("line_8");
        line_8->setGeometry(QRect(30, 100, 671, 4));
        line_8->setFrameShape(QFrame::Shape::HLine);
        line_8->setFrameShadow(QFrame::Shadow::Sunken);
        line_9 = new QFrame(page_2);
        line_9->setObjectName("line_9");
        line_9->setGeometry(QRect(30, 140, 671, 4));
        line_9->setFrameShape(QFrame::Shape::HLine);
        line_9->setFrameShadow(QFrame::Shadow::Sunken);
        line_10 = new QFrame(page_2);
        line_10->setObjectName("line_10");
        line_10->setGeometry(QRect(30, 180, 671, 4));
        line_10->setFrameShape(QFrame::Shape::HLine);
        line_10->setFrameShadow(QFrame::Shadow::Sunken);
        line_11 = new QFrame(page_2);
        line_11->setObjectName("line_11");
        line_11->setGeometry(QRect(30, 220, 671, 4));
        line_11->setFrameShape(QFrame::Shape::HLine);
        line_11->setFrameShadow(QFrame::Shadow::Sunken);
        line_12 = new QFrame(page_2);
        line_12->setObjectName("line_12");
        line_12->setGeometry(QRect(30, 260, 671, 4));
        line_12->setFrameShape(QFrame::Shape::HLine);
        line_12->setFrameShadow(QFrame::Shadow::Sunken);
        line_13 = new QFrame(page_2);
        line_13->setObjectName("line_13");
        line_13->setGeometry(QRect(30, 300, 671, 4));
        line_13->setFrameShape(QFrame::Shape::HLine);
        line_13->setFrameShadow(QFrame::Shadow::Sunken);
        line_14 = new QFrame(page_2);
        line_14->setObjectName("line_14");
        line_14->setGeometry(QRect(30, 340, 671, 4));
        line_14->setFrameShape(QFrame::Shape::HLine);
        line_14->setFrameShadow(QFrame::Shadow::Sunken);
        presentLocation = new QLabel(page_2);
        presentLocation->setObjectName("presentLocation");
        presentLocation->setGeometry(QRect(40, 110, 71, 21));
        presentLocation->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        presentTemp = new QLabel(page_2);
        presentTemp->setObjectName("presentTemp");
        presentTemp->setGeometry(QRect(40, 150, 81, 21));
        presentTemp->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        presentHumidity = new QLabel(page_2);
        presentHumidity->setObjectName("presentHumidity");
        presentHumidity->setGeometry(QRect(40, 190, 71, 21));
        presentHumidity->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        presentStatus = new QLabel(page_2);
        presentStatus->setObjectName("presentStatus");
        presentStatus->setGeometry(QRect(40, 230, 71, 21));
        presentStatus->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        presentLat = new QLabel(page_2);
        presentLat->setObjectName("presentLat");
        presentLat->setGeometry(QRect(40, 270, 71, 21));
        presentLat->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        presentLon = new QLabel(page_2);
        presentLon->setObjectName("presentLon");
        presentLon->setGeometry(QRect(40, 310, 81, 21));
        presentLon->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        presentLocation_2 = new QLabel(page_2);
        presentLocation_2->setObjectName("presentLocation_2");
        presentLocation_2->setGeometry(QRect(600, 110, 91, 21));
        presentLocation_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        presentTemp_2 = new QLabel(page_2);
        presentTemp_2->setObjectName("presentTemp_2");
        presentTemp_2->setGeometry(QRect(600, 150, 91, 21));
        presentTemp_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        presentHumidity_2 = new QLabel(page_2);
        presentHumidity_2->setObjectName("presentHumidity_2");
        presentHumidity_2->setGeometry(QRect(600, 190, 91, 21));
        presentHumidity_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        presentStatus_2 = new QLabel(page_2);
        presentStatus_2->setObjectName("presentStatus_2");
        presentStatus_2->setGeometry(QRect(600, 230, 91, 21));
        presentStatus_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        presentLat_2 = new QLabel(page_2);
        presentLat_2->setObjectName("presentLat_2");
        presentLat_2->setGeometry(QRect(600, 270, 91, 21));
        presentLat_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        presentLon_2 = new QLabel(page_2);
        presentLon_2->setObjectName("presentLon_2");
        presentLon_2->setGeometry(QRect(600, 310, 91, 21));
        presentLon_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        locationpresent = new QLabel(page_2);
        locationpresent->setObjectName("locationpresent");
        locationpresent->setGeometry(QRect(40, 40, 181, 51));
        locationpresent->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 16pt 'Segoe UI';\n"
"color:black;"));
        iconpresent = new QLabel(page_2);
        iconpresent->setObjectName("iconpresent");
        iconpresent->setGeometry(QRect(220, 20, 151, 71));
        iconpresent->setStyleSheet(QString::fromUtf8("background:transparent;\n"
""));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        future_data_btn = new QPushButton(page_3);
        future_data_btn->setObjectName("future_data_btn");
        future_data_btn->setGeometry(QRect(558, 30, 141, 51));
        sizePolicy.setHeightForWidth(future_data_btn->sizePolicy().hasHeightForWidth());
        future_data_btn->setSizePolicy(sizePolicy);
        future_data_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 10pt 'Segoe UI';\n"
"	color:black;\n"
"	background:rgba(255,255,255,.1);\n"
"}\n"
"QPushButton:hover{\n"
"	background:rgba(255,255,255,.3);\n"
"}"));
        line_15 = new QFrame(page_3);
        line_15->setObjectName("line_15");
        line_15->setGeometry(QRect(30, 100, 671, 4));
        line_15->setFrameShape(QFrame::Shape::HLine);
        line_15->setFrameShadow(QFrame::Shadow::Sunken);
        line_16 = new QFrame(page_3);
        line_16->setObjectName("line_16");
        line_16->setGeometry(QRect(30, 140, 671, 4));
        line_16->setFrameShape(QFrame::Shape::HLine);
        line_16->setFrameShadow(QFrame::Shadow::Sunken);
        line_17 = new QFrame(page_3);
        line_17->setObjectName("line_17");
        line_17->setGeometry(QRect(30, 180, 671, 4));
        line_17->setFrameShape(QFrame::Shape::HLine);
        line_17->setFrameShadow(QFrame::Shadow::Sunken);
        line_18 = new QFrame(page_3);
        line_18->setObjectName("line_18");
        line_18->setGeometry(QRect(30, 220, 671, 4));
        line_18->setFrameShape(QFrame::Shape::HLine);
        line_18->setFrameShadow(QFrame::Shadow::Sunken);
        line_19 = new QFrame(page_3);
        line_19->setObjectName("line_19");
        line_19->setGeometry(QRect(30, 260, 671, 4));
        line_19->setFrameShape(QFrame::Shape::HLine);
        line_19->setFrameShadow(QFrame::Shadow::Sunken);
        line_20 = new QFrame(page_3);
        line_20->setObjectName("line_20");
        line_20->setGeometry(QRect(30, 300, 671, 4));
        line_20->setFrameShape(QFrame::Shape::HLine);
        line_20->setFrameShadow(QFrame::Shadow::Sunken);
        line_21 = new QFrame(page_3);
        line_21->setObjectName("line_21");
        line_21->setGeometry(QRect(30, 340, 671, 4));
        line_21->setFrameShape(QFrame::Shape::HLine);
        line_21->setFrameShadow(QFrame::Shadow::Sunken);
        futureLocation = new QLabel(page_3);
        futureLocation->setObjectName("futureLocation");
        futureLocation->setGeometry(QRect(40, 110, 71, 21));
        futureLocation->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        futureTemp = new QLabel(page_3);
        futureTemp->setObjectName("futureTemp");
        futureTemp->setGeometry(QRect(40, 150, 81, 21));
        futureTemp->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        futureHumidity = new QLabel(page_3);
        futureHumidity->setObjectName("futureHumidity");
        futureHumidity->setGeometry(QRect(40, 190, 71, 21));
        futureHumidity->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        futureStatus = new QLabel(page_3);
        futureStatus->setObjectName("futureStatus");
        futureStatus->setGeometry(QRect(40, 230, 71, 21));
        futureStatus->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        futureLat = new QLabel(page_3);
        futureLat->setObjectName("futureLat");
        futureLat->setGeometry(QRect(40, 270, 71, 21));
        futureLat->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        futureLon = new QLabel(page_3);
        futureLon->setObjectName("futureLon");
        futureLon->setGeometry(QRect(40, 310, 71, 21));
        futureLon->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        futureLocation_2 = new QLabel(page_3);
        futureLocation_2->setObjectName("futureLocation_2");
        futureLocation_2->setGeometry(QRect(600, 110, 91, 21));
        futureLocation_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        futureTemp_2 = new QLabel(page_3);
        futureTemp_2->setObjectName("futureTemp_2");
        futureTemp_2->setGeometry(QRect(600, 150, 91, 21));
        futureTemp_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        futureHumidity_2 = new QLabel(page_3);
        futureHumidity_2->setObjectName("futureHumidity_2");
        futureHumidity_2->setGeometry(QRect(600, 190, 91, 21));
        futureHumidity_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        futureStatus_2 = new QLabel(page_3);
        futureStatus_2->setObjectName("futureStatus_2");
        futureStatus_2->setGeometry(QRect(600, 230, 91, 21));
        futureStatus_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        futureLat_2 = new QLabel(page_3);
        futureLat_2->setObjectName("futureLat_2");
        futureLat_2->setGeometry(QRect(600, 270, 91, 21));
        futureLat_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        futureLon_2 = new QLabel(page_3);
        futureLon_2->setObjectName("futureLon_2");
        futureLon_2->setGeometry(QRect(600, 310, 91, 21));
        futureLon_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 10pt 'Segoe UI';"));
        locationfuture = new QLabel(page_3);
        locationfuture->setObjectName("locationfuture");
        locationfuture->setGeometry(QRect(40, 40, 171, 51));
        locationfuture->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"font: 16pt 'Segoe UI';\n"
"color:black;"));
        iconfuture = new QLabel(page_3);
        iconfuture->setObjectName("iconfuture");
        iconfuture->setGeometry(QRect(220, 20, 151, 71));
        iconfuture->setStyleSheet(QString::fromUtf8("background:transparent;"));
        stackedWidget->addWidget(page_3);

        verticalLayout_2->addWidget(stackedWidget);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 10);

        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_2->addWidget(centralWidget);


        retranslateUi(intermediateWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(intermediateWindow);
    } // setupUi

    void retranslateUi(QDialog *intermediateWindow)
    {
        intermediateWindow->setWindowTitle(QCoreApplication::translate("intermediateWindow", "Dialog", nullptr));
        return_btn->setText(QString());
        btnPast->setText(QCoreApplication::translate("intermediateWindow", "Past Weather", nullptr));
        btnPresent->setText(QCoreApplication::translate("intermediateWindow", "Present Weather", nullptr));
        btnFuture->setText(QCoreApplication::translate("intermediateWindow", "Future Weather", nullptr));
        past_data_btn->setText(QCoreApplication::translate("intermediateWindow", "View Insights", nullptr));
        pastLocation->setText(QCoreApplication::translate("intermediateWindow", "Location", nullptr));
        pastTemp->setText(QCoreApplication::translate("intermediateWindow", "Temperature", nullptr));
        pastHumidity->setText(QCoreApplication::translate("intermediateWindow", "Humidity", nullptr));
        pastLat->setText(QCoreApplication::translate("intermediateWindow", "Latitude", nullptr));
        pastLon->setText(QCoreApplication::translate("intermediateWindow", "Longitude", nullptr));
        pastStatus->setText(QCoreApplication::translate("intermediateWindow", "Status", nullptr));
        pastLocation_2->setText(QString());
        pastTemp_2->setText(QString());
        pastHumidity_2->setText(QString());
        pastStatus_2->setText(QString());
        pastLat_2->setText(QString());
        pastLon_2->setText(QString());
        locationpast->setText(QCoreApplication::translate("intermediateWindow", "Location", nullptr));
        iconpast->setText(QString());
        present_data_btn->setText(QCoreApplication::translate("intermediateWindow", "View Insights", nullptr));
        presentLocation->setText(QCoreApplication::translate("intermediateWindow", "Location", nullptr));
        presentTemp->setText(QCoreApplication::translate("intermediateWindow", "Temperature", nullptr));
        presentHumidity->setText(QCoreApplication::translate("intermediateWindow", "Humidity", nullptr));
        presentStatus->setText(QCoreApplication::translate("intermediateWindow", "Status", nullptr));
        presentLat->setText(QCoreApplication::translate("intermediateWindow", "Latitude", nullptr));
        presentLon->setText(QCoreApplication::translate("intermediateWindow", "Longitude", nullptr));
        presentLocation_2->setText(QString());
        presentTemp_2->setText(QString());
        presentHumidity_2->setText(QString());
        presentStatus_2->setText(QString());
        presentLat_2->setText(QString());
        presentLon_2->setText(QString());
        locationpresent->setText(QCoreApplication::translate("intermediateWindow", "Location", nullptr));
        iconpresent->setText(QString());
        future_data_btn->setText(QCoreApplication::translate("intermediateWindow", "View Insights", nullptr));
        futureLocation->setText(QCoreApplication::translate("intermediateWindow", "Location", nullptr));
        futureTemp->setText(QCoreApplication::translate("intermediateWindow", "Temperature", nullptr));
        futureHumidity->setText(QCoreApplication::translate("intermediateWindow", "Humidity", nullptr));
        futureStatus->setText(QCoreApplication::translate("intermediateWindow", "Status", nullptr));
        futureLat->setText(QCoreApplication::translate("intermediateWindow", "Latitude", nullptr));
        futureLon->setText(QCoreApplication::translate("intermediateWindow", "Longitude", nullptr));
        futureLocation_2->setText(QString());
        futureTemp_2->setText(QString());
        futureHumidity_2->setText(QString());
        futureStatus_2->setText(QString());
        futureLat_2->setText(QString());
        futureLon_2->setText(QString());
        locationfuture->setText(QCoreApplication::translate("intermediateWindow", "Location", nullptr));
        iconfuture->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class intermediateWindow: public Ui_intermediateWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERMEDIATEWINDOW_H
