ADD_LIBRARY(AppImage STATIC)
QT_ADD_QML_MODULE(AppImage
    URI App.Image
    RESOURCES
        chat-list/group.svg
        chat-list/notes.svg
        chat-list/person.svg
        status-bar/burger.svg
        status-bar/close.svg
        status-bar/collapse.svg
        status-bar/maximize.svg
    RESOURCE_PREFIX "/"
    OUTPUT_DIRECTORY "App/Image"
)
