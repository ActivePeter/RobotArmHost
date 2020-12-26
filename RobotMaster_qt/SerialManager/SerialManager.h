#ifndef __SERIALMANAGER_H__
#define __SERIALMANAGER_H__
#include "QSerialPort"     //串口访问
#include "QSerialPortInfo" //串口端口信息访问
class SerialManager
{
public:
    void init();
    static SerialManager instance;

private:
    QSerialPort qSerialPort;
    QString portName;
    bool deviceFound=false;
    void lookForDevice();
    void onDeviceFound(const QString &portName);
};

#endif // __SERIALMANAGER_H__