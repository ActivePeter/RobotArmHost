#include <QDebug>
#include "SerialManager.h"

SerialManager SerialManager::instance;

void SerialManager::init()
{
}

void SerialManager::lookForDevice()
{
    //通过QSerialPortInfo查找可用串口
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    { //在portBox中显示可用串口
        // ui->portBox->addItem(info.portName());
        qDebug() << ("portName:") << info.portName() << info.description() << ("\r\n");
        if(info.description().compare()){

        }
    }
}

void SerialManager::onDeviceFound(const QString &portName) 
{
    
}
