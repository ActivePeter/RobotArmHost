#include <QDebug>
#include "SerialManager.h"
#include "pa_CommonLibOnOS/DataConv/DataConv.h"
#
SerialManager SerialManager::instance;

void SerialManager::init()
{
    lookForDevice();
}

void SerialManager::lookForDevice()
{
    deviceFound = false;
    //通过QSerialPortInfo查找可用串口
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    { //在portBox中显示可用串口
        // ui->portBox->addItem(info.portName());
        // qDebug() << ("portName:") << info.portName() << info.description() << ("\r\n");
        if (!info.description().compare(StrConv::str2qstr("STMicroelectronics Virtual COM Port")))
        {
            onDeviceFound(info.portName());
            break;
        }
    }
}
void SerialManager::onDeviceFound(const QString &portName)
{
    qDebug() << ("deviceFound:") << portName << ("\r\n");
    deviceFound = true;

}


