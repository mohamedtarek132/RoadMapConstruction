#ifndef ALGORITHMWINDOW_H
#define ALGORITHMWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <vector>
#include <queue>
#include "Graph.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class AlgorithmWindow;
}
QT_END_NAMESPACE

class GraphDrawer : public QWidget
{
    Q_OBJECT
public:
    int x1, x2, y1, y2;
    std::queue<Edge> edges;
    Graph graph;
    GraphDrawer(QWidget *parent, int X1=0, int Y1=0, int X2=200, int Y2=200);
    GraphDrawer(QWidget *parent,  std::queue<Edge> Edges, Graph G);
    void paintEvent(QPaintEvent*);
};


class AlgorithmWindow : public QMainWindow
{
    Q_OBJECT
public:
    AlgorithmWindow(QWidget *parent = nullptr);
    // void paintEvent(QPaintEvent*);
    ~AlgorithmWindow();
    void mousePressEvent(QMouseEvent *);
signals:
    void mousePressed();
private:
    GraphDrawer *graphDrawer;
    Ui::AlgorithmWindow *ui;
};

#endif // ALGORITHMWINDOW_H
