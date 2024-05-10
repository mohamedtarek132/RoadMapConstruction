#include "GraphWindow.h"
#include "ui_GraphWindow.h"
#include "AlgorithmWindow.h"

GraphWindow::GraphWindow(Graph *graph1, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GraphWindow)
    , graph(graph1)
{
    ui->setupUi(this);

    queue<Edge> copiedEdges = graph->BFStraversal("c");

    staticGraphDrawer = new StaticGraphDrawer(this, copiedEdges, *graph);
    staticGraphDrawer->resize(1024, 720);

    // timer = new QTimer(this);

    // connect(timer, &QTimer::timeout, dynamicGraphDrawer, &DynamicGraphDrawer::callPaintEvent);

    // timer->start(1000);
}

GraphWindow::~GraphWindow()
{
    delete ui;
}
