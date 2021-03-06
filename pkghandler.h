#ifndef PKGHANDLER_H
#define PKGHANDLER_H

#include "datapkg.h"
#include <QFile>
#include <QObject>
class MyTcpSocket;
class PkgHandler : public QObject {
    Q_OBJECT
public:
    explicit PkgHandler(MyTcpSocket* parent);
    MyTcpSocket* socket;
    void handle(DataPkg& pkg);

private:
    static qint64 segSize;
    QFile* nowFile;
    quint64 fileCount;
    void handle1001(DataPkg& pkg);
    void handle1002(DataPkg& pkg);
    void handle1003(DataPkg& pkg);
signals:
    void printMsg(QString msg);
    void addListWidget(QString item);
};

#endif // PKGHANDLER_H
