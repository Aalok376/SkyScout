/********************************************************************************
** Form generated from reading UI file 'presentgraph.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRESENTGRAPH_H
#define UI_PRESENTGRAPH_H

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

class Ui_presentGraph
{
public:
    QHBoxLayout *horizontalLayout_3;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *location;
    QPushButton *return_btn_4;
    QCustomPlot *presentplot;

    void setupUi(QDialog *presentGraph)
    {
        if (presentGraph->objectName().isEmpty())
            presentGraph->setObjectName("presentGraph");
        presentGraph->resize(744, 580);
        presentGraph->setStyleSheet(QString::fromUtf8("background-image: url(\":/new/prefix1/image/background.png\");"));
        horizontalLayout_3 = new QHBoxLayout(presentGraph);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        centralWidget = new QWidget(presentGraph);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, 20, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color:black;\n"
"font: 10pt 'Segoe UI';"));

        horizontalLayout->addWidget(label);

        location = new QLabel(centralWidget);
        location->setObjectName("location");
        location->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color:black;\n"
"font: 10pt 'Segoe UI';"));

        horizontalLayout->addWidget(location);

        return_btn_4 = new QPushButton(centralWidget);
        return_btn_4->setObjectName("return_btn_4");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(return_btn_4->sizePolicy().hasHeightForWidth());
        return_btn_4->setSizePolicy(sizePolicy);
        return_btn_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background:transparent;\n"
"	border:none;\n"
"	border-radius:12%;\n"
"	background:rgba(255,255,255,0.1);\n"
"}\n"
"QPushButton:hover{\n"
"	background:rgba(255,255,255,0.3);\n"
"}"));

        horizontalLayout->addWidget(return_btn_4);


        verticalLayout->addLayout(horizontalLayout);

        presentplot = new QCustomPlot(centralWidget);
        presentplot->setObjectName("presentplot");

        verticalLayout->addWidget(presentplot);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 5);

        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout_3->addWidget(centralWidget);


        retranslateUi(presentGraph);

        QMetaObject::connectSlotsByName(presentGraph);
    } // setupUi

    void retranslateUi(QDialog *presentGraph)
    {
        presentGraph->setWindowTitle(QCoreApplication::translate("presentGraph", "Dialog", nullptr));
        label->setText(QString());
        location->setText(QCoreApplication::translate("presentGraph", "Location:", nullptr));
        return_btn_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class presentGraph: public Ui_presentGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRESENTGRAPH_H
