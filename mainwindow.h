#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <vector>
#include <queue>
#include "graph.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class Line : public QWidget
{
    Q_OBJECT
public:
    int x1, x2, y1, y2;
    std::queue<Edge> edges;
    Graph g;
    Line(QWidget *parent, int X1=0, int Y1=0, int X2=200, int Y2=200);
    Line(QWidget *parent,  std::queue<Edge> Edges, Graph G);
    void paintEvent(QPaintEvent*);
};


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    // void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent *);
    ~MainWindow();

private:
    Line *l;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
