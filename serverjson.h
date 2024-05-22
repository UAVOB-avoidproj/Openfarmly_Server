#ifndef SERVERJSON_H
#define SERVERJSON_H

#include <QObject>
#include <iostream>
#include <cmath>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include "servertcp.h"
extern serverTCP *servertcp;

class serverJSON : public QObject
{
    Q_OBJECT
public:
    explicit serverJSON(QObject *parent = nullptr);
    void addJsonKeyValuepair(QJsonValue, QJsonValue);
    void addJsonArray(QJsonValue, QJsonValue, QJsonValue, QJsonValue);
    void addJsonArray(QJsonValue, QJsonValue, QJsonValue);

signals:
    void signal_sendJsonDataTCP();
private slots:
    void slot_sendJsonDataTCP();
private:
    QJsonDocument send_doc;
    QJsonObject send_obj;
//    QByteArray send_json;

};

#endif // SERVERJSON_H
