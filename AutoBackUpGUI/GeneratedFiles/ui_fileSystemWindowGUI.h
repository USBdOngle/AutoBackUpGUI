/********************************************************************************
** Form generated from reading UI file 'fileSystemWindowGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESYSTEMWINDOWGUI_H
#define UI_FILESYSTEMWINDOWGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fileSystemWindowGUI
{
public:

    void setupUi(QWidget *fileSystemWindowGUI)
    {
        if (fileSystemWindowGUI->objectName().isEmpty())
            fileSystemWindowGUI->setObjectName(QStringLiteral("fileSystemWindowGUI"));
        fileSystemWindowGUI->resize(400, 300);

        retranslateUi(fileSystemWindowGUI);

        QMetaObject::connectSlotsByName(fileSystemWindowGUI);
    } // setupUi

    void retranslateUi(QWidget *fileSystemWindowGUI)
    {
        fileSystemWindowGUI->setWindowTitle(QApplication::translate("fileSystemWindowGUI", "fileSystemWindowGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fileSystemWindowGUI: public Ui_fileSystemWindowGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESYSTEMWINDOWGUI_H
