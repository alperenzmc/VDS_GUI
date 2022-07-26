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
    this->socket->bind(QHostAddress("127.0.0.1"),1235);
    connect(this->socket,SIGNAL(readyRead()),this,SLOT(readReady()));
}


/*!
 * \brief qbyteToDoublee
 * \param DataQByte
 * \param data
 */
void qbyteToDoublee(QByteArray DataQByte, Configuration data)
{

    QStringList data_list = QString(DataQByte).split(' ');

    data.set_latitude(data_list[0].toDouble());
    data.set_longitude(data_list[1].toDouble());
    data.set_velocity(data_list[2].toDouble());
    data.set_acceleration(data_list[3].toDouble());
    qDebug()  << "Data (double): " << data.get_latitude() <<data.get_longitude() << data.get_velocity() << data.get_acceleration();
}


/*!
 * \brief UdpServer::readReady
 */
void UdpServer::readReady()
{

    QByteArray Buffer;
    Buffer.resize(this->socket->pendingDatagramSize());

    QHostAddress sender;

    quint16 senderPort;
    this->socket->readDatagram(Buffer.data(),Buffer.size(),&sender, &senderPort);

    qDebug() << "Data from:" << sender.toString();
    qDebug() << "Data Port:" << senderPort;
    qDebug() << "Data:" << Buffer;

    qbyteToDoublee(Buffer, data);


}
