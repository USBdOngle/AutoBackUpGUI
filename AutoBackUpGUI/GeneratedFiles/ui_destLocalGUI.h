/********************************************************************************
** Form generated from reading UI file 'destLocalGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESTLOCALGUI_H
#define UI_DESTLOCALGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_destLocalGUI
{
public:

    void setupUi(QWidget *destLocalGUI)
    {
        if (destLocalGUI->objectName().isEmpty())
            destLocalGUI->setObjectName(QStringLiteral("destLocalGUI"));
        destLocalGUI->resize(400, 300);

        retranslateUi(destLocalGUI);

        QMetaObject::connectSlotsByName(destLocalGUI);
    } // setupUi

    void retranslateUi(QWidget *destLocalGUI)
    {
        destLocalGUI->setWindowTitle(QApplication::translate("destLocalGUI", "destLocalGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class destLocalGUI: public Ui_destLocalGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESTLOCALGUI_H
