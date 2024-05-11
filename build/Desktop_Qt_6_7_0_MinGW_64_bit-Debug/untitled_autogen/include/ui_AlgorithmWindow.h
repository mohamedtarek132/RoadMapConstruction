/********************************************************************************
** Form generated from reading UI file 'AlgorithmWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALGORITHMWINDOW_H
#define UI_ALGORITHMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlgorithmWindow
{
public:
    QWidget *centralwidget;
    QLabel *pageTitle;
    QFrame *frame;
    QFrame *frame_2;
    QPushButton *backButton;
    QPushButton *dynamicButton;
    QPushButton *staticButton;

    void setupUi(QMainWindow *AlgorithmWindow)
    {
        if (AlgorithmWindow->objectName().isEmpty())
            AlgorithmWindow->setObjectName("AlgorithmWindow");
        AlgorithmWindow->resize(1024, 720);
        AlgorithmWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 52, 72);"));
        centralwidget = new QWidget(AlgorithmWindow);
        centralwidget->setObjectName("centralwidget");
        pageTitle = new QLabel(centralwidget);
        pageTitle->setObjectName("pageTitle");
        pageTitle->setGeometry(QRect(122, 20, 780, 70));
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
        frame->setGeometry(QRect(87, 120, 850, 490));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 208, 184);\n"
"\n"
""));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(8);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(16, 16, 818, 458));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        backButton = new QPushButton(centralwidget);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(790, 630, 140, 70));
        QFont font1;
        font1.setPointSize(25);
        backButton->setFont(font1);
        backButton->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
        dynamicButton = new QPushButton(centralwidget);
        dynamicButton->setObjectName("dynamicButton");
        dynamicButton->setGeometry(QRect(280, 630, 141, 71));
        dynamicButton->setFont(font1);
        dynamicButton->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
        staticButton = new QPushButton(centralwidget);
        staticButton->setObjectName("staticButton");
        staticButton->setGeometry(QRect(100, 630, 141, 71));
        staticButton->setFont(font1);
        staticButton->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
        AlgorithmWindow->setCentralWidget(centralwidget);

        retranslateUi(AlgorithmWindow);

        QMetaObject::connectSlotsByName(AlgorithmWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AlgorithmWindow)
    {
        AlgorithmWindow->setWindowTitle(QCoreApplication::translate("AlgorithmWindow", "MainWindow", nullptr));
        pageTitle->setText(QCoreApplication::translate("AlgorithmWindow", "Prim's  Minimum Spanning Tree", nullptr));
        backButton->setText(QCoreApplication::translate("AlgorithmWindow", "Back", nullptr));
        dynamicButton->setText(QCoreApplication::translate("AlgorithmWindow", "Dynamic", nullptr));
        staticButton->setText(QCoreApplication::translate("AlgorithmWindow", "Static", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AlgorithmWindow: public Ui_AlgorithmWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALGORITHMWINDOW_H
