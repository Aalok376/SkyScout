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
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_intermediateWindow
{
public:
    QPushButton *return_btn;
    QPushButton *past_data_btn;
    QPushButton *present_data_btn;
    QPushButton *future_data_btn;

    void setupUi(QDialog *intermediateWindow)
    {
        if (intermediateWindow->objectName().isEmpty())
            intermediateWindow->setObjectName("intermediateWindow");
        intermediateWindow->resize(753, 434);
        intermediateWindow->setStyleSheet(QString::fromUtf8("background-image: url(\":/new/prefix1/image/background.png\");"));
        return_btn = new QPushButton(intermediateWindow);
        return_btn->setObjectName("return_btn");
        return_btn->setGeometry(QRect(180, 240, 80, 24));
        past_data_btn = new QPushButton(intermediateWindow);
        past_data_btn->setObjectName("past_data_btn");
        past_data_btn->setGeometry(QRect(70, 80, 111, 51));
        present_data_btn = new QPushButton(intermediateWindow);
        present_data_btn->setObjectName("present_data_btn");
        present_data_btn->setGeometry(QRect(220, 80, 111, 51));
        future_data_btn = new QPushButton(intermediateWindow);
        future_data_btn->setObjectName("future_data_btn");
        future_data_btn->setGeometry(QRect(410, 100, 111, 41));

        retranslateUi(intermediateWindow);

        QMetaObject::connectSlotsByName(intermediateWindow);
    } // setupUi

    void retranslateUi(QDialog *intermediateWindow)
    {
        intermediateWindow->setWindowTitle(QCoreApplication::translate("intermediateWindow", "Dialog", nullptr));
        return_btn->setText(QCoreApplication::translate("intermediateWindow", "return", nullptr));
        past_data_btn->setText(QCoreApplication::translate("intermediateWindow", "past data", nullptr));
        present_data_btn->setText(QCoreApplication::translate("intermediateWindow", "present data", nullptr));
        future_data_btn->setText(QCoreApplication::translate("intermediateWindow", "future data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class intermediateWindow: public Ui_intermediateWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERMEDIATEWINDOW_H
