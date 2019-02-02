/********************************************************************************
** Form generated from reading UI file 'destGoogleGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESTGOOGLEGUI_H
#define UI_DESTGOOGLEGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_destGoogleGUI
{
public:

    void setupUi(QWidget *destGoogleGUI)
    {
        if (destGoogleGUI->objectName().isEmpty())
            destGoogleGUI->setObjectName(QStringLiteral("destGoogleGUI"));
        destGoogleGUI->resize(400, 300);

        retranslateUi(destGoogleGUI);

        QMetaObject::connectSlotsByName(destGoogleGUI);
    } // setupUi

    void retranslateUi(QWidget *destGoogleGUI)
    {
        destGoogleGUI->setWindowTitle(QApplication::translate("destGoogleGUI", "destGoogleGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class destGoogleGUI: public Ui_destGoogleGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESTGOOGLEGUI_H
