#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_listenButton_clicked();

    void on_clearButton_clicked();

    void on_msgTextBrowser_textChanged();

private:
    Ui::MainWindow* ui;

signals:
    void serverListen(quint16 port);
};
#endif // MAINWINDOW_H
