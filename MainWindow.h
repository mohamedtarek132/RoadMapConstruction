#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QTimer>
#include "ui_MainWindow.h"
#include "AlgorithmWindow.h"
#include "GraphWindow.h"
#include "startwindowmenu.h"

namespace Ui {
class MainWindow2;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *);
    ~MainWindow();
public slots:
    void returnToPreviousWindow();
    void goToNextWindow();
    void saveGraph();
private:
    Ui::MainWindow2 *ui;
    QStackedWidget *stackedWidget;
    QTimer *timer;
    Graph *graph;
    HomeWindow *homeWindow;
    AlgorithmWindow *algorithmWindow;
    GraphWindow *graphWindow;
};

#endif // MAINWINDOW_H
