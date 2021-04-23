#include "mainwindow.h"
#include <QApplication>
#include <winsock2.h>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Server");
    w.show();
    return a.exec(); //测试一下
    // 测试信息
}
