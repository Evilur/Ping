import QtQuick
import 'qrc:/component/control'
import 'qrc:/component/visual'
import 'qrc:/js/color.mjs' as Color
import 'qrc:/js/chat_type.mjs' as ChatType

Button {
    id: chat
    anchors {
        left: parent.left
        right: parent.right
    }
    height: chatList.minWidth
    hoverEnabled: true

    property bool isActive: false
    property alias title: chatTitle.text
    property int membersNumber: 2
    property int chatType: membersNumber <= 2 ? ChatType.PERSONAL : ChatType.GROUP
    property date lastMessageDate: new Date();

    readonly property real margin: 12.5

    /* Background */
    Rectangle {
        color: parent.isActive ? Color.BLUE_BRIGHT :
            parent.containsMouse ? Color.GREY_00 :
                'transparent'
        anchors.fill: parent
    }

    /* Avatar */
    Rectangle {
        id: chatAvatar
        anchors {
            left: parent.left
            top: parent.top
            margins: parent.margin
        }
        width: 50
        height: 50
        radius: width / 2
        color: Color.CRUST
    }

    /* Title */
    AppText {
        id: chatTitle
        anchors {
            top: chatAvatar.top
            left: chatAvatar.right
            leftMargin: parent.margin
            right: chat.right
            rightMargin: parent.margin
        }
        text: 'Агрессивно-Пассивные кабачки'
        elide: Text.ElideRight
        color: Color.TEXT
        font {
            pixelSize: 20
            bold: true
        }
    }

    /* Chat type image */
    Image {
        id: chatTypeImage
        anchors {
            verticalCenter: chatMemberNumberText.verticalCenter
            left: chatTitle.left
        }
        source: {
            const imageName =
                    parent.chatType === ChatType.NOTES ? 'notes' :
                    parent.chatType === ChatType.PERSONAL ? 'person' :
                        parent.chatType === ChatType.GROUP ? 'group' :
                            parent.chatType === ChatType.SERVER ? 'server' :
                            'channel';
            return `qrc:/img/chat-list/${imageName}.svg`;
        }
        sourceSize {
            width: 16
            height: 16
        }
    }

    /* Number of chat members */
    AppText {
        id: chatMemberNumberText
        anchors {
            top: chatTitle.bottom
            right: chatLastMessageDate.left
            left: chatTypeImage.right
            rightMargin: parent.margin
            leftMargin: 5
        }
        elide: Text.ElideRight
        text: qsTr('%n chat member(s)', '', chat.membersNumber)
        font.pixelSize: 18
    }

    /* Last message date */
    AppText {
        id: chatLastMessageDate
        visible: !chatList.collapsed
        anchors {
            right: chat.right
            rightMargin: parent.margin
            bottom: chatAvatar.bottom
        }
        text: parent.lastMessageDate.toLocaleDateString(Locale.ShortFormat);
        color: Color.GREY_75
    }

    onClicked: {
        /* Make the last active chat unactive */
        if (chatList.activeChat)
            chatList.activeChat.isActive = false;

        /* Make this chat active */
        this.isActive = true;
        chatList.activeChat = this;
    }
}
