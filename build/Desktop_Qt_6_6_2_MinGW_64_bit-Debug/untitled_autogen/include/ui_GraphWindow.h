/********************************************************************************
** Form generated from reading UI file 'GraphWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
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
    QFrame *frame_2;
    QLabel *label_2;
    QComboBox *addEdgeV1Combo;
    QComboBox *addEdgeV2Combo;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QPushButton *addEdgeButton;
    QComboBox *deleteEdgeV1Combo;
    QComboBox *deleteEdgeV2Combo;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *deleteVertexButton;
    QLabel *label_9;
    QLineEdit *edgeLength;
    QFrame *line;
    QLabel *label_5;
    QLineEdit *xPosition;
    QLineEdit *yPosition;
    QLineEdit *vertexName;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *addVertexButton;
    QLabel *label_13;
    QComboBox *deleteVertexCombo;
    QLabel *label_14;
    QFrame *line_2;
    QPushButton *deleteEdgeButton;
    QPushButton *algorithmsButton;
    QLabel *label_15;
    QPushButton *homeButton;
    QLabel *addError;

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
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(16, 16, 739, 429));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 580, 150, 50));
        QFont font1;
        font1.setPointSize(18);
        label_2->setFont(font1);
        label_2->setWordWrap(false);
        addEdgeV1Combo = new QComboBox(centralwidget);
        addEdgeV1Combo->setObjectName("addEdgeV1Combo");
        addEdgeV1Combo->setGeometry(QRect(111, 630, 82, 28));
        addEdgeV1Combo->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
        addEdgeV1Combo->setEditable(false);
        addEdgeV1Combo->setCurrentText(QString::fromUtf8(""));
        addEdgeV2Combo = new QComboBox(centralwidget);
        addEdgeV2Combo->setObjectName("addEdgeV2Combo");
        addEdgeV2Combo->setGeometry(QRect(280, 630, 82, 28));
        addEdgeV2Combo->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
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
        addEdgeButton = new QPushButton(centralwidget);
        addEdgeButton->setObjectName("addEdgeButton");
        addEdgeButton->setGeometry(QRect(280, 590, 83, 29));
        addEdgeButton->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
        deleteEdgeV1Combo = new QComboBox(centralwidget);
        deleteEdgeV1Combo->setObjectName("deleteEdgeV1Combo");
        deleteEdgeV1Combo->setGeometry(QRect(540, 650, 82, 28));
        deleteEdgeV1Combo->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
        deleteEdgeV2Combo = new QComboBox(centralwidget);
        deleteEdgeV2Combo->setObjectName("deleteEdgeV2Combo");
        deleteEdgeV2Combo->setGeometry(QRect(710, 650, 82, 28));
        deleteEdgeV2Combo->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(640, 650, 63, 20));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(470, 650, 63, 20));
        deleteVertexButton = new QPushButton(centralwidget);
        deleteVertexButton->setObjectName("deleteVertexButton");
        deleteVertexButton->setGeometry(QRect(920, 440, 83, 29));
        deleteVertexButton->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(40, 675, 63, 20));
        edgeLength = new QLineEdit(centralwidget);
        edgeLength->setObjectName("edgeLength");
        edgeLength->setGeometry(QRect(110, 670, 81, 28));
        edgeLength->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 208, 184);\n"
" border-radius: 10px;"));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(420, 590, 1, 120));
        line->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 208, 184);"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(840, 100, 150, 50));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(false);
        xPosition = new QLineEdit(centralwidget);
        xPosition->setObjectName("xPosition");
        xPosition->setGeometry(QRect(860, 225, 111, 28));
        xPosition->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 208, 184);\n"
" border-radius: 10px;"));
        yPosition = new QLineEdit(centralwidget);
        yPosition->setObjectName("yPosition");
        yPosition->setGeometry(QRect(860, 265, 111, 28));
        yPosition->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 208, 184);\n"
" border-radius: 10px;"));
        vertexName = new QLineEdit(centralwidget);
        vertexName->setObjectName("vertexName");
        vertexName->setGeometry(QRect(860, 180, 111, 28));
        vertexName->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 208, 184);\n"
" border-radius: 10px;"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(840, 230, 16, 20));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(840, 270, 16, 20));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(815, 185, 41, 20));
        addVertexButton = new QPushButton(centralwidget);
        addVertexButton->setObjectName("addVertexButton");
        addVertexButton->setGeometry(QRect(875, 310, 83, 29));
        addVertexButton->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(820, 360, 181, 50));
        label_13->setFont(font1);
        label_13->setWordWrap(false);
        deleteVertexCombo = new QComboBox(centralwidget);
        deleteVertexCombo->setObjectName("deleteVertexCombo");
        deleteVertexCombo->setGeometry(QRect(820, 440, 82, 28));
        deleteVertexCombo->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(840, 470, 63, 20));
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(810, 350, 200, 1));
        line_2->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 208, 184);"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        deleteEdgeButton = new QPushButton(centralwidget);
        deleteEdgeButton->setObjectName("deleteEdgeButton");
        deleteEdgeButton->setGeometry(QRect(710, 590, 83, 29));
        deleteEdgeButton->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
        algorithmsButton = new QPushButton(centralwidget);
        algorithmsButton->setObjectName("algorithmsButton");
        algorithmsButton->setGeometry(QRect(670, 50, 131, 41));
        QFont font2;
        font2.setPointSize(15);
        algorithmsButton->setFont(font2);
        algorithmsButton->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(210, 675, 63, 20));
        homeButton = new QPushButton(centralwidget);
        homeButton->setObjectName("homeButton");
        homeButton->setGeometry(QRect(910, 670, 101, 41));
        QFont font3;
        font3.setPointSize(16);
        homeButton->setFont(font3);
        homeButton->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 73, 84);"));
        addError = new QLabel(centralwidget);
        addError->setObjectName("addError");
        addError->setEnabled(true);
        addError->setGeometry(QRect(810, 140, 201, 31));
        QFont font4;
        font4.setPointSize(10);
        addError->setFont(font4);
        addError->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        addError->setAlignment(Qt::AlignCenter);
        addError->setVisible(false);
        GraphWindow->setCentralWidget(centralwidget);

        retranslateUi(GraphWindow);

        addEdgeV1Combo->setCurrentIndex(-1);


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
        addEdgeButton->setText(QCoreApplication::translate("GraphWindow", "Add", nullptr));
        label_7->setText(QCoreApplication::translate("GraphWindow", "vertex2", nullptr));
        label_8->setText(QCoreApplication::translate("GraphWindow", "vertex1", nullptr));
        deleteVertexButton->setText(QCoreApplication::translate("GraphWindow", "Delete", nullptr));
        label_9->setText(QCoreApplication::translate("GraphWindow", "Length", nullptr));
        label_5->setText(QCoreApplication::translate("GraphWindow", "Add Vertex", nullptr));
        xPosition->setInputMask(QString());
        yPosition->setInputMask(QString());
        vertexName->setInputMask(QString());
        label_10->setText(QCoreApplication::translate("GraphWindow", "X", nullptr));
        label_11->setText(QCoreApplication::translate("GraphWindow", "Y", nullptr));
        label_12->setText(QCoreApplication::translate("GraphWindow", "Name", nullptr));
        addVertexButton->setText(QCoreApplication::translate("GraphWindow", "Add", nullptr));
        label_13->setText(QCoreApplication::translate("GraphWindow", "Delete Vertex", nullptr));
        label_14->setText(QCoreApplication::translate("GraphWindow", "vertex", nullptr));
        deleteEdgeButton->setText(QCoreApplication::translate("GraphWindow", "Delete", nullptr));
        algorithmsButton->setText(QCoreApplication::translate("GraphWindow", "Algortims", nullptr));
        label_15->setText(QCoreApplication::translate("GraphWindow", "Kilometers", nullptr));
        homeButton->setText(QCoreApplication::translate("GraphWindow", "Home", nullptr));
        addError->setText(QCoreApplication::translate("GraphWindow", "There is a vertex in this position!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphWindow: public Ui_GraphWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHWINDOW_H
