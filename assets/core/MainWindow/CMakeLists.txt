ADD_LIBRARY(AppMainWindow SHARED)
QT_ADD_QML_MODULE(AppMainWindow
    URI App.MainWindow
    QML_FILES
        BurgerMenu.qml
        Chat.qml
        ChatList.qml
        MessageArea.qml
        StatusBar.qml
    RESOURCE_PREFIX "/"
    OUTPUT_DIRECTORY "App/MainWindow"
)
