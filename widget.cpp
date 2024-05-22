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
    // 确保QLabel可以自动调整大小以适应图片
    ui->logo_image->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    // 图片在QLabel中居中显示（可选）
    ui->logo_image->setAlignment(Qt::AlignCenter);

    tim = new QTimer();
    tim->setInterval(1000);
    QObject::connect(tim, SIGNAL(timeout()), this,SLOT(ui_QttimeCallback()));

    QObject::connect(this, &Widget::pushButton_test1, servertcp, &serverTCP::ClientConnect);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_QtMavsdk_Init_clicked()
{
    qtmavfly->QtMavsdk_Init();
}

void Widget::on_QtOffboard_Init_clicked()
{
    qtmavfly->QtOffboard_Init();
}

void Widget::on_QtOffboard_Start_clicked()
{
    qtmavfly->QtOffboard_Start();
}

void Widget::on_QtOffboard_Stop_clicked()
{
    qtmavfly->QtOffboard_Stop();
}

void Widget::on_QtsetOffboard_VBY_clicked()
{
    qtmavfly->QtsetOffboard_VBY(vbyForward);
}

void Widget::on_QtAction_takeoff_clicked()
{
    qtmavfly->QtAction_takeoff();
}

void Widget::on_QtAction_land_clicked()
{
    qtmavfly->QtAction_land();
}
void Widget::on_QtsetOffboard_VBY_2_clicked()
{
    qtmavfly->QtReturn_to_Launch();
}

void Widget::ui_QttimeCallback(){
    // Global_position update
    Telemetry::Position _position = get_Global_Position();

    ui->latitude_value->setText(QString::number(_position.latitude_deg, 'f', 2));
    ui->longitude_value->setText(QString::number(_position.longitude_deg, 'f', 2));
//    qDebug()<<"QString::number(_position.latitude_deg, 'f', 2):"<<QString::number(_position.latitude_deg, 'f', 2);
    serverjson->addJsonArray(QJsonValue("Position"), QJsonValue(_position.latitude_deg), QJsonValue(_position.longitude_deg));
//    qDebug()<<"QJsonValue(_position.latitude_deg)"<<QJsonValue(_position.latitude_deg);

    // Flight_mode update
    QString _flightmode = QString::fromStdString(get_FlightMode());
    ui->FlightMode_value->setText(_flightmode);

    serverjson->addJsonKeyValuepair(QJsonValue("FlightMode"), QJsonValue(_flightmode));

    // Odometry update
    //position_body update
    Telemetry::Odometry odometry = get_Odometry();
    ui->label_position_x->setText(QString::number(odometry.position_body.x_m, 'f', 2));
    ui->label_position_x->setText(QString::number(odometry.position_body.y_m, 'f', 2));
    ui->label_position_x->setText(QString::number(odometry.position_body.z_m, 'f', 2));
    qDebug()<<"QJsonValue(odometry.position_body.x_m)"<<QJsonValue(odometry.position_body.x_m);
    serverjson->addJsonArray(QJsonValue("Position_body"), QJsonValue(odometry.position_body.x_m), QJsonValue(odometry.position_body.y_m), QJsonValue(odometry.position_body.z_m));
    // velocity_body update
    ui->label_velocity_x->setText(QString::number(odometry.velocity_body.x_m_s, 'f', 2));
    ui->label_velocity_y->setText(QString::number(odometry.velocity_body.y_m_s, 'f', 2));
    ui->label_velocity_z->setText(QString::number(odometry.velocity_body.z_m_s, 'f', 2));
    serverjson->addJsonArray(QJsonValue("Velocity_body"), QJsonValue(odometry.velocity_body.x_m_s), QJsonValue(odometry.velocity_body.y_m_s), QJsonValue(odometry.velocity_body.z_m_s));
    // angular_velocity_body update
    ui->label_angularvelocity_x->setText(QString::number(odometry.angular_velocity_body.roll_rad_s, 'f', 2));
    ui->label_angularvelocity_y->setText(QString::number(odometry.angular_velocity_body.pitch_rad_s, 'f', 2));
    ui->label_angularvelocity_z->setText(QString::number(odometry.angular_velocity_body.yaw_rad_s, 'f', 2));
    qDebug()<<"QJsonValue(odometry.angular_velocity_body.roll_rad_s)"<<QJsonValue(odometry.angular_velocity_body.roll_rad_s);
    serverjson->addJsonArray(QJsonValue("Angular_Velocity_body"), QJsonValue(odometry.angular_velocity_body.roll_rad_s), QJsonValue(odometry.angular_velocity_body.pitch_rad_s), QJsonValue(odometry.angular_velocity_body.yaw_rad_s));
    // eulerangle update
    Telemetry::EulerAngle _eulerangle = get_EulerAngle();
    ui->label_attitude_x->setText(QString::number(_eulerangle.roll_deg, 'f', 2));
    ui->label_attitude_y->setText(QString::number(_eulerangle.pitch_deg, 'f', 2));
    ui->label_attitude_z->setText(QString::number(_eulerangle.yaw_deg, 'f', 2));
    serverjson->addJsonArray(QJsonValue("EulerAngle"), QJsonValue(_eulerangle.roll_deg), QJsonValue(_eulerangle.pitch_deg), QJsonValue(_eulerangle.yaw_deg));

    emit serverjson->signal_sendJsonDataTCP();
}
void Widget::on_start_flydataMonitor_clicked()
{
    tim->start();
}
void Widget::on_pushButton_test1_clicked()
{
 emit pushButton_test1();
}

