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
    Configuration data;
signals:

public slots:
    void readReady();



/*!
* \brief socket
*/
private:
  QUdpSocket* socket;
};


#endif // UDPCLIENT_H
