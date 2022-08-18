#include "udpserver.h"

/*!
 * \brief UdpServer::UdpServer
 * \param parent
 */
UdpServer::UdpServer(QObject *parent)
    : QObject{parent}
{


}

void UdpServer::run(){
    this->socket = new QUdpSocket(this);
    //socket->bind(QHostAddress("192.168.0.3"),1234);
    sleep(1);
    this->socket->bind(QHostAddress("127.0.0.1"),1235);
}


/*!
 * \brief qbyteToDoublee
 * \param DataQByte
 * \param data
 */
void UdpServer::sendData() // Call with VDP *;
{
    this->socket = new QUdpSocket(this);

    qDebug() << "Starting...";

    QString latittude = QString::number(data.get_latitude());//vdp.blabla

    QString longitude = QString::number(data.get_longitude());

    QString velocity = QString::number(data.get_velocity());

    QString acceleration = QString::number(data.get_acceleration());

    QByteArray qbyte_data {latittude.toUtf8()};
    qbyte_data.append(" " + longitude.toUtf8() + " " + velocity.toUtf8() + " " + acceleration.toUtf8());

    socket->writeDatagram(qbyte_data,QHostAddress("127.0.0.1"),1235);
    qDebug() << "Sent data:" << qbyte_data;
}


/*!
 * \brief UdpServer::readReady
 */
void UdpServer::setData(Configuration data_values)
{
    this->data = data_values;
}

/*!
 * \brief UdpClient::getData
 * \return
 */
Configuration UdpServer::getData()
{
    return this->data;
}


