#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 假设ui->label是指向你的QLabel的指针
    QPixmap originalPixmap("://images/logo.png"); // 使用qrc资源文件路径
    // 设置图片按比例缩放以适应QLabel的大小，同时保持宽高比
    QPixmap scaledPixmap = originalPixmap.scaled(ui->logo_image->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    // 将缩放后的图片设置为QLabel的背景
    ui->logo_image->setPixmap(scaledPixmap);
    ui->logo_image->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored); // 确保QLabel可以自动调整大小以适应图片
    ui->logo_image->setAlignment(Qt::AlignCenter); // 图片在QLabel中居中显示（可选）
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_QtMavsdk_Init_clicked()
{
    qtmavfly.QtMavsdk_Init();
}

void Widget::on_QtOffboard_Init_clicked()
{
    qtmavfly.QtOffboard_Init();
}

void Widget::on_QtOffboard_Start_clicked()
{
    qtmavfly.QtOffboard_Start();
}

void Widget::on_QtOffboard_Stop_clicked()
{
    qtmavfly.QtOffboard_Stop();
}

void Widget::on_QtsetOffboard_VBY_clicked()
{
    qtmavfly.QtsetOffboard_VBY(vbyForward);
}

void Widget::on_QtAction_takeoff_clicked()
{
    qtmavfly.QtAction_takeoff();
}

void Widget::on_QtAction_land_clicked()
{
    qtmavfly.QtReturn_to_Launch();
}

