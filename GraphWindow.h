#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QMainWindow>
#include "Graph.h"
#include "AlgorithmWindow.h"

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphWindow(Graph *graph = nullptr, QWidget *parent = nullptr);
    ~GraphWindow();
    void mousePressEvent(QMouseEvent *);
    void setGraph(Graph*);
signals:
    void homeButtonPressed();
    void algorithmsButtonPressed();
public slots:
    void addVertex();
    void deleteVertex();
    void addEdge();
    void deleteEdge();
    void editCombobox();

private:
    Ui::GraphWindow *ui;
    Graph *graph;
    QTimer *timer;
    GraphDrawer *staticGraphDrawer;
    XYPlaneDrawer *xyPlaneDrawer;
};

#endif // GRAPHWINDOW_H
