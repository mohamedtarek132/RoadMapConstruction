#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "AlgorithmWindow.h"
#include "GraphWindow.h"
#include "startwindowmenu.h"
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

    HomeWindow *homeWindow = new HomeWindow();

    AlgorithmWindow *algorithmWindow = new AlgorithmWindow(graph);

    GraphWindow *graphWindow = new GraphWindow(graph);

    stackedWidget = new QStackedWidget(this);

    stackedWidget->addWidget(algorithmWindow);
    stackedWidget->addWidget(graphWindow);
    stackedWidget->addWidget(homeWindow);

    this->setCentralWidget(stackedWidget);

    connect(algorithmWindow, &AlgorithmWindow::backButtonPressed, this, &MainWindow::returnToPreviousWindow);
    connect(graphWindow, &GraphWindow::algorithmsButtonPressed, this, &MainWindow::goToNextWindow);
    connect(graphWindow, &GraphWindow::homeButtonPressed, this, &MainWindow::returnToPreviousWindow);
    // timer = new QTimer(this);

    // connect(timer, &QTimer::timeout, this, &MainWindow::changeWindows);

    // timer->start(100);

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint point = QWidget::mapFromGlobal(QCursor::pos());
    // l->x2 = point.x();
    // l->y2 = point.y();
    // l->update();
    // event->pos();
    //stuff
}
void MainWindow::returnToPreviousWindow()
{
    int index = this->stackedWidget->currentIndex() + 1;
    this->stackedWidget->setCurrentIndex(index);
}
void MainWindow::goToNextWindow()
{

    int index = this->stackedWidget->currentIndex() - 1;
    this->stackedWidget->setCurrentIndex(index);
}
MainWindow::~MainWindow()
{
    delete ui;
}
