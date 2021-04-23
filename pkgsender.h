#ifndef PKGSENDER_H
#define PKGSENDER_H

#include <QObject>
class MyTcpSocket;
class PkgSender : public QObject {
    Q_OBJECT
public:
    explicit PkgSender(MyTcpSocket* parent);
    MyTcpSocket* socket;
signals:
};

#endif // PKGSENDER_H
