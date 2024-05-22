#include "serverjson.h"

serverJSON::serverJSON(QObject *parent) : QObject(parent)
{
    connect(this, &serverJSON::signal_sendJsonDataTCP, this, &serverJSON::slot_sendJsonDataTCP);
}
void serverJSON::addJsonKeyValuepair(QJsonValue key, QJsonValue value){
    send_obj.insert(key.toString(), value);
}

void serverJSON::addJsonArray(QJsonValue a, QJsonValue b, QJsonValue c, QJsonValue d){
    QJsonArray _array;
    if ((b.isDouble() && std::isnan(b.toDouble())) || b==0) {
        _array.append("0"); // 如果是NaN，则添加"0"
    } else {
        _array.append(b.toString()); // 否则，正常添加转换后的字符串
    }
    if ((c.isDouble() && std::isnan(c.toDouble())) || c==0) {
        _array.append("0"); // 如果是NaN，则添加"0"
    } else {
        _array.append(c.toString()); // 否则，正常添加转换后的字符串
    }
    if ((d.isDouble() && std::isnan(d.toDouble())) || d==0) {
        _array.append("0"); // 如果是NaN，则添加"0"
    } else {
        _array.append(d.toString()); // 否则，正常添加转换后的字符串
    }
//    _array.append(b.toString());
//    _array.append(c.toString());
//    _array.append(d.toString());

    send_obj.insert(a.toString(), _array);
}
void serverJSON::addJsonArray(QJsonValue a, QJsonValue b, QJsonValue c){
    QJsonArray _array;
    if (b.isDouble() && std::isnan(b.toDouble())) {
        _array.append("0"); // 如果是NaN，则添加"0"
    } else {
        _array.append(b.toString()); // 否则，正常添加转换后的字符串
    }
    if (c.isDouble() && std::isnan(c.toDouble())) {
        _array.append("0"); // 如果是NaN，则添加"0"
    } else {
        _array.append(c.toString()); // 否则，正常添加转换后的字符串
    }
//    _array.append(b.toString());
//    _array.append(c.toString());
    send_obj.insert(a.toString(), _array);
}
void serverJSON::slot_sendJsonDataTCP(){
    QJsonDocument _doc(send_obj);
    QByteArray _send_json = _doc.toJson();
    servertcp->sendJsonData(_send_json);
    // clear send_obj & sen_doc
    send_obj = QJsonObject();
    send_doc = QJsonDocument();
}
