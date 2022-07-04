/********************************************************************************
** Form generated from reading UI file 'FramelessModel.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMELESSMODEL_H
#define UI_FRAMELESSMODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FramelessModelClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FramelessModelClass)
    {
        if (FramelessModelClass->objectName().isEmpty())
            FramelessModelClass->setObjectName(QStringLiteral("FramelessModelClass"));
        FramelessModelClass->resize(600, 400);
        menuBar = new QMenuBar(FramelessModelClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        FramelessModelClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FramelessModelClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FramelessModelClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(FramelessModelClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        FramelessModelClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(FramelessModelClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FramelessModelClass->setStatusBar(statusBar);

        retranslateUi(FramelessModelClass);

        QMetaObject::connectSlotsByName(FramelessModelClass);
    } // setupUi

    void retranslateUi(QMainWindow *FramelessModelClass)
    {
        FramelessModelClass->setWindowTitle(QApplication::translate("FramelessModelClass", "FramelessModel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FramelessModelClass: public Ui_FramelessModelClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMELESSMODEL_H
