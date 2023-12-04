#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QTcpserver>
#include<QtNetwork>
MainWindow::MainWindow(QWidget *parent) ://定义构造函数
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 /* QTcpServer  *mserver=new QTcpServer;
    mserver->listen(QHostAddress::Any,0); */


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonstart_clicked()
{
     mserver=new QTcpServer(this);
     QObject::connect(mserver,&QTcpServer::newConnection,this,[&](){
     //客服端连接字
     msocket=mserver->nextPendingConnection();

     QObject::connect(msocket,&QTcpSocket::readyRead,this,[&](){
         QByteArray arr=msocket->readAll();

         QString str(arr);
   //    ui->lineEdit->str(arr);
    ui->lineEdit->setText(str);
     });
      });
     //监听
    mserver->listen(QHostAddress::Any,ui->spinBox->value());


}

void MainWindow::on_pushButtonsend_clicked()

{      QString str=ui->lineEdit->text();
    //add 2022/11/5
      // str="CTSeriesInfo {\"PatientID\":\"aaa\",\"PatientName\":\"bbb\",\"NumberOfSeries\":128,}";
   //    CTSeriesInfo {"PatientID":"01011","PatientName":"bbb","NumberOfSeries":"58","NumberOfSlic":18}
       //CTSeriesInfo {"PatientID":"01011","PatientName":"bbb","NumberOfSeries":128}  可以用
       //CTSeriesInfo {"PatientID":"01011","PatientName":"bbb","NumberOfSeries":106,"NumberOfSlice":298,"NumberOfSpacing":4}
       //CTSeriesInfo {"PatientID":"000001","PatientName":"666","NumberOfSeries":106,"NumberOfSlice":398,"NumberOfSpacing":3}
   // QString    str2=str.toStdWString();
       QByteArray arr;
          arr.append(str);
              msocket->write(arr);

}
