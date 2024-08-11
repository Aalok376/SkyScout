/********************************************************************************
** Form generated from reading UI file 'worldmap.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORLDMAP_H
#define UI_WORLDMAP_H

#include <QtCore/QVariant>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_worldMap
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QQuickWidget *quickWidget;

    void setupUi(QDialog *worldMap)
    {
        if (worldMap->objectName().isEmpty())
            worldMap->setObjectName("worldMap");
        worldMap->resize(841, 466);
        horizontalLayout_2 = new QHBoxLayout(worldMap);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(worldMap);
        pushButton->setObjectName("pushButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border:1px solid black;"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        quickWidget = new QQuickWidget(worldMap);
        quickWidget->setObjectName("quickWidget");
        quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

        verticalLayout->addWidget(quickWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 11);

        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(worldMap);

        QMetaObject::connectSlotsByName(worldMap);
    } // setupUi

    void retranslateUi(QDialog *worldMap)
    {
        worldMap->setWindowTitle(QCoreApplication::translate("worldMap", "Dialog", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class worldMap: public Ui_worldMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORLDMAP_H
