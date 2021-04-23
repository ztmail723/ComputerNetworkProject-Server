#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "datapkg.h"
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_listenButton_clicked();

    void on_clearButton_clicked();

    void on_msgTextBrowser_textChanged();

public slots:
    void printTextMessage(QString msg);

private:
    Ui::MainWindow* ui;

signals:
    void serverListen(quint16 port);
};
#endif // MAINWINDOW_H
