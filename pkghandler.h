#ifndef PKGHANDLER_H
#define PKGHANDLER_H

#include <QObject>
class MyTcpSocket;
class PkgHandler : public QObject {
    Q_OBJECT
public:
    explicit PkgHandler(MyTcpSocket* parent);
    MyTcpSocket* socket;
signals:
};

#endif // PKGHANDLER_H
