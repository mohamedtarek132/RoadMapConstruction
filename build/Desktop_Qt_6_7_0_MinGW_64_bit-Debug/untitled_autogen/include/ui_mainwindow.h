/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *pageTitle;
    QFrame *frame;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1024, 720);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 52, 72);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pageTitle = new QLabel(centralwidget);
        pageTitle->setObjectName("pageTitle");
        pageTitle->setGeometry(QRect(122, 50, 780, 70));
        QFont font;
        font.setPointSize(32);
        pageTitle->setFont(font);
        pageTitle->setLayoutDirection(Qt::LeftToRight);
        pageTitle->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 208, 184);\n"
"color: rgb(21, 52, 72);\n"
" border-radius: 10px;"));
        pageTitle->setTextFormat(Qt::AutoText);
        pageTitle->setScaledContents(true);
        pageTitle->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        pageTitle->setWordWrap(false);
        pageTitle->setMargin(0);
        pageTitle->setIndent(0);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(87, 175, 850, 490));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 208, 184);\n"
"\n"
""));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(10);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pageTitle->setText(QCoreApplication::translate("MainWindow", "Prim's  Minimum Spanning Tree", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
