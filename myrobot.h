#ifndef MYROBOT_H
#define MYROBOT_H

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
    typedef struct dataInType{
        int SpeedFront;
        int BatLevel;
    }dataInType;



    explicit MyRobot(QObject *parent = nullptr);
    void doConnect(QString ipAddress, quint16 port);
    void disConnect();
    QByteArray DataToSend;
    QByteArray DataReceived;
    QMutex Mutex;
    short Crc16(unsigned char *Adresse_tab, unsigned char Taille_max);
    void moveBack();
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
};

#endif // MYROBOT_H
