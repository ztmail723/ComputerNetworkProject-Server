#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QTcpServer>

class MyTcpServer : public QTcpServer {
    Q_OBJECT

public:
    explicit MyTcpServer(QObject* parent = nullptr);

public slots:
    void startListen(quint16 port = 2333);

protected:
    virtual void incomingConnection(qintptr socketDescriptor) override;
signals:
    void printTextToWindow(QString msg);
    void addListWidget(QString item);
};

#endif // MYTCPSERVER_H
