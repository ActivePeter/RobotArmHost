#include "QmlCom_SerialPart.h"
#include "SerialManager/SerialManager.h"

QmlCom_SerialPart::QmlCom_SerialPart(QObject *parent)
{
    QmlCom_SerialPart::instance = this;
    SerialManager::instance.init();
}
