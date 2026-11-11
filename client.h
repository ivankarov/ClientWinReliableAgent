#ifndef CLIENT_H
#define CLIENT_H
#include <stdio.h>

#include <QtNetwork/QLocalSocket>
#include <QLocalSocket>
#include <QLocalServer>
#include <QTextStream>
#include <qdatastream.h>

class client : public QObject
{
    Q_OBJECT
public:
    client(QString remoteServername, QObject *parent = nullptr);
    ~client();
    QString Read();

signals:
    void serverResponse(QString);

public slots:
    void send_StopToServer();
//    void socket_connected();
    void socket_disconnected();

    void socket_readReady();
    void socket_error(QLocalSocket::LocalSocketError);

private:
    QLocalSocket*   m_socket;
    quint16 m_blockSize;
    QString m_message;
//    QString Smessage;
    QString m_serverName;
};


#endif // CLIENT_H
