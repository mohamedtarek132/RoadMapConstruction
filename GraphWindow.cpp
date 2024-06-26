#include "GraphWindow.h"
#include "ui_GraphWindow.h"
#include "AlgorithmWindow.h"
#include <QPoint>
#include <string>
#include <iostream>

using namespace std;

GraphWindow::GraphWindow(Graph *graph1, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GraphWindow)
    , graph(graph1)
{
    ui->setupUi(this);

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
    // staticGraphDrawer->unconnectedGraph();
    // staticGraphDrawer->setStartingVertex(graph->adjacencyList.begin()->first);
    // staticGraphDrawer->setAlgorithm("DFS");


    timer = new QTimer(this);

    connect(ui->homeButton, &QPushButton::clicked, this, &GraphWindow::homeButtonPressed);

    connect(ui->addVertexButton, &QPushButton::clicked, this, &GraphWindow::addVertex);
    connect(ui->deleteVertexButton, &QPushButton::clicked, this, &GraphWindow::deleteVertex);

    connect(ui->addEdgeButton, &QPushButton::clicked, this, &GraphWindow::addEdge);
    connect(ui->deleteEdgeButton, &QPushButton::clicked, this, &GraphWindow::deleteEdge);

    connect(ui->algorithmsButton, &QPushButton::clicked, this, &GraphWindow::checkConnectivity);

    connect(ui->addEdgeV1Combo, &QComboBox::currentTextChanged, this, &GraphWindow::editAddCombobox);
    connect(ui->addEdgeV2Combo, &QComboBox::currentTextChanged, this, &GraphWindow::editAddCombobox);
    connect(ui->deleteEdgeV1Combo, &QComboBox::currentTextChanged, this, &GraphWindow::editDeleteCombobox);
    connect(ui->deleteEdgeV2Combo, &QComboBox::currentTextChanged, this, &GraphWindow::editDeleteCombobox);

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

    if (point.x() > x1 && point.x() < x2 &&
        point.y() > y1 && point.y() < y2)
    {
        ui->xPosition->setText(xPos);
        ui->yPosition->setText(yPos);
    }
}

