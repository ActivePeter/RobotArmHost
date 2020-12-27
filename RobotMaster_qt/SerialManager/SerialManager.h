#ifndef __SERIALMANAGER_H__
#define __SERIALMANAGER_H__
#include "QSerialPort"     //串口访问
#include "QSerialPortInfo" //串口端口信息访问

class SerialManager
{
public:
    enum SlaveState
    {
        NotFound,
        FoundAndNotConnect,
        FoundAndConnect
    };
    void init();
    static SerialManager instance;
    void setSlaveState(SlaveState slaveState);
    SlaveState getSlaveState();
    void lookForDevice();
    void connectDevice();
    void disconnectDevice();

private:
    QSerialPort qSerialPort;
    // QString portName;
    // bool deviceFound = false;

    void onDeviceFound(const QString &portName);

    SlaveState slaveState;
};

#endif // __SERIALMANAGER_H__