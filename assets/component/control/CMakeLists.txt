ADD_LIBRARY(AppControl SHARED)
SET_SOURCE_FILES_PROPERTIES(ToolTip.qml PROPERTIES
    QT_QML_SINGLETON_TYPE TRUE
)
QT_ADD_QML_MODULE(AppControl
    URI App.Control
    QML_FILES
        Button.qml
        Scrollable.qml
        ToolTip.qml
    RESOURCE_PREFIX "/"
    OUTPUT_DIRECTORY "App/Control"
)
