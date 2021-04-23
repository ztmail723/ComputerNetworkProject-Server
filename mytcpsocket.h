#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include "datapkg.h"
#include <QTcpSocket>
class PkgHandler;
class PkgSender;
class MyTcpSocket : public QTcpSocket {
    Q_OBJECT
public:
    MyTcpSocket(qintptr p);
    PkgHandler* handler;
    PkgSender* sender;
public slots:
    void onReceiveData(); //收到信息
    void onDisconnected(); //断开连接
    void sendMessage(DataPkg pkg);
signals:
    void printTextToWindow(QString msg);
};

#endif // MYTCPSOCKET_H