void GraphWindow::addVertex()
{
    string name = ui->vertexName->text().toStdString();
    string xPos = ui->xPosition->text().toStdString();
    string yPos = ui->yPosition->text().toStdString();

    if (!xPos.size() || !yPos.size())
    {
        ui->invalidPositionTypeError->show();
        QTimer::singleShot(3000, ui->invalidPositionTypeError, &QLabel::hide);
        return;
    }

    for (int i=0; i<xPos.size(); i++)
    {
        if (int(xPos[i])<48 || int(xPos[i])>57)
        {
            ui->invalidPositionTypeError->show();
            QTimer::singleShot(3000, ui->invalidPositionTypeError, &QLabel::hide);
            return;
        }
    }
    for (int i=0; i<yPos.size(); i++)
    {
        if (int(yPos[i])<48 || int(yPos[i])>57)
        {
            ui->invalidPositionTypeError->show();
            QTimer::singleShot(3000, ui->invalidPositionTypeError, &QLabel::hide);
            return;
        }
    }
    if (name.empty())
    {
        ui->nameEmptyError->show();
        QTimer::singleShot(3000, ui->nameEmptyError, &QLabel::hide);
        return;
    }

    int x = stoi(xPos),
        y = stoi(yPos);

    QString Name = QString::fromStdString(name);

    if ((x < 0) || (x > 740)|| (y < 0)|| (y > 430))
    {
        ui->outOfBoundsError->show();
        QTimer::singleShot(3000, ui->outOfBoundsError, &QLabel::hide);
        return;
    }

    for (auto it = graph->positions.begin(); it != graph->positions.end(); it++)
    {
        int vX = it->second.first;
        int vY = it->second.second;
        if (pow((x-vX),2) + pow((y-vY),2) <= 36)
        {
            ui->samePositionError->show();
            QTimer::singleShot(3000, ui->samePositionError, &QLabel::hide);
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
        staticGraphDrawer->setStartingVertex(graph->adjacencyList.begin()->first);
        staticGraphDrawer->setAlgorithm("DFS");
    }

    staticGraphDrawer->unconnectedGraph();
    staticGraphDrawer->update();
}

void GraphWindow::deleteVertex()
{
    string name = ui->deleteVertexCombo->currentText().toStdString();

    //if (name.empty())return;

    int index = ui->addEdgeV2Combo->findText(QString::fromStdString(name));
    ui->addEdgeV2Combo->removeItem(index);

    editAddCombobox();

    index = ui->addEdgeV1Combo->findText(QString::fromStdString(name));
    ui->addEdgeV1Combo->removeItem(index);

    editAddCombobox();

    index = ui->deleteEdgeV1Combo->findText(QString::fromStdString(name));
    ui->deleteEdgeV1Combo->removeItem(index);

    editDeleteCombobox();

    index = ui->deleteEdgeV2Combo->findText(QString::fromStdString(name));
    ui->deleteEdgeV2Combo->removeItem(index);

    editDeleteCombobox();

    index = ui->deleteVertexCombo->findText(QString::fromStdString(name));
    ui->deleteVertexCombo->removeItem(index);

    graph->deleteVertex(name);

    staticGraphDrawer->unconnectedGraph();

    staticGraphDrawer->update();

}

void GraphWindow::addEdge()
{
    string vertex1 = ui->addEdgeV1Combo->currentText().toStdString(),
           vertex2 = ui->addEdgeV2Combo->currentText().toStdString();
    string strLength = ui->edgeLength->text().toStdString();

    if (!strLength.size())
    {
        ui->invalidLengthTypeError->show();
        QTimer::singleShot(3000, ui->invalidLengthTypeError, &QLabel::hide);
        return;
    }

    for (int i=0; i<strLength.size(); i++)
    {
        if (int(strLength[i])<48 || int(strLength[i])>57)
        {
            ui->invalidLengthTypeError->show();
            QTimer::singleShot(3000, ui->invalidLengthTypeError, &QLabel::hide);
            return;
        }
    }
    //if (vertex1.empty() || vertex2.empty())return;
    if (vertex1 == vertex2)
    {
        ui->sameVerticesAddError->show();
        QTimer::singleShot(3000, ui->sameVerticesAddError, &QLabel::hide);
        return;
    }

    for (auto i = graph->adjacencyList[vertex1].begin(); i != graph->adjacencyList[vertex1].end(); i++)
    {
        if (i->getVertex2() == vertex2)
        {
            ui->alreadyExistsError->show();
            QTimer::singleShot(3000, ui->alreadyExistsError, &QLabel::hide);
            return;
        }
    }

    double length = stod(strLength);

    graph->insertEdge(vertex1, vertex2, length);

    staticGraphDrawer->unconnectedGraph();

    staticGraphDrawer->update();
}

void GraphWindow::deleteEdge()
{
    string vertex1 = ui->deleteEdgeV1Combo->currentText().toStdString(),
           vertex2 = ui->deleteEdgeV2Combo->currentText().toStdString();

    //if (vertex1.empty() || vertex2.empty())return;
    if (vertex1 == vertex2)
    {
        ui->sameVerticesDeleteError->show();
        QTimer::singleShot(3000, ui->sameVerticesDeleteError, &QLabel::hide);
        return;
    }

    bool exists = false;
    for (auto i = graph->adjacencyList[vertex1].begin(); i != graph->adjacencyList[vertex1].end(); i++)
    {
        if (i->getVertex2() == vertex2)
        {
            exists = true;
        }
    }
    if (!exists)
    {
        ui->doesntExistError->show();
        QTimer::singleShot(3000, ui->doesntExistError, &QLabel::hide);
        return;
    }


    graph->deleteEdge(vertex1, vertex2);

    staticGraphDrawer->unconnectedGraph();

    staticGraphDrawer->update();
}

void GraphWindow::editAddCombobox()
{
    int verticesNumber = graph->adjacencyList.size();
    if (verticesNumber == 0)return;
    if (ui->addEdgeV1Combo->currentText() == ui->addEdgeV2Combo->currentText())
    {
        int newIndex = (ui->addEdgeV2Combo->currentIndex() + 1) % verticesNumber;
        ui->addEdgeV2Combo->setCurrentIndex(newIndex);
    }
}

void GraphWindow::editDeleteCombobox()
{
    int verticesNumber = graph->adjacencyList.size();
    if (verticesNumber == 0)return;
    if (ui->deleteEdgeV1Combo->currentText() == ui->deleteEdgeV2Combo->currentText())
    {
        int newIndex = (ui->deleteEdgeV2Combo->currentIndex() + 1) % verticesNumber;
        ui->deleteEdgeV2Combo->setCurrentIndex(newIndex);
    }
}

void GraphWindow::checkConnectivity()
{
    if (graph->adjacencyList.size()<2)
    {
        ui->algortihmsError->show();
        QTimer::singleShot(3000, ui->algortihmsError, &QLabel::hide);
        return;
    }
    queue<Edge> prims = graph->PrimMinimumSpanningTree(graph->adjacencyList.begin()->first);
    if (prims.size() != graph->adjacencyList.size()-1)
    {
        ui->algortihmsError->show();
        QTimer::singleShot(3000, ui->algortihmsError, &QLabel::hide);
        return;
    }
    emit GraphWindow::algorithmsButtonPressed();
}

void GraphWindow::setGraph(Graph* graph, string graphName)
{
    *this->graph = *graph;
    this->graphName = graphName;
    this->ui->graphNameLabel->setText(QString::fromStdString(graphName));

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
    editAddCombobox();
    editDeleteCombobox();
}

GraphWindow::~GraphWindow()
{
    delete ui;
    delete staticGraphDrawer;
    delete timer;
    delete xyPlaneDrawer;
    delete graph;
}
