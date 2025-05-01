#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database/database.h"
#include <QTimer>
#include <QPoint>
#include <QSqlQuery>
#include <QDateTime>
#include <QMessageBox>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void pointStart();

    void pointStop();

    void movePoint();

    void insertAction(const QString& action);

private:
    Ui::MainWindow *ui;
    Database db;
    QTimer* timer;
    QPoint point;
    QSqlQuery query;
};
#endif // MAINWINDOW_H
