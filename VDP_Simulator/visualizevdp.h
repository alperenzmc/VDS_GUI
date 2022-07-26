#ifndef VISUALIZEVDP_H
#define VISUALIZEVDP_H
#include "configuration.h"


class VisualizeVDP
{
private:
    Configuration vdp_m;
    bool is_tcp_m;
    bool is_udp_m;

public:
    VisualizeVDP(Configuration vdp_value,bool is_tcp_value,bool is_udp_value);
};

#endif // VISUALIZEVDP_H
