#include "mainwindow.h"
#include "mytcpserver.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyTcpServer* server = new MyTcpServer(this);
    connect(this, &MainWindow::serverListen, server, &MyTcpServer::startListen);
    connect(server, &MyTcpServer::printTextToWindow, this, &MainWindow::printTextMessage);
    connect(server, &MyTcpServer::addListWidget, this, &MainWindow::addListWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listenButton_clicked()
{
    emit serverListen(quint16(ui->portLineEdit->text().toUInt())); //发出侦听信号
    ui->listenButton->setDisabled(true);
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

void MainWindow::addListWidget(QString item)
{
    ui->listWidget->addItem(item);
}
