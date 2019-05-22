#include "mainwindow.h"
#include "myrobot.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}
void MainWindow::updateSendTest(){
    updateSentLabel("Bonjour");
}
void MainWindow::updateReceivedTest(){
    updateReceivedLabel("Bonjour reçu");
}
void MainWindow::updateSentTrame(QByteArray* sentData){
    QString bytesText = QString::fromStdString(sentData->toStdString()) ;
    updateSentLabel(bytesText);
    qDebug() << bytesText;
}
void MainWindow::updateReceivedTrame(QByteArray* receivedData){
    QString bytesText = QString::fromStdString(receivedData->toStdString());
    updateReceivedLabel(bytesText);
    qDebug() << bytesText;
}
void MainWindow::updateSentLabel(QString newText){
    ui->sent->setText(newText);
}
void MainWindow::updateReceivedLabel(QString newText){
    ui->received->setText(newText);
}
MainWindow::~MainWindow()
{
    delete ui;
}
