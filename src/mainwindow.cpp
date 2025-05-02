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
    delete painter;
}

void MainWindow::paintEvent(QPaintEvent*)
{
    painter = new QPainter(this);
    painter->setPen(QPen(Qt::red, 10));
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawPoint(point);
}

void MainWindow::pointStart()
{
    timer->start(5000);
    insertAction("Start");
}

void MainWindow::pointStop()
{
    timer->stop();
    insertAction("Stop");
}

void MainWindow::movePoint()
{
    point.setX(QRandomGenerator::global()->bounded(width() / 2, width()));
    point.setY(QRandomGenerator::global()->bounded(height() / 2, height()));
    update();
}

void MainWindow::insertAction(const QString& action)
{
    query = QSqlQuery();
    query.prepare("INSERT INTO point_position (point_action, point_action_time) VALUES (?, ?)");
    query.addBindValue(action);
    query.addBindValue(QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm"));
    if (!query.exec())
    {
        QMessageBox::critical(nullptr, "Ошибка", "Произошла ошибка во время добавления записи в таблицу");
        qDebug() << query.lastError().text();
    }
}
