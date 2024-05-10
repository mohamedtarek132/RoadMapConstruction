/********************************************************************************
** Form generated from reading UI file 'dfd.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DFD_H
#define UI_DFD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dfd
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *dfd)
    {
        if (dfd->objectName().isEmpty())
            dfd->setObjectName("dfd");
        dfd->resize(1024, 720);
        dfd->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 52, 72);"));
        centralwidget = new QWidget(dfd);
        centralwidget->setObjectName("centralwidget");
        dfd->setCentralWidget(centralwidget);
        menubar = new QMenuBar(dfd);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1024, 25));
        dfd->setMenuBar(menubar);
        statusbar = new QStatusBar(dfd);
        statusbar->setObjectName("statusbar");
        dfd->setStatusBar(statusbar);

        retranslateUi(dfd);

        QMetaObject::connectSlotsByName(dfd);
    } // setupUi

    void retranslateUi(QMainWindow *dfd)
    {
        dfd->setWindowTitle(QCoreApplication::translate("dfd", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dfd: public Ui_dfd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DFD_H
