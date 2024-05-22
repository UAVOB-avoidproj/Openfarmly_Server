#include "widget.h"
#include "mavsdk_simplify.hpp"
#include <QApplication>
#include <iostream>
#include <QThread>
#include <QObject>

#include "servertcp.h"
#include "qtmavfly.h"
#include "serverjson.h"

QtMAVfly *qtmavfly;
serverTCP *servertcp;
serverJSON *serverjson;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    qtmavfly = new QtMAVfly();
    servertcp = new serverTCP();
    serverjson = new serverJSON();

    // During Qt remote run/debug, std::cout invalid. Set to unbuffered mode
    std::cout.setf(std::ios::unitbuf);

//    servertcp

    return a.exec();
}
