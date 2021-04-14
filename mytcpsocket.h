#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QTcpSocket>

class MyTcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    MyTcpSocket(qintptr p);

public slots:
    void onReceiveData();//收到信息
    void onDisconnected();//断开连接
};

#endif // MYTCPSOCKET_H
