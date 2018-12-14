/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *canvas_label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *coord_label;
    QLabel *label_2;
    QDoubleSpinBox *cv_ratio;
    QLabel *label_3;
    QDoubleSpinBox *eta_goal;
    QLabel *label_4;
    QSpinBox *iter_max;
    QLabel *label_5;
    QDoubleSpinBox *alpha;
    QLabel *label_6;
    QDoubleSpinBox *beta;
    QLabel *label_7;
    QDoubleSpinBox *k;
    QLabel *label_8;
    QDoubleSpinBox *radius;
    QLabel *city_counter;
    QPushButton *start_button;
    QLabel *log_label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(547, 514);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        canvas_label = new QLabel(centralWidget);
        canvas_label->setObjectName(QStringLiteral("canvas_label"));
        canvas_label->setGeometry(QRect(0, 0, 401, 411));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(410, 10, 121, 391));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        coord_label = new QLabel(groupBox);
        coord_label->setObjectName(QStringLiteral("coord_label"));

        verticalLayout->addWidget(coord_label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        cv_ratio = new QDoubleSpinBox(groupBox);
        cv_ratio->setObjectName(QStringLiteral("cv_ratio"));

        verticalLayout->addWidget(cv_ratio);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        eta_goal = new QDoubleSpinBox(groupBox);
        eta_goal->setObjectName(QStringLiteral("eta_goal"));

        verticalLayout->addWidget(eta_goal);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        iter_max = new QSpinBox(groupBox);
        iter_max->setObjectName(QStringLiteral("iter_max"));

        verticalLayout->addWidget(iter_max);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        alpha = new QDoubleSpinBox(groupBox);
        alpha->setObjectName(QStringLiteral("alpha"));

        verticalLayout->addWidget(alpha);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        beta = new QDoubleSpinBox(groupBox);
        beta->setObjectName(QStringLiteral("beta"));

        verticalLayout->addWidget(beta);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        k = new QDoubleSpinBox(groupBox);
        k->setObjectName(QStringLiteral("k"));

        verticalLayout->addWidget(k);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout->addWidget(label_8);

        radius = new QDoubleSpinBox(groupBox);
        radius->setObjectName(QStringLiteral("radius"));

        verticalLayout->addWidget(radius);

        city_counter = new QLabel(groupBox);
        city_counter->setObjectName(QStringLiteral("city_counter"));

        verticalLayout->addWidget(city_counter);

        start_button = new QPushButton(centralWidget);
        start_button->setObjectName(QStringLiteral("start_button"));
        start_button->setGeometry(QRect(410, 410, 121, 21));
        log_label = new QLabel(centralWidget);
        log_label->setObjectName(QStringLiteral("log_label"));
        log_label->setGeometry(QRect(0, 440, 391, 71));
        log_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        canvas_label->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Config:", nullptr));
        label->setText(QApplication::translate("MainWindow", "Cursor Pos:", nullptr));
        coord_label->setText(QApplication::translate("MainWindow", "X:    Y:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "CV_Ratio:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Eta_Goal:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Iter_Max:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Alpha:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Beta:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "K:", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Radius:", nullptr));
        city_counter->setText(QApplication::translate("MainWindow", "City Counter:", nullptr));
        start_button->setText(QApplication::translate("MainWindow", "Start", nullptr));
        log_label->setText(QApplication::translate("MainWindow", "Message Box:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
