#include "client.h"
#include <QDebug>
#include <QLocalSocket>
#include <QDataStream>
#include <QThread>
client::client(QString remoteServername, QObject *parent) :
        QObject(parent){
    qDebug()<< "from client construct";
    m_socket = new QLocalSocket(this);
    m_serverName = remoteServername;

//    connect(m_socket, SIGNAL(connected()), this, SLOT(socket_connected()));
    connect(m_socket, SIGNAL(disconnected()), this, SLOT(socket_disconnected()));

    connect(m_socket, SIGNAL(readyRead()), this, SLOT(socket_readReady()));
    QThread::sleep(3);
    m_socket->connectToServer(m_serverName);
    for (int i = 0; i < 30; ++i) {
          m_socket->connectToServer(m_serverName);
          if (m_socket->waitForConnected(500)) {
              qDebug() << "Connected to server after" << i+1 << "attempt(s)";
              return;
          }
          qDebug() << "Retry connect...";
      }
}
client::~client() {
    m_socket->abort();
    delete m_socket;
    m_socket = NULL;
}
QString client::Read(){
    return m_message;
}
void client::send_StopToServer() {
    qDebug()<<"from sendmsgtosrv";
    m_socket->write("1");
    m_socket->flush();
    qDebug()<<"\"1\" has been writting";
}
void client::socket_readReady() {
      QByteArray bytes = m_socket->readAll();
      qDebug() << "from socket_readReady";
      m_message=QString::fromUtf8(bytes);
      m_message.removeLast();

      emit serverResponse(m_message);

      qDebug()<<"trying to write \"0\" in socket_readReady";
      m_socket->write("0");
      m_socket->flush();
      qDebug() << "\"0\" has been writting";
}

void client::socket_error(QLocalSocket::LocalSocketError error) {
    qDebug() << "socket_error : " << error;
}
void client::socket_disconnected() {

}
//void client::socket_connected(){
//    qDebug() << "from socket_connected";
//    QByteArray block;
//    QDataStream out(&block, QIODevice::ReadWrite);
//    out << this->Smessage.toUtf8().data();
//    out.device()->seek(0);
//    m_socket->write(block);
//    m_socket->flush();
//    qDebug()() << "socket connected";
//}
