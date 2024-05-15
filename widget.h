#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "qtmavfly.h"
#include <enumVelocityBodyYawspeed.h>
#include <QTimer>
#include "servertcp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
extern serverTCP *servertcp;
extern QtMAVfly *qtmavfly;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

signals:
    void pushButton_test1();

public slots:

private slots:
    void on_QtMavsdk_Init_clicked();
    void on_QtsetOffboard_VBY_clicked();
    void on_QtOffboard_Init_clicked();
    void on_QtOffboard_Start_clicked();
    void on_QtOffboard_Stop_clicked();
    void on_QtAction_takeoff_clicked();
    void on_QtAction_land_clicked();

    void ui_QttimeCallback();

    void on_start_flydataMonitor_clicked();

    void on_QtsetOffboard_VBY_2_clicked();



    void on_pushButton_test1_clicked();

private:
    Ui::Widget *ui;
    QTimer *tim;
};
#endif // WIDGET_H
