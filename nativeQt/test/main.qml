import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    id:window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Column {
            anchors.centerIn: parent

            TextField {
                id: input
                text: "sss"
                selectByMouse:true
                anchors.horizontalCenter: parent.horizontalCenter
                placeholderText: "Write something ..."
            }

            Button {
                anchors.horizontalCenter: parent.horizontalCenter
                text: "and click me!"
                onClicked: dialog.open()
            }

        }

        Dialog {
            id: dialog

            x: (window.width - width) * 0.5
            y: (window.height - height) * 0.5

            contentWidth: window.width * 0.5
            contentHeight: window.height * 0.25
            standardButtons: Dialog.Ok

            contentItem: Label {
                text: input.text
            }
        }
}
