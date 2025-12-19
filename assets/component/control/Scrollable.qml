import QtQuick
import QtQuick.Controls
import '../../js/color.mjs' as Color

Item {
    clip: true

    property Item scrollable

    /* Scrollbar */
    Rectangle {
        id: scrollbar
        width: 6
        radius: 3
        z: 9999
        anchors.right: parent.right
        height: parent.height * parent.height / scrollable.height
        y: -scrollable.y * parent.height / scrollable.height
        opacity: 0
        visible: opacity > 0
        color: Color.GREY_25

        /* Animation */
        Behavior on opacity { NumberAnimation { duration: 75 } }
    }

    /* Hide the scrollbar */
    Timer {
        id: timer
        interval: 1500
        repeat: false
        onTriggered: scrollbar.opacity = 0
    }

    /* Scroll with a mouse */
    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true

        onWheel: (wheel) => {
            /* Scroll the object */
            parent.scrollable.y += wheel.angleDelta.y;

            /* Create the stoppers */
            if (parent.scrollable.y > 0) parent.scrollable.y = 0;
            const minY = parent.height - parent.scrollable.height;
            if (parent.scrollable.y < minY) parent.scrollable.y = minY;

            /* Show the scrollbar and hide with timer */
            scrollbar.opacity = 1;
            timer.restart();
        }
    }
}