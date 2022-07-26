#include "mythread.h"



/*!
 * \brief MyThread::MyThread
 * \param ID
 * \param parent
 */
MyThread::MyThread(qintptr ID, QObject *parent):QThread(parent)
{
    this->socket_descriptor = ID;
}


/*!
 * \brief MyThread::run
 */
void MyThread::run(){

    qDebug() << socket_descriptor << "Starting thread";
    this->socket = new QTcpSocket();

    if(!this->socket->setSocketDescriptor(this->socket_descriptor))
    {
        qDebug() << "HATA";
        return;
    }

    connect(this->socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(this->socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);


    qDebug() << socket_descriptor << "Client Connected";

    exec();
}


/*!
 * \brief qbyteToDouble
 * \param DataQByte
 * \param data
 */
void qbyteToDouble(QByteArray DataQByte, Configuration data)
{

    QStringList dataList = QString(DataQByte).split(' ');

    data.set_latitude(dataList[0].toDouble());
    data.set_longitude(dataList[1].toDouble());
    data.set_velocity(dataList[2].toDouble());
    data.set_acceleration(dataList[3].toDouble());

    //qDebug()  << "Data: " << data.getLongitude() <<data.getLatittude() << data.getVelocity() << data.getAcceleration();
}


/*!
 * \brief MyThread::readyRead
 */
void MyThread::readyRead()
{
    QByteArray DataQByte = this->socket->readAll();
    qbyteToDouble(DataQByte, getData());


    qDebug() << socket_descriptor << "Data:" << DataQByte;
   socket->write("asdfdsadsffasdfs");
}


/*!
 * \brief MyThread::disconnected
 */
void MyThread::disconnected()
{
    //socket->close();
    socket->disconnectFromHost();
    qDebug() << socket_descriptor << "Disconnected";
    delete this->socket;
    exit(0);
}


/*!
 * \brief MyThread::setData
 * \param data_values
 */
void MyThread::setData(Configuration data_values)
{
    this->data = data_values;
}


/*!
 * \brief MyThread::getData
 * \return
 */
Configuration MyThread::getData()
{
    return this->data;
}
