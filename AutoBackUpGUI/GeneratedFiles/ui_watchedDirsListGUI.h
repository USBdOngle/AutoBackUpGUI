/********************************************************************************
** Form generated from reading UI file 'watchedDirsListGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WATCHEDDIRSLISTGUI_H
#define UI_WATCHEDDIRSLISTGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_watchedDirsListGUI
{
public:

    void setupUi(QWidget *watchedDirsListGUI)
    {
        if (watchedDirsListGUI->objectName().isEmpty())
            watchedDirsListGUI->setObjectName(QStringLiteral("watchedDirsListGUI"));
        watchedDirsListGUI->resize(400, 300);

        retranslateUi(watchedDirsListGUI);

        QMetaObject::connectSlotsByName(watchedDirsListGUI);
    } // setupUi

    void retranslateUi(QWidget *watchedDirsListGUI)
    {
        watchedDirsListGUI->setWindowTitle(QApplication::translate("watchedDirsListGUI", "watchedDirsListGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class watchedDirsListGUI: public Ui_watchedDirsListGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WATCHEDDIRSLISTGUI_H
