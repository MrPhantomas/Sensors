/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *LE_Period;
    QLineEdit *LE_VkID;
    QLabel *label;
    QLabel *label_2;
    QPushButton *btn_SaveConfig;
    QPushButton *btn_EnableDisable;
    QLabel *label_3;
    QPushButton *btn_Exit;
    QTableWidget *tableWidget;
    QLineEdit *LE_PeriodWeb;
    QLabel *label_4;
    QComboBox *cmbComPort;
    QLabel *label_5;
    QPushButton *btn_Update;
    QCheckBox *chbx_SendWeb;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(743, 217);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        LE_Period = new QLineEdit(centralWidget);
        LE_Period->setObjectName(QString::fromUtf8("LE_Period"));
        LE_Period->setGeometry(QRect(120, 50, 131, 20));
        LE_VkID = new QLineEdit(centralWidget);
        LE_VkID->setObjectName(QString::fromUtf8("LE_VkID"));
        LE_VkID->setGeometry(QRect(120, 70, 131, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 50, 101, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 101, 16));
        btn_SaveConfig = new QPushButton(centralWidget);
        btn_SaveConfig->setObjectName(QString::fromUtf8("btn_SaveConfig"));
        btn_SaveConfig->setGeometry(QRect(10, 150, 141, 21));
        btn_EnableDisable = new QPushButton(centralWidget);
        btn_EnableDisable->setObjectName(QString::fromUtf8("btn_EnableDisable"));
        btn_EnableDisable->setGeometry(QRect(10, 170, 141, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(300, 10, 71, 16));
        btn_Exit = new QPushButton(centralWidget);
        btn_Exit->setObjectName(QString::fromUtf8("btn_Exit"));
        btn_Exit->setGeometry(QRect(10, 190, 141, 21));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(340, 40, 401, 175));
        tableWidget->horizontalHeader()->setDefaultSectionSize(60);
        LE_PeriodWeb = new QLineEdit(centralWidget);
        LE_PeriodWeb->setObjectName(QString::fromUtf8("LE_PeriodWeb"));
        LE_PeriodWeb->setGeometry(QRect(120, 90, 131, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 90, 101, 16));
        cmbComPort = new QComboBox(centralWidget);
        cmbComPort->setObjectName(QString::fromUtf8("cmbComPort"));
        cmbComPort->setGeometry(QRect(120, 110, 131, 22));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 110, 91, 16));
        btn_Update = new QPushButton(centralWidget);
        btn_Update->setObjectName(QString::fromUtf8("btn_Update"));
        btn_Update->setGeometry(QRect(260, 110, 61, 23));
        chbx_SendWeb = new QCheckBox(centralWidget);
        chbx_SendWeb->setObjectName(QString::fromUtf8("chbx_SendWeb"));
        chbx_SendWeb->setGeometry(QRect(180, 140, 111, 20));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320\275\320\276\321\201\321\202\321\214 (\321\201)", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "ID \320\277\320\276\320\273\321\203\321\207\320\260\321\202\320\265\320\273\321\217", nullptr));
        btn_SaveConfig->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        btn_EnableDisable->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\232\320\273\320\270\320\265\320\275\321\202", nullptr));
        btn_Exit->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\202\320\260\320\275", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\277\320\260\320\275", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\223\320\260\320\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "T (c)", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\222\320\265\320\261(\321\201)", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "COM  port", nullptr));
        btn_Update->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        chbx_SendWeb->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\273\321\217\321\202\321\214 \320\262 \320\262\320\265\320\261", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
