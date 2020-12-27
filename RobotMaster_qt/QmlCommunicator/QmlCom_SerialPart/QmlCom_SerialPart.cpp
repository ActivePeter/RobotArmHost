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

void QmlCom_SerialPart::emit_connectionStateChange(bool connected)
{
    emit connectionStateChange(connected);
}

void QmlCom_SerialPart::emit_scanStateChange(bool found)
{
    emit scanStateChange(found);
}
