#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QTimer>

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
    void changeWindows();
private:
    Ui::MainWindow2 *ui;
    QStackedWidget *stackedWidget;
    QTimer *timer;
};

#endif // MAINWINDOW_H
