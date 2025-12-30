import QtQuick
import App.Control
import App.Visual
import '../JS/color.mjs' as Color

Rectangle {
    /* Placeholder message */
    Rectangle {
        id: placeholderMessage
        anchors.centerIn: parent
        color: Color.GREY_10
        radius: 10

        width: placeholderMessageText.contentWidth + 20
        height: placeholderMessageText.contentHeight + 8

        AppText {
            id: placeholderMessageText
            text: qsTr('To start messaging open a chat or create a new one')
            anchors.centerIn: parent
            color: Color.TEXT
            font.pixelSize: 18
            wrapMode: Text.WordWrap
            width: Math.min(implicitWidth, messageArea.width - 50)
            horizontalAlignment: Text.AlignHCenter
        }
    }
}
