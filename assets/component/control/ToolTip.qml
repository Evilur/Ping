pragma Singleton
import QtQuick
import App.Visual
import '../JS/color.mjs' as Color

Window {
    width: Math.min(tooltipText.contentWidth + 18, 500)
    height: Math.min(tooltipText.contentHeight + 6, 500)
    flags: Qt.ToolTip
    color: Color.GREY_15

    function show(item, text) {
        const itemPos = item.mapToGlobal(0, 0);
        tooltipText.text = text;
        x = itemPos.x + (item.width - width) / 2;
        y = itemPos.y - height - 10;
        visible = true;
    }

    function hide() { visible = false; }

    AppText {
        id: tooltipText
        width: parent.width
        anchors.centerIn: parent
        wrapMode: Text.WordWrap
        color: Color.TEXT
        font.pixelSize: 18
        horizontalAlignment: Text.AlignHCenter
    }
}
