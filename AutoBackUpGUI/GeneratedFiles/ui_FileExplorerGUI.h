/********************************************************************************
** Form generated from reading UI file 'FileExplorerGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEEXPLORERGUI_H
#define UI_FILEEXPLORERGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileExplorerGUI
{
public:

    void setupUi(QWidget *FileExplorerGUI)
    {
        if (FileExplorerGUI->objectName().isEmpty())
            FileExplorerGUI->setObjectName(QStringLiteral("FileExplorerGUI"));
        FileExplorerGUI->resize(400, 300);

        retranslateUi(FileExplorerGUI);

        QMetaObject::connectSlotsByName(FileExplorerGUI);
    } // setupUi

    void retranslateUi(QWidget *FileExplorerGUI)
    {
        FileExplorerGUI->setWindowTitle(QApplication::translate("FileExplorerGUI", "FileExplorerGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileExplorerGUI: public Ui_FileExplorerGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEEXPLORERGUI_H
