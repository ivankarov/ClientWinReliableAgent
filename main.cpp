#include <QApplication>
#include <QProcess>
#include "mainwindow.h"
#include <windows.h>
#include <qDebug>
#include <iostream>
#include "client.h"
int main(int argc, char *argv[])
{
    qDebug() << "Starting application";
    QApplication a(argc, argv);
    MainWindow w;
    qDebug() << "Window created";
    w.show();
    qDebug() << "Window shown, visible:" << w.isVisible();
    int result = a.exec();
    qDebug() << "Application exited with code" << result;
    return result;
}
