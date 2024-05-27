#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QTimer>
#include "ui_MainWindow.h"
#include "AlgorithmWindow.h"
#include "GraphWindow.h"
#include "HomeWindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void loadGraphs();
    ~MainWindow();

public slots:
    void returnToPreviousWindow();
    void goToNextWindow();
    void saveGraph();
    void saveGraphs();

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
    QTimer *timer;
    Graph *graph;
    HomeWindow *homeWindow;
    AlgorithmWindow *algorithmWindow;
    GraphWindow *graphWindow;
    unordered_map<string,Graph*> graphs;

};

#endif // MAINWINDOW_H
