#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "AlgorithmWindow.h"
#include "GraphWindow.h"
#include "Graph.h"
#include <QStackedWidget>
#include <QTimer>
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow2)
{
    ui->setupUi(this);

    Graph *graph = new Graph();

    AlgorithmWindow *algorithmWindow = new AlgorithmWindow(graph);

    GraphWindow *graphWindow = new GraphWindow(graph);

    stackedWidget = new QStackedWidget(this);

    stackedWidget->addWidget(algorithmWindow);
    stackedWidget->addWidget(graphWindow);

    this->setCentralWidget(stackedWidget);

    connect(algorithmWindow, &AlgorithmWindow::mousePressed, this, &MainWindow::changeWindows);
    // timer = new QTimer(this);

    // connect(timer, &QTimer::timeout, this, &MainWindow::changeWindows);

    // timer->start(100);

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
