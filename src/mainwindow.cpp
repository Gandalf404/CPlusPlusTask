#include "../include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::movePoint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pointStart()
{

}

void MainWindow::pointStop()
{

}

void MainWindow::movePoint()
{

}
