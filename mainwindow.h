#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "wifibot.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateSentLabel(QString newText);
    void updateReceivedLabel(QString newText);
    Wifibot *robot;

    void updateBatteryLevel();
    void updateIRSensorLabel();
    void updateSpeedLabel();
    void updateCurrentLabel();
    void updateOdomeryLabel();
public slots:
    void updateSendTest();
    void updateReceivedTest();
    void updateSentTrame(QByteArray *sentData);
    void updateReceivedTrame(QByteArray *receivedData);

    void updateInfos(dataInType* dataL, dataInType* dataR);
private slots:
    void on_upBoutton_clicked();

    void on_rightBoutton_clicked();

    void on_LeftBoutton_clicked();

    void on_connectBoutton_clicked();

    void on_disconnectBoutton_clicked();

    void on_downBouton_clicked();

    void on_speedSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
