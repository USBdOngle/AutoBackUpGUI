/********************************************************************************
** Form generated from reading UI file 'confirmDirMessageGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMDIRMESSAGEGUI_H
#define UI_CONFIRMDIRMESSAGEGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>

QT_BEGIN_NAMESPACE

class Ui_confirmDirMessageGUI
{
public:

    void setupUi(QMessageBox *confirmDirMessageGUI)
    {
        if (confirmDirMessageGUI->objectName().isEmpty())
            confirmDirMessageGUI->setObjectName(QStringLiteral("confirmDirMessageGUI"));
        confirmDirMessageGUI->resize(400, 300);

        retranslateUi(confirmDirMessageGUI);

        QMetaObject::connectSlotsByName(confirmDirMessageGUI);
    } // setupUi

    void retranslateUi(QMessageBox *confirmDirMessageGUI)
    {
        confirmDirMessageGUI->setWindowTitle(QApplication::translate("confirmDirMessageGUI", "confirmDirMessageGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class confirmDirMessageGUI: public Ui_confirmDirMessageGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMDIRMESSAGEGUI_H
