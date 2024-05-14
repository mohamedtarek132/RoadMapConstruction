#ifndef ALGORITHMWINDOW_H
#define ALGORITHMWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <vector>
#include <queue>
#include "Graph.h"
#include <QTimer>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui {
class AlgorithmWindow;
}
QT_END_NAMESPACE

class XYPlaneDrawer : public QWidget
{
    Q_OBJECT
public:
    int xOffset;
    int yOffset;
    int size;
    int width;
    int height;

    XYPlaneDrawer(QWidget *parent, int size, int xOffset, int yOffset, int width, int height);
    void paintEvent(QPaintEvent*);
};



class GraphDrawer : public QWidget
{
    Q_OBJECT
public:
    int x1, x2, y1, y2;
    std::queue<Edge> edges;
    Graph *graph;
    int xOffset;
    int yOffset;
    bool dynamic;
    string startingVertex;

    GraphDrawer(QWidget *parent,  string startingVertex, Graph *graph, int xOffset, int yOffset, bool dynamic);
    void paintEvent(QPaintEvent*);
    void changeAlgorithm(string);
    void changeStartingVertex(string, string);
    void unconnectedGraph();

    public slots:
    void callPaintEvent();
    void changeToDynamic();
    void changeToStatic();
};


class AlgorithmWindow : public QMainWindow
{
    Q_OBJECT
public:
    Ui::AlgorithmWindow *ui;

    AlgorithmWindow(Graph *graph = nullptr, QWidget *parent = nullptr);
    // void paintEvent(QPaintEvent*);
    ~AlgorithmWindow();
    void mousePressEvent(QMouseEvent *);

signals:
    void backButtonPressed();

public slots:
    void changeAlgorithm();
    void changeStartingVertex();

private:
    GraphDrawer *graphDrawer;
    QTimer *timer;
    Graph *graph;
    XYPlaneDrawer *xyPlaneDrawer;
};

#endif // ALGORITHMWINDOW_H
