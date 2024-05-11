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
#include <iostream>
using namespace std;


StaticGraphDrawer::StaticGraphDrawer(QWidget *parent, int X1, int Y1, int X2, int Y2)
    : QWidget(parent), x1(X1), y1(Y1),x2(X2), y2(Y2){}

StaticGraphDrawer::StaticGraphDrawer(QWidget *parent,  queue<Edge> Edges, Graph G, int xOffset, int yOffset)
    : QWidget(parent),edges(Edges), graph(G), xOffset(xOffset), yOffset(yOffset){}

void StaticGraphDrawer::paintEvent(QPaintEvent* pQEvent)
{
    QPainter painter(this);

    QPen edgePen(Qt::blue);
    QPen vertexPen(Qt::black);
    QPen vertexNamePen(Qt::black);

    int diameter = 6;
    int radius = diameter/2;

    painter.setFont(QFont("times",22));

    edgePen.setWidth(4);
    vertexPen.setWidth(diameter);
    vertexNamePen.setWidth(20);

    queue<Edge> copiedEdges = edges;

    while(!copiedEdges.empty())
    {
        Edge edge = copiedEdges.front();

        string vertex1Name = edge.getVertex1();
        string vertex2Name = edge.getVertex2();

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

        QString vertex1String = QString::fromStdString(vertex1Name);
        QString vertex2String = QString::fromStdString(vertex2Name);

        painter.setPen(vertexNamePen);

        painter.drawText(x1 + diameter*2, y1 + radius, vertex1String);
        painter.drawText(x2 + diameter*2, y2 + radius, vertex2String);

        QString edgeLength = QString::number(edge.length);

        painter.drawText((x1+x2)/2 + diameter*2, (y1 + y2)/2 + radius, edgeLength);

        copiedEdges.pop();
    }

}


DynamicGraphDrawer::DynamicGraphDrawer(QWidget *parent, int X1, int Y1, int X2, int Y2)
    : QWidget(parent), x1(X1), y1(Y1),x2(X2), y2(Y2){}

DynamicGraphDrawer::DynamicGraphDrawer(QWidget *parent,  queue<Edge> Edges, Graph G, int xOffset, int yOffset)
    : QWidget(parent),edges(Edges), graph(G), xOffset(xOffset), yOffset(yOffset){}

void DynamicGraphDrawer::paintEvent(QPaintEvent* pQEvent)
{
    static int counter = -1;

    if(edges.size() <= (counter))
    {
        counter = -1;
    }

    queue<Edge>copiedEdges = edges;
    queue<Edge>shownEdges;
    for(int i = 0; i <= counter; i++)
    {
        shownEdges.push(copiedEdges.front());
        copiedEdges.pop();
    }

    QPainter painter(this);

    QPen edgePen(Qt::blue);
    QPen vertexPen(Qt::black);
    QPen vertexNamePen(Qt::black);

    int diameter = 6;
    int radius = diameter/2;

    painter.setFont(QFont("times",22));

    edgePen.setWidth(4);
    vertexPen.setWidth(diameter);
    vertexNamePen.setWidth(20);

    while(!shownEdges.empty())
    {
        Edge edge = shownEdges.front();

        string vertex1Name = edge.getVertex1();
        string vertex2Name = edge.getVertex2();

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

        QString vertex1String = QString::fromStdString(vertex1Name);
        QString vertex2String = QString::fromStdString(vertex2Name);

        painter.setPen(vertexNamePen);

        painter.drawText(x1 + diameter*2, y1 + radius, vertex1String);
        painter.drawText(x2 + diameter*2, y2 + radius, vertex2String);

        QString edgeLength = QString::number(edge.length);

        painter.drawText((x1+x2)/2 + diameter*2, (y1 + y2)/2 + radius, edgeLength);

        shownEdges.pop();
    }
    counter++;
}

void DynamicGraphDrawer::callPaintEvent(){
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

    queue<Edge> copiedEdges = graph->PrimMinimumSpanningTree("f");

    staticGraphDrawer = new StaticGraphDrawer(this, copiedEdges, *graph, ui->frame->x() + ui->frame->lineWidth() * 2.5, ui->frame->y() + ui->frame->lineWidth() * 2.5);
    staticGraphDrawer->resize(1024, 720);
    staticGraphDrawer->hide();

    dynamicGraphDrawer = new DynamicGraphDrawer(this, copiedEdges, *graph, ui->frame->x() + ui->frame->lineWidth() * 2.5, ui->frame->y() + ui->frame->lineWidth() * 2.5);
    dynamicGraphDrawer->resize(1024, 720);

    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, dynamicGraphDrawer, &DynamicGraphDrawer::callPaintEvent);

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
