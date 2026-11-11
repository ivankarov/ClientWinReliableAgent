#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <client.h>
#include <QProcess>
#include <QThread>
#include <mythread.h>
#include <vector>
#include <windows.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void button_clicked();
    void button_Stop_clicked();
    void onDataUpd(QString msg);
    void getClient();
private:
    void getAgent();
    client *cl;
    Ui::MainWindow *ui;
    QProcess *srv;
    qint64 srvpid;
    DWORD **procId;
    std::vector<DWORD> vec;
};
#endif // MAINWINDOW_H
