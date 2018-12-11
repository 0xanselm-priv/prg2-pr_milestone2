#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include <../ElasticNet.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void myfunction();

private:
    Ui::MainWindow *ui;

    void log_append(QString to_append);

    QTimer *timer;

protected:
    void mousePressEvent(QMouseEvent *ev);

private slots:
    void on_cv_ratio_valueChanged(double arg1);
    void on_eta_goal_valueChanged(double arg1);
    void on_iter_max_valueChanged(int arg1);
    void on_alpha_valueChanged(double arg1);
    void on_beta_valueChanged(double arg1);
    void on_k_valueChanged(double arg1);
    void on_radius_valueChanged(double arg1);
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
