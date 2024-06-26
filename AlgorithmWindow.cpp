#include "AlgorithmWindow.h"
#include "Graph.h"
#include "MainWindow.h"
#include "./ui_AlgorithmWindow.h"
#include <QLine>
#include <QPoint>
#include <QPushButton>
#include <QPainter>
//#include <QtWidgets>
#include <QWidget>
#include <queue>
#include <QString>
#include <QFont>
#include <QTimer>
#include <set>

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

GraphDrawer::GraphDrawer(QWidget *parent,  Graph *graph, int xOffset, int yOffset, bool dynamic)
    : QWidget(parent), graph(graph), xOffset(xOffset), yOffset(yOffset), dynamic(dynamic){}

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

void GraphDrawer::setAlgorithm(string algorithm)
{
    if (algorithm == "BFS")
    {
        edges = graph->BFStraversal(startingVertex);
    }
    else if (algorithm == "DFS")
    {
        edges = graph->DFStraversal(startingVertex);
    }
    else if (algorithm == "Prim")
    {
        edges = graph->PrimMinimumSpanningTree(startingVertex);
    }
    else
    {
        edges = graph->DijkstraShortestPath(startingVertex, endingVertex);
    }
}

void GraphDrawer::setStartingVertex(string vertex)
{
    startingVertex = vertex;
}
void GraphDrawer::setEndingVertex(string vertex)
{
    endingVertex = vertex;
}
void GraphDrawer::callPaintEvent(){
    this->update();
}

void GraphDrawer::unconnectedGraph()
{
    edges = graph->unconnectedTraversal();
    update();
}

void GraphDrawer::setToDynamic()
{
    dynamic = true;
}

void GraphDrawer::setToStatic()
{
    dynamic = false;
}

AlgorithmWindow::AlgorithmWindow(Graph *graph, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AlgorithmWindow)
    , graph(graph)
{
    ui->setupUi(this);

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

    graphDrawer = new GraphDrawer(this, graph, xOffset, yOffset-60, true);
    graphDrawer->resize(1024, 550);
    graphDrawer->move(0, 60);

    timer = new QTimer(this);

    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &AlgorithmWindow::setAlgorithm);
    connect(ui->dynamicButton, &QPushButton::clicked, graphDrawer, &GraphDrawer::setToDynamic);
    connect(ui->staticButton, &QPushButton::clicked, graphDrawer, &GraphDrawer::setToStatic);
    connect(ui->backButton, &QPushButton::clicked, this, &AlgorithmWindow::backButtonPressed);
    connect(ui->startPointCombo, &QComboBox::currentIndexChanged, this, &AlgorithmWindow::setStartingVertex);
    connect(ui->endPointCombo, &QComboBox::currentIndexChanged, this, &AlgorithmWindow::setEndingVertex);


    connect(timer, &QTimer::timeout, graphDrawer, &GraphDrawer::callPaintEvent);

    timer->start(900);

}

void AlgorithmWindow::setAlgorithm()
{
    string algorithm = ui->comboBox->currentText().toStdString();

    if(algorithm == "Dijkstra")
    {
        ui->endPointCombo->show();
        ui->endPoint->show();
    }
    else
    {
        ui->endPointCombo->hide();
        ui->endPoint->hide();
    }

    graphDrawer->setAlgorithm(algorithm);
}

void AlgorithmWindow::setStartingVertex()
{

    string algorithm = ui->comboBox->currentText().toStdString();
    string startingVertex = ui->startPointCombo->currentText().toStdString();
    string endingVertex = ui->endPointCombo->currentText().toStdString();
    if (startingVertex.size() == 0)return;

    graphDrawer->setStartingVertex(startingVertex);
    if(algorithm == "Dijkstra")
    {
        graphDrawer->setEndingVertex(endingVertex);
    }
    graphDrawer->setAlgorithm(algorithm);
}

void AlgorithmWindow::setEndingVertex()
{

    string algorithm = ui->comboBox->currentText().toStdString();
    string startingVertex = ui->startPointCombo->currentText().toStdString();
    string endingVertex = ui->endPointCombo->currentText().toStdString();
    if (startingVertex.size() == 0)return;

    graphDrawer->setStartingVertex(startingVertex);
    if(algorithm == "Dijkstra")
    {
        graphDrawer->setEndingVertex(endingVertex);
    }
    graphDrawer->setAlgorithm(algorithm);
}

void AlgorithmWindow::setStartPointCombo()
{
    ui->startPointCombo->clear();
    ui->endPointCombo->clear();

    for(auto i = graph->adjacencyList.begin();i != graph->adjacencyList.end();i++)
    {
        QString item = QString::fromStdString(i->first);

        ui->startPointCombo->addItem(item);
        ui->endPointCombo->addItem(item);
    }

    string algorithm = ui->comboBox->currentText().toStdString();
    string startingvertex = graph->adjacencyList.begin()->first;

    if(graph->adjacencyList.size() > 1)
    {
        string endingVertex = (++graph->adjacencyList.begin())->first;
        graphDrawer->setEndingVertex(endingVertex);
        ui->endPointCombo->setCurrentIndex(1);
    }

    graphDrawer->setStartingVertex(startingvertex);
    graphDrawer->setAlgorithm(algorithm);

    graphDrawer->update();
}

AlgorithmWindow::~AlgorithmWindow()
{
    delete ui;
    delete xyPlaneDrawer;
    delete timer;
}
