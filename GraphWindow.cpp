#include "GraphWindow.h"
#include "ui_GraphWindow.h"
#include "AlgorithmWindow.h"
#include <QPoint>
#include <iostream>

using namespace std;

GraphWindow::GraphWindow(Graph *graph1, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GraphWindow)
    , graph(graph1)
{
    ui->setupUi(this);

//     for (auto i = graph->adjacencyList.begin(); i != graph->adjacencyList.end(); i++)
//     {
//         QString item = QString::fromStdString(i->first);

//     ui->addEdgeV1Combo->addItem(item);
//     ui->addEdgeV2Combo->addItem(item);
//  ui->deleteEdgeV1Combo->addItem(item);
// ui->deleteEdgeV2Combo->addItem(item);
// ui->deleteVertexCombo->addItem(item);
//     }

    //queue<Edge> copiedEdges = graph->DFStraversal("alexandria");

    int xOffset =  ui->frame->x() + ui->frame->lineWidth() * 2;
    int yOffset = ui->frame->y() + ui->frame->lineWidth() * 2;

    int size = 30;
    int width = ui->frame_2->width();
    int height = ui->frame_2->height();

    xyPlaneDrawer = new XYPlaneDrawer(this, size, xOffset, 30, width, height);
    xyPlaneDrawer->resize(width + xOffset, height + 30 );
    xyPlaneDrawer->move(0, yOffset - 30);

     staticGraphDrawer = new GraphDrawer(this, graph,  xOffset, 30, false);
     staticGraphDrawer->resize(width + xOffset, height + 30 );
     staticGraphDrawer->move(0, yOffset - 30);
     staticGraphDrawer->unconnectedGraph();


    timer = new QTimer(this);

    connect(ui->homeButton, &QPushButton::clicked, this, &GraphWindow::homeButtonPressed);
    connect(ui->addVertexButton, &QPushButton::clicked, this, &GraphWindow::addVertex);
    connect(ui->deleteVertexButton, &QPushButton::clicked, this, &GraphWindow::deleteVertex);
    connect(ui->addEdgeButton, &QPushButton::clicked, this, &GraphWindow::addEdge);
    connect(ui->deleteEdgeButton, &QPushButton::clicked, this, &GraphWindow::deleteEdge);
    connect(ui->algorithmsButton, &QPushButton::clicked, this, &GraphWindow::algorithmsButtonPressed);

    connect(timer, &QTimer::timeout, staticGraphDrawer, &GraphDrawer::callPaintEvent);

    timer->start(900);
}

void GraphWindow::mousePressEvent(QMouseEvent *event)
{

    QPoint point = QWidget::mapFromGlobal(QCursor::pos());

    int x1 = ui->frame->x() + 16,
        y1 = ui->frame->y() + 16,
        x2 = x1 + ui->frame->width() - 32,
        y2 = y1 + ui->frame->height() - 32;

    int x = point.x() - x1,
    y = point.y() - y1;

    QString xPos = QString::number(x),
        yPos = QString::number(y);

    if (point.x() > x1 &&
        point.x() < x2 &&
        point.y() > y1 &&
        point.y() < y2)
    {
        ui->xPosition->setText(xPos);
        ui->yPosition->setText(yPos);
    }
}

