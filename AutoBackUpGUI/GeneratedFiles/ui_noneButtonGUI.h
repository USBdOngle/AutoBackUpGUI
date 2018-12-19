/********************************************************************************
** Form generated from reading UI file 'noneButtonGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NONEBUTTONGUI_H
#define UI_NONEBUTTONGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <buttongui.h>

QT_BEGIN_NAMESPACE

class Ui_noneButtonGUI
{
public:

    void setupUi(buttonGUI *noneButtonGUI)
    {
        if (noneButtonGUI->objectName().isEmpty())
            noneButtonGUI->setObjectName(QStringLiteral("noneButtonGUI"));
        noneButtonGUI->resize(400, 300);

        retranslateUi(noneButtonGUI);

        QMetaObject::connectSlotsByName(noneButtonGUI);
    } // setupUi

    void retranslateUi(buttonGUI *noneButtonGUI)
    {
        noneButtonGUI->setWindowTitle(QApplication::translate("noneButtonGUI", "noneButtonGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class noneButtonGUI: public Ui_noneButtonGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NONEBUTTONGUI_H
