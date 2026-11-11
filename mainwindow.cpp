#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QProcess>
#include <iostream>
#include <qDebug>
#include <windows.h>
#include <tlhelp32.h>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srv = new QProcess(this);
    connect(this->srv, &QProcess::started,this,&MainWindow::getClient);
    srv->start("D:\\agent\\serv\\serv.exe");
    qDebug()<<"serv запущен";
}
//void MainWindow::getAgent(){
//    srvpid = srv->processId();
//    HANDLE hp = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
//    PROCESSENTRY32 pe = { 0 };
//    pe.dwSize = sizeof(PROCESSENTRY32);
//    if (Process32First(hp, &pe)) {
//      do {
//        if (pe.th32ParentProcessID == (DWORD)srvpid) {
//          vec.push_back(pe.th32ProcessID);
//        }
//      } while (Process32Next(hp, &pe));
//    }
//    CloseHandle(hp);
//}
void MainWindow::getClient(){
    cl = new client("\\\\.\\pipe\\mynamedpipe",this);
    connect(cl,&client::serverResponse,this,&MainWindow::onDataUpd);
    connect(this->ui->pushButton,SIGNAL(clicked()),this,SLOT(button_clicked()));
    connect(this->ui->pushButtonStop,SIGNAL(clicked()),this,SLOT(button_Stop_clicked()));
//    this->getAgent();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onDataUpd(QString msg){
    qDebug() << "from on data upd";
    qDebug()<<msg;
}

void MainWindow::button_clicked(){
    qDebug()<<"from button_clckd";
    ui->TextEdit->appendPlainText(cl->Read()+QString("\n"));
}
void MainWindow::button_Stop_clicked(){
    cl->send_StopToServer();
//    auto start{vec.begin()};
//    std::string s = std::to_string(start);
//    qDebug()<<QString::fromStdString(s);
//    for(start; start!=vec.end();start++){
//        qDebug()<<"2";
//        QStringList arguments;
//        arguments << "/F" << "/PID" << QString::number(*start);
//        QProcess::execute("taskkill", arguments);
//    }
}

