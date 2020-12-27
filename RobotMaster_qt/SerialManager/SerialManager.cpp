#include <QDebug>
#include "SerialManager.h"
#include "pa_CommonLibOnOS/DataConv/DataConv.h"
#include "QmlCommunicator/QmlCom_SerialPart/QmlCom_SerialPart.h"

SerialManager SerialManager::instance;

void SerialManager::init()
{
    qSerialPort = new QSerialPort(this);
    qSerialPort->setDataBits(QSerialPort::Data8);
    qSerialPort->setParity(QSerialPort::NoParity);
    qSerialPort->setFlowControl(QSerialPort::NoFlowControl);
    qSerialPort->setStopBits(QSerialPort::StopBits::OneStop);
    qSerialPort->setBaudRate(QSerialPort::Baud9600);

    slaveState = SlaveState::NotFound;
    // connect(&qSerialPort, &QSerialPort::error, this, &SerialManager::onError);
    connect(qSerialPort, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(onError(QSerialPort::SerialPortError)));

    lookForDevice();
}

void SerialManager::setSlaveState(SlaveState slaveState1)
{
    this->slaveState = slaveState1;
}

SerialManager::SlaveState SerialManager::getSlaveState()
{
    return this->slaveState;
}

void SerialManager::lookForDevice()
{
    slaveState = SlaveState::NotFound;
    bool deviceFound = false;
    //通过QSerialPortInfo查找可用串口
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    { //在portBox中显示可用串口
        // ui->portBox->addItem(info.portName());
        // qDebug() << ("portName:") << info.portName() << info.description() << ("\r\n");
        if (!info.description().compare(StrConv::str2qstr("STMicroelectronics Virtual COM Port")))
        {
            onDeviceFound(info.portName());
            deviceFound = true;
            break;
        }
    }
    QmlCom_SerialPart::instance->emit_scanStateChange(deviceFound);
}
void SerialManager::onDeviceFound(const QString &portName)
{
    qSerialPort->setPortName(portName);
    qDebug() << ("deviceFound:") << portName << ("\r\n");
    slaveState = SlaveState::FoundAndNotConnect;
    // deviceFound = true;
}

void SerialManager::connectDevice()
{
    if (qSerialPort->open(QIODevice::ReadWrite))
    {
        QmlCom_SerialPart::instance->emit_connectionStateChange(true);
        slaveState = SlaveState::FoundAndConnect;
    }
    else
    {
        qDebug() << ("connectDeviceFail:") << ("\r\n");
        lookForDevice();
    }
}

void SerialManager::disconnectDevice()
{
    // qSerialPort->clear();
    qSerialPort->close();
    // qSerialPort->clear();
    // qDebug() << "disconnect:" << qSerialPort->disconnect() << "\r\n";

    QmlCom_SerialPart::instance->emit_connectionStateChange(false);
    slaveState = SlaveState::FoundAndNotConnect;
}

void SerialManager::onError(QSerialPort::SerialPortError serialPortError)
{
    switch (serialPortError)
    {
    case QSerialPort::SerialPortError::ResourceError:
        // qSerialPort->clearError();
        // qSerialPort->clearError();
        qSerialPort->close();
        // lookForDevice();
        slaveState = SlaveState::NotFound;
        // qSerialPort.
        QmlCom_SerialPart::instance->emit_scanStateChange(false);
        break;

    default:
        break;
    }

    qDebug() << "nError:" << serialPortError;
    // qSerialPort->close();
    // lookForDevice();
}

void SerialManager::onError()
{
}

// void SerialManager::onDisconnect()
// {

// }

// SerialManager::SerialManager(QObject *parent)
// {
// }
