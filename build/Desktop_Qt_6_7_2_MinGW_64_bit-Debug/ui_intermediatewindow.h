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
    QLabel *label_2;
    QPushButton *past_data_btn;
    QWidget *page_2;
    QLabel *label_3;
    QPushButton *present_data_btn;
    QWidget *page_3;
    QLabel *label_4;
    QPushButton *future_data_btn;

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
        return_btn->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border:none;"));

        horizontalLayout_4->addWidget(return_btn);

        btnPast = new QPushButton(centralWidget);
        btnPast->setObjectName("btnPast");

        horizontalLayout_4->addWidget(btnPast);

        btnPresent = new QPushButton(centralWidget);
        btnPresent->setObjectName("btnPresent");

        horizontalLayout_4->addWidget(btnPresent);

        btnFuture = new QPushButton(centralWidget);
        btnFuture->setObjectName("btnFuture");

        horizontalLayout_4->addWidget(btnFuture);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 5);
        horizontalLayout_4->setStretch(2, 5);
        horizontalLayout_4->setStretch(3, 5);

        verticalLayout_2->addLayout(horizontalLayout_4);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 70, 49, 16));
        past_data_btn = new QPushButton(page);
        past_data_btn->setObjectName("past_data_btn");
        past_data_btn->setGeometry(QRect(110, 20, 171, 221));
        sizePolicy.setHeightForWidth(past_data_btn->sizePolicy().hasHeightForWidth());
        past_data_btn->setSizePolicy(sizePolicy);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_3 = new QLabel(page_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 80, 51, 41));
        present_data_btn = new QPushButton(page_2);
        present_data_btn->setObjectName("present_data_btn");
        present_data_btn->setGeometry(QRect(130, 30, 131, 191));
        sizePolicy.setHeightForWidth(present_data_btn->sizePolicy().hasHeightForWidth());
        present_data_btn->setSizePolicy(sizePolicy);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        label_4 = new QLabel(page_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(48, 115, 31, 21));
        future_data_btn = new QPushButton(page_3);
        future_data_btn->setObjectName("future_data_btn");
        future_data_btn->setGeometry(QRect(120, 0, 159, 255));
        sizePolicy.setHeightForWidth(future_data_btn->sizePolicy().hasHeightForWidth());
        future_data_btn->setSizePolicy(sizePolicy);
        stackedWidget->addWidget(page_3);

        verticalLayout_2->addWidget(stackedWidget);


        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_2->addWidget(centralWidget);


        retranslateUi(intermediateWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(intermediateWindow);
    } // setupUi

    void retranslateUi(QDialog *intermediateWindow)
    {
        intermediateWindow->setWindowTitle(QCoreApplication::translate("intermediateWindow", "Dialog", nullptr));
        return_btn->setText(QString());
        btnPast->setText(QCoreApplication::translate("intermediateWindow", "past", nullptr));
        btnPresent->setText(QCoreApplication::translate("intermediateWindow", "present", nullptr));
        btnFuture->setText(QCoreApplication::translate("intermediateWindow", "future", nullptr));
        label_2->setText(QCoreApplication::translate("intermediateWindow", "1", nullptr));
        past_data_btn->setText(QCoreApplication::translate("intermediateWindow", "past data", nullptr));
        label_3->setText(QCoreApplication::translate("intermediateWindow", "2", nullptr));
        present_data_btn->setText(QCoreApplication::translate("intermediateWindow", "present data", nullptr));
        label_4->setText(QCoreApplication::translate("intermediateWindow", "3", nullptr));
        future_data_btn->setText(QCoreApplication::translate("intermediateWindow", "future data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class intermediateWindow: public Ui_intermediateWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERMEDIATEWINDOW_H
