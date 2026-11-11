#include "MyThread.h"
#include <QProcess>
#include<QDebug>
#include "mainwindow.h"
MyThread::MyThread(QObject *o){
}
void MyThread::run()
{
    srv = new QProcess(this);
    srv->start("D:\\agent\\agent.exe");
    qDebug()<<"agent запущен";
}
int MyThread::checkR(){
    if(srv->state()==QProcess::Running){
       return 1;
   }
   return 0;
}
void MyThread::endProc(){
    srv->kill();
    qDebug()<<"kill is exected";

}
