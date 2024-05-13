#include "widget.h"
#include "mavsdk_simplify.hpp"
#include <QApplication>
#include <iostream>
#include <QThread>
#include <QObject>

#include "qtmavfly.h"
QtMAVfly qtmavfly;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    // During Qt remote run/debug, std::cout invalid. Set to unbuffered mode
    std::cout.setf(std::ios::unitbuf);

//    QObject::connect(&qtmavfly, &QtMAVfly::QtMavsdk_Init_start, &qtmavfly, &QtMAVfly::QtMavsdk_Init);
    //QObject::connect(&qtmavfly, &QtMAVfly::QtMavsdk_Init_rt, );

    return a.exec();
}
