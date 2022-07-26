#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPushButton>
#include "configuration.h"
#include <memory>
#include <QString>
#include <string.h>
#include <iostream>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Display->setText("VEHICLE DATA PROVIDER SIMULATOR");
    ui->Latitude->setText("Latitude");
    ui->Longitude->setText("Longitude");
    ui->Velocity->setText("Velocity");
    ui->Acceleration->setText("Acceleration");

    std::unique_ptr<Configuration> vehicleDataProvider = std::make_unique<Configuration>();
    ui->latitude_value->setText(QString::number(vehicleDataProvider->get_latitude()));
    ui->longitude_value->setText(QString::number(vehicleDataProvider->get_longitude()));
    ui->velocity_value->setText(QString::number(vehicleDataProvider->get_velocity()));
    ui->acceleration_value->setText(QString::number(vehicleDataProvider->get_acceleration()));

    ui->pushButton->setIcon(QIcon("/home/ulak/Downloads/switch.png"));
    ui->pushButton->setCheckable(true);
    ui->tcp_or_udp->setText("TCP");
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_toggled(bool checked)
{
    if(checked){
        ui->pushButton->setIcon(QIcon("/home/ulak/Downloads/toggle.png"));
        ui->tcp_or_udp->setText("UDP");
      //  Visualizebıdıdı.isTcP = true


        std::cout<<"--UDP--"<<std::endl;
    }
    else{
        ui->pushButton->setIcon(QIcon("/home/ulak/Downloads/switch.png"));
        ui->tcp_or_udp->setText("TCP");
        std::cout<<"--TCP--"<<std::endl;
    }

}
