#include <QProcess>
#include "Worker.h"
#include <QDebug>
void Worker::doWork() {
        QString result;
        QProcess *serv = new QProcess(this);
        serv->start("D:\\agent\\agent.exe");
        qDebug()<<"agent вызван";
    }




