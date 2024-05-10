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
#include <iostream>
using namespace std;


GraphDrawer::GraphDrawer(QWidget *parent, int X1, int Y1, int X2, int Y2)
    : QWidget(parent), x1(X1), y1(Y1),x2(X2), y2(Y2){}

GraphDrawer::GraphDrawer(QWidget *parent,  queue<Edge> Edges, Graph G)
    : QWidget(parent),edges(Edges), graph(G){}

void GraphDrawer::paintEvent(QPaintEvent* pQEvent)
{
    QPainter painter(this);

    QPen edgePen(Qt::white);
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

        int x1 = 117 + vertex1.first;
        int y1 = 205 + vertex1.second;
        int x2 = 117 + vertex2.first;
        int y2 = 205 + vertex2.second;

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

        copiedEdges.pop();
    }

}
AlgorithmWindow::AlgorithmWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AlgorithmWindow)
{
    ui->setupUi(this);

    Graph g;

    g.insertVertex("a", 0, 0);
    g.insertVertex("b", 60, 80);
    g.insertVertex("c", 120, 140);
    g.insertVertex("d", 20, 300);
    g.insertVertex("e", 700, 50);
    g.insertVertex("f", 50, 200);

    g.insertEdge("a", "b", 4);
    g.insertEdge("a", "c", 4);
    g.insertEdge("b", "c", 2);
    g.insertEdge("c", "d", 3);
    g.insertEdge("c", "e", 2);
    g.insertEdge("c", "f", 4);
    g.insertEdge("d", "f", 3);
    g.insertEdge("e", "f", 3);

    queue<Edge> copiedEdges = g.PrimMinimumSpanningTree("a");

    graphDrawer = new GraphDrawer(this, copiedEdges, g);
    graphDrawer->resize(1024, 720);
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
