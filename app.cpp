#include <QtWidgets/QApplication>
#include <QtQml>
#include <QQmlApplicationEngine>
#include <QtQuick/QQuickView>
#include <QtCore/QDir>
#include <QtQml/QQmlEngine>
#include <QtGui/QGuiApplication>
#include <QQmlContext>
#include "application.h"
//#include "view/radialbar.h"

#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQuickView viewer;
    QQmlApplicationEngine engine;
    QObject::connect(viewer.engine(), &QQmlEngine::quit, &viewer, &QWindow::close);

    Application application;

    engine.rootContext()->setContextProperty("application", &application);
    engine.rootContext()->setContextProperty("bleDeviceModel", application.getBleModelDevice());
    engine.rootContext()->setContextProperty("bleServicesModel", application.getBleModelServices());

    engine.load(QUrl(QStringLiteral("qrc:/qml/qml/app.qml")));

    return app.exec();
}
