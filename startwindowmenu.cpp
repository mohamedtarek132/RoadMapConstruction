#include "startwindowmenu.h"
#include "./ui_startwindowmenu.h"
// #include"editgraph.h"
#include<QMessageBox>
#include<QRegularExpressionValidator>
#include<QString>

HomeWindow::HomeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomeWindow)
{
    QRegularExpression regex("[^\\s]*"); // Regular expression to match any string without whitespaces
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);

    ui->setupUi(this);
    ui->lineEdit->setFocus();
    ui->errorlabel->setVisible(false);
    ui->lineEdit->setValidator(validator);
}

HomeWindow::~HomeWindow()
{
    delete ui;
}



void HomeWindow::on_addButton_clicked()
{
     ui->errorlabel->setVisible(false);

    if(!ui->lineEdit->text().isEmpty())
    {
        QListWidgetItem *item = new QListWidgetItem(ui->lineEdit->text(),ui->graphList);
        ui->graphList->addItem(item);
        ui->lineEdit->clear();
        ui->lineEdit->setFocus();
    }
    else
    {
        ui->errorlabel->setVisible(true);
    }


}


void HomeWindow::on_displayButton_clicked()
{

}


void HomeWindow::on_editButton_clicked()
{

    QListWidgetItem *item = ui->graphList->currentItem();
    // if(item != NULL)
    // {
    //     QString  key = item->text();
    //     EditGraph *editgraph = new EditGraph();
    //     editgraph->setData(key);
    //     editgraph->exec();
    // }




}


void HomeWindow::on_deleteButton_clicked()
{
    QListWidgetItem *item = ui->graphList->takeItem(ui->graphList->currentRow());
    delete item;

}


void HomeWindow::on_exitButton_clicked()
{
    QCoreApplication::quit();
}






