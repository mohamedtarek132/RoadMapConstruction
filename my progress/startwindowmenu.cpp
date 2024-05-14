#include "startwindowmenu.h"
#include "./ui_mainwindow.h"
#include"editgraph.h"
#include<QMessageBox>
#include<QRegularExpressionValidator>
#include<QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QRegularExpression regex("[^\\s]*"); // Regular expression to match any string without whitespaces
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);

    ui->setupUi(this);
    ui->lineEdit->setFocus();
    ui->errorlabel->setVisible(false);
    ui->lineEdit->setValidator(validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_addButton_clicked()
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


void MainWindow::on_displayButton_clicked()
{

}


void MainWindow::on_editButton_clicked()
{

    QListWidgetItem *item = ui->graphList->currentItem();
    if(item != NULL)
    {
        QString  key = item->text();
        EditGraph *editgraph = new EditGraph();
        editgraph->setData(key);
        editgraph->exec();
    }




}


void MainWindow::on_deleteButton_clicked()
{
    QListWidgetItem *item = ui->graphList->takeItem(ui->graphList->currentRow());
    delete item;

}


void MainWindow::on_exitButton_clicked()
{
    QCoreApplication::quit();
}






