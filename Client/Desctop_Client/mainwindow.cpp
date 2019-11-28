#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QUrl>
#include <QDateTime>
#include <QSerialPort>
#include <QSerialPortInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    FindComPorts();
    this->sendWeb = false;
    this->serial = nullptr;
    Dachvalue tmp("0","0","0","0","0");
    queue.push_back(tmp);
    queue.push_back(tmp);
    queue.push_back(tmp);
    queue.push_back(tmp);
    queue.push_back(tmp);

    tmr = new QTimer();
    tmr->setInterval(10000);
    tmrSendJson = new QTimer();
    tmrSendJson->setInterval(10000);

    active = false;
    user_id = "271136939";

    connect(tmr, SIGNAL(timeout()), this, SLOT(show_data()));
    connect(tmrSendJson, SIGNAL(timeout()), this, SLOT(sendJson()));
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    ui->LE_VkID->setText("271136939");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FindComPorts()
{
    ui->cmbComPort->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        qDebug() << "Name : " << info.portName();
        qDebug() << "Description : " << info.description();
        qDebug() << "Manufacturer: " << info.manufacturer();
        ui->cmbComPort->addItem(QString(info.portName()));
    }
}

void MainWindow::on_btn_Update_clicked()
{
    FindComPorts();
}

void MainWindow::on_btn_EnableDisable_clicked()
{
    active = !active;
    if(active)
    {
        ui->btn_EnableDisable->setText("Остановить");
        qDebug()<<"Старт";
        tmr->start();
        tmrSendJson->start();
    }
    else{
        qDebug()<<"Стоп";
        ui->btn_EnableDisable->setText("Запустить");
        tmr->stop();
        tmrSendJson->stop();
    }
}




 void MainWindow::sendJson()
 {
     if(this->sendWeb)
     {
         QString str;
         if(queue[0].metan.toDouble() > 20 || queue[0].propan.toDouble() > 20 || queue[0].gas.toDouble() > 50 )
             str = "danger_data_smoke";
         else
             str = "send_data_smoke";

         mutexSendJson.lock();
         QByteArray json = ("{"
                            "\"type\": \"" + str.toUtf8() + "\","
                            "\"object\":{"
                                 "\"user_id\": \"" + user_id.toUtf8() + "\","
                                 "\"metan\": \"" + queue[0].metan.toUtf8() + "\","
                                 "\"propan\": \"" + queue[0].propan.toUtf8() + "\","
                                 "\"gas\": \"" + queue[0].gas.toUtf8() + "\","
                                 "\"temperature\": \"" + queue[0].temperature.toUtf8() + "\","
                                 "\"datetime\": \"" + queue[0].time.toUtf8() + "\","
                                 "\"body\": \"датчик\""
                            "}}");

         mutexSendJson.unlock();
         qDebug() << "Sync" << QString::fromUtf8(json.data(), json.size());
         QUrl url;
         url.setUrl("http://phoudor11122.pythonanywhere.com");
         QNetworkRequest request(url);
         QNetworkAccessManager *manager = new QNetworkAccessManager(this);
         request.setHeader(QNetworkRequest::ContentTypeHeader,"text/json");
         manager->post(request, json);
     }
 }


void MainWindow::on_btn_Exit_clicked()
{
    QApplication::quit();
}

void MainWindow::on_btn_SaveConfig_clicked()
{
    this->tmr->setInterval(ui->LE_Period->text().toDouble()*1000);
    this->tmrSendJson->setInterval(ui->LE_PeriodWeb->text().toDouble()*1000);
    this->user_id = ui->LE_VkID->text();
    if(this->user_id == "") this->user_id = "271136939";
    this->comPortName = ui->cmbComPort->currentText();
    this->sendWeb = ui->chbx_SendWeb->isChecked();
    if(this->serial != nullptr)
    {
        delete this->serial;
        this->serial = nullptr;
        qDebug() <<"Удален компорт";
    }
    if(this->serial == nullptr)
    {
        initSerial();
        qDebug() <<"Инициализирован новый";
    }

}

