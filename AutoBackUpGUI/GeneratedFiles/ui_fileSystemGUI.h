/********************************************************************************
** Form generated from reading UI file 'fileSystemGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESYSTEMGUI_H
#define UI_FILESYSTEMGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_fileSystemGUI
{
public:

    void setupUi(QTreeView *fileSystemGUI)
    {
        if (fileSystemGUI->objectName().isEmpty())
            fileSystemGUI->setObjectName(QStringLiteral("fileSystemGUI"));
        fileSystemGUI->resize(400, 300);
        if (fileSystemGUI->header()->objectName().isEmpty())

        retranslateUi(fileSystemGUI);

        QMetaObject::connectSlotsByName(fileSystemGUI);
    } // setupUi

    void retranslateUi(QTreeView *fileSystemGUI)
    {
        fileSystemGUI->setWindowTitle(QApplication::translate("fileSystemGUI", "fileSystemGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fileSystemGUI: public Ui_fileSystemGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESYSTEMGUI_H
