ADD_LIBRARY(AppCore SHARED)
QT_ADD_QML_MODULE(AppCore
    URI App
    QML_FILES
        MainWindow.qml
    RESOURCE_PREFIX "/"
    OUTPUT_DIRECTORY "App"
)
