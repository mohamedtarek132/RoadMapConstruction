#ifndef ALGORITHMWINDOW_H
#define ALGORITHMWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <vector>
#include <queue>
#include "Graph.h"
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui {
class AlgorithmWindow;
}
QT_END_NAMESPACE

class StaticGraphDrawer : public QWidget
{
    Q_OBJECT
public:
    int x1, x2, y1, y2;
    std::queue<Edge> edges;
    Graph graph;
    StaticGraphDrawer(QWidget *parent, int X1=0, int Y1=0, int X2=200, int Y2=200);
    StaticGraphDrawer(QWidget *parent,  std::queue<Edge> Edges, Graph G);
    void paintEvent(QPaintEvent*);
};

class DynamicGraphDrawer : public QWidget
{
    Q_OBJECT
public:
    int x1, x2, y1, y2;
    std::queue<Edge> edges;
    Graph graph;
    DynamicGraphDrawer(QWidget *parent, int X1=0, int Y1=0, int X2=200, int Y2=200);
    DynamicGraphDrawer(QWidget *parent,  std::queue<Edge> Edges, Graph G);
    void paintEvent(QPaintEvent*);
public slots:
    void callPaintEvent();
};

class AlgorithmWindow : public QMainWindow
{
    Q_OBJECT
public:
    AlgorithmWindow(Graph *graph = nullptr, QWidget *parent = nullptr );
    // void paintEvent(QPaintEvent*);
    ~AlgorithmWindow();
    void mousePressEvent(QMouseEvent *);
signals:
    void mousePressed();
private:
    StaticGraphDrawer *staticGraphDrawer;
    DynamicGraphDrawer *dynamicGraphDrawer;
    Ui::AlgorithmWindow *ui;
    QTimer *timer;
    Graph *graph;
};

#endif // ALGORITHMWINDOW_H
