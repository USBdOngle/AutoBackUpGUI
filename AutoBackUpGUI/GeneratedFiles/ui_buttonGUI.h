/********************************************************************************
** Form generated from reading UI file 'buttonGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUTTONGUI_H
#define UI_BUTTONGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_buttonGUI
{
public:

    void setupUi(QPushButton *buttonGUI)
    {
        if (buttonGUI->objectName().isEmpty())
            buttonGUI->setObjectName(QStringLiteral("buttonGUI"));
        buttonGUI->resize(400, 300);

        retranslateUi(buttonGUI);

        QMetaObject::connectSlotsByName(buttonGUI);
    } // setupUi

    void retranslateUi(QPushButton *buttonGUI)
    {
        buttonGUI->setWindowTitle(QApplication::translate("buttonGUI", "buttonGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class buttonGUI: public Ui_buttonGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUTTONGUI_H
