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
    QHBoxLayout *horizontalLayout_4;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnPast;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_2;
    QWidget *page_2;
    QLabel *label_3;
    QWidget *page_3;
    QLabel *label_4;
    QPushButton *btnPresent;
    QPushButton *btnFuture;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *past_data_btn;
    QPushButton *present_data_btn;
    QPushButton *future_data_btn;
    QPushButton *return_btn;

    void setupUi(QDialog *intermediateWindow)
    {
        if (intermediateWindow->objectName().isEmpty())
            intermediateWindow->setObjectName("intermediateWindow");
        intermediateWindow->resize(753, 434);
        intermediateWindow->setStyleSheet(QString::fromUtf8("background-image: url(\":/new/prefix1/image/background.png\");"));
        horizontalLayout_4 = new QHBoxLayout(intermediateWindow);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        centralWidget = new QWidget(intermediateWindow);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnPast = new QPushButton(centralWidget);
        btnPast->setObjectName("btnPast");

        horizontalLayout_2->addWidget(btnPast);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 70, 49, 16));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_3 = new QLabel(page_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 80, 49, 16));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        label_4 = new QLabel(page_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(90, 140, 49, 16));
        stackedWidget->addWidget(page_3);

        horizontalLayout_2->addWidget(stackedWidget);

        btnPresent = new QPushButton(centralWidget);
        btnPresent->setObjectName("btnPresent");

        horizontalLayout_2->addWidget(btnPresent);

        btnFuture = new QPushButton(centralWidget);
        btnFuture->setObjectName("btnFuture");

        horizontalLayout_2->addWidget(btnFuture);

        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("color:rgb( 225, 255, 255);\n"
"font: 12pt \"Segoe UI\";"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        past_data_btn = new QPushButton(centralWidget);
        past_data_btn->setObjectName("past_data_btn");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(past_data_btn->sizePolicy().hasHeightForWidth());
        past_data_btn->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(past_data_btn);

        present_data_btn = new QPushButton(centralWidget);
        present_data_btn->setObjectName("present_data_btn");
        sizePolicy.setHeightForWidth(present_data_btn->sizePolicy().hasHeightForWidth());
        present_data_btn->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(present_data_btn);

        future_data_btn = new QPushButton(centralWidget);
        future_data_btn->setObjectName("future_data_btn");
        sizePolicy.setHeightForWidth(future_data_btn->sizePolicy().hasHeightForWidth());
        future_data_btn->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(future_data_btn);


        verticalLayout->addLayout(horizontalLayout);

        return_btn = new QPushButton(centralWidget);
        return_btn->setObjectName("return_btn");
        sizePolicy.setHeightForWidth(return_btn->sizePolicy().hasHeightForWidth());
        return_btn->setSizePolicy(sizePolicy);
        return_btn->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border:none;"));

        verticalLayout->addWidget(return_btn);

        verticalLayout->setStretch(0, 5);
        verticalLayout->setStretch(1, 1);

        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_4->addWidget(centralWidget);


        retranslateUi(intermediateWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(intermediateWindow);
    } // setupUi

    void retranslateUi(QDialog *intermediateWindow)
    {
        intermediateWindow->setWindowTitle(QCoreApplication::translate("intermediateWindow", "Dialog", nullptr));
        btnPast->setText(QCoreApplication::translate("intermediateWindow", "past", nullptr));
        label_2->setText(QCoreApplication::translate("intermediateWindow", "1", nullptr));
        label_3->setText(QCoreApplication::translate("intermediateWindow", "2", nullptr));
        label_4->setText(QCoreApplication::translate("intermediateWindow", "3", nullptr));
        btnPresent->setText(QCoreApplication::translate("intermediateWindow", "present", nullptr));
        btnFuture->setText(QCoreApplication::translate("intermediateWindow", "future", nullptr));
        label->setText(QString());
        past_data_btn->setText(QCoreApplication::translate("intermediateWindow", "past data", nullptr));
        present_data_btn->setText(QCoreApplication::translate("intermediateWindow", "present data", nullptr));
        future_data_btn->setText(QCoreApplication::translate("intermediateWindow", "future data", nullptr));
        return_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class intermediateWindow: public Ui_intermediateWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERMEDIATEWINDOW_H
