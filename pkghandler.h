#ifndef PKGHANDLER_H
#define PKGHANDLER_H

#include <QObject>

class PkgHandler : public QObject
{
    Q_OBJECT
public:
    explicit PkgHandler(QObject *parent = nullptr);

signals:

};

#endif // PKGHANDLER_H
