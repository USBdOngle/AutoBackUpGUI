/********************************************************************************
** Form generated from reading UI file 'watchedDirsGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WATCHEDDIRSGUI_H
#define UI_WATCHEDDIRSGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_watchedDirsGUI
{
public:

    void setupUi(QLabel *watchedDirsGUI)
    {
        if (watchedDirsGUI->objectName().isEmpty())
            watchedDirsGUI->setObjectName(QStringLiteral("watchedDirsGUI"));
        watchedDirsGUI->resize(400, 300);

        retranslateUi(watchedDirsGUI);

        QMetaObject::connectSlotsByName(watchedDirsGUI);
    } // setupUi

    void retranslateUi(QLabel *watchedDirsGUI)
    {
        watchedDirsGUI->setWindowTitle(QApplication::translate("watchedDirsGUI", "watchedDirsGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class watchedDirsGUI: public Ui_watchedDirsGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WATCHEDDIRSGUI_H
