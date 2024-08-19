/********************************************************************************
** Form generated from reading UI file 'futuregraph.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUTUREGRAPH_H
#define UI_FUTUREGRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_futureGraph
{
public:
    QHBoxLayout *horizontalLayout_3;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *location;
    QLabel *label;
    QPushButton *return_btn_3;
    QCustomPlot *futureplot;

    void setupUi(QDialog *futureGraph)
    {
        if (futureGraph->objectName().isEmpty())
            futureGraph->setObjectName("futureGraph");
        futureGraph->resize(712, 542);
        futureGraph->setStyleSheet(QString::fromUtf8("background-image: url(\":/new/prefix1/image/background.png\");"));
        horizontalLayout_3 = new QHBoxLayout(futureGraph);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        centralWidget = new QWidget(futureGraph);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, 20, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        location = new QLabel(centralWidget);
        location->setObjectName("location");
        location->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color:black;\n"
"font: 10pt 'Segoe UI';"));

        horizontalLayout->addWidget(location);

        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color:black;\n"
"font: 10pt 'Segoe UI';"));

        horizontalLayout->addWidget(label);

        return_btn_3 = new QPushButton(centralWidget);
        return_btn_3->setObjectName("return_btn_3");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(return_btn_3->sizePolicy().hasHeightForWidth());
        return_btn_3->setSizePolicy(sizePolicy);
        return_btn_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background:transparent;\n"
"	border:none;\n"
"	border-radius:12%;\n"
"	background:rgba(255,255,255,0.1);\n"
"}\n"
"QPushButton:hover{\n"
"	background:rgba(255,255,255,0.3);\n"
"}"));

        horizontalLayout->addWidget(return_btn_3);


        verticalLayout->addLayout(horizontalLayout);

        futureplot = new QCustomPlot(centralWidget);
        futureplot->setObjectName("futureplot");

        verticalLayout->addWidget(futureplot);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 12);

        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout_3->addWidget(centralWidget);


        retranslateUi(futureGraph);

        QMetaObject::connectSlotsByName(futureGraph);
    } // setupUi

    void retranslateUi(QDialog *futureGraph)
    {
        futureGraph->setWindowTitle(QCoreApplication::translate("futureGraph", "Dialog", nullptr));
        location->setText(QCoreApplication::translate("futureGraph", "Location:", nullptr));
        label->setText(QCoreApplication::translate("futureGraph", "Forecast Data", nullptr));
        return_btn_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class futureGraph: public Ui_futureGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUTUREGRAPH_H
