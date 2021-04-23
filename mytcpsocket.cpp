#include "mytcpsocket.h"
#include "pkghandler.h"
#include "pkgsender.h"
#include <QDataStream>
MyTcpSocket::MyTcpSocket(qintptr p)
{
    this->handler = new PkgHandler(this);
    this->sender = new PkgSender(this);
    this->setSocketDescriptor(p);
    this->connect(this, &MyTcpSocket::disconnected, this, &MyTcpSocket::onDisconnected); //断开连接的信号与断开连接的槽相连
    this->connect(this, &MyTcpSocket::readyRead, this, &MyTcpSocket::onReceiveData); //准备就绪的信号与接收数据的槽相连
}
void MyTcpSocket::onReceiveData()
{
    qDebug() << "服务端开始接受数据";
    QByteArray array = this->readAll();
    QDataStream dts(&array, QIODevice::ReadOnly);
    DataPkg pkg;
    dts >> pkg;
    this->handler->handle(pkg); //将打包好的数据包交给handler处理
}
void MyTcpSocket::onDisconnected()
{
    qDebug() << "有一个客户端断开";
}
