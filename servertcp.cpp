#include "servertcp.h"

serverTCP::serverTCP(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
    bool isserverStart = server->listen(QHostAddress::AnyIPv4, 8081);//监听所有ip和8081端口
    qDebug()<<isserverStart;

    connect(server, SIGNAL(newConnection()), this, SLOT(ClientConnect()));
}
void serverTCP::ClientConnect(){
    qDebug()<<"new client";
    while (server->hasPendingConnections()){
        //连接上后通过socket（QTcpSocket对象）获取连接信息
        socket = server->nextPendingConnection();
        QString str = QString("[ip:%1,port:%2]").arg(socket->peerAddress().toString()).arg(socket->peerPort());//监听客户端是否有消息发送
        qDebug()<<str;
        connect(this->socket, &QTcpSocket::readyRead, this, &serverTCP::ReadData);
        connect(this->socket, &QTcpSocket::disconnected, this, &serverTCP::ClientDisConnect);
    }
}

void serverTCP::ClientDisConnect(){
    qDebug()<<"disconnect client";
}
void serverTCP::ReadData(){
//    qDebug()<<socket->bytesAvailable();
    QByteArray buf = socket->readAll();//readAll最多接收65532的数据
    QString str = QString("[ip:%1,port:%2]").arg(socket->peerAddress().toString()).arg(socket->peerPort());
    qDebug()<<str;
    qDebug()<<buf;
//    ui.textEdit_server->append(str +QString(buf));
    socket->write("ok");//服务器接收到信息后返回一个ok
}