void MainWindow::show_data()
{
    //271136939
    mutex.lock();
        QString metan = this->metan_osn;
        QString propan = this->propan_osn;
        QString gas = this->gas_osn;
        QString temperature = this->temperature_osn;
        QString time = this->time_osn;
    mutex.unlock();

    Dachvalue tmp(metan,propan,gas,temperature,time);
    mutexSendJson.lock();
    queue.pop_back();
    queue.push_front(tmp);
    mutexSendJson.unlock();
    for(unsigned short int j = 0;j<6;j++)ui->tableWidget->removeRow(0);
    for(unsigned short int i = 0;i<queue.size();i++){
         ui->tableWidget->insertRow(i);
         QTableWidgetItem *cell = new QTableWidgetItem(queue[i].metan);
         ui->tableWidget->setItem(i,0,cell);
         if(queue[i].metan.toDouble() > 20) ui->tableWidget->item(i, 0)->setBackground(Qt::red);
         cell = new QTableWidgetItem(queue[i].propan);
         ui->tableWidget->setItem(i,1,cell);
         if(queue[i].propan.toDouble()>20)ui->tableWidget->item(i, 1)->setBackground(Qt::red);
         cell = new QTableWidgetItem(queue[i].gas);
         ui->tableWidget->setItem(i,2,cell);
         if(queue[i].gas.toDouble()>50)ui->tableWidget->item(i, 2)->setBackground(Qt::red);
         cell = new QTableWidgetItem(queue[i].temperature);
         ui->tableWidget->setItem(i,3,cell);
         cell = new QTableWidgetItem(queue[i].time);
         ui->tableWidget->setItem(i,4,cell);
    }
}

void MainWindow::procSerialDataReceive()
{
    if (this->serial && this->serial->isOpen())
    {
        QByteArray byte = this->serial->readAll();
        qDebug() <<"Сообщение - "<< QString::fromUtf8(byte.data(),byte.size());
        mutex.lock();
        this->metan_osn = QString::fromUtf8(byte.data(),byte.size()).split(" ")[0];
        this->propan_osn = QString::fromUtf8(byte.data(),byte.size()).split(" ")[1];
        this->gas_osn = QString::fromUtf8(byte.data(),byte.size()).split(" ")[2];
        this->temperature_osn = QString::fromUtf8(byte.data(),byte.size()).split(" ")[3];
        this->time_osn = QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss");
        mutex.unlock();
    }
}

void MainWindow::initSerial()
{
    this->serial = new QSerialPort;
    if(this->comPortName == "")
    {
       this->comPortName = "COM3";
       ui->cmbComPort->clear();
       ui->cmbComPort->addItem(QString("COM3"));
    }

    this->serial->setPortName(this->comPortName);
    this->serial->setBaudRate(QSerialPort::Baud9600);
    this->serial->setDataBits(QSerialPort::Data8);
    this->serial->setParity(QSerialPort::NoParity);
    this->serial->setStopBits(QSerialPort::OneStop);
    this->serial->setFlowControl(QSerialPort::NoFlowControl);
    if (this->serial->open(QIODevice::ReadOnly))
    {
        qDebug() << "= Start =======";
    }

    qDebug() << "= Default parameters =";
    qDebug() << "Device name            : " << this->serial->portName();
    qDebug() << "Baud rate              : " << this->serial->baudRate();
    qDebug() << "Data bits              : " << this->serial->dataBits();
    qDebug() << "Parity                 : " << this->serial->parity();
    qDebug() << "Stop bits              : " << this->serial->stopBits();
    qDebug() << "Flow                   : " << this->serial->flowControl();

    connect(this->serial, SIGNAL(readyRead()), this, SLOT(procSerialDataReceive()));
}

