#ifndef PKGHANDLER_H
#define PKGHANDLER_H

#include "datapkg.h"
#include <QObject>
class MyTcpSocket;
class PkgHandler : public QObject {
    Q_OBJECT
public:
    explicit PkgHandler(MyTcpSocket* parent);
    MyTcpSocket* socket;
    void handle(DataPkg& pkg);
signals:
};

#endif // PKGHANDLER_H
