#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "AlgorithmWindow.h"
#include "GraphWindow.h"
#include <QStackedWidget>
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow2)
{
    ui->setupUi(this);

    AlgorithmWindow *algorithmWindow = new AlgorithmWindow;

    GraphWindow *graphWindow = new GraphWindow;

    stackedWidget = new QStackedWidget(this);

    stackedWidget->addWidget(algorithmWindow);
    stackedWidget->addWidget(graphWindow);

    this->setCentralWidget(stackedWidget);

    connect(algorithmWindow, &AlgorithmWindow::mousePressed, this, &MainWindow::changeWindows);

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint point = QWidget::mapFromGlobal(QCursor::pos());
    cout << 1;
    // l->x2 = point.x();
    // l->y2 = point.y();
    // l->update();
    // event->pos();
    //stuff
}
void MainWindow::changeWindows()
{
    this->stackedWidget->setCurrentIndex(1);
}
MainWindow::~MainWindow()
{
    delete ui;
}
