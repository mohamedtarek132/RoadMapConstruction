#include "HomeWindow.h"
#include "./ui_HomeWindow.h"

// #include"editgraph.h"
#include<QMessageBox>
#include<QRegularExpressionValidator>
#include<QString>
#include<unordered_map>


HomeWindow::HomeWindow(unordered_map<string,Graph*> graphs, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomeWindow)
    , graphs(graphs)
{
    QRegularExpression regex("[^\\s]*"); // Regular expression to match any string without whitespaces
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);

    ui->setupUi(this);
    ui->lineEdit->setFocus();
    ui->errorlabel->setVisible(false);
    ui->lineEdit->setValidator(validator);

    for(auto it = graphs.begin(); it != graphs.end(); it++)
    {
        cout << it->first;
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(it->first),ui->graphList);

        ui->graphList->addItem(item);
    }
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

        graphs[item->text().toStdString()] = new Graph();
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
    string graphName = ui->graphList->currentItem()->text().toStdString();

    emit setGraph(graphs[graphName], graphName);
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

HomeWindow::~HomeWindow()
{
    delete ui;
}





