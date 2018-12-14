/********************************************************************************
** Form generated from reading UI file 'confirmationBoxGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMATIONBOXGUI_H
#define UI_CONFIRMATIONBOXGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_confirmationBoxGUI
{
public:

    void setupUi(QWidget *confirmationBoxGUI)
    {
        if (confirmationBoxGUI->objectName().isEmpty())
            confirmationBoxGUI->setObjectName(QStringLiteral("confirmationBoxGUI"));
        confirmationBoxGUI->resize(400, 300);

        retranslateUi(confirmationBoxGUI);

        QMetaObject::connectSlotsByName(confirmationBoxGUI);
    } // setupUi

    void retranslateUi(QWidget *confirmationBoxGUI)
    {
        confirmationBoxGUI->setWindowTitle(QApplication::translate("confirmationBoxGUI", "confirmationBoxGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class confirmationBoxGUI: public Ui_confirmationBoxGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMATIONBOXGUI_H
