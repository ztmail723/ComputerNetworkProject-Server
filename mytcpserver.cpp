#include "mytcpserver.h"
#include "mythread.h"

MyTcpServer::MyTcpServer(QObject* parent)
    : QTcpServer(parent)
{
}

void MyTcpServer::startListen(quint16 port)
{
    this->listen(QHostAddress::Any, port);
}

void MyTcpServer::incomingConnection(qintptr socketDescriptor)
{
    emit printTextToWindow("服务器接收到了新连接");
    MyThread* thread = new MyThread(socketDescriptor);
    connect(thread, &MyThread::printTextToWindow, this, &MyTcpServer::printTextToWindow);
    connect(thread, &MyThread::addListWidget, this, &MyTcpServer::addListWidget);
    thread->start();
}
