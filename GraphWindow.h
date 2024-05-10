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

private:
    Ui::GraphWindow *ui;
    Graph *graph;
    DynamicGraphDrawer *dynamicGraphDrawer;
    QTimer *timer;
    StaticGraphDrawer *staticGraphDrawer;
};

#endif // GRAPHWINDOW_H
