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

GraphDrawer::GraphDrawer(QWidget *parent,  string startingVertex, Graph *graph, int xOffset, int yOffset, bool dynamic)
    : QWidget(parent),startingVertex(startingVertex), graph(graph), xOffset(xOffset), yOffset(yOffset), dynamic(dynamic),
    edges(graph->DFStraversal(startingVertex)){}

void GraphDrawer::paintEvent(QPaintEvent* pQEvent)
{
    static int counter = -1;
    static GraphDrawer *currentVariable = this;
    static queue<Edge>copiedEdges = edges;

    QPainter painter(this);

    QColor edgeColor(125, 0, 0);
    QColor vertexNameColor(12, 76, 16);


    QPen edgePen(Qt::red);
    QPen vertexPen(Qt::black);
    QPen vertexNamePen(vertexNameColor);

    int diameter = 6;
    int radius = diameter/2;

    painter.setFont(QFont("times",16));

    edgePen.setWidth(4);
    vertexPen.setWidth(diameter);
    vertexNamePen.setWidth(16);

    queue<Edge>shownEdges;

    set<string> shownVertex;

    if(dynamic)
    {
        if(edges.size() <= (counter) || this != currentVariable || copiedEdges != edges)
        {
            counter = -1;
            currentVariable = this;

            pair<int, int> vertex1 = graph->positions[startingVertex];

            int x1 = xOffset + vertex1.first;
            int y1 = yOffset + vertex1.second;

            painter.setPen(vertexPen);

            painter.drawEllipse(x1 - radius, y1 - radius, diameter, diameter);

            QString vertexString = QString::fromStdString(startingVertex);

            x1 = graph->positions[startingVertex].first + xOffset;
            y1 = graph->positions[startingVertex].second + yOffset;

            painter.setPen(vertexNamePen);

            painter.drawText(x1 - diameter*2, y1 - diameter, vertexString);
        }

        for(int i = 0; i <= counter; i++)
        {
            shownEdges.push(copiedEdges.front());
            copiedEdges.pop();
        }

        counter++;
        copiedEdges = edges;
    }
    else{
        counter = -1;
        shownEdges = edges;
        //cout << shownEdges.size();
    }

    while(!shownEdges.empty())
    {
        Edge edge = shownEdges.front();

        string vertex1Name = edge.getVertex1();
        string vertex2Name = edge.getVertex2();

        shownVertex.insert(vertex1Name);
        shownVertex.insert(vertex2Name);

        pair<int, int> vertex1 = graph->positions[vertex1Name];
        pair<int, int> vertex2 = graph->positions[vertex2Name];

        int x1 = xOffset + vertex1.first;
        int y1 = yOffset + vertex1.second;
        int x2 = xOffset + vertex2.first;
        int y2 = yOffset + vertex2.second;

        painter.setPen(edgePen);

        painter.drawLine(x1,y1,x2,y2);

        painter.setPen(vertexPen);

        QString edgeLength = QString::number(edge.length);

        painter.drawText((x1+x2)/2, (y1 + y2)/2, edgeLength);

        shownEdges.pop();
    }
    if(dynamic)
    {
        painter.setPen(vertexPen);

        for (auto i = shownVertex.begin(); i != shownVertex.end(); i++)
        {
            string vertex = *i;
            QString vertexString = QString::fromStdString(vertex);
            int x1 = graph->positions[vertex].first + xOffset;
            int y1 = graph->positions[vertex].second + yOffset;


            painter.drawEllipse(x1 - radius, y1 - radius, diameter, diameter);
        }

        painter.setPen(vertexNamePen);

        for (auto i = shownVertex.begin(); i != shownVertex.end(); i++)
        {
            string vertex = *i;
            QString vertexString = QString::fromStdString(vertex);
            int x1 = graph->positions[vertex].first + xOffset;
            int y1 = graph->positions[vertex].second + yOffset;

            painter.drawText(x1 - diameter*2, y1 - diameter, vertexString);
        }
    }
    else
    {
        painter.setPen(vertexPen);

        for (auto i = graph->adjacencyList.begin(); i != graph->adjacencyList.end(); i++)
        {
            string vertex = i->first;
            QString vertexString = QString::fromStdString(vertex);
            int x1 = graph->positions[vertex].first + xOffset;
            int y1 = graph->positions[vertex].second + yOffset;


            painter.drawEllipse(x1 - radius, y1 - radius, diameter, diameter);
        }

        painter.setPen(vertexNamePen);

        for (auto i = graph->adjacencyList.begin(); i != graph->adjacencyList.end(); i++)
        {
            string vertex = i->first;
            QString vertexString = QString::fromStdString(vertex);
            int x1 = graph->positions[vertex].first + xOffset;
            int y1 = graph->positions[vertex].second + yOffset;

            painter.drawText(x1 - diameter*2, y1 - diameter, vertexString);
        }
    }
}

void GraphDrawer::changeAlgorithm(string algorithm)
{
    if (algorithm == "BFS")
    {
        cout<<"Hello BFS\n";
        edges = graph->BFStraversal(startingVertex);
    }
    else if (algorithm == "DFS")
    {
        cout<<"Hello DFS\n";
        edges = graph->DFStraversal(startingVertex);
    }
    else if (algorithm == "Prim")
    {
        cout<<"Hello Prim\n";
        edges = graph->PrimMinimumSpanningTree(startingVertex);
    }
    else
    {
        //edges = graph->DijkstraShortestPath(startingVertex, "endingVertex");
    }
}

