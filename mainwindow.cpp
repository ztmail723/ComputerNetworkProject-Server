#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mytcpserver.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyTcpServer* server = new MyTcpServer(this);
    connect(this, &MainWindow::serverListen, server, &MyTcpServer::startListen);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_listenButton_clicked()
{
    emit serverListen(ui->portLineEdit->text().toUInt()); //发出侦听信号
}

void MainWindow::on_clearButton_clicked()
{
    ui->msgTextBrowser->clear();
}

void MainWindow::on_msgTextBrowser_textChanged()
{
    ui->msgTextBrowser->moveCursor(QTextCursor::End);
}

void MainWindow::printTextMessage(QString msg)
{
    ui->msgTextBrowser->append(msg);
}
