#ifndef GUIINTERFACE_H
#define GUIINTERFACE_H

#include "VDP_Simulator/configuration.h"
#include "tcpclient.h"
#include "udpclient.h"
#include "random"

class GuiInterface
{
public:

    GuiInterface();
    ~GuiInterface();

    TcpClient* m_tcp_client;
    UdpClient* m_udp_client;
    Configuration* m_data;

    inline double dRand(double d_max);
    void setVehicleData();
};

#endif // GUIINTERFACE_H
