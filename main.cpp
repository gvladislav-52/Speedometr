#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "speedometr.h"
#include "QTimer"
#include "QTime"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<Speedometr>("com.ulasdikme.speedometer",1,0,"Speedometer");
    const QUrl url(u"qrc:/untitled10/main.qml"_qs);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    QObject *object = engine.rootObjects()[0];
    QObject *speedometer = object->findChild<QObject*>("speedoMeter");

    Speedometr * ptrSpeedometr = qobject_cast<Speedometr*>(speedometer);
    qreal val = 0;
    ptrSpeedometr->setSpeed(val);

    QTimer timer1;
    QObject::connect(&timer1, &QTimer::timeout, [&]()
                     {
                         val = val  + 10;
                         ptrSpeedometr->setSpeed(val);
                     });

    timer1.start(100);

    return app.exec();
}
