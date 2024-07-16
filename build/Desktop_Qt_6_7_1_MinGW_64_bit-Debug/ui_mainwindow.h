/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_search;
    QLineEdit *lineEdit_searchbar;
    QLabel *label_recentSearch;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_currentWeather;
    QLabel *label_alert;
    QLabel *label_temp;
    QLabel *label_weatherIcon;
    QFrame *line_3;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *icon1;
    QVBoxLayout *verticalLayout_3;
    QLabel *weather1;
    QLabel *temp1;
    QLabel *time1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *icon2;
    QVBoxLayout *verticalLayout_2;
    QLabel *weather2;
    QLabel *temp2;
    QLabel *time2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *icon3;
    QVBoxLayout *verticalLayout_4;
    QLabel *weather3;
    QLabel *temp3;
    QLabel *time3;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_flag;
    QLabel *label_18;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *fIcon1;
    QLabel *fWeather1;
    QLabel *fTemp1;
    QLabel *fDate1;
    QFrame *line;
    QHBoxLayout *horizontalLayout_10;
    QLabel *fIcon2;
    QLabel *fWeather2;
    QLabel *fTemp2;
    QLabel *fDate2;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *fIcon3;
    QLabel *fWeather3;
    QLabel *fTemp3;
    QLabel *fDate3;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1247, 893);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8("background-image: url(\":/new/prefix1/image/background.png\");"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_13 = new QHBoxLayout(centralwidget);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(-1, 5, -1, 5);
        pushButton_search = new QPushButton(centralwidget);
        pushButton_search->setObjectName("pushButton_search");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_search->sizePolicy().hasHeightForWidth());
        pushButton_search->setSizePolicy(sizePolicy1);
        pushButton_search->setMinimumSize(QSize(1, 2));
        pushButton_search->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);\n"
"border-top-left-radius:12%;\n"
"border-bottom-left-radius:12%;"));

        horizontalLayout_7->addWidget(pushButton_search);

        lineEdit_searchbar = new QLineEdit(centralwidget);
        lineEdit_searchbar->setObjectName("lineEdit_searchbar");
        sizePolicy1.setHeightForWidth(lineEdit_searchbar->sizePolicy().hasHeightForWidth());
        lineEdit_searchbar->setSizePolicy(sizePolicy1);
        lineEdit_searchbar->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);\n"
