import QtQuick 2.4
import QtQuick.Window 2.2
import BGraphicsScene 1.0

Window {
    id: mainView
    width: 1080
    height: 720
    visible: true
    color: "#404040"


    BGraphicsScene {
        id: graphicsScene
        anchors.fill: parent
    }

    Rectangle {
        id: tool
        anchors.left: graphicsScene.left
        anchors.right: graphicsScene.right
        anchors.bottom: graphicsScene.bottom
        height: 40
        color: "#FFFFFF"

        Row {
            spacing: 30
            Rectangle {
                id: moveBtn
                width: 40
                height: 40
                color: "#CD3131"
                Text {
                    text: qsTr("移动")
                    color: "#FFFFFF"
                    anchors.centerIn: parent
                }

               MouseArea {
                   anchors.fill: parent

                   onClicked: {
                       graphicsScene.setNormalMode()
                   }
               }
            }

            Rectangle {
                id: penBtn
                width: 40
                height: 40
                color: "#CD3131"

                Text {
                    text: qsTr("画笔")
                    color: "#FFFFFF"
                    anchors.centerIn: parent
                }

               MouseArea {
                   anchors.fill: parent

                   onClicked: {
                       graphicsScene.setPenMode(4, "#ff0000")
                   }
               }
            }

            Rectangle {
                id: lineBtn
                width: 40
                height: 40
                color: "#CD3131"
                Text {
                    text: qsTr("直线")
                    color: "#FFFFFF"
                    anchors.centerIn: parent
                }

               MouseArea {
                   anchors.fill: parent

                   onClicked: {
                       graphicsScene.setShapeMode(5, 4, "#ff0000")
                   }
               }
            }

            Rectangle {
                id: rectBtn
                width: 40
                height: 40
                color: "#CD3131"
                Text {
                    text: qsTr("矩形")
                    color: "#FFFFFF"
                    anchors.centerIn: parent
                }

               MouseArea {
                   anchors.fill: parent

                   onClicked: {
                       graphicsScene.setShapeMode(6, 4, "#ff0000")
                   }
               }
            }

            Rectangle {
                id: ellipseBtn
                width: 40
                height: 40
                color: "#CD3131"
                Text {
                    text: qsTr("椭圆")
                    color: "#FFFFFF"
                    anchors.centerIn: parent
                }

               MouseArea {
                   anchors.fill: parent

                   onClicked: {
                       graphicsScene.setShapeMode(7, 4, "#ff0000")
                   }
               }
            }

            Rectangle {
                id: eraserBtn
                width: 40
                height: 40
                color: "#CD3131"
                Text {
                    text: qsTr("橡皮擦")
                    color: "#FFFFFF"
                    anchors.centerIn: parent
                }

               MouseArea {
                   anchors.fill: parent

                   onClicked: {
                       graphicsScene.setEraserMode()
                   }
               }
            }
        }
    }
}
