#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QProcess>
class MyThread : public QThread
{
    Q_OBJECT

public:
    void endProc();
    MyThread(QObject *o);
    void run();
    int checkR();
private:
    QProcess *srv;
signals:
};
#endif // MYTHREAD_H
