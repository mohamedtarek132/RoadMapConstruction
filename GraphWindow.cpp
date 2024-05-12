#include "GraphWindow.h"
#include "ui_GraphWindow.h"
#include "AlgorithmWindow.h"

GraphWindow::GraphWindow(Graph *graph1, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GraphWindow)
    , graph(graph1)
{
    ui->setupUi(this);

    queue<Edge> copiedEdges = graph->DFStraversal("alexandria");

    int xOffset =  ui->frame->x() + ui->frame->lineWidth() * 2;
    int yOffset = ui->frame->y() + ui->frame->lineWidth() * 2;

    int size = 30;
    int width = ui->frame_2->width();
    int height = ui->frame_2->height();

    xyPlaneDrawer = new XYPlaneDrawer(this, size, xOffset, 30, width, height);
    xyPlaneDrawer->resize(width + xOffset, height + 30 );
    xyPlaneDrawer->move(0, yOffset - 30);

    staticGraphDrawer = new GraphDrawer(this, copiedEdges, *graph,  xOffset, 30, false);
    staticGraphDrawer->resize(width + xOffset, height + 30 );
    staticGraphDrawer->move(0, yOffset - 30);
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, staticGraphDrawer, &GraphDrawer::callPaintEvent);

    timer->start(1000);
}

GraphWindow::~GraphWindow()
{
    delete ui;
}
