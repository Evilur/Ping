#include "util/path.h"
#include "config/settings.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char* argv[]) {
    /* Init static classes */
    Path::Init();
    Settings::Init();

    /* Read the settings from the config file */
    Settings::Read();

    /* Create a GUI application object */
    QGuiApplication app(argc, argv);

    /* Create a QML engine */
    QQmlApplicationEngine engine;

    /* Load the main window url */
    const QUrl url(QStringLiteral("qrc:/app/MainWindow.qml"));
    engine.load(url);

    /* Run the application */
    return app.exec();
}