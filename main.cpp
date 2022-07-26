#include <iostream>
#include <memory>
#include <QApplication>
#include <vector>
#include <fstream>
#include <sstream>

#include "yaml-cpp/yaml.h"
#include "VDP_Simulator/configuration.h"
#include "VDP_Simulator/mainwindow.h"
#include "Server/tcpserver.h"
#include "Server/udpserver.h"
#include "Client/tcpclient.h"
#include "Client/udpclient.h"
#include <thread>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    std::unique_ptr<Configuration> dataValues = std::make_unique<Configuration>();



    YAML::Node config;


    config = YAML::LoadFile("/home/ulak/VDPS_GUI/config_files/config.yaml");

    YAML::Node dataList = config["SCENARIO"];


        dataValues->set_latitude(dataList["Latitude"].as<double>());
        dataValues->set_longitude(dataList["Longitude"].as<double>());
        dataValues->set_velocity(dataList["Velocity"].as<double>());
        dataValues->set_acceleration(dataList["Acceleration"].as<double>());

        if (dataList) {
             std::cout<<"CONFIGURATION\n";
             std::cout << "The given parameters on YAML file is:\n " << config["SCENARIO"]<<"\n";
       }

       dataValues->display();

       Configuration m_data;


        UdpServer m_udp_server;
        //TcpServer m_tcp_server;

        m_udp_server.run();
//        m_tcp_server.startServer();


//        srand(time(NULL));


//            TcpClient m_tcp_client;
//            UdpClient m_udp_client;


//            m_tcp_client.setData(m_data);
//            m_tcp_client.run();


//            m_udp_client.setData(m_data);
//            m_udp_client.sendData();

    //   if(is_tcp == true) {
    //   TcpClient *tcp;
    //   tcp->run(;)

    //   } else {
    //       UDPclient *udp;
    //       udp->run();

    //   }


        w.show();
        return a.exec();
    //   return 0;
    }


