#include "mainwindow.h"
#include "myrobot.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.robot = new MyRobot(nullptr);
    //QString ipAdress = "192.168.1.106";
    //w.robot->doConnect(ipAdress, 15020);
    w.show();
    return a.exec();
}
