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
    string endingVertex;

    GraphDrawer(QWidget *parent,   Graph *graph, int xOffset, int yOffset, bool dynamic);
    void paintEvent(QPaintEvent*);
    void setAlgorithm(string);
    void setStartingVertex(string);
    void setEndingVertex(string);
    void unconnectedGraph();

    public slots:
    void callPaintEvent();
    void setToDynamic();
    void setToStatic();
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
    void setAlgorithm();
    void setStartingVertex();
    void setStartPointCombo();
    void setEndingVertex();

private:
    GraphDrawer *graphDrawer;
    QTimer *timer;
    Graph *graph;
    XYPlaneDrawer *xyPlaneDrawer;
};

#endif // ALGORITHMWINDOW_H
