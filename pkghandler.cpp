#include "pkghandler.h"
#include "mytcpsocket.h"
#include "pkgsender.h"
#include <QDir>
#include <QVariant>
qint64 PkgHandler::segSize = 1024;
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
        if (i.fileName() == "." || i.fileName() == "..") {
            continue;
        }
        list.append(i.fileName());
    }
    this->socket->sender->send2001(list);
}

void PkgHandler::handle1002(DataPkg& pkg)
{
    QString userName = pkg.data.at(0).toString();
    QString fileName = pkg.data.at(1).toString();
    this->nowFile = new QFile("file/" + fileName);
    qint64 fileSize = this->nowFile->size();
    this->fileCount = quint64(fileSize / this->segSize + 1);
    emit printMsg("用户" + userName + "请求获取文件\"" + fileName + "\"(" + QString::number(fileSize) + " Byte)");
    this->socket->sender->send2002(fileName, this->fileCount);
}

void PkgHandler::handle1003(DataPkg& pkg)
{
    //QString userName = pkg.data.at(0).toString();
    quint64 fileID = pkg.data.at(1).toUInt();
    QByteArray fileData;
    if (fileID == this->fileCount) {
        fileData = this->nowFile->readAll(); // 最后一个数据包
    } else {
        fileData = this->nowFile->read(this->segSize);
    }
    this->socket->sender->send2003(fileID, fileData);
}
