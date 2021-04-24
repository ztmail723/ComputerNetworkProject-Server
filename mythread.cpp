#include "mythread.h"
#include "mytcpsocket.h"

MyThread::MyThread(qintptr socketDescriptor)
    : ptr(socketDescriptor)
{
}

void MyThread::run()
{
    MyTcpSocket* socket = new MyTcpSocket(ptr);
    connect(socket, &MyTcpSocket::disconnected, this, &MyThread::exit);
    connect(socket, &MyTcpSocket::printTextToWindow, this, &MyThread::printTextToWindow);
    connect(socket, &MyTcpSocket::addListWidget, this, &MyThread::addListWidget);
    this->exec();
}

void MyThread::exit()
{
    emit printTextToWindow("一个客户端已中断连接");
    this->requestInterruption(); //请求线程中断
    this->quit();
    this->wait();
}
