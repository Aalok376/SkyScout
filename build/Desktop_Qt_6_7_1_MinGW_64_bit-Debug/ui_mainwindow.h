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
    QLabel *label;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_currentWeather;
    QLabel *label_alert;
    QLabel *label_temp;
    QLabel *label_weatherIcon;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_flag;
    QLabel *label_18;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_22;
    QLabel *label_19;
    QLabel *label_23;
    QLabel *label_24;
    QFrame *line;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_28;
    QLabel *label_21;
    QLabel *label_29;
    QLabel *label_30;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_25;
    QLabel *label_20;
    QLabel *label_26;
    QLabel *label_27;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(151,163,197);"));
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

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout_9->addWidget(label);


        verticalLayout_10->addLayout(verticalLayout_9);

        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
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
"color:rgb(0, 0, 0);"));
        label_currentWeather->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_currentWeather);

        label_alert = new QLabel(frame);
        label_alert->setObjectName("label_alert");
        label_alert->setStyleSheet(QString::fromUtf8("color:black;"));
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
"color:rgb(0, 0, 0);"));
        label_temp->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_temp);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 5);

        horizontalLayout->addLayout(verticalLayout);

        label_weatherIcon = new QLabel(frame);
        label_weatherIcon->setObjectName("label_weatherIcon");

        horizontalLayout->addWidget(label_weatherIcon);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout_10->addWidget(frame);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_2);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_10 = new QLabel(frame_2);
        label_10->setObjectName("label_10");

        horizontalLayout_4->addWidget(label_10);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_11 = new QLabel(frame_2);
        label_11->setObjectName("label_11");
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_11);

        label_12 = new QLabel(frame_2);
        label_12->setObjectName("label_12");
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_12);


        horizontalLayout_4->addLayout(verticalLayout_3);

        label_13 = new QLabel(frame_2);
        label_13->setObjectName("label_13");

        horizontalLayout_4->addWidget(label_13);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 5);
        horizontalLayout_4->setStretch(2, 1);

        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_9 = new QLabel(frame_2);
        label_9->setObjectName("label_9");

        horizontalLayout_3->addWidget(label_9);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_7 = new QLabel(frame_2);
        label_7->setObjectName("label_7");
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_7);

        label_6 = new QLabel(frame_2);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_6);


        horizontalLayout_3->addLayout(verticalLayout_2);

        label_8 = new QLabel(frame_2);
        label_8->setObjectName("label_8");

        horizontalLayout_3->addWidget(label_8);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 5);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_14 = new QLabel(frame_2);
        label_14->setObjectName("label_14");

        horizontalLayout_5->addWidget(label_14);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_15 = new QLabel(frame_2);
        label_15->setObjectName("label_15");
        label_15->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_15);

        label_16 = new QLabel(frame_2);
        label_16->setObjectName("label_16");
        label_16->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_16);


        horizontalLayout_5->addLayout(verticalLayout_4);

        label_17 = new QLabel(frame_2);
        label_17->setObjectName("label_17");

        horizontalLayout_5->addWidget(label_17);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 5);
        horizontalLayout_5->setStretch(2, 1);

        verticalLayout_5->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_10->addWidget(frame_2);

        verticalLayout_10->setStretch(0, 1);
        verticalLayout_10->setStretch(1, 3);
        verticalLayout_10->setStretch(2, 3);

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
        label_18->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout_7->addWidget(label_18);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_22 = new QLabel(centralwidget);
        label_22->setObjectName("label_22");
        label_22->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_8->addWidget(label_22);

        label_19 = new QLabel(centralwidget);
        label_19->setObjectName("label_19");

        horizontalLayout_8->addWidget(label_19);

        label_23 = new QLabel(centralwidget);
        label_23->setObjectName("label_23");
        label_23->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_8->addWidget(label_23);

        label_24 = new QLabel(centralwidget);
        label_24->setObjectName("label_24");
        label_24->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_8->addWidget(label_24);


        verticalLayout_6->addLayout(horizontalLayout_8);

        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_6->addWidget(line);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_28 = new QLabel(centralwidget);
        label_28->setObjectName("label_28");
        label_28->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_10->addWidget(label_28);

        label_21 = new QLabel(centralwidget);
        label_21->setObjectName("label_21");

        horizontalLayout_10->addWidget(label_21);

        label_29 = new QLabel(centralwidget);
        label_29->setObjectName("label_29");
        label_29->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_10->addWidget(label_29);

        label_30 = new QLabel(centralwidget);
        label_30->setObjectName("label_30");
        label_30->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_10->addWidget(label_30);


        verticalLayout_6->addLayout(horizontalLayout_10);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_6->addWidget(line_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_25 = new QLabel(centralwidget);
        label_25->setObjectName("label_25");
        label_25->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_9->addWidget(label_25);

        label_20 = new QLabel(centralwidget);
        label_20->setObjectName("label_20");

        horizontalLayout_9->addWidget(label_20);

        label_26 = new QLabel(centralwidget);
        label_26->setObjectName("label_26");
        label_26->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_9->addWidget(label_26);

        label_27 = new QLabel(centralwidget);
        label_27->setObjectName("label_27");
        label_27->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_9->addWidget(label_27);


        verticalLayout_6->addLayout(horizontalLayout_9);


        verticalLayout_7->addLayout(verticalLayout_6);

        verticalLayout_7->setStretch(0, 2);
        verticalLayout_7->setStretch(1, 1);
        verticalLayout_7->setStretch(2, 4);

        verticalLayout_8->addLayout(verticalLayout_7);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        verticalLayout_8->addWidget(graphicsView);


        verticalLayout_11->addLayout(verticalLayout_8);


        horizontalLayout_11->addLayout(verticalLayout_11);


        horizontalLayout_13->addLayout(horizontalLayout_11);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
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
        label->setText(QCoreApplication::translate("MainWindow", "Recent location searched ", nullptr));
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
        label_10->setText(QCoreApplication::translate("MainWindow", "icon", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "weather", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "time", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "temp", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "icon", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "weather", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "time", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "temp", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "icon", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "weather", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "time", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "temp", nullptr));
        pushButton_flag->setText(QString());
        label_18->setText(QCoreApplication::translate("MainWindow", "3 days forecast", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "icon", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "icon", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "icon", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
