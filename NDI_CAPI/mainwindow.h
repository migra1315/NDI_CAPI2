#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QObject>
#include <QThread>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QByteArray>
#include "processtrackingdata.h"

#ifdef _WIN32
    // For Windows Sleep(ms)
    #include <windows.h>
#else
    // For POSIX sleep(sec)
    #include <unistd.h>
#endif

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "CombinedApi.h"
#include "PortHandleInfo.h"
#include "ToolData.h"

using namespace std;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //-----------------------------连接和配置信息-----------------------------
    string hostname;
    const char *ToolDefine1;
    const char *ToolDefine2;
    QSharedMemory *sharememory;

    // -----------------------------以下是NDI连接相关函数-----------------------------
    bool startConfig();
    QByteArray startTracking(int);
    QByteArray startTrackingSimulate();
    //以下是官方提供，稍作修改
    void sleepSeconds(unsigned numSeconds);
    bool onErrorPrintDebugMessage(std::string methodName, int errorCode);
    std::string getToolInfo(std::string toolHandle);
    std::string toolDataToCSV(const ToolData& toolData);
    void writeCSV(std::string fileName, int numberOfLines);
    void printToolData(const ToolData& toolData);
    void printTrackingData();
    bool initializeAndEnableTools();
    bool loadTool(const char* toolDefinitionFilePath);
    bool configurePassiveTools();
    void configureUserParameters();
    void simulateAlerts(uint32_t simulatedAlerts = 0x00000000);
    void determineApiSupportForBX2();
    // -----------------------------以上是NDI连接相关函数-----------------------------

private:
    Ui::MainWindow *ui;
    CombinedApi *capi;
    bool apiSupportsBX2;
    int option_id;
    uint16_t options;

signals:
    void sendSignal(QString);

private slots:
    void recSlot(QString);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // MAINWINDOW_H
