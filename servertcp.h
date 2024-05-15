#ifndef SERVERTCP_H
#define SERVERTCP_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class serverTCP : public QObject
{
    Q_OBJECT
public:
    explicit serverTCP(QObject *parent = nullptr);


signals:

public slots:
    void ClientConnect();
    void ClientDisConnect();
    void ReadData();

private:
    QTcpSocket *socket = nullptr;
    QTcpServer *server = nullptr;
};
//extern serverTCP *servertcp;
#endif // SERVERTCP_H
