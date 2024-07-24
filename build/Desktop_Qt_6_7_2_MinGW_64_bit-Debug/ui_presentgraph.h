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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_presentGraph
{
public:
    QPushButton *return_btn_4;
    QLabel *label;
    QCustomPlot *presentplot;
    QLabel *location;

    void setupUi(QDialog *presentGraph)
    {
        if (presentGraph->objectName().isEmpty())
            presentGraph->setObjectName("presentGraph");
        presentGraph->resize(744, 580);
        presentGraph->setStyleSheet(QString::fromUtf8("background-image: url(\":/new/prefix1/image/background.png\");"));
        return_btn_4 = new QPushButton(presentGraph);
        return_btn_4->setObjectName("return_btn_4");
        return_btn_4->setGeometry(QRect(250, 30, 80, 24));
        label = new QLabel(presentGraph);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 151, 41));
        presentplot = new QCustomPlot(presentGraph);
        presentplot->setObjectName("presentplot");
        presentplot->setGeometry(QRect(100, 120, 551, 401));
        location = new QLabel(presentGraph);
        location->setObjectName("location");
        location->setGeometry(QRect(420, 50, 221, 41));

        retranslateUi(presentGraph);

        QMetaObject::connectSlotsByName(presentGraph);
    } // setupUi

    void retranslateUi(QDialog *presentGraph)
    {
        presentGraph->setWindowTitle(QCoreApplication::translate("presentGraph", "Dialog", nullptr));
        return_btn_4->setText(QCoreApplication::translate("presentGraph", "return", nullptr));
        label->setText(QCoreApplication::translate("presentGraph", "present graph", nullptr));
        location->setText(QCoreApplication::translate("presentGraph", "Location:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class presentGraph: public Ui_presentGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRESENTGRAPH_H
