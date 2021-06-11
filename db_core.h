#ifndef DB_CORE_H
#define DB_CORE_H
#include <QtSql>


class db_core
{
public:
    static db_core *Instance()
    {
        if (!m_p)
            m_p = new db_core;
        return m_p;
    };
    db_core();

    QSqlDatabase GetDB() { return db; }

private:
    static db_core *m_p;
    QSqlDatabase db;

public:
    bool ConnectToDB(const char *szName);
    bool IsTableExist(const char *szName);

private:
    bool restoreDataBase(const char *szName);
    void closeDataBase(const char *szName);
};

#endif // DB_CORE_H
