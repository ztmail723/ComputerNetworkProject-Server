#ifndef PKGSENDER_H
#define PKGSENDER_H

#include "datapkg.h"
#include <QObject>
class MyTcpSocket;
class PkgSender : public QObject {
    Q_OBJECT
public:
    explicit PkgSender(MyTcpSocket* parent);
    MyTcpSocket* socket;

public:
    void send2001(QVector<QVariant> fileList);
    void send2002(QString fileName, quint64 fileCount);
    void send2003(quint64 fileID, QByteArray fileData);

private:
    void send(DataPkg& pkg);
signals:
};

#endif // PKGSENDER_H
