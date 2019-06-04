#ifndef WIFIBOT_H
#define WIFIBOT_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QTimer>
#include <QMutex>
#include <QString>

class Wifibot : public QObject {
    Q_OBJECT
public:
    typedef struct dataInType{
        int SpeedFront;
        qint8 BatLevel;
        int IR;
        int IR2;
        int odometry;
        int Current;
        int Version;
    }dataInType;

    dataInType *dataL, *dataR;

    explicit Wifibot(QObject *parent = nullptr);
    void doConnect(QString ipAddress, quint16 port);
    void disConnect();
    QByteArray DataToSend;
    QByteArray DataReceived;
    QMutex Mutex;
    short Crc16(unsigned char *Adresse_tab, unsigned char Taille_max);
    void moveBack();


signals:
    void readCompleted();
public slots :
    void connected();
    void readyRead();
    void disconnected();
    void bytesWritten(qint64 bytes);
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

#endif // WIFIBOT_H
