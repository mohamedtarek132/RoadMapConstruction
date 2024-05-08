#include "mainwindow.h"
#include "graph.h"
#include "./ui_mainwindow.h"
#include <QLine>
#include <QPoint>
#include <QPushButton>
#include <QPainter>
#include <QtWidgets>
#include <QWidget>
#include <queue>
#include <iostream>
using namespace std;


Line::Line(QWidget *parent, int X1, int Y1, int X2, int Y2)
    : QWidget(parent), x1(X1), y1(Y1),x2(X2), y2(Y2){}

Line::Line(QWidget *parent,  queue<Edge> Edges, Graph G)
    : QWidget(parent),edges(Edges), g(G){}

void Line::paintEvent(QPaintEvent* pQEvent)
{
    QPainter painter(this);

    QPen pen(Qt::white);
    QPen pen2(Qt::black);

    pen.setWidth(4);
    pen2.setWidth(10);

    painter.setPen(pen2);

    queue<Edge> Edges = edges;
    while(!Edges.empty())
    {
        Edge edge = Edges.front();

        string vertex1Name = edge.getVertex1();
        string vertex2Name = edge.getVertex2();

        pair<int, int> vertex1 = g.positions[vertex1Name];
        pair<int, int> vertex2 = g.positions[vertex2Name];

        int x1 = 117 + vertex1.first;
        int y1 = 205 + vertex1.second;
        int x2 = 117 + vertex2.first;
        int y2 = 205 + vertex2.second;

        painter.setPen(pen);
        painter.drawLine(x1,y1,x2,y2);

        painter.setPen(pen2);
        painter.drawEllipse(x1-5, y1-5, 10, 10);
        painter.drawEllipse(x2-5, y2-5, 10, 10);

        Edges.pop();
    }

}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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

    queue<Edge> edges = g.PrimMinimumSpanningTree("a");

    l = new Line(this, edges, g);
    l->resize(1024, 720);
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
MainWindow::~MainWindow()
{
    delete ui;
}
