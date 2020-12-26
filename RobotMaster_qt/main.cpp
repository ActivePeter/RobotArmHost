#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQuickView>
#include <QFont>
#include "PathPainter/PathPainter.h"

void registQmlCommunicator()
{
    qmlRegisterType<PathPainter>("PathPainter", 1, 0, "PathPainter");
    qmlRegisterType<PathPainter>("PathPainter", 1, 0, "PathPainter");
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    registQmlCommunicator();
    //    QQmlApplicationEngine engine;

    QQuickStyle::setStyle("Material");
    QFont f("Microsoft JhengHei", 10);
    app.setFont(f);

    QQuickView *view = new QQuickView;
    view->setResizeMode(QQuickView::SizeRootObjectToView);
    view->setMinimumSize(QSize(250, 200));
    view->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    // view->show();
    //    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    //    if (engine.rootObjects().isEmpty())
    //        return -1;

    return app.exec();
}
