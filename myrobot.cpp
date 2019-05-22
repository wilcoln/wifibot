// myrobot.cpp

#include "mainwindow.h"
#include "myrobot.h"

MyRobot::MyRobot(QObject *parent, MainWindow *w) : QObject(parent) {
    window = w;
    DataToSend.resize(9);
    DataToSend[0] = 0xFF;
    DataToSend[1] = 0x07;
    DataToSend[2] = 0xF0;
    DataToSend[3] = 0x0;
    DataToSend[4] = 0xF0;
    DataToSend[5] = 0x0;
    DataToSend[6] = 0x50;
    DataToSend[7] = 0x0;
    DataToSend[8] = 0x0;

    DataReceived.resize(21);
    TimerEnvoi = new QTimer();
    // setup signal and slot
    connect(TimerEnvoi, SIGNAL(timeout()), this, SLOT(MyTimerSlot())); //Send data to wifibot timer
}

void MyRobot::moveForward(){
    DataToSend[2] = 120;
    DataToSend[3] = 120;
    DataToSend[4] = 120;
    DataToSend[5] = 120;
    DataToSend[6] = 80;
}

void MyRobot::moveLeft(){
    DataToSend[2] = 120;
    DataToSend[3] = 0;
    DataToSend[4] = 0;
    DataToSend[5] = 0;
    DataToSend[6] = 64;
}

void MyRobot::moveRight(){
    DataToSend[2] = 0;
    DataToSend[3] = 0;
    DataToSend[4] = 120;
    DataToSend[5] = 0;
    DataToSend[6] = 16;
}

void MyRobot::doConnect(QString ipAddress, quint16 port) {
    socket = new QTcpSocket(this); // socket creation
    connect(socket, SIGNAL(connected()),this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    qDebug() << "connecting..."; // this is not blocking call
    socket->connectToHost(ipAddress, port); // connection to wifibot
    // we need to wait...
    if(!socket->waitForConnected(5000)) {
        qDebug() << "Error: " << socket->errorString();
        return;
    }
    TimerEnvoi->start(75);

}

void MyRobot::disConnect() {
    TimerEnvoi->stop();
    socket->close();
}

void MyRobot::connected() {
    qDebug() << "connected..."; // Hey server, tell me about you.
}

void MyRobot::disconnected() {
    qDebug() << "disconnected...";
}

void MyRobot::bytesWritten(qint64 bytes) {
    qDebug() << bytes << " bytes written...";
}

void MyRobot::readyRead() {
    qDebug() << "reading..."; // read the data from the socket
    DataReceived = socket->readAll();
    emit updateUI(DataReceived);
    qDebug() << DataReceived[0] << DataReceived[1] << DataReceived[2];
    window->updateReceivedTrame(&DataReceived);
}

void MyRobot::MyTimerSlot() {
    qDebug() << "Timer...";
    while(Mutex.tryLock());
    DataToSend[2] = DataToSend[2] + 120;
    DataToSend[3] = DataToSend[3] + 120;
    DataToSend[4] = DataToSend[4] + 120;
    DataToSend[5] = DataToSend[5] + 120;
    DataToSend[6] = 80;
    socket->write(DataToSend);
    Mutex.unlock();
    window->updateSentTrame(&DataToSend);
}
void MyRobot::readData(QByteArray* receivedData) {
}
void  MyRobot::sendData(QByteArray* sentData) {
}
