#ifndef QTMAVFLY_H
#define QTMAVFLY_H

#include <QObject>
#include <mavsdk_simplify.hpp>

class QtMAVfly : public QObject
{
    Q_OBJECT
public:
    explicit QtMAVfly(QObject *parent = nullptr);
    ~QtMAVfly();

//    const Telemetry::PositionCallback positionCallback(Telemetry::Position);

public slots:
    // Here is the qt quadratic encapsulation declaration(slots) for the libmavfly library
    void QtMavsdk_Init();
    void QtOffboard_Init();

    void QtOffboard_Start();
    void QtOffboard_Stop();

    void QtsetOffboard_VBY(mavsdk::Offboard::VelocityBodyYawspeed);
    void QtAction_takeoff();
    void QtAction_land();
    void QtReturn_to_Launch();

signals:
    // Here is a qt signals for use in the libmavfly library
//    void QtMavsdk_Init_start();
//    void QtOffboard_Init_start();
    void QtMavsdk_Init_rt(const int rt);
    void QtOffboard_Init_rt(const int rt);

    void QtOffboard_Start_rt(const int rt);
    void QtOffboard_Stop_rt(const int rt);

    void QtsetOffboard_VBY_rt(const int rt);
    void QtAction_takeoff_rt(const int rt);
    void QtAction_land_rt(const int rt);
    void QtReturn_to_Launch_rt(const int rt);



};
extern QtMAVfly qtmavfly;
#endif // QTMAVFLY_H
