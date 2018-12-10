/********************************************************************************
** Form generated from reading UI file 'AutoBackUpGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOBACKUPGUI_H
#define UI_AUTOBACKUPGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AutoBackUpGUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AutoBackUpGUIClass)
    {
        if (AutoBackUpGUIClass->objectName().isEmpty())
            AutoBackUpGUIClass->setObjectName(QStringLiteral("AutoBackUpGUIClass"));
        AutoBackUpGUIClass->resize(600, 400);
        menuBar = new QMenuBar(AutoBackUpGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        AutoBackUpGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AutoBackUpGUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        AutoBackUpGUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(AutoBackUpGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        AutoBackUpGUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(AutoBackUpGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AutoBackUpGUIClass->setStatusBar(statusBar);

        retranslateUi(AutoBackUpGUIClass);

        QMetaObject::connectSlotsByName(AutoBackUpGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *AutoBackUpGUIClass)
    {
        AutoBackUpGUIClass->setWindowTitle(QApplication::translate("AutoBackUpGUIClass", "AutoBackUpGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AutoBackUpGUIClass: public Ui_AutoBackUpGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOBACKUPGUI_H
