#include "pkghandler.h"
#include "mytcpsocket.h"
#include "pkgsender.h"
#include <QDir>
#include <QVariant>
PkgHandler::PkgHandler(MyTcpSocket* parent)
    : QObject(parent)
    , socket(parent)
{
    connect(this, &PkgHandler::printMsg, socket, &MyTcpSocket::printTextToWindow);
}

void PkgHandler::handle(DataPkg& pkg)
{
    quint64 ID = pkg.ID;
    switch (ID) {
    case 1001:
        handle1001(pkg);
        break;
    case 1002:
        handle1002(pkg);
        break;
    case 1003:
        handle1003(pkg);
        break;
    default:
        break;
    }
}

void PkgHandler::handle1001(DataPkg& pkg)
{
    QString userName = pkg.data.at(0).toString();
    emit printMsg("用户" + userName + "请求获取文件列表");
    QDir dirPath("file");
    QVector<QVariant> list;
    QList<QFileInfo> file(dirPath.entryInfoList());
    for (auto& i : file) {
        list.append(i.fileName());
    }
    this->socket->sender->send2001(list);
}

void PkgHandler::handle1002(DataPkg& pkg)
{
    QString userName = pkg.data.at(0).toString();
    QString fileName = pkg.data.at(1).toString();
    emit printMsg("用户" + userName + "请求获取文件" + fileName);
    this->nowFile = new QFile("file/" + fileName);
    this->nowFile->size();
}

void PkgHandler::handle1003(DataPkg& pkg)
{
}
