ADD_LIBRARY(AppImage STATIC)
QT_ADD_QML_MODULE(AppImage
    URI App.Image
    RESOURCES
        group.svg
        notes.svg
        person.svg
        burger.svg
        close.svg
        collapse.svg
        maximize.svg
    RESOURCE_PREFIX "/"
    OUTPUT_DIRECTORY "App/Image"
)
