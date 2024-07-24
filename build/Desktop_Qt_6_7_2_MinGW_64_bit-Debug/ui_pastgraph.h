/********************************************************************************
** Form generated from reading UI file 'pastgraph.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASTGRAPH_H
#define UI_PASTGRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_pastGraph
{
public:
    QLabel *label;
    QCustomPlot *pastplot;
    QPushButton *return_btn_2;
    QLabel *location;

    void setupUi(QDialog *pastGraph)
    {
        if (pastGraph->objectName().isEmpty())
            pastGraph->setObjectName("pastGraph");
        pastGraph->resize(750, 550);
        pastGraph->setStyleSheet(QString::fromUtf8("background-image: url(\":/new/prefix1/image/background.png\");"));
        label = new QLabel(pastGraph);
        label->setObjectName("label");
        label->setGeometry(QRect(330, 20, 201, 51));
        pastplot = new QCustomPlot(pastGraph);
        pastplot->setObjectName("pastplot");
        pastplot->setGeometry(QRect(60, 100, 611, 351));
        pastplot->setStyleSheet(QString::fromUtf8("background:transparent;"));
        return_btn_2 = new QPushButton(pastGraph);
        return_btn_2->setObjectName("return_btn_2");
        return_btn_2->setGeometry(QRect(570, 30, 80, 24));
        location = new QLabel(pastGraph);
        location->setObjectName("location");
        location->setGeometry(QRect(70, 40, 161, 41));

        retranslateUi(pastGraph);

        QMetaObject::connectSlotsByName(pastGraph);
    } // setupUi

    void retranslateUi(QDialog *pastGraph)
    {
        pastGraph->setWindowTitle(QCoreApplication::translate("pastGraph", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("pastGraph", "past graph", nullptr));
        return_btn_2->setText(QCoreApplication::translate("pastGraph", "return", nullptr));
        location->setText(QCoreApplication::translate("pastGraph", "Location:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pastGraph: public Ui_pastGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASTGRAPH_H
