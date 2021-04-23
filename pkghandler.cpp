#include "pkghandler.h"
#include "mytcpsocket.h"
PkgHandler::PkgHandler(MyTcpSocket* parent)
    : QObject(parent)
    , socket(parent)
{
}

void PkgHandler::handle(DataPkg& pkg)
{
    quint64 ID = pkg.ID;
    switch (ID) {
    case 1001:
        break;
    case 1002:
        break;
    default:
        break;
    }
}
