#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread {
    Q_OBJECT
public:
    MyThread(qintptr socketDescriptor);
    virtual void run() override;
public slots:
    void exit();

private:
    qintptr ptr;
signals:
    void printTextToWindow(QString msg);
    void addListWidget(QString item);
};

#endif // MYTHREAD_H
