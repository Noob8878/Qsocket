#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QTcpSocket>
#include<QTcpServer>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);//显示说明 只有一参数的构造函数
    ~MainWindow();

private slots:
    void on_pushButtonstart_clicked();

    void on_pushButtonsend_clicked();

private:
    Ui::MainWindow *ui;
    QTcpServer *mserver;
    QTcpSocket *msocket;
};

#endif // MAINWINDOW_H
