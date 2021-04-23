#include "pkgsender.h"
#include "mytcpsocket.h"
PkgSender::PkgSender(MyTcpSocket* parent)
    : QObject(parent)
    , socket(parent)
{
}

void PkgSender::send2001(QVector<QVariant> fileList)
{
    DataPkg pkg;
    pkg.ID = 2001;
    pkg.data = fileList;
    send(pkg);
}

void PkgSender::send2002(QString fileName, quint64 fileCount)
{
    DataPkg pkg;
    pkg.ID = 2002;
    pkg.data.append(fileName);
    pkg.data.append(fileCount);
    send(pkg);
}

void PkgSender::send2003(quint64 fileID, QByteArray fileData)
{
    DataPkg pkg;
    pkg.ID = 2003;
    pkg.data.append(fileID);
    pkg.data.append(fileData);
    send(pkg);
}

void PkgSender::send(DataPkg& pkg)
{
    this->socket->sendMessage(pkg);
}
