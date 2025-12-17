import QtQuick
import "component/control"
import "js/color.mjs" as Color

Window {
    id: root
    visible: true
    width: 1280
    height: 720
    minimumWidth: 425
    minimumHeight: 450
    title: 'Ping'

    StatusBar { id: statusBar }

    ChatList { id: chatList }

    MessageArea { id: messageArea }

    /* Resize the chat list */
    onWidthChanged: chatList.resize()
}