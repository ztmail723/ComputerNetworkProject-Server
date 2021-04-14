#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QTcpServer>

class MyTcpServer : public QTcpServer
{
    Q_OBJECT

public:
    explicit MyTcpServer();
protected:
    virtual void incomingConnection(qintptr socketDescriptor);
};

#endif // MYTCPSERVER_H
