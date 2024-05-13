#ifndef STARTWINDOWMENU_H
#define STARTWINDOWMENU_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class HomeWindow;
}
QT_END_NAMESPACE

class HomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    HomeWindow(QWidget *parent = nullptr);
    ~HomeWindow();

private slots:


    void on_addButton_clicked();

    void on_editButton_clicked();

    void on_deleteButton_clicked();

    void on_exitButton_clicked();


    void on_displayButton_clicked();

private:
    Ui::HomeWindow *ui;
};
#endif // STARTWINDOWMENU_H
