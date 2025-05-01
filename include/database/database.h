#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>

class Database
{
private:
    QSqlDatabase db;
    QSqlQuery query;
public:
    bool connect();
};
#endif //DATABASE_H
