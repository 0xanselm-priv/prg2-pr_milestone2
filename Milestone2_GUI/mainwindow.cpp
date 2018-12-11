#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <iostream>
#include <QMessageBox>

#include <vector>
#include <tuple>
#include <math.h>

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

ElasticNet net;

int run_counter = 0;

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
    ui->cv_ratio->setValue(2.5);
    ui->cv_ratio->setMaximum(50.0);

    ui->eta_goal->setMinimum(0.01);
    ui->eta_goal->setValue(2.0);
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

    //Timer init
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(applying()));

    //Call Elastic Net Constructor


    //Security/Validation Checks
    ui->start_button->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::applying()
{
    qDebug() << "Applying " << "run counter" << QString::number(run_counter);
    //net.solve();
    //net.apply();
}

void MainWindow::log_append(QString to_append) {
    QString new_line = "\n";
    ui->log_label->setText( to_append + new_line + ui->log_label->text());
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    city_counter_value++;
    ui->city_counter->setText("City Counter: " + QString::number(city_counter_value));

    //Security Action. No running possible without cities.
    if(city_counter_value > 0) {
        ui->start_button->setEnabled(true);
    }

    int x = ev->x();
    int y = ev->y();
    float x_float = static_cast<float>(x);
    float y_float = static_cast<float>(y);

    //Printing the x,y coords on label
    QString x_str = QString::number(x);
    QString y_str = QString::number(y);

    ui->coord_label->setText("X: " + x_str + " Y: " + y_str);
    ui->coord_label->adjustSize();

    //pushing the cities in cities list
    //cities_list.push_back(std::tuple<float, float>(float(x),float(y)));

    //pushing cities in Elastic Net Object
    City city(x_float, y_float, 0.0);
    if (net.get_city_list().empty()) {
        net.add_city(x_float, y_float);
    } else {
        for (int i = 0; i < net.get_city_list().size(); i++) {
            qDebug() << city % net.get_city_list()[i];
            float dist = city % net.get_city_list()[i];
            float eta_2 = 2 * eta_goal_value;
            if (dist < eta_2){
                QMessageBox::warning(this,"Distance Warning","City too close.");
                break;
            } else {
                net.add_city(x_float, y_float);
            }
        }

    }

    QPixmap pixmap(canvas_width, canvas_height);
    pixmap.fill(QColor("transparent"));
    QPainter painter (&pixmap);

    //Paint Vertices
    for (int i = 0; i < net.get_city_list().size(); ++i) {
        int x_coord = net.get_city_list()[i].get_x();
        int y_coord = net.get_city_list()[i].get_y();
        painter.setBrush(Qt::red);
        painter.drawRect(x_coord, y_coord, 5, 5);
        this->log_append("Last City added: " + QString::number(x_coord) + " " + QString::number(y_coord));
    }

    //Paint Vertices
    for (int i = 0; i < net.get_vertex_list().size(); ++i) {
        int x_coord = int (net.get_vertex_list()[i].get_x());
        int y_coord = int (net.get_vertex_list()[i].get_y());
        painter.setBrush(Qt::green);
        painter.drawRect(x_coord, y_coord, 5, 5);
        this->log_append("Last Vertex added: " + QString::number(x_coord) + " " + QString::number(y_coord));
        this->log_append("Vertex List Size: " + QString::number(net.get_vertex_list().size()));
    }

    //Drawing Mid - Niels Style
    int factor = 10;
    int mid_x = int(net.get_mid_x());
    int mid_y = int(net.get_mid_y());
    painter.setBrush(Qt::black);
    painter.drawLine(mid_x-factor, mid_y, mid_x+factor, mid_y);
    painter.drawLine(mid_x, mid_y-factor, mid_x, mid_y+factor);
    this->log_append("Mid: " + QString::number(mid_x) + " " + QString::number(mid_y));

    //Drawing Mid - Robert Style
    int factor_r = 10;
    int mid_x_r = canvas_width/2;
    int mid_y_r = canvas_height/2;
    painter.setBrush(Qt::yellow);
    painter.drawLine(mid_x_r-factor_r, mid_y_r, mid_x_r+factor_r, mid_y_r);
    painter.drawLine(mid_x_r, mid_y_r-factor_r, mid_x_r, mid_y_r+factor_r);
    this->log_append("Mid: " + QString::number(mid_x_r) + " " + QString::number(mid_y_r));

    //Drawing connecting lines between vertices
    for (int i = 0; i < net.get_vertex_list().size() - 1; ++i) {
        // Look out for logic error
        int vert1_x = net.get_vertex_list()[i].get_x();
        int vert1_y = net.get_vertex_list()[i].get_y();
        int vert2_x = net.get_vertex_list()[i+1].get_x();
        int vert2_y = net.get_vertex_list()[i+1].get_y();
        QLineF line(vert1_x, vert1_y, vert2_x, vert2_y);
        painter.drawLine(line);
    }
    int length = net.get_vertex_list().size();
    int vert1_x = net.get_vertex_list()[0].get_x();
    int vert1_y = net.get_vertex_list()[0].get_y();
    int vert2_x = net.get_vertex_list()[length-1].get_x();
    int vert2_y = net.get_vertex_list()[length-1].get_y();
    QLineF line(vert1_x, vert1_y, vert2_x, vert2_y);
    painter.setBrush(Qt::blue);
    painter.drawLine(line);
    //End Vertex Painting

    ui->canvas_label->setPixmap(pixmap);
}

