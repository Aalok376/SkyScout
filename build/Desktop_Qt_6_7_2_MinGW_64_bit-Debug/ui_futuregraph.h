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
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_futureGraph
{
public:
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
        horizontalLayout_2 = new QHBoxLayout(futureGraph);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, 20, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        location = new QLabel(futureGraph);
        location->setObjectName("location");

        horizontalLayout->addWidget(location);

        label = new QLabel(futureGraph);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        return_btn_3 = new QPushButton(futureGraph);
        return_btn_3->setObjectName("return_btn_3");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(return_btn_3->sizePolicy().hasHeightForWidth());
        return_btn_3->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(return_btn_3);


        verticalLayout->addLayout(horizontalLayout);

        futureplot = new QCustomPlot(futureGraph);
        futureplot->setObjectName("futureplot");

        verticalLayout->addWidget(futureplot);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 5);

        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(futureGraph);

        QMetaObject::connectSlotsByName(futureGraph);
    } // setupUi

    void retranslateUi(QDialog *futureGraph)
    {
        futureGraph->setWindowTitle(QCoreApplication::translate("futureGraph", "Dialog", nullptr));
        location->setText(QCoreApplication::translate("futureGraph", "Location:", nullptr));
        label->setText(QCoreApplication::translate("futureGraph", "future graph", nullptr));
        return_btn_3->setText(QCoreApplication::translate("futureGraph", "return", nullptr));
    } // retranslateUi

};

namespace Ui {
    class futureGraph: public Ui_futureGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUTUREGRAPH_H