void GraphDrawer::changeStartingVertex(string vertex, string algorithm)
{
    startingVertex = vertex;
    changeAlgorithm(algorithm);
}

void GraphDrawer::callPaintEvent(){
    this->update();
}

void GraphDrawer::unconnectedGraph()
{
    set<Edge> trying;
    for(auto it = graph->adjacencyList.begin(); it != graph->adjacencyList.end(); it++)
    {
        queue<Edge> edge = graph->DFStraversal(it->first);
        while(!edge.empty())
        {
            trying.insert(edge.front());
            edge.pop();
        }
    }
    queue<Edge>edge;
    for(auto it = trying.begin(); it != trying.end(); it++)
    {
        edge.push(*it);
    }
    edges = edge;
    update();
}

void GraphDrawer::changeToDynamic()
{
    dynamic = true;
}

void GraphDrawer::changeToStatic()
{
    dynamic = false;
}


AlgorithmWindow::AlgorithmWindow(Graph *graph, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AlgorithmWindow)
    , graph(graph)
{
    ui->setupUi(this);

    // graph->insertVertex("a", 0, 0);
    // graph->insertVertex("b", 60, 80);
    // graph->insertVertex("c", 120, 140);
    // graph->insertVertex("d", 20, 300);
    // graph->insertVertex("e", 700, 50);
    // graph->insertVertex("f", 50, 200);

    // graph->insertEdge("a", "b", 4);
    // graph->insertEdge("a", "c", 4);
    // graph->insertEdge("b", "c", 2);
    // graph->insertEdge("c", "d", 3);
    // graph->insertEdge("c", "e", 2);
    // graph->insertEdge("c", "f", 4);
    // graph->insertEdge("d", "f", 3);
    // graph->insertEdge("e", "f", 3);

    graph->insertVertex("alexandria", 0, 0);
    graph->insertVertex("banha", 60, 80);
    graph->insertVertex("cairo", 120, 140);
    graph->insertVertex("damanhoor", 20, 300);
    graph->insertVertex("elmansoura", 700, 50);
    graph->insertVertex("fayoum", 50, 200);
    graph->insertVertex("ana", 300, 300);
    //cout<<"Why are we here????\n";

    graph->insertEdge("alexandria", "banha", 4);
    graph->insertEdge("alexandria", "cairo", 4);
    graph->insertEdge("banha", "cairo", 2);
    graph->insertEdge("cairo", "damanhoor", 3);
    graph->insertEdge("cairo", "elmansoura", 2);
    graph->insertEdge("cairo", "fayoum", 4);
    graph->insertEdge("damanhoor", "fayoum", 3);
    graph->insertEdge("elmansoura", "fayoum", 3);

    // cout<<"Why are we here\n";
    ui->comboBox->addItem("DFS");
    ui->comboBox->addItem("BFS");
    ui->comboBox->addItem("Prim");
    ui->comboBox->addItem("Dijkstra");

    for (auto i = graph->adjacencyList.begin(); i != graph->adjacencyList.end(); i++)
    {
        QString item = QString::fromStdString(i->first);

        ui->startPointCombo->addItem(item);
        ui->endPointCombo->addItem(item);
    }

    int xOffset =  ui->frame->x() + ui->frame->lineWidth() * 2;
    int yOffset = ui->frame->y() + ui->frame->lineWidth() * 2;

    int size = 30;
    int width = ui->frame_2->width();
    int height = ui->frame_2->height();

    xyPlaneDrawer = new XYPlaneDrawer(this, size, xOffset, yOffset-60, width, height);
    xyPlaneDrawer->resize(1024, 550);
    xyPlaneDrawer->move(0, 60);

    xOffset =  ui->frame->x() + ui->frame->lineWidth() * 2.5;
    yOffset = ui->frame->y() + ui->frame->lineWidth() * 2.5;

    string startingVertex = graph->adjacencyList.begin()->first;

    graphDrawer = new GraphDrawer(this, startingVertex, graph, xOffset, yOffset-60, true);
    graphDrawer->resize(1024, 550);
    graphDrawer->move(0, 60);

    timer = new QTimer(this);

    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &AlgorithmWindow::changeAlgorithm);
    connect(ui->dynamicButton, &QPushButton::clicked, graphDrawer, &GraphDrawer::changeToDynamic);
    connect(ui->staticButton, &QPushButton::clicked, graphDrawer, &GraphDrawer::changeToStatic);
    connect(ui->backButton, &QPushButton::clicked, this, &AlgorithmWindow::backButtonPressed);
    connect(ui->startPointCombo, &QComboBox::currentIndexChanged, this, &AlgorithmWindow::changeStartingVertex);

    connect(timer, &QTimer::timeout, graphDrawer, &GraphDrawer::callPaintEvent);

    timer->start(900);

}

void AlgorithmWindow::mousePressEvent(QMouseEvent *event)
{

    QPoint point = QWidget::mapFromGlobal(QCursor::pos());
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

void AlgorithmWindow::changeAlgorithm()
{
    string algorithm = ui->comboBox->currentText().toStdString();

    graphDrawer->changeAlgorithm(algorithm);
}

void AlgorithmWindow::changeStartingVertex()
{
    string algorithm = ui->comboBox->currentText().toStdString();
    string vertex = ui->startPointCombo->currentText().toStdString();

    graphDrawer->changeStartingVertex(vertex, algorithm);
}

AlgorithmWindow::~AlgorithmWindow()
{
    delete ui;
    delete graph;
    delete xyPlaneDrawer;
    delete timer;
}
