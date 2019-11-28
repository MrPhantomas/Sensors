#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QNetworkAccessManager>
#include <QQueue>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMutex>

struct Dachvalue{
    Dachvalue(){}
    Dachvalue(QString tmp_m,QString tmp_p,QString tmp_g,QString tmp_t,QString tmp_tm)
    {
        metan = tmp_m;
        propan = tmp_p;
        gas = tmp_g;
        temperature = tmp_t;
        time = tmp_tm;
    }

    QString metan;
    QString propan;
    QString gas;
    QString temperature;
    QString time;
};


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_EnableDisable_clicked();
    void sendJson();
    void on_btn_Exit_clicked();
    void procSerialDataReceive();
    void on_btn_SaveConfig_clicked();
    void show_data();
    void on_btn_Update_clicked();

private:
    QString comPortName;
    void FindComPorts();
    QSerialPort* serial;
    void initSerial();
    bool sendWeb;
    QTimer *tmrSendJson;
    QMutex mutexSendJson;
    bool active;
    QTimer *tmr;
    Ui::MainWindow *ui;
    QNetworkAccessManager *networkManager;
    QQueue<Dachvalue> queue;
    QMutex mutex;
    QString user_id;
    QString metan_osn;
    QString propan_osn;
    QString gas_osn;
    QString temperature_osn;
    QString time_osn;
};

#endif // MAINWINDOW_H
