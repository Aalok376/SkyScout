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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_pastGraph
{
public:
    QHBoxLayout *horizontalLayout_3;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *location;
    QLabel *label;
    QPushButton *return_btn_2;
    QCustomPlot *pastplot;

    void setupUi(QDialog *pastGraph)
    {
        if (pastGraph->objectName().isEmpty())
            pastGraph->setObjectName("pastGraph");
        pastGraph->resize(750, 550);
        pastGraph->setStyleSheet(QString::fromUtf8("background-image: url(\":/new/prefix1/image/background.png\");"));
        horizontalLayout_3 = new QHBoxLayout(pastGraph);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        centralWidget = new QWidget(pastGraph);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 20, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        location = new QLabel(centralWidget);
        location->setObjectName("location");
        location->setStyleSheet(QString::fromUtf8("background:transparent;"));

        horizontalLayout->addWidget(location);

        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("background:transparent;"));

        horizontalLayout->addWidget(label);

        return_btn_2 = new QPushButton(centralWidget);
        return_btn_2->setObjectName("return_btn_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(return_btn_2->sizePolicy().hasHeightForWidth());
        return_btn_2->setSizePolicy(sizePolicy);
        return_btn_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border:none;"));

        horizontalLayout->addWidget(return_btn_2);


        verticalLayout->addLayout(horizontalLayout);

        pastplot = new QCustomPlot(centralWidget);
        pastplot->setObjectName("pastplot");
        pastplot->setStyleSheet(QString::fromUtf8("background:transparent;"));

        verticalLayout->addWidget(pastplot);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 5);

        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout_3->addWidget(centralWidget);


        retranslateUi(pastGraph);

        QMetaObject::connectSlotsByName(pastGraph);
    } // setupUi

    void retranslateUi(QDialog *pastGraph)
    {
        pastGraph->setWindowTitle(QCoreApplication::translate("pastGraph", "Dialog", nullptr));
        location->setText(QCoreApplication::translate("pastGraph", "Location:", nullptr));
        label->setText(QCoreApplication::translate("pastGraph", "past graph", nullptr));
        return_btn_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class pastGraph: public Ui_pastGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASTGRAPH_H
