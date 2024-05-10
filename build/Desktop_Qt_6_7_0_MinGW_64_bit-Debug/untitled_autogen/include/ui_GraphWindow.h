/********************************************************************************
** Form generated from reading UI file 'GraphWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHWINDOW_H
#define UI_GRAPHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QFrame *frame;
    QLabel *label_2;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QPushButton *pushButton;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton_2;
    QLabel *label_9;
    QLineEdit *lineEdit_2;
    QFrame *line;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *pushButton_3;
    QLabel *label_13;
    QComboBox *comboBox_5;
    QLabel *label_14;
    QFrame *line_2;
    QPushButton *pushButton_4;

    void setupUi(QMainWindow *GraphWindow)
    {
        if (GraphWindow->objectName().isEmpty())
            GraphWindow->setObjectName("GraphWindow");
        GraphWindow->resize(1024, 720);
        GraphWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 52, 72);"));
        centralwidget = new QWidget(GraphWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 10, 341, 80));
        QFont font;
        font.setPointSize(36);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(30, 110, 771, 461));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 208, 184);"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(8);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 580, 150, 50));
        QFont font1;
        font1.setPointSize(18);
        label_2->setFont(font1);
        label_2->setWordWrap(false);
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(111, 630, 82, 28));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
        comboBox->setEditable(false);
        comboBox->setCurrentText(QString::fromUtf8(""));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(280, 630, 82, 28));
        comboBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(41, 630, 63, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(210, 630, 63, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(470, 580, 171, 50));
        label_6->setFont(font1);
        label_6->setWordWrap(false);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(280, 590, 83, 29));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
        comboBox_3 = new QComboBox(centralwidget);
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(540, 650, 82, 28));
        comboBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
        comboBox_4 = new QComboBox(centralwidget);
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(710, 650, 82, 28));
        comboBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(640, 650, 63, 20));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(470, 650, 63, 20));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(920, 440, 83, 29));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(40, 675, 63, 20));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(282, 670, 81, 28));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 208, 184);\n"
" border-radius: 10px;"));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(420, 590, 1, 120));
        line->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 208, 184);"));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(840, 110, 150, 50));
        label_5->setFont(font1);
        label_5->setWordWrap(false);
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(860, 225, 111, 28));
        lineEdit_3->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 208, 184);\n"
" border-radius: 10px;"));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(860, 265, 111, 28));
        lineEdit_4->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 208, 184);\n"
" border-radius: 10px;"));
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(860, 180, 111, 28));
        lineEdit_5->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 208, 184);\n"
" border-radius: 10px;"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(840, 230, 16, 20));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(840, 270, 16, 20));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(810, 185, 41, 20));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(875, 310, 83, 29));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(820, 360, 181, 50));
        label_13->setFont(font1);
        label_13->setWordWrap(false);
        comboBox_5 = new QComboBox(centralwidget);
        comboBox_5->setObjectName("comboBox_5");
        comboBox_5->setGeometry(QRect(820, 440, 82, 28));
        comboBox_5->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(840, 470, 63, 20));
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(810, 350, 200, 1));
        line_2->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 208, 184);"));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(710, 590, 83, 29));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
        GraphWindow->setCentralWidget(centralwidget);

        retranslateUi(GraphWindow);

        comboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(GraphWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GraphWindow)
    {
        GraphWindow->setWindowTitle(QCoreApplication::translate("GraphWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("GraphWindow", "Graph Name", nullptr));
        label_2->setText(QCoreApplication::translate("GraphWindow", "Add Edge", nullptr));
        label_3->setText(QCoreApplication::translate("GraphWindow", "vertex1", nullptr));
        label_4->setText(QCoreApplication::translate("GraphWindow", "vertex2", nullptr));
        label_6->setText(QCoreApplication::translate("GraphWindow", "Delete Edge", nullptr));
        pushButton->setText(QCoreApplication::translate("GraphWindow", "Add", nullptr));
        label_7->setText(QCoreApplication::translate("GraphWindow", "vertex2", nullptr));
        label_8->setText(QCoreApplication::translate("GraphWindow", "vertex1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("GraphWindow", "Delete", nullptr));
        label_9->setText(QCoreApplication::translate("GraphWindow", "Length", nullptr));
        label_5->setText(QCoreApplication::translate("GraphWindow", "Add Vertex", nullptr));
        lineEdit_3->setInputMask(QString());
        lineEdit_4->setInputMask(QString());
        lineEdit_5->setInputMask(QString());
        label_10->setText(QCoreApplication::translate("GraphWindow", "X", nullptr));
        label_11->setText(QCoreApplication::translate("GraphWindow", "Y", nullptr));
        label_12->setText(QCoreApplication::translate("GraphWindow", "Name", nullptr));
        pushButton_3->setText(QCoreApplication::translate("GraphWindow", "Add", nullptr));
        label_13->setText(QCoreApplication::translate("GraphWindow", "Delete Vertex", nullptr));
        label_14->setText(QCoreApplication::translate("GraphWindow", "vertex", nullptr));
        pushButton_4->setText(QCoreApplication::translate("GraphWindow", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphWindow: public Ui_GraphWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHWINDOW_H
