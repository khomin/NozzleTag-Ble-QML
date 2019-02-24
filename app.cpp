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

#include "source/bluetooth/AnimalModel.h"
#include "source/bluetooth/animal.h"

#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQuickView viewer;

//    QmlTranslator qmlTranslator;

    QQmlApplicationEngine engine;
    // and register it as a context in Qml layer
//    engine.rootContext()->setContextProperty("qmlTranslator", &qmlTranslator);

    QObject::connect(viewer.engine(), &QQmlEngine::quit, &viewer, &QWindow::close);

//    Model *interfaceModel = new Model();
    Application *application = new Application();

    viewer.rootContext()->setContextProperty("application", application);

//    qmlRegisterType<RadialBar>("CustomControls", 1, 0, "RadialBar");

//    viewer.rootContext()->setContextProperty("myModel", application->getBleModel());

//    AnimalModel model;
//    viewer.rootContext()->setContextProperty("myModel", &model);
//    model.addAnimal(new Animal("Wolf", "Medium"));

//    QTimer::singleShot(1000, [&] {
//        model.addAnimal(new Animal("Polar bear", "Large"));
//        model.addAnimal(new Animal("Quoll", "Small"));
//    });

    viewer.setSource(QUrl("qrc:/qml/qml/app.qml"));

    return app.exec();
}
