#include "pkghandler.h"
#include "mytcpsocket.h"
PkgHandler::PkgHandler(MyTcpSocket* parent)
    : QObject(parent)
    , socket(parent)
{
}
