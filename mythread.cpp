#include "mythread.h"
#include "mytcpsocket.h"

MyThread::MyThread(qintptr socketDescriptor):
    ptr(socketDescriptor)
{

}

void MyThread::run()
{
    MyTcpSocket* socket = new MyTcpSocket(ptr);
    connect(socket, &MyTcpSocket::disconnected, this, &MyThread::exit);
    this->exec();
}

void MyThread::exit()
{
    this->requestInterruption();//请求线程中断
    this->quit();
    this->wait();
}
