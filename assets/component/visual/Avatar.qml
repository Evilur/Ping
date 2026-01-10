import QtQuick
import Qt5Compat.GraphicalEffects

Image {
    /* Avatar size */
    sourceSize {
        width: size
        height: size
    }
    property real size

    /* Circle mask */
    Rectangle {
        id: mask
        anchors.fill: parent
        radius: width / 2
        visible: false
    }

    /* Round the avatar */
    layer.enabled: true
    layer.effect: OpacityMask { maskSource: mask }
}
