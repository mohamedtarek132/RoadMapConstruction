/********************************************************************************
** Form generated from reading UI file 'startwindowmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOWMENU_H
#define UI_STARTWINDOWMENU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeWindow
{
public:
    QWidget *centralwidget;
    QLabel *mainLabel;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QPushButton *exitButton;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QListWidget *graphList;
    QLabel *errorlabel;
    QPushButton *displayButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HomeWindow)
    {
        if (HomeWindow->objectName().isEmpty())
            HomeWindow->setObjectName("HomeWindow");
        HomeWindow->resize(1024, 720);
        HomeWindow->setAutoFillBackground(false);
        HomeWindow->setStyleSheet(QString::fromUtf8("background-color:#153448;"));
        centralwidget = new QWidget(HomeWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setCursor(QCursor(Qt::ArrowCursor));
        mainLabel = new QLabel(centralwidget);
        mainLabel->setObjectName("mainLabel");
        mainLabel->setGeometry(QRect(10, 10, 1004, 131));
        mainLabel->setStyleSheet(QString::fromUtf8("font-color:rgb(21, 52, 72);\n"
"font-weight:800;\n"
"background-color:rgb(223, 208, 184);\n"
"border:rgb(223, 208, 184);\n"
"border-radius:10;"));
        mainLabel->setTextFormat(Qt::AutoText);
        mainLabel->setAlignment(Qt::AlignCenter);
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(820, 190, 100, 60));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(false);
        addButton->setFont(font);
        addButton->setStyleSheet(QString::fromUtf8("background-color:#dfd0b8;\n"
"font: 14pt \"Segoe UI\" ;\n"
"color:#153448;\n"
"font-weight:bold;\n"
"border:#dfd0b8;\n"
"border-radius:10;\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("icons/more.png"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon);
        addButton->setIconSize(QSize(50, 50));
        editButton = new QPushButton(centralwidget);
        editButton->setObjectName("editButton");
        editButton->setGeometry(QRect(820, 410, 100, 60));
        editButton->setFont(font);
        editButton->setStyleSheet(QString::fromUtf8("background-color:#dfd0b8;\n"
"font: 14pt \"Segoe UI\" ;\n"
"border:#dfd0b8;\n"
"border-radius:10;\n"
"color:#153448;\n"
"font-weight:bold;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("icons/editing.png"), QSize(), QIcon::Normal, QIcon::Off);
        editButton->setIcon(icon1);
        editButton->setIconSize(QSize(50, 50));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(820, 520, 100, 60));
        deleteButton->setFont(font);
        deleteButton->setStyleSheet(QString::fromUtf8("background-color:#dfd0b8;\n"
"font: 14pt \"Segoe UI\" ;\n"
"color:#153448;\n"
"font-weight:bold;\n"
"border:#dfd0b8;\n"
"border-radius:10;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon2);
        deleteButton->setIconSize(QSize(50, 50));
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(820, 630, 100, 60));
        exitButton->setFont(font);
        exitButton->setStyleSheet(QString::fromUtf8("background-color:#dfd0b8;\n"
"font: 14pt \"Segoe UI\" ;\n"
"color:#153448;\n"
"font-weight:bold;\n"
"border:#dfd0b8;\n"
"border-radius:10;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        exitButton->setIcon(icon3);
        exitButton->setIconSize(QSize(50, 50));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(130, 20, 141, 111));
        label_2->setStyleSheet(QString::fromUtf8("background-color:#dfd0b8;"));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../../My Downloads/road.png")));
        label_2->setScaledContents(true);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(70, 190, 671, 61));
        QFont font1;
        font1.setPointSize(14);
        font1.setWeight(QFont::ExtraBold);
        lineEdit->setFont(font1);
        lineEdit->setStyleSheet(QString::fromUtf8("color:rgb(21, 52, 72);\n"
"font-weight:800;\n"
"background-color:rgb(223, 208, 184);\n"
"border:rgb(223, 208, 184);\n"
"border-radius:10;"));
        lineEdit->setAlignment(Qt::AlignCenter);
        graphList = new QListWidget(centralwidget);
        graphList->setObjectName("graphList");
        graphList->setGeometry(QRect(70, 280, 681, 321));
        graphList->setFont(font1);
        graphList->setStyleSheet(QString::fromUtf8("color:rgb(21, 52, 72);\n"
"font-weight:800;\n"
"background-color:rgb(223, 208, 184);\n"
"border:rgb(223, 208, 184);\n"
"border-radius:10;"));
        errorlabel = new QLabel(centralwidget);
        errorlabel->setObjectName("errorlabel");
        errorlabel->setGeometry(QRect(90, 150, 621, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setWeight(QFont::ExtraBold);
        errorlabel->setFont(font2);
        errorlabel->setStyleSheet(QString::fromUtf8("\n"
"font-weight:800;\n"
"color:rgb(255, 244, 254);\n"
"background-color:#153448;\n"
"border:rgb(223, 208, 184);\n"
"border-radius:10;"));
        errorlabel->setTextFormat(Qt::AutoText);
        errorlabel->setAlignment(Qt::AlignCenter);
        displayButton = new QPushButton(centralwidget);
        displayButton->setObjectName("displayButton");
        displayButton->setGeometry(QRect(820, 300, 100, 60));
        displayButton->setFont(font);
        displayButton->setStyleSheet(QString::fromUtf8("background-color:#dfd0b8;\n"
"font: 14pt \"Segoe UI\" ;\n"
"border:#dfd0b8;\n"
"border-radius:10;\n"
"color:#153448;\n"
"font-weight:bold;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("D:/My Downloads/visible.png"), QSize(), QIcon::Normal, QIcon::Off);
        displayButton->setIcon(icon4);
        displayButton->setIconSize(QSize(50, 50));
        HomeWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(HomeWindow);
        statusbar->setObjectName("statusbar");
        HomeWindow->setStatusBar(statusbar);

        retranslateUi(HomeWindow);

        QMetaObject::connectSlotsByName(HomeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HomeWindow)
    {
        HomeWindow->setWindowTitle(QCoreApplication::translate("HomeWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        HomeWindow->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        mainLabel->setText(QCoreApplication::translate("HomeWindow", "<html><head/><body><p><span style=\" font-size:26pt; color:#153448;\">Road - Map</span></p><p><span style=\" font-size:26pt; color:#153448;\">Construction</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        addButton->setToolTip(QCoreApplication::translate("HomeWindow", "Add New Graph", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        addButton->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        addButton->setText(QString());
#if QT_CONFIG(shortcut)
        addButton->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        editButton->setToolTip(QCoreApplication::translate("HomeWindow", "Edit Graph", nullptr));
#endif // QT_CONFIG(tooltip)
        editButton->setText(QString());
#if QT_CONFIG(tooltip)
        deleteButton->setToolTip(QCoreApplication::translate("HomeWindow", "Delete Graph", nullptr));
#endif // QT_CONFIG(tooltip)
        deleteButton->setText(QString());
#if QT_CONFIG(tooltip)
        exitButton->setToolTip(QCoreApplication::translate("HomeWindow", "Exit App", nullptr));
#endif // QT_CONFIG(tooltip)
        exitButton->setText(QString());
        label_2->setText(QString());
        lineEdit->setText(QCoreApplication::translate("HomeWindow", "Add Graph here", nullptr));
        errorlabel->setText(QCoreApplication::translate("HomeWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Enter a valid name</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        displayButton->setToolTip(QCoreApplication::translate("HomeWindow", "Display Graph", nullptr));
#endif // QT_CONFIG(tooltip)
        displayButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HomeWindow: public Ui_HomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOWMENU_H
