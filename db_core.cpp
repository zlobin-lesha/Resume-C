#include "db_core.h"

db_core * db_core::m_p = nullptr;


db_core::db_core()
{

}

 /* bool db_core::restoreDataBase()
{
    if(this->openDataBase()){
        if(!this->createTable()){
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "failed to restore database";
        return false;
    }
    return false;
} */

bool db_core::ConnectToDB(const char *szName)
{
    if(db.isOpen())
    {
        qDebug() << "Database alredy init!!";
        return true;
    }

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/SVN/Program" "printing_house"); // правильно ли я обратился к файлу?

    if(!db.open())
    {
        qDebug() << __LINE__ << "Database init >> falied";
        return false;
    }
    qDebug() << __LINE__ << "Database init >> success";
    return true;
}

void db_core::closeDataBase(const char *szName)
{
    db.close();
}

bool db_core::IsTableExist(const char *szName)
{
    QSqlQuery qry(QString ("SELECT * FROM sqlite_master where type = 'table' AND name = 'tbl_test';"));

    if (!qry.exec())
    {
        qDebug() << __LINE__ << "Unexpected error!";
        return false;
    }
    if (!qry.next())
    {
        return false;
    }
    return true;
}
