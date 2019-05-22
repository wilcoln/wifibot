#ifndef MYROBOT_H
#define MYROBOT_H

#include "mainwindow.h"

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QTimer>
#include <QMutex>
#include <QString>

class MyRobot : public QObject {
    Q_OBJECT
public:
    explicit MyRobot(QObject *parent = nullptr);
    void doConnect(QString ipAddress, quint16 port);
    void disConnect();
    QByteArray DataToSend;
    QByteArray DataReceived;
    QMutex Mutex;

    MyRobot(QObject *parent, MainWindow *w);
signals:
    void updateUI(const QByteArray Data);
public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
    void MyTimerSlot();

    void readData(QByteArray *receivedData);
    void sendData(QByteArray *sendData);
    void moveLeft();
    void moveForward();
    void moveRight();
private:
    QTcpSocket *socket;
    QTimer *TimerEnvoi;
    MainWindow *window;
};

#endif // MYROBOT_H