"color: rgb(0, 0, 0);\n"
"border-top-right-radius:12%;\n"
"border-bottom-right-radius:12%;"));

        horizontalLayout_7->addWidget(lineEdit_searchbar);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 8);

        verticalLayout_9->addLayout(horizontalLayout_7);

        label_recentSearch = new QLabel(centralwidget);
        label_recentSearch->setObjectName("label_recentSearch");
        label_recentSearch->setStyleSheet(QString::fromUtf8("background:transparent;"));

        verticalLayout_9->addWidget(label_recentSearch);


        verticalLayout_10->addLayout(verticalLayout_9);

        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("border:ignore;\n"
"background:transparent;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_currentWeather = new QLabel(frame);
        label_currentWeather->setObjectName("label_currentWeather");
        sizePolicy.setHeightForWidth(label_currentWeather->sizePolicy().hasHeightForWidth());
        label_currentWeather->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(30);
        font.setBold(false);
        font.setItalic(false);
        label_currentWeather->setFont(font);
        label_currentWeather->setStyleSheet(QString::fromUtf8("font: 30pt \"Segoe UI\";\n"
"color:rgb(0, 0, 0);\n"
"background:transparent;"));
        label_currentWeather->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_currentWeather);

        label_alert = new QLabel(frame);
        label_alert->setObjectName("label_alert");
        label_alert->setStyleSheet(QString::fromUtf8("color:black;\n"
"background:transparent;"));
        label_alert->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_alert);

        label_temp = new QLabel(frame);
        label_temp->setObjectName("label_temp");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(38);
        font1.setBold(false);
        font1.setItalic(false);
        label_temp->setFont(font1);
        label_temp->setStyleSheet(QString::fromUtf8("font: 38pt \"Segoe UI\";\n"
"color:rgb(0, 0, 0);\n"
"background:transparent;"));
        label_temp->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_temp);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 5);

        horizontalLayout->addLayout(verticalLayout);

        label_weatherIcon = new QLabel(frame);
        label_weatherIcon->setObjectName("label_weatherIcon");
        label_weatherIcon->setStyleSheet(QString::fromUtf8("background:transparent;"));
        label_weatherIcon->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_weatherIcon);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout_10->addWidget(frame);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setStyleSheet(QString::fromUtf8(""));
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_10->addWidget(line_3);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setStyleSheet(QString::fromUtf8("border-top:4px white solid;\n"
"background:transparent;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_2);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        icon1 = new QLabel(frame_2);
        icon1->setObjectName("icon1");

        horizontalLayout_4->addWidget(icon1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        weather1 = new QLabel(frame_2);
        weather1->setObjectName("weather1");
        weather1->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(weather1);

        temp1 = new QLabel(frame_2);
        temp1->setObjectName("temp1");
        temp1->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(temp1);


        horizontalLayout_4->addLayout(verticalLayout_3);

        time1 = new QLabel(frame_2);
        time1->setObjectName("time1");

        horizontalLayout_4->addWidget(time1);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 5);
        horizontalLayout_4->setStretch(2, 1);

        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        icon2 = new QLabel(frame_2);
        icon2->setObjectName("icon2");

        horizontalLayout_3->addWidget(icon2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        weather2 = new QLabel(frame_2);
        weather2->setObjectName("weather2");
        weather2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(weather2);

        temp2 = new QLabel(frame_2);
        temp2->setObjectName("temp2");
        temp2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(temp2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        time2 = new QLabel(frame_2);
        time2->setObjectName("time2");

        horizontalLayout_3->addWidget(time2);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 5);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        icon3 = new QLabel(frame_2);
        icon3->setObjectName("icon3");

        horizontalLayout_5->addWidget(icon3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        weather3 = new QLabel(frame_2);
        weather3->setObjectName("weather3");
        weather3->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(weather3);

        temp3 = new QLabel(frame_2);
        temp3->setObjectName("temp3");
        temp3->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(temp3);


        horizontalLayout_5->addLayout(verticalLayout_4);

        time3 = new QLabel(frame_2);
        time3->setObjectName("time3");

        horizontalLayout_5->addWidget(time3);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 5);
        horizontalLayout_5->setStretch(2, 1);

        verticalLayout_5->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_10->addWidget(frame_2);

        verticalLayout_10->setStretch(0, 1);
        verticalLayout_10->setStretch(1, 3);
        verticalLayout_10->setStretch(3, 3);

        horizontalLayout_11->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);

        pushButton_flag = new QPushButton(centralwidget);
        pushButton_flag->setObjectName("pushButton_flag");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_flag->sizePolicy().hasHeightForWidth());
        pushButton_flag->setSizePolicy(sizePolicy2);
        pushButton_flag->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:none;\n"
"}"));

        horizontalLayout_12->addWidget(pushButton_flag);

        horizontalLayout_12->setStretch(0, 5);
        horizontalLayout_12->setStretch(1, 1);

        verticalLayout_7->addLayout(horizontalLayout_12);

        label_18 = new QLabel(centralwidget);
        label_18->setObjectName("label_18");
        label_18->setStyleSheet(QString::fromUtf8("color:black;\n"
"background:transparent;"));

        verticalLayout_7->addWidget(label_18);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        fIcon1 = new QLabel(centralwidget);
        fIcon1->setObjectName("fIcon1");
        fIcon1->setStyleSheet(QString::fromUtf8("color:black;\n"
"background:transparent;"));

        horizontalLayout_8->addWidget(fIcon1);

        fWeather1 = new QLabel(centralwidget);
        fWeather1->setObjectName("fWeather1");
        fWeather1->setStyleSheet(QString::fromUtf8("background:transparent;"));

        horizontalLayout_8->addWidget(fWeather1);

        fTemp1 = new QLabel(centralwidget);
        fTemp1->setObjectName("fTemp1");
        fTemp1->setStyleSheet(QString::fromUtf8("color:black;\n"
"background:transparent;"));

        horizontalLayout_8->addWidget(fTemp1);

        fDate1 = new QLabel(centralwidget);
        fDate1->setObjectName("fDate1");
        fDate1->setStyleSheet(QString::fromUtf8("color:black;\n"
"background:transparent;"));

        horizontalLayout_8->addWidget(fDate1);


        verticalLayout_6->addLayout(horizontalLayout_8);

        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_6->addWidget(line);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        fIcon2 = new QLabel(centralwidget);
        fIcon2->setObjectName("fIcon2");
        fIcon2->setStyleSheet(QString::fromUtf8("color:black;\n"
"background:transparent;"));

        horizontalLayout_10->addWidget(fIcon2);

        fWeather2 = new QLabel(centralwidget);
        fWeather2->setObjectName("fWeather2");
        fWeather2->setStyleSheet(QString::fromUtf8("background:transparent;"));

        horizontalLayout_10->addWidget(fWeather2);

        fTemp2 = new QLabel(centralwidget);
        fTemp2->setObjectName("fTemp2");
        fTemp2->setStyleSheet(QString::fromUtf8("color:black;\n"
"background:transparent;"));

        horizontalLayout_10->addWidget(fTemp2);

        fDate2 = new QLabel(centralwidget);
        fDate2->setObjectName("fDate2");
        fDate2->setStyleSheet(QString::fromUtf8("color:black;\n"
"background:transparent;"));

        horizontalLayout_10->addWidget(fDate2);


        verticalLayout_6->addLayout(horizontalLayout_10);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_6->addWidget(line_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        fIcon3 = new QLabel(centralwidget);
        fIcon3->setObjectName("fIcon3");
        fIcon3->setStyleSheet(QString::fromUtf8("color:black;\n"
"background:transparent;"));

        horizontalLayout_9->addWidget(fIcon3);

        fWeather3 = new QLabel(centralwidget);
        fWeather3->setObjectName("fWeather3");
        fWeather3->setStyleSheet(QString::fromUtf8("background:transparent;"));

        horizontalLayout_9->addWidget(fWeather3);

        fTemp3 = new QLabel(centralwidget);
        fTemp3->setObjectName("fTemp3");
        fTemp3->setStyleSheet(QString::fromUtf8("color:black;\n"
"background:transparent;"));

        horizontalLayout_9->addWidget(fTemp3);

        fDate3 = new QLabel(centralwidget);
        fDate3->setObjectName("fDate3");
        fDate3->setStyleSheet(QString::fromUtf8("color:black;\n"
"background:transparent;"));

        horizontalLayout_9->addWidget(fDate3);


        verticalLayout_6->addLayout(horizontalLayout_9);


        verticalLayout_7->addLayout(verticalLayout_6);

        verticalLayout_7->setStretch(0, 2);
        verticalLayout_7->setStretch(1, 1);
        verticalLayout_7->setStretch(2, 4);

        verticalLayout_8->addLayout(verticalLayout_7);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setStyleSheet(QString::fromUtf8("background:transparent;"));

        verticalLayout_8->addWidget(graphicsView);


        verticalLayout_11->addLayout(verticalLayout_8);


        horizontalLayout_11->addLayout(verticalLayout_11);


        horizontalLayout_13->addLayout(horizontalLayout_11);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1247, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_search->setText(QString());
        label_recentSearch->setText(QString());
#if QT_CONFIG(tooltip)
        label_currentWeather->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_currentWeather->setText(QString());
        label_alert->setText(QString());
#if QT_CONFIG(tooltip)
        label_temp->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">36</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_temp->setText(QString());
        label_weatherIcon->setText(QString());
        icon1->setText(QCoreApplication::translate("MainWindow", "icon", nullptr));
        weather1->setText(QCoreApplication::translate("MainWindow", "weather", nullptr));
        temp1->setText(QCoreApplication::translate("MainWindow", "temp", nullptr));
        time1->setText(QCoreApplication::translate("MainWindow", "time", nullptr));
        icon2->setText(QCoreApplication::translate("MainWindow", "icon", nullptr));
        weather2->setText(QCoreApplication::translate("MainWindow", "weather", nullptr));
        temp2->setText(QCoreApplication::translate("MainWindow", "temp", nullptr));
        time2->setText(QCoreApplication::translate("MainWindow", "time", nullptr));
        icon3->setText(QCoreApplication::translate("MainWindow", "icon", nullptr));
        weather3->setText(QCoreApplication::translate("MainWindow", "weather", nullptr));
        temp3->setText(QCoreApplication::translate("MainWindow", "temp", nullptr));
        time3->setText(QCoreApplication::translate("MainWindow", "time", nullptr));
        pushButton_flag->setText(QString());
        label_18->setText(QCoreApplication::translate("MainWindow", "3 days forecast", nullptr));
        fIcon1->setText(QCoreApplication::translate("MainWindow", "icon", nullptr));
        fWeather1->setText(QCoreApplication::translate("MainWindow", "weather", nullptr));
        fTemp1->setText(QCoreApplication::translate("MainWindow", "temp", nullptr));
        fDate1->setText(QCoreApplication::translate("MainWindow", "date", nullptr));
        fIcon2->setText(QCoreApplication::translate("MainWindow", "icon", nullptr));
        fWeather2->setText(QCoreApplication::translate("MainWindow", "weather", nullptr));
        fTemp2->setText(QCoreApplication::translate("MainWindow", "temp", nullptr));
        fDate2->setText(QCoreApplication::translate("MainWindow", "date", nullptr));
        fIcon3->setText(QCoreApplication::translate("MainWindow", "icon", nullptr));
        fWeather3->setText(QCoreApplication::translate("MainWindow", "weather", nullptr));
        fTemp3->setText(QCoreApplication::translate("MainWindow", "temp", nullptr));
        fDate3->setText(QCoreApplication::translate("MainWindow", "date", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
