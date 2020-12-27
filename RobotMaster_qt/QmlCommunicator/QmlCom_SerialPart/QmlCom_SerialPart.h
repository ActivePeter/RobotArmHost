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
    Q_INVOKABLE void initSerial();
    Q_INVOKABLE void onClick_ConnectBtn();
    Q_INVOKABLE void onClick_Switch(bool checked);
    // Q_INVOKABLE float getAttitudes(int id, int index);
    // Q_INVOKABLE
    // static QmlCppInterface *instance;
    void emit_connectionStateChange(bool connected);
    void emit_scanStateChange(bool found);
signals:
    void connectionStateChange(bool connected);
    void scanStateChange(bool found);

public slots:

    // void setAttitude(float x, float y, float z);
    // void startMqtt();

private:
};

#endif // __QMLCOM_SERIALPART_H__