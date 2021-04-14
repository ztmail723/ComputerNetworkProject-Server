#include "mytcpserver.h"
#include "mythread.h"

MyTcpServer::MyTcpServer()
{

}

void MyTcpServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << "服务器接收到了新连接";
    MyThread* thread = new MyThread(socketDescriptor);
    qDebug() << "建立新线程";
    thread->start();
    qDebug() << "线程开始运行";
}