void MainWindow::on_cv_ratio_valueChanged(double arg1)
{
    //Dating up Elastic net Object with Value
    cv_ratio_value = ui->cv_ratio->value();
    QString info = "CV_Ratio: ";
    QString value = QString::number(cv_ratio_value);
    this->log_append(info + value);
    net.set_cv_ratio(cv_ratio_value);
}

void MainWindow::on_eta_goal_valueChanged(double arg1)
{
    //Dating up Elastic net Object with Value
    eta_goal_value = ui->eta_goal->value();
    QString info = "Eta_Goal: ";
    QString value = QString::number(eta_goal_value);
    this->log_append(info + value);
    net.set_eta_goal(eta_goal_value);
}

void MainWindow::on_iter_max_valueChanged(int arg1)
{
    //Dating up Elastic net Object with Value
    iter_max_value = ui->iter_max->value();
    QString info = "Iter_Max: ";
    QString value = QString::number(iter_max_value);
    this->log_append(info + value);
    net.set_iter_max(iter_max_value);
}

void MainWindow::on_alpha_valueChanged(double arg1)
{
    //Dating up Elastic net Object with Value
    alpha_value = ui->alpha->value();
    QString info = "Alpha: ";
    QString value = QString::number(alpha_value);
    this->log_append(info + value);
    net.set_alpha(alpha_value);
}

void MainWindow::on_beta_valueChanged(double arg1)
{
    //Dating up Elastic net Object with Value
    beta_value = ui->beta->value();
    QString info = "Beta: ";
    QString value = QString::number(beta_value);
    this->log_append(info + value);
    net.set_beta(beta_value);
}

void MainWindow::on_k_valueChanged(double arg1)
{
    //Dating up Elastic net Object with Value
    k_value = ui->k->value();
    QString info = "K: ";
    QString value = QString::number(k_value);
    this->log_append(info + value);
    net.set_k(k_value);
}

void MainWindow::on_radius_valueChanged(double arg1)
{
    //Dating up Elastic net Object with Value
    radius_value = ui->radius->value();
    QString info = "Radius: ";
    QString value = QString::number(radius_value);
    this->log_append(info + value);
    net.set_radius(radius_value);
}

void MainWindow::on_start_button_clicked()
{
    //    net.set_cv_ratio(cv_ratio_value);
    //    net.set_eta_goal(eta_goal_value);
    //    net.set_iter_max(iter_max_value);
    //    net.set_alpha(alpha_value);
    //    net.set_beta(beta_value);
    //    net.set_k(k_value);
    //    net.set_radius(radius_value);

    if (run_counter == 0) {
        ui->start_button->setText("Stop");
        run_counter++;
        this->log_append("Start or Apply");
        timer->start(1000);
    } else if (run_counter % 2 == 0 && run_counter > 1) {
        ui->start_button->setText("Stop");
        run_counter++;
        this->log_append("Continue to Apply");
        timer->start(1000);
    } else if (run_counter % 2 == 1) {
        timer->stop();
        ui->start_button->setText("Continue");
        run_counter++;
        this->log_append("Paused");
    }

}
