#include "../include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = Database();
    db.connect();
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::movePoint);
    connect(ui->startPushButton, &QPushButton::clicked, this, &MainWindow::pointStart);
    connect(ui->stopPushButton, &QPushButton::clicked, this, &MainWindow::pointStop);
    point = QPoint(width() / 2, height() / 2);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

void MainWindow::insertAction(const QString& action)
{
    query = QSqlQuery();
    query.prepare("INSERT INTO point_position (point_action, point_action_time) VALUES (?, ?)");
    query.addBindValue(action);
    query.addBindValue(QDateTime::currentDateTime());
    if (!query.exec())
    {
        QMessageBox::critical(nullptr, "Ошибка", "Произошла ошибка во время добавления записи в таблицу");
    }
}

void MainWindow::pointStart()
{
    timer->start(50);
    insertAction("Start");
}

void MainWindow::pointStop()
{
    timer->stop();
    insertAction("Stop");
}

void MainWindow::movePoint()
{
    point.setX(QRandomGenerator::global()->bounded(2000));
    point.setY(QRandomGenerator::global()->bounded(2000));
    if (point.x() <= 0 || point.x() >= width()) {
        point.setX(-point.x());
    }
    if (point.y() <= 0 || point.y() >= height()) {
        point.setY(-point.y());
    }
}
