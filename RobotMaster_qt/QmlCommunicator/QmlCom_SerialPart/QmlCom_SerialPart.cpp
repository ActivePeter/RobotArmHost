#include "QmlCom_SerialPart.h"
#include "SerialManager/SerialManager.h"
QmlCom_SerialPart *QmlCom_SerialPart::instance;
QmlCom_SerialPart::QmlCom_SerialPart(QObject *parent)
{
    QmlCom_SerialPart::instance = this;
}

Q_INVOKABLE void QmlCom_SerialPart::initSerial()
{
    SerialManager::instance.init();
}

Q_INVOKABLE void QmlCom_SerialPart::onClick_ConnectBtn()
{
    switch (SerialManager::instance.getSlaveState())
    {
    case SerialManager::NotFound:
        SerialManager::instance.lookForDevice();
        break;

    case SerialManager::FoundAndConnect:
        SerialManager::instance.disconnectDevice();
        break;
    case SerialManager::FoundAndNotConnect:
        SerialManager::instance.connectDevice();
        break;
    }
}

void QmlCom_SerialPart::emit_connectionStateChange(bool connected)
{
    emit connectionStateChange(connected);
}

void QmlCom_SerialPart::emit_scanStateChange(bool found)
{
    emit scanStateChange(found);
}
