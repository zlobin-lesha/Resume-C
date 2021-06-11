#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui (new Ui::MainWindow)
{
    ui->setupUi(this);
    db = new QSqlDatabase();
    db->addDatabase("SQLITE");

    this->createUI();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupModel(const QString &tableName, const QStringList &headers)
{
    model = new QSqlTableModel(this);
    model->setTable(tableName);

}

void MainWindow::createUI()
{
    ui->tableView->setModel(model);
 // .....
    model->select();
}
