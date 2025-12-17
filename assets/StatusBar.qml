import QtQuick
import "component/control"
import "js/color.mjs" as Color

Rectangle {
    id: statusBar
    anchors {
        top: parent.top
        right: parent.right
        left: parent.left
    }
    height: 40
    color: Color.mantle

    /* Move the window by dragging the status bar */
    MouseArea {
        anchors.fill: parent
        cursorShape: Qt.OpenHandCursor

        property int clickPosX
        property int clickPosY

        /* Save the cursor position on the status bar */
        onPressed: (mouse) => {
            this.clickPosX = mouse.x
            this.clickPosY = mouse.y
        }

        /* Move the window */
        onPositionChanged: (mouse) => {
            root.x += mouse.x - this.clickPosX
            root.y += mouse.y - this.clickPosY
        }
    }

    /* Action Buttons */
    Row {
        component ActionButton: Button {
            anchors {
                top: parent.top
                bottom: parent.bottom
            }
            scale: 1
            width: height * 2
            hoverEnabled: true

            property string hoverColor: Color.grey_05
            property alias source: image.source

            Rectangle {
                anchors.fill: parent
                color: parent.containsMouse ? parent.hoverColor : 'transparent'
            }

            Image {
                id: image
                anchors.centerIn: parent
                fillMode: Image.PreserveAspectFit
            }
        }
        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
        }
        ActionButton {
            source: 'qrc:/img/status-bar/collapse.svg'
            onClicked: console.log('Collapse button is clicked')
        }
        ActionButton {
            source: 'qrc:/img/status-bar/maximize.svg'
            onClicked: console.log('Maximize button is clicked')
        }
        ActionButton {
            hoverColor: Color.red
            source: 'qrc:/img/status-bar/close.svg'
            onClicked: console.log('Close button is clicked')
        }
    }
}