#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QObject>
#include <QUdpSocket>
#include "VDP_Simulator/configuration.h"

class UdpClient : public QObject
{
    Q_OBJECT
public:
    explicit UdpClient(QObject *parent = nullptr);
    void sendData();
    void setData(Configuration data_values);
    Configuration getData();
signals:

public slots:


/*!
* \brief socket
*/
private:
    QUdpSocket *socket;
    Configuration data;
};


#endif // UDPCLIENT_H
