import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Dialogs 1.2
import QmlCommunicator 1.0

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

        Flow {
            id: element
            x: 0
            y: -8
            width: 412
            height: 49
            spacing: 10

            Text {
                id: serialFoundStateText
                width: contentWidth+10
                height: 42
                text: qsTr("未检测到")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 12
            }

            Button {
                id: connectSlaveBtn
                width:text.contentWidth+10
                height: 42
                text: qsTr("重新扫描")
                //            flat: true
                onClicked: {
                    enabled=false;
                    text=qsTr("正在链接")
                    serialPart.onClick_ConnectBtn();

                }
            }
        }
    }
    PathPainter{
        id:pathPainter
        x: 10
        y: 10
        contentsScale: 1
        anchors.fill: parent
    }
    SerialPart{
        id:serialPart
        onConnectionStateChange:{
            console.log("qml onConnectionStateChange"+connected);
            if(connected){
                serialFoundStateText.text=qsTr("已链接到从机");
                connectSlaveBtn.text=qsTr("断开");
                connectSlaveBtn.enabled=true;
            }else{
                serialFoundStateText.text=qsTr("已检测到从机");
                connectSlaveBtn.text=qsTr("链接");
                connectSlaveBtn.enabled=true;
            }
        }
        onScanStateChange:{
            console.log("qml onScanStateChange"+found);
            if(found){
                serialFoundStateText.text=qsTr("已检测到从机");
                connectSlaveBtn.text=qsTr("链接");
                connectSlaveBtn.enabled=true;
            }else{
                serialFoundStateText.text=qsTr("未检测到");
                connectSlaveBtn.text=qsTr("重新扫描");
                connectSlaveBtn.enabled=true;
            }
        }
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
    Component.onCompleted: {
        //关联信号与信号处理函数的方式同QML中的类型
        serialPart.initSerial();
    }

}






















































