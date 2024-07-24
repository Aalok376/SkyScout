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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_futureGraph
{
public:
    QLabel *label;
    QPushButton *return_btn_3;
    QCustomPlot *futureplot;
    QLabel *location;

    void setupUi(QDialog *futureGraph)
    {
        if (futureGraph->objectName().isEmpty())
            futureGraph->setObjectName("futureGraph");
        futureGraph->resize(712, 542);
        futureGraph->setStyleSheet(QString::fromUtf8("background-image: url(\":/new/prefix1/image/background.png\");"));
        label = new QLabel(futureGraph);
        label->setObjectName("label");
        label->setGeometry(QRect(310, 30, 141, 51));
        return_btn_3 = new QPushButton(futureGraph);
        return_btn_3->setObjectName("return_btn_3");
        return_btn_3->setGeometry(QRect(510, 50, 91, 31));
        futureplot = new QCustomPlot(futureGraph);
        futureplot->setObjectName("futureplot");
        futureplot->setGeometry(QRect(70, 120, 571, 381));
        location = new QLabel(futureGraph);
        location->setObjectName("location");
        location->setGeometry(QRect(50, 40, 211, 61));

        retranslateUi(futureGraph);

        QMetaObject::connectSlotsByName(futureGraph);
    } // setupUi

    void retranslateUi(QDialog *futureGraph)
    {
        futureGraph->setWindowTitle(QCoreApplication::translate("futureGraph", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("futureGraph", "future graph", nullptr));
        return_btn_3->setText(QCoreApplication::translate("futureGraph", "return", nullptr));
        location->setText(QCoreApplication::translate("futureGraph", "Location:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class futureGraph: public Ui_futureGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUTUREGRAPH_H
