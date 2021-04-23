#include "pkgsender.h"
#include "mytcpsocket.h"
PkgSender::PkgSender(MyTcpSocket* parent)
    : QObject(parent)
    , socket(parent)
{
}
