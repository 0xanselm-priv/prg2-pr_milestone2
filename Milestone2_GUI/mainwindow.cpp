#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <iostream>

#include <vector>
#include <tuple>

int canvas_width;
int canvas_height;

auto cv_ratio_value = 0.0;
auto eta_goal_value = 0.0;
auto iter_max_value = 0;
auto alpha_value = 0.0;
auto beta_value = 0.0;
auto k_value = 0.0;
auto radius_value = 0.0;

int city_counter_value = 0;
typedef std::vector< std::tuple<float, float> > cities_type;
cities_type cities_list;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Elastic Net");

    ui->canvas_label->setFrameShape(QFrame::Box);
    canvas_width = ui->canvas_label->width();
    canvas_height = ui->canvas_label->height();

    //value definitions
    ui->cv_ratio->setMinimum(0.01);
    ui->cv_ratio->setMaximum(50.0);
    ui->eta_goal->setMinimum(0.01);
    ui->eta_goal->setMaximum(50.0);
    ui->iter_max->setMinimum(1);
    ui->iter_max->setMaximum(50);
    ui->alpha->setMinimum(0.01);
    ui->alpha->setMaximum(50.0);
    ui->beta->setMinimum(0.01);
    ui->beta->setMaximum(50.0);
    ui->k->setMinimum(0.01);
    ui->k->setMaximum(50.0);
    ui->radius->setMinimum(1.0);
    ui->radius->setMaximum(50.0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::log_append(QString to_append) {
    QString new_line = "\n";
    ui->log_label->setText( to_append + new_line + ui->log_label->text());
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    city_counter_value++;
    ui->city_counter->setText("City Counter: " + QString::number(city_counter_value));

    int x = ev->x();
    int y = ev->y();

    //Printing the x,y coords on label
    QString x_str = QString::number(x);
    QString y_str = QString::number(y);

    ui->coord_label->setText("X: " + x_str + " Y: " + y_str);
    ui->coord_label->adjustSize();

    //pushing the cities in cities list
    cities_list.push_back(std::tuple<float, float>(float(x),float(y)));

    QPixmap pixmap(canvas_width, canvas_height);
    pixmap.fill(QColor("transparent"));
    QPainter painter (&pixmap);

    for (int i = 0; i < cities_list.size(); ++i) {
        int x_coord = static_cast<int>(std::get<0>(cities_list[i]));
        int y_coord = static_cast<int>(std::get<1>(cities_list[i]));
        painter.setBrush(Qt::red);
        painter.drawRect(x_coord, y_coord, 5, 5);
    }

    ui->canvas_label->setPixmap(pixmap);
}

void MainWindow::on_cv_ratio_valueChanged(double arg1)
{
    cv_ratio_value = ui->cv_ratio->value();
    QString info = "CV_Ratio: ";
    QString value = QString::number(cv_ratio_value);
    this->log_append(info + value);
}

void MainWindow::on_eta_goal_valueChanged(double arg1)
{
    eta_goal_value = ui->eta_goal->value();
    QString info = "Eta_Goal: ";
    QString value = QString::number(eta_goal_value);
    this->log_append(info + value);
}

void MainWindow::on_iter_max_valueChanged(int arg1)
{
    iter_max_value = ui->iter_max->value();
    QString info = "Iter_Max: ";
    QString value = QString::number(iter_max_value);
    this->log_append(info + value);
}

void MainWindow::on_alpha_valueChanged(double arg1)
{
    alpha_value = ui->alpha->value();
    QString info = "Alpha: ";
    QString value = QString::number(alpha_value);
    this->log_append(info + value);
}

void MainWindow::on_beta_valueChanged(double arg1)
{
    beta_value = ui->beta->value();
    QString info = "Beta: ";
    QString value = QString::number(beta_value);
    this->log_append(info + value);
}

void MainWindow::on_k_valueChanged(double arg1)
{
    k_value = ui->k->value();
    QString info = "K: ";
    QString value = QString::number(k_value);
    this->log_append(info + value);
}

void MainWindow::on_radius_valueChanged(double arg1)
{
    radius_value = ui->radius->value();
    QString info = "Radius: ";
    QString value = QString::number(radius_value);
    this->log_append(info + value);
}
