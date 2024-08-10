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
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_worldMap
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *worldMap)
    {
        if (worldMap->objectName().isEmpty())
            worldMap->setObjectName("worldMap");
        worldMap->resize(841, 466);
        pushButton = new QPushButton(worldMap);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(140, 120, 80, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border:1px solid black;"));

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
