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
    Graph *graph;
    string graphName;

    explicit GraphWindow(Graph *graph = nullptr, QWidget *parent = nullptr);
    ~GraphWindow();
    void mousePressEvent(QMouseEvent *);
    void setGraph(Graph*, string);
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
    QTimer *timer;
    GraphDrawer *staticGraphDrawer;
    XYPlaneDrawer *xyPlaneDrawer;
    Ui::GraphWindow *ui;
};

#endif // GRAPHWINDOW_H
