ADD_LIBRARY(AppVisual SHARED)
QT_ADD_QML_MODULE(AppVisual
    URI App.Visual
    QML_FILES
        AppText.qml
        Overlay.qml
    RESOURCE_PREFIX "/"
    OUTPUT_DIRECTORY "App/Visual"
)
