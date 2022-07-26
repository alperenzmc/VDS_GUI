#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include "VDP_Simulator/configuration.h"


class TcpClient : public QObject
{
    Q_OBJECT
public:
    explicit TcpClient(QObject *parent = nullptr);

    void run();
    void setData(Configuration data_values);
    Configuration getData();

public slots:
    void connectedd();
    void disconnectedd();
    void bytesWrittenn(qint64 bytes);
    void readyReadd();
private:
    QTcpSocket* socket;
    Configuration data;
signals:

};

#endif // TCPCLIENT_H
