#include "mainwindow.h"
#include "myrobot.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    MyRobot robot(nullptr, &w);
    QString ipAdress = "192.168.1.106";
    robot.doConnect(ipAdress, 15020);
    //robot.disConnect();
    robot.moveForward();
    w.show();
    return a.exec();
}