void GraphWindow::addVertex()
{
    string name = ui->vertexName->text().toStdString();

    int x = ui->xPosition->text().toInt(),
        y = ui->yPosition->text().toInt();


    QString Name = QString::fromStdString(name);

    for (auto it = graph->positions.begin(); it != graph->positions.end(); it++)
    {
        int vX = it->second.first;
        int vY = it->second.second;
        if (pow((x-vX),2) + pow((y-vY),2) <= 36)
        {
            ui->addError->show();
            QTimer::singleShot(3000, ui->addError, &QLabel::hide);
            return;
        }
    }

    if (graph->adjacencyList.find(name) == graph->adjacencyList.end())
    {
        ui->addEdgeV2Combo->addItem(Name);
        ui->addEdgeV1Combo->addItem(Name);
        ui->deleteEdgeV1Combo->addItem(Name);
        ui->deleteEdgeV2Combo->addItem(Name);
        ui->deleteVertexCombo->addItem(Name);
    }



    graph->insertVertex(name, x, y);

    if(graph->adjacencyList.size()==1)
    {
        staticGraphDrawer->changeStartingVertex(graph->adjacencyList.begin()->first,"DFS");
    }
    staticGraphDrawer->unconnectedGraph();
    staticGraphDrawer->update();

    // cout<<"Vertex: \""<<name<<"\" is now added\n";
}

void GraphWindow::deleteVertex()
{
    string name = ui->deleteVertexCombo->currentText().toStdString();

    int index = ui->addEdgeV2Combo->findText(QString::fromStdString(name));

    ui->addEdgeV2Combo->removeItem(index);
    ui->addEdgeV1Combo->removeItem(index);
    ui->deleteEdgeV1Combo->removeItem(index);
    ui->deleteEdgeV2Combo->removeItem(index);
    ui->deleteVertexCombo->removeItem(index);

    graph->deleteVertex(name);
    staticGraphDrawer->unconnectedGraph();
    staticGraphDrawer->update();
}

void GraphWindow::addEdge()
{
    string vertex1 = ui->addEdgeV1Combo->currentText().toStdString(),
        vertex2 = ui->addEdgeV2Combo->currentText().toStdString();

    double length = ui->edgeLength->text().toDouble();

    graph->insertEdge(vertex1, vertex2, length);
    staticGraphDrawer->unconnectedGraph();
    staticGraphDrawer->update();
}

void GraphWindow::deleteEdge()
{
    string vertex1 = ui->deleteEdgeV1Combo->currentText().toStdString(),
        vertex2 = ui->deleteEdgeV2Combo->currentText().toStdString();

    graph->deleteEdge(vertex1, vertex2);
    staticGraphDrawer->unconnectedGraph();
    staticGraphDrawer->update();
}

void GraphWindow::editCombobox()
{
    int addIndex = ui->addEdgeV1Combo->currentIndex();
    ui->addEdgeV2Combo->removeItem(addIndex);
    int deleteIndex = ui->deleteEdgeV1Combo->currentIndex();
    ui->addEdgeV2Combo->removeItem(deleteIndex);
}

GraphWindow::~GraphWindow()
{
    delete ui;
    delete staticGraphDrawer;
    delete timer;
    delete xyPlaneDrawer;
}


void GraphWindow::setGraph(Graph* graph, string graphName)
{
    cout <<"does it gors here";

    *this->graph = *graph;
    this->graphName = graphName;
    this->ui->graphNameLabel->setText(QString::fromStdString(graphName));

    if(!(graph->adjacencyList.empty()))
    {
        staticGraphDrawer->changeStartingVertex(graph->adjacencyList.begin()->first,"DFS");
    }

    staticGraphDrawer->unconnectedGraph();
    staticGraphDrawer->update();

    ui->addEdgeV1Combo->clear();
    ui->addEdgeV2Combo->clear();
    ui->deleteEdgeV1Combo->clear();
    ui->deleteEdgeV2Combo->clear();
    ui->deleteVertexCombo->clear();
    ui->edgeLength->clear();
    ui->vertexName->clear();
    ui->xPosition->clear();
    ui->yPosition->clear();

    for (auto i = graph->adjacencyList.begin(); i != graph->adjacencyList.end(); i++)
    {
        QString item = QString::fromStdString(i->first);

        ui->addEdgeV1Combo->addItem(item);
        ui->addEdgeV2Combo->addItem(item);
        ui->deleteEdgeV1Combo->addItem(item);
        ui->deleteEdgeV2Combo->addItem(item);
        ui->deleteVertexCombo->addItem(item);
    }
}
