#include "mainwindow.h"
#include <QApplication>
#include <winsock2.h>

int main(int argc, char* argv[])
{
    sock = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
