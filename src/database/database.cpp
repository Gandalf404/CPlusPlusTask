#include "../../include/database/database.h"

bool Database::connect()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("point.db");
    if (!db.open())
    {
        QMessageBox::critical(nullptr, "Ошибка", "Произошла ошибка во время подключения к базе данных");
        qDebug() << db.lastError().text();
        return false;
    }
    query = QSqlQuery("CREATE TABLE IF NOT EXISTS point_position ("
                      "point_id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "point_action TEXT,"
                      "point_action_time DATETIME)");
    if (!query.exec())
    {
        QMessageBox::critical(nullptr, "Ошибка", "Произошла ошибка во время создания таблицы");
        qDebug() << db.lastError().text();
        return false;
    }
    return true;
}
