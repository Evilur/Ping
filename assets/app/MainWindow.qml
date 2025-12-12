import QtQuick
import "qrc:/component/control"
import "qrc:/js/color.mjs" as Color

Window {
    id: root
    visible: true
    width: 1280
    height: 720
    title: 'Ping'

    /* Status Bar */
    Rectangle {
        id: statusBar
        width: parent.width
        height: 45
        color: Color.mantle

        /* Action Buttons */
        component ActionButton: Rectangle {
            height: parent.height
            width: parent.height * 2
            property alias source: image.source

            /* Default and hover colors */
            color: "transparent"
            property string hoverColor: Color.grey_05

            /* OnClicked signal */
            signal clicked()

            Image {
                id: image
                anchors.centerIn: parent
                fillMode: Image.PreserveAspectFit
            }

            MouseArea {
                /* Fill the parent */
                anchors.fill: parent

                /* Change the background color on mouse over */
                hoverEnabled: true
                onEntered: parent.color = parent.hoverColor
                onExited: parent.color = "transparent"

                /* Change the cursors type to pointer */
                cursorShape: Qt.PointingHandCursor

                /* Send the onClicked signal */
                onClicked: parent.clicked();
            }
        }
        ActionButton {
            id: collapseButton
            anchors.right: maximizeButton.left
            anchors.top: parent.top
            source: 'qrc:/img/status-bar/collapse.svg'
        }
        ActionButton {
            id: maximizeButton
            anchors.right: closeButton.left
            anchors.top: parent.top
            source: 'qrc:/img/status-bar/maximize.svg'
        }
        ActionButton {
            id: closeButton
            hoverColor: Color.red
            anchors.right: parent.right
            anchors.top: parent.top
            source: 'qrc:/img/status-bar/close.svg'
        }
    }

    /* Chat List */
    Rectangle {
        id: chatList
        width: 500
        height: root.height - statusBar.height
        anchors.left: statusBar.left
        anchors.top: statusBar.bottom
        color: Color.mantle

        property real minWidth: 75

        function resize(newWidth = 0): void {
            if (newWidth !== 0 && (newWidth > 300 || newWidth < this.minWidth))
                this.width = newWidth;
            if (messageArea.width < 350) this.width = root.width - 350;
            if (this.width < 250) this.width = this.minWidth;
        }

        /* Resizer */
        MouseArea {
            height: parent.height
            width: 20
            cursorShape: Qt.SizeHorCursor
            anchors.horizontalCenter: parent.right
            anchors.top: parent.top
            onPositionChanged: (mouse) => {
                parent.resize(parent.width + mouse.x - this.width / 2);
            }
        }
    }

    /* Message Area */
    Rectangle {
        id: messageArea
        width: root.width - chatList.width
        height: chatList.height
        anchors.left: chatList.right
        anchors.top: statusBar.bottom
        color: Color.base
    }

    /* Resize the chat list */
    onWidthChanged: chatList.resize();
}