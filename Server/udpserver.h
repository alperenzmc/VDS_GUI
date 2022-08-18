#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QObject>
#include <QUdpSocket>
#include"VDP_Simulator/configuration.h"
#include "mythread.h"
#include <unistd.h>



/*!
 * \brief The UdpServer class
 */
class UdpServer : public QObject
{
    Q_OBJECT
public:

    explicit UdpServer(QObject *parent = nullptr);

    void run();
    void sendData();
    void setData(Configuration data_values);
    Configuration getData();
signals:

public slots:

private:

     QUdpSocket *socket;
     Configuration data;


};

#endif // UDPSERVER_H

//vehicledatsimulator server olacak
//client udp üzerinden bağlanacak
//senaryo dosyasındaki parametreleri göndercek.
//server çalışsın yaml dosyalar ile parametreler doldurulup clienta gönderilsin ve veriloer alınsın
//clientı ayrı çalıştır

