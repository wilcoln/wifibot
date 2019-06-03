#include "mainwindow.h"
#include "wifibot.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.robot = new Wifibot(nullptr);
    w.show();
    return a.exec();
}
