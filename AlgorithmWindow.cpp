#include "AlgorithmWindow.h"
#include "Graph.h"
#include "MainWindow.h"
#include "./ui_AlgorithmWindow.h"
#include <QLine>
#include <QPoint>
#include <QPushButton>
#include <QPainter>
#include <QtWidgets>
#include <QWidget>
#include <queue>
#include <QString>
#include <QFont>
#include <QTimer>
#include <set>
#include <iostream>
using namespace std;
using namespace std::chrono_literals;


XYPlaneDrawer::XYPlaneDrawer(QWidget *parent, int Size, int xOffset, int yOffset, int width, int height)
    : QWidget(parent), size(Size), xOffset(xOffset),yOffset(yOffset), width(width), height(height){}

void XYPlaneDrawer::paintEvent(QPaintEvent* pQEvent)
{
    QPainter painter(this);

    QPen linePen(Qt::gray);

    linePen.setWidth(1);

    painter.setPen(linePen);

    // we add a one because it will start from zero so we added a one
    int numberOfHorizontalLines = height/size + 1;
    int numberOfVerticalLines = width/size + 1;

    for(int i = 0; i < numberOfVerticalLines; i++)
    {
        int x = xOffset + i * size;
        painter.drawLine(x, yOffset, x, yOffset + height);
    }

    for(int i = 0; i < numberOfHorizontalLines; i++)
    {
        int y = yOffset + i * size;
        painter.drawLine(xOffset, y, xOffset + width, y);
    }
}

GraphDrawer::GraphDrawer(QWidget *parent,  queue<Edge> Edges, Graph G, int xOffset, int yOffset, bool dynamic)
    : QWidget(parent),edges(Edges), graph(G), xOffset(xOffset), yOffset(yOffset), dynamic(dynamic){}

void GraphDrawer::paintEvent(QPaintEvent* pQEvent)
{
    static int counter = -1;
    static GraphDrawer *currentVariable = this;

    QPainter painter(this);

    QColor edgeColor(125, 0, 0);
    QColor vertexNameColor(63, 0, 94);


    QPen edgePen(edgeColor);
    QPen vertexPen(Qt::black);
    QPen vertexNamePen(vertexNameColor);

    int diameter = 6;
    int radius = diameter/2;

    painter.setFont(QFont("times",16));

    edgePen.setWidth(4);
    vertexPen.setWidth(diameter);
    vertexNamePen.setWidth(16);

    queue<Edge>copiedEdges = edges;
    queue<Edge>shownEdges;

    set<string> shownVertex;

    if(dynamic)
    {
        if(edges.size() <= (counter) || this != currentVariable)
        {
            counter = -1;
            currentVariable = this;
        }

        for(int i = 0; i <= counter; i++)
        {
            shownEdges.push(copiedEdges.front());
            copiedEdges.pop();
        }

        counter++;
    }
    else{
        counter = -1;
        shownEdges = edges;
        cout << shownEdges.size();
    }

    while(!shownEdges.empty())
    {
        Edge edge = shownEdges.front();

        string vertex1Name = edge.getVertex1();
        string vertex2Name = edge.getVertex2();

        shownVertex.insert(vertex1Name);
        shownVertex.insert(vertex2Name);

        pair<int, int> vertex1 = graph.positions[vertex1Name];
        pair<int, int> vertex2 = graph.positions[vertex2Name];

        int x1 = xOffset + vertex1.first;
        int y1 = yOffset + vertex1.second;
        int x2 = xOffset + vertex2.first;
        int y2 = yOffset + vertex2.second;

        painter.setPen(edgePen);

        painter.drawLine(x1,y1,x2,y2);

        painter.setPen(vertexPen);

        painter.drawEllipse(x1 - radius, y1 - radius, diameter, diameter);
        painter.drawEllipse(x2 - radius, y2 - radius, diameter, diameter);


        QString edgeLength = QString::number(edge.length);

        painter.drawText((x1+x2)/2 + diameter*2, (y1 + y2)/2 + radius, edgeLength);

        shownEdges.pop();
    }
    for (auto i = shownVertex.begin(); i != shownVertex.end(); i++)
    {

        QString vertex1String = QString::fromStdString(*i);
        int x1 = graph.positions[*i].first + xOffset;
        int y1 = graph.positions[*i].second + yOffset;
        painter.setPen(vertexNamePen);

        painter.drawText(x1 - diameter*2, y1 - diameter, vertex1String);
    }
}


void GraphDrawer::callPaintEvent(){
    this->update();
}


AlgorithmWindow::AlgorithmWindow(Graph *tery, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AlgorithmWindow)
    , graph(tery)
{
    ui->setupUi(this);

    graph->insertVertex("a", 0, 0);
    graph->insertVertex("b", 60, 80);
    graph->insertVertex("c", 120, 140);
    graph->insertVertex("d", 20, 300);
    graph->insertVertex("e", 700, 50);
    graph->insertVertex("f", 50, 200);

    graph->insertEdge("a", "b", 4);
    graph->insertEdge("a", "c", 4);
    graph->insertEdge("b", "c", 2);
    graph->insertEdge("c", "d", 3);
    graph->insertEdge("c", "e", 2);
    graph->insertEdge("c", "f", 4);
    graph->insertEdge("d", "f", 3);
    graph->insertEdge("e", "f", 3);

    int xOffset =  ui->frame->x() + ui->frame->lineWidth() * 2;
    int yOffset = ui->frame->y() + ui->frame->lineWidth() * 2;

    int size = 30;
    int width = ui->frame_2->width();
    int height = ui->frame_2->height();

    xyPlaneDrawer = new XYPlaneDrawer(this, size, xOffset, yOffset, width, height);

    xyPlaneDrawer->resize(1024, 720);

    queue<Edge> shownEdges = graph->PrimMinimumSpanningTree("c");

    xOffset =  ui->frame->x() + ui->frame->lineWidth() * 2.5;
    yOffset = ui->frame->y() + ui->frame->lineWidth() * 2.5;

    staticGraphDrawer = new GraphDrawer(this, shownEdges, *graph, xOffset, yOffset, false);
    staticGraphDrawer->resize(1024, 720);
    staticGraphDrawer->hide();

    dynamicGraphDrawer = new GraphDrawer(this, shownEdges, *graph, xOffset, yOffset, true);
    dynamicGraphDrawer->resize(1024, 720);

    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, dynamicGraphDrawer, &GraphDrawer::callPaintEvent);

    timer->start(1000);
}
void AlgorithmWindow::mousePressEvent(QMouseEvent *event)
{

    QPoint point = QWidget::mapFromGlobal(QCursor::pos());
    emit AlgorithmWindow::mousePressed();
    // this->
    // this->hide();
    // dfd *d = new dfd(0);
    // d->show();
    // l->x2 = point.x();
    // l->y2 = point.y();
    // l->update();
    // event->pos();
    //stuff
}
AlgorithmWindow::~AlgorithmWindow()
{
    delete ui;
}
