import QtQuick

Item {
    clip: true

    MouseArea {
        anchors.fill: parent

        onWheel: (wheel) => {
            for (let i = 0; i < parent.children.length; i++) {
                /* Scroll the object */
                const item = parent.children[i];
                item.y += wheel.angleDelta.y;

                /* Create the stoppers */
                if (item.y > 0) item.y = 0;
                const minY = parent.height - item.height;
                if (item.y < minY) item.y = minY;
            }
        }
    }
}