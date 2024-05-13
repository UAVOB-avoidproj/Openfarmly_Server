#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "qtmavfly.h"
#include <enumVelocityBodyYawspeed.h>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

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

private:
    Ui::Widget *ui;
    QTimer *tim;
};
#endif // WIDGET_H
