#include <QDebug>
#include <QTimer>
#include "SerialManager.h"
#include "pa_CommonLibOnOS/DataConv/DataConv.h"
#include "QmlCommunicator/QmlCom_SerialPart/QmlCom_SerialPart.h"
#include "PathBuilder/PathBuilder.h"
#include "PathPainter/PathPainter.h"
#include "qmath.h"
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
    connect(qSerialPort, SIGNAL(readyRead()), this, SLOT(receiveInfo()));
    lookForDevice();
}
void SerialManager::receiveInfo()
{
    QByteArray info = qSerialPort->readAll();
    qDebug() << "info received: " << info;
    switch (info[0])
    {
    case 0x24:
        sendNextPointSet();
        break;

    default:
        break;
    }
    // QByteArray hexData = info.toHex();
    // //这里面的协议 你们自己定义就行  单片机发什么 代表什么 我们这里简单模拟一下
    // if (hexData == "0x10000")
    // {
    //     //do something
    // }
    // else if (hexData == "0x100001")
    // {
    //     //do something
    // }
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

void SerialManager::switchMotor(bool state)
{
    char buff[20];
    if (state) //启动
    {
        buff[0] = 0x21;
        writeData(buff, 1);
        pointReadStep = 0;
        // QTimer::singleShot(500, this, SLOT(sendNextPointSet()));
    }
    else
    {
        buff[0] = 0x22;
        writeData(buff, 1);
    }
}
// typedef struct
// {
//     char cmd;
//     PathPointStruct3D arr[5];

//     /* data */
// } PointSetCmd;

// typedef union
// {
//     struct
//     {
//         char cmd;
//         PathPointStruct3D arr[5];

//         /* data */
//     } structForm;
//     char charArrForm[61];
// } PointSetCmd;
#ifndef PI
#define PI (3.1415926535898)
#endif
void SerialManager::sendNextPointSet()
{
    // PointSetCmd psc;
    // sizeof(psc);
    // psc.cmd = 0x23;
    char buff[61];
    buff[0] = 0x23;
    // memcpy()
    PathPointStruct3D(*point_p)[5];
    point_p = (PathPointStruct3D(*)[5])(buff + 1);
    // PathPointStruct3D **pointArr = (PathPointStruct3D **)(buff + 1);
    // // PathPointStruct3D point3DArr[5];
    bool sendAble = false;
    {
        // static char curStarPoint = 0;

        // float x2 = 200 + r * cosf(angle2);
        // float y2 = 0 + r * sinf(angle2);

        for (int i = 0; i < 5; i++)
        {

            // static char lineStep = 0;
            float angle = (int)i * 4 / 5.0 * PI;
            // float angle2 = (int)(curStarPoint + 1) * 4 / 5.0 * PI;
            float r = 25;
            float x1 = 200 + r * cosf(angle);
            float y1 = 0 + r * sinf(angle);
            // (*point_p)[i].x = x1 * 1.2;
            // (*point_p)[i].y = 0;
            // (*point_p)[i].z = y1;
            sendAble = getNextPoint((*point_p)[i]);
        }
    }
    if (sendAble)
    {
        // PathPainter::

        if (PathPainter::instance)
        {
            PathPainter::instance->update();
        }
        writeData(buff, 61);
    }
}

bool SerialManager::getNextPoint(PathPointStruct3D &point)
{
    // { //test distance
    //     static int step = 0;
    //     point.y = 0;
    //     point.x = 170 + (step / 2) * 10;
    //     point.z = (step % 2) * 20;
    //     step++;
    //     step %= 8;
    // }
    {
        // static
        vector<PathPointStruct> &pointsVector = PathBuilder::instance.pathPointsVector;
        if (pointReadStep < (pointsVector.size() - 1) * 2)
        {
            if (pointReadStep % 2 == 0)
            {
                point.x = 170 + pointsVector[pointReadStep / 2].x / 2;
                point.z = 0 + pointsVector[pointReadStep / 2].y / 2;
            }
            else
            {
                point.x = 170 + pointsVector[pointReadStep / 2 + 1].x / 2;
                point.z = 0 + pointsVector[pointReadStep / 2 + 1].y / 2;
            }
            if (pointsVector[pointReadStep / 2].putDown)
            {
                point.y = 0;
            }
            else
            {
                point.y = 3;
            }
            pointReadStep++;
        }
    }

    // int
}

qint64 SerialManager::writeData(const char *data, qint64 len)
{
    if (slaveState == SlaveState::FoundAndConnect)
    {
        qSerialPort->write(data, len);
    }
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
