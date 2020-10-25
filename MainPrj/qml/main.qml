import QtQuick 2.12
        import QtQuick.Window 2.12
        import QtQuick.Controls 2.3
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

        Button {
        id: button
        x: 62
        y: 74
        text: qsTr("导入图片..")
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
        }
        }





































        /*##^## Designer {
        D{i:13;anchors_height:400;anchors_width:200;anchors_x:208;anchors_y:25}D{i:28;anchors_height:200;anchors_width:640}
        }
        ##^##*/
