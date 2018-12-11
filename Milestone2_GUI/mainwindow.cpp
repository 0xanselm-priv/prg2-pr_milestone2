#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <iostream>

int canvas_width = 0;
int canvas_height = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->canvas_label->setFrameShape(QFrame::Box);
    canvas_width = ui->canvas_label->width();
    canvas_width = ui->canvas_label->height();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    QString x_str = QString::number(ev->x());
    QString y_str = QString::number(ev->y());
    ui->coord_label->setText("X: " + x_str + " Y: " + y_str);
    ui->coord_label->adjustSize();

    int width = ui->canvas_label->width();
    int height = ui->canvas_label->height();

    QPixmap pixmap(width, height);
    pixmap.fill(QColor("transparent"));
    QPainter painter (&pixmap);
    painter.setBrush(Qt::red);
    painter.drawRect(x_str.toInt(), y_str.toInt(), 5,5);

    ui->canvas_label->setPixmap(pixmap);

    std::cout << canvas_width << endl;
}
