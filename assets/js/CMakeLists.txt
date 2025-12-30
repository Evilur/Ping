ADD_LIBRARY(AppJS STATIC)
QT_ADD_QML_MODULE(AppJS
    URI App.JS
    QML_FILES
        chat_type.mjs
        color.mjs
    RESOURCE_PREFIX "/"
    OUTPUT_DIRECTORY "App/JS"
)
