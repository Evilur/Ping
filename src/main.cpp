#include "util/path.h"
#include "config/settings.h"
#include "util/logger.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char* argv[]) {
    /* Init static classes */
    Path::Init();
    Settings::Init();

    /* Create a GUI application object */
    INFO_LOG("Creating the Qt application");
    QGuiApplication app(argc, argv);

    /* Create a QML engine */
    QQmlApplicationEngine engine;

    /* Load the main window url */
    const QUrl url(QStringLiteral("qrc:/app/MainWindow.qml"));
    engine.load(url);

    /* Run the application */
    INFO_LOG("Starting the application");
    return app.exec();
}