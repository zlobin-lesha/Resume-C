#include "mainwindow.h"

#include <QApplication>
#include <QtSql>
#include <QDebug>
#include <QTableView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    db_core::Instance()->ConnectToDB("test");


        QTableView view;
        QSqlTableModel model;

        return 0;

    return a.exec();
}
