#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "person.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Person>("io.qt.examples.person", 1, 0, "Person");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
