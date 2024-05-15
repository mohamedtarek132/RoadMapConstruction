#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "AlgorithmWindow.h"
#include "GraphWindow.h"
#include "HomeWindow.h"
#include "Graph.h"
#include <QStackedWidget>
#include <QTimer>
#include <iostream>
#include <fstream>
#include <ostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadGraphs();

    graph = new Graph();

    homeWindow = new HomeWindow(graphs);

    algorithmWindow = new AlgorithmWindow(graph);

    graphWindow = new GraphWindow(graph);

    stackedWidget = new QStackedWidget(this);

    stackedWidget->addWidget(homeWindow);
    stackedWidget->addWidget(graphWindow);
    stackedWidget->addWidget(algorithmWindow);

    this->setCentralWidget(stackedWidget);

    connect(algorithmWindow, &AlgorithmWindow::backButtonPressed, this, &MainWindow::returnToPreviousWindow);
    connect(graphWindow, &GraphWindow::algorithmsButtonPressed, this, &MainWindow::goToNextWindow);
    connect(graphWindow, &GraphWindow::homeButtonPressed, this, &MainWindow::returnToPreviousWindow);
    connect(graphWindow, &GraphWindow::homeButtonPressed, this, &MainWindow::saveGraph);
    connect(homeWindow,&HomeWindow::setGraph,graphWindow,&GraphWindow::setGraph);
    connect(homeWindow,&HomeWindow::setGraph,this,&MainWindow::goToNextWindow);
    connect(graphWindow, &GraphWindow::algorithmsButtonPressed, algorithmWindow, &AlgorithmWindow::setStartPointCombo);
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

void MainWindow::returnToPreviousWindow()
{
    int index = this->stackedWidget->currentIndex() - 1;

    this->stackedWidget->setCurrentIndex(index);
}

void MainWindow::goToNextWindow()
{

    int index = this->stackedWidget->currentIndex() + 1;

    this->stackedWidget->setCurrentIndex(index);
}

void MainWindow::saveGraph()
{
    *homeWindow->graphs[graphWindow->graphName] = *(graphWindow->graph);
}

void MainWindow::loadGraphs()
{
    ifstream file("C:\\Users\\hp\\Documents\\Programming projects\\C++ Projects\\RoadMapConstruction2\\RoadMapConstruction\\graphs.txt");

    while(!file.eof())
    {
        string graphName;

        std::getline(file, graphName);
        if (graphName.size() == 0)
        {
            break;
        }
        graphs[graphName] = new Graph();

        string numberOfVerticies;
        getline(file, numberOfVerticies);

        for (int i = 0; i < stoi(numberOfVerticies); i++)
        {
            string vertexName;
            string xPosition;
            string yPosition;

            getline(file, vertexName, '|');
            getline(file, xPosition, '|');
            getline(file, yPosition);

            graphs[graphName]->insertVertex(vertexName, stoi(xPosition), stoi(yPosition));
        }

        string numberOfEdges;
        getline(file, numberOfEdges);

        for(int i = 0; i < stoi(numberOfEdges); i++)
        {
            string vertex1Name;
            string vertex2Name;
            string edgeLength;

            getline(file, vertex1Name, '|');
            getline(file, vertex2Name, '|');
            getline(file, edgeLength);

            graphs[graphName]->insertEdge(vertex1Name, vertex2Name, stoi(edgeLength));
        }
    }
    file.close();
}

void MainWindow::saveGraphs()
{
    ofstream file("C:\\Users\\hp\\Documents\\Programming projects\\C++ Projects\\RoadMapConstruction2\\RoadMapConstruction\\graphs.txt");

    graphs = homeWindow->graphs;

    for(auto it = graphs.begin(); it != graphs.end(); it++)
    {
        file << it->first << '\n';

        Graph graph = *it->second;

        file << graph.positions.size() << '\n';

        for(auto it2 = graph.positions.begin(); it2 != graph.positions.end(); it2++)
        {
            file << it2->first << '|' << it2->second.first << '|' << it2->second.second << '\n';
        }

        queue<Edge> edges = graph.unconnectedTraversal();

        file << edges.size() << '\n';

        while(!edges.empty())
        {
            Edge edge = edges.front();
            file << edge.getVertex1() << '|' << edge.getVertex2() << '|' << edge.length << '\n';
            edges.pop();
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

