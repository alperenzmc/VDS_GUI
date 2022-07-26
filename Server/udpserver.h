#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QObject>
#include <QUdpSocket>
#include"VDP_Simulator/configuration.h"
#include "mythread.h"


/*!
 * \brief The UdpServer class
 */
class UdpServer : public QObject
{
    Q_OBJECT
public:

    explicit UdpServer(QObject *parent = nullptr);
    Configuration data;
    void run();
signals:

public slots:
    void readReady();
private:
     QUdpSocket* socket;

};

#endif // UDPSERVER_H

//vehicledatsimulator server olacak
//client udp üzerinden bağlanacak
//senaryo dosyasındaki parametreleri göndercek.
//server çalışsın yaml dosyalar ile parametreler doldurulup clienta gönderilsin ve veriloer alınsın
//clientı ayrı çalıştır

