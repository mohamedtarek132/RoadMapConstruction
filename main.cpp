#include "AlgorithmWindow.h"
#include "MainWindow.h"

#include <QApplication>
#include <QObject>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.move(200, 50);
    w.show();
    QObject::connect(&a, SIGNAL(aboutToQuit()), &w, SLOT(saveGraphs()));
    return a.exec();
}
