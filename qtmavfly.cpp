#include "qtmavfly.h"
#define wait_time 3

QtMAVfly::QtMAVfly(QObject *parent) : QObject(parent)
{
}
QtMAVfly::~QtMAVfly(){}

void QtMAVfly::QtMavsdk_Init(){
    int rt = 0;
    std::thread thread(Mavsdk_Init, &rt);
    thread.detach();
    while(1){
        if(rt == 0) std::cout << "mavsdk_init ……\n";
        if(rt == 1) {std::cout << "mavsdk_init success" << std::endl;break;}
        if(rt == -1) {std::cout << "mavsdk_init failed\n";break;}
        sleep_for(seconds(1));
    }

    emit QtMavsdk_Init_rt(rt);
}
void QtMAVfly::QtOffboard_Init(){

    int rt = 0;
    std::thread thread(Offboard_Init, &rt, wait_time);
    thread.detach();
    while(1){
        if(rt == 0) std::cout << "offboard_init ……\n";
        if(rt == 1) {std::cout << "offboard_init successful!\n";break;}
        if(rt == -1) {std::cerr << "offboard_init failed\n";break;}
//        std::cout.flush();
        sleep_for(seconds(1));
    }
    emit QtOffboard_Init_rt(rt);
}
void QtMAVfly::QtOffboard_Start(){
    int rt = 0;
    std::thread thread(Offboard_Start, &rt);
    thread.detach();
    while(1){
        if(rt == 0) std::cout << "offboard_start ……\n";
        if(rt == 1) {std::cout << "offboard_start successful!\n";break;}
        if(rt == -1) {std::cerr << "offboard_start failed\n";break;}
        sleep_for(seconds(1));
    }


    emit QtOffboard_Start_rt(rt);
}
void QtMAVfly::QtOffboard_Stop(){
    int rt = 0;
    std::thread thread(Offboard_Stop, &rt);
    thread.detach();
    while(1){
        if(rt == 0) std::cout << "offboard_stop ……\n";
        if(rt == 1) {std::cout << "offboard_stop successful!\n";break;}
        if(rt == -1) {std::cerr << "offboard_stop failed\n";break;}
        sleep_for(seconds(1));
    }

    emit QtOffboard_Stop_rt(rt);
}

void QtMAVfly::QtsetOffboard_VBY(mavsdk::Offboard::VelocityBodyYawspeed VBYvalue){
    int rt = 0;
    setOffboard_VBY(VBYvalue);
    rt = 1;
    emit QtsetOffboard_VBY_rt(rt);
}
void QtMAVfly::QtAction_takeoff(){
    int rt = 0;
    std::thread thread_takeoff(Action_takeoff, &rt, 3);
    thread_takeoff.detach();
    while(1){
        if(rt == 0) std::cout << "Action_takeoff ……\n";
        if(rt == 1) {std::cout << "Action_takeoff successful!\n";break;}
        if(rt == -1) {std::cerr << "Action_takeoff failed\n";break;}
        sleep_for(seconds(1));
    }

    emit QtAction_takeoff_rt(rt);
}
void QtMAVfly::QtAction_land(){
    int rt = 0;
    std::thread thread_land(Action_land, &rt);
    thread_land.detach();
    while(1){
        if(rt == 0) std::cout << "Action_land ……\n";
        if(rt == 1) {std::cout << "Action_land successful!\n";break;}
        if(rt == -1) {std::cerr << "Action_land failed\n";break;}
        sleep_for(seconds(1));
    }

    emit QtAction_land_rt(rt);
}
void QtMAVfly::QtReturn_to_Launch(){
    int rt = 0;
    std::thread thread_rtl(Return_to_Launch, &rt);
    thread_rtl.detach();
    while(1){
        if(rt == 0) std::cout << "Return_to_Launch ……\n";
        if(rt == 1) {std::cout << "Return_to_Launch successful!\n";break;}
        if(rt == -1) {std::cerr << "Return_to_Launch failed\n";break;}
        sleep_for(seconds(1));
    }

    emit QtReturn_to_Launch_rt(rt);
}

