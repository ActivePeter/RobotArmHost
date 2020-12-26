#ifndef __QMLCOM_SERIALPART_H__
#define __QMLCOM_SERIALPART_H__
#include <QObject>
#include <QQueue>
class QmlCom_SerialPart : public QObject

{
    Q_OBJECT

public:
    explicit QmlCom_SerialPart(QObject *parent = 0);
    static QmlCom_SerialPart *instance;
    // Q_INVOKABLE QString getAttitude();
    // Q_INVOKABLE float getAttitudes(int id, int index);
    // Q_INVOKABLE
    // static QmlCppInterface *instance;
signals:
    void connectionStateChange();
    void scanStateChange();

public slots:

    // void setAttitude(float x, float y, float z);
    // void startMqtt();

private:
};
#endif // __QMLCOM_SERIALPART_H__