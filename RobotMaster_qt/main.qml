import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Dialogs 1.2
import PathPainter 1.0

Window {
    id:window
    visible: true
    width: 640
    height: 480
    minimumWidth:width
    maximumWidth:width
    minimumHeight:height
    maximumHeight:height
    title: qsTr("Hello World")

    Column {
        id: column
        anchors.fill: parent
        padding: 10

        Row {
            id: row
            height: 200

            GroupBox {
                id: groupBox1
                width: 380
                height: 245
                title: qsTr("路径预览")
            }

            Pane {
                id: pane
                width: 10
                height: 200
            }

            GroupBox {
                id: groupBox2
                width: 229
                height: 245
                title: qsTr("导入图片")

                Image {
                    id: viewImage
                    anchors.bottom: picPathText.top
                    anchors.bottomMargin: 0
                    visible: false
                    anchors.right: parent.right
                    anchors.rightMargin: 0
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.top: parent.top
                    anchors.topMargin: 0
                    fillMode: Image.PreserveAspectFit
                    source: "qrc:/qtquickplugin/images/template_image.png"
                }

                Button {
                    id: button
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter

                    text: qsTr("导入图片..")
                    onClicked: {
                        // pathPainter.recalcPath();
                        fds.open();
                    }
                }

                Text {
                    id: picPathText
                    x: -414
                    y: -29
                    text: qsTr("")
                    horizontalAlignment: Text.AlignHCenter
                    anchors.bottom: button.top
                    anchors.bottomMargin: 0
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: 10
                    width: parent.width
                    wrapMode: Text.WordWrap
                }

            }

        }
    }

    GroupBox {
        id: groupBox
        x: 10
        y: 263
        height: 207
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.topMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        title: qsTr("下位机信息")

        Text {
            id: element
            x: 6
            y: 8
            width: 48
            height: 16
            text: qsTr("未检测到")
            font.pixelSize: 12
        }

        Button {
            id: button1
            x: 66
            y: -5
            width: 56
            height: 42
            text: qsTr("链接")
        }
    }
    PathPainter{
        id:pathPainter
        x: 10
        y: 10
        contentsScale: 1
        anchors.fill: parent
    }

    FileDialog {
        id:fds
        title: "选择文件"
        folder: shortcuts.desktop
        selectExisting: true
        selectFolder: false
        selectMultiple: false
        nameFilters: ["图像文件(*.gif;*.jpg;*.jpeg;*.png;)"]
        onAccepted: {

            //            labels.text = fds.fileUrl;
            console.log("You chose: " + fds.fileUrl);
            pathPainter.transmitImagePath(fds.fileUrl)
            viewImage.source=fds.fileUrl
            viewImage.visible=true
            button.anchors.verticalCenter=undefined
            button.anchors.bottom= button.parent.bottom
            picPathText.text=fds.fileUrl
        }

        onRejected: {
        }

    }

}






















































