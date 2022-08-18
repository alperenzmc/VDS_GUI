#include "udpclient.h"


/*!
 * \brief UdpClient::UdpClient
 * \param parent
 */
UdpClient::UdpClient(QObject *parent)
    : QObject{parent}
{
  connect(this->socket,SIGNAL(readyRead()),this,SLOT(readReady()));


}

/*!
 * \brief UdpClient::sendData
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
 * \brief UdpClient::setData
 * \param data_values
 */
void UdpClient::readReady()
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
