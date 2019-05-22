#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

public slots:
    void updateSendTest();
    void updateReceivedTest();
    void updateSentTrame(QByteArray *sentData);
    void updateReceivedTrame(QByteArray *receivedData);
private:
    Ui::MainWindow *ui;    
};

#endif // MAINWINDOW_H
