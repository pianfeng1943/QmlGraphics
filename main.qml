import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import BGraphicsScene 1.0

Window {
    id: mainView
    width: 1280
    height: 720
    minimumWidth: 1280
    minimumHeight: 720
    //flags: Qt.FramelessWindowHint | Qt.Window
    visible: true
    color: "#FFFFFF"

    property double oldWidth: 0.0
    property double oldHeight: 0.0
    property double scaled: 1.0

    Rectangle {
        id: bg
        anchors.centerIn: parent
        color: "#404040"
    }

    function changeSize()
    {
        var oWidth = mainView.width;
        if (mainView.width === 1280)
        {
            scaled = 1.0
            bg.width = 1280
            bg.height = 720
            if (oldWidth === 0.0 || oldHeight === 0.0)
                graphicsScene.setSceneScale(1.0, 1.0, 1.0)
            else
                graphicsScene.setSceneScale(1.0, 1280/oldWidth, 720/oldHeight)
        }
        else
        {
            var left = mainView.width * 9;
            var right = mainView.height * 16;
            var re_height
            var re_width
            if (left > right) {
                re_height = mainView.height;
                re_width = re_height * 16 / 9;
            } else {
                re_width = mainView.width;
                re_height = re_width * 9 / 16;
            }
            bg.width = oldWidth = re_width
            bg.height = oldHeight = re_height
            scaled = re_width/1280
            graphicsScene.setSceneScale(re_width/1280, re_width/1280, re_height/720)
        }
    }

    Component.onCompleted: {
        changeSize()
    }

    onWidthChanged: {
        changeSize()
    }

    BGraphicsScene {
        id: graphicsScene
        x: bg.x
        y: bg.y
        width: bg.width
        height: bg.height * 20
        clip: true
        property int sceneMode: 0
        Component {
            id: comC
            TextField {
                id: text
                width: text.length > 0 ? contentWidth+10 : 20
                height: 40
                padding: 1
                background: Rectangle {
                    id: textBg
                    implicitWidth: text.width
                    implicitHeight: text.height
                    border.color: "white"
                    border.width: text.focus ? 1 : 0
                    anchors.fill: parent
                    color: "#00000000"
                }
                font.pointSize: penWidthS
                color: "red"
                selectByMouse: true
                readOnly: graphicsScene.sceneMode == 1
                property int sceneWidth: 0
                property int sceneHeight: 0
                property double penWidth: 20
                property double penWidthS: 20
                property double penScale: 1.0

                onFocusChanged: {
                    if (focus === true)
                        return
                    if (text.length === 0)
                        destroy()
                }

                Connections {
                    target: graphicsScene
                    onWidthChanged: {
                        if (text.penScale === 1.0)
                        {
                            if (graphicsScene.width === text.sceneWidth)
                                penWidthS = penWidth;
                            else
                                penWidthS = penWidth * graphicsScene.width/text.sceneWidth
                        }
                        else
                        {
                            if (graphicsScene.width === text.sceneWidth)
                                penWidthS = penWidth * penScale
                            else
                                penWidthS = penWidth * graphicsScene.width/text.sceneWidth * penScale
                        }
                    }
                }

                MouseArea {
                    enabled: graphicsScene.sceneMode === 1
                    anchors.fill: parent
                    drag.target: text
                    drag.axis: Drag.XAndYAxis
                    drag.minimumX: 0
                    drag.minimumY: 0
                    drag.maximumX: graphicsScene.width - text.width
                    drag.maximumY: graphicsScene.height - text.height

                    onPressed: {
                        if (mouse.button === Qt.LeftButton) {
                            text.focus = true
                        }
                    }

                }
            }
        }

        function addText(x, y, scale)
        {
            var obj = comC.createObject(graphicsScene, {"x": x, "y": y, "penScale": scale});
            obj.penWidthS = obj.penWidth * scale
            obj.sceneWidth = parent.width
            obj.sceneHeight = parent.height
            obj.focus = true
            return obj;
        }
    }

    Rectangle {
        id: tool
        anchors.left: mainView.left
        anchors.right: mainView.right
        anchors.top: mainView.bottom
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
                       graphicsScene.sceneMode = 1
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
                       graphicsScene.sceneMode = 0
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
                       graphicsScene.sceneMode = 0
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
                       graphicsScene.sceneMode = 0
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
                       graphicsScene.sceneMode = 0
                   }
               }
            }

            Rectangle {
                id: textBtn
                width: 40
                height: 40
                color: "#CD3131"
                Text {
                    text: qsTr("文字")
                    color: "#FFFFFF"
                    anchors.centerIn: parent
                }

               MouseArea {
                   anchors.fill: parent

                   onClicked: {
                        graphicsScene.setTextMode(20, "微软雅黑", "#ff0000")
                        graphicsScene.sceneMode = 0
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
                       graphicsScene.sceneMode = 0
                   }
               }
            }

            Rectangle {
                id: pixBtn
                width: 40
                height: 40
                color: "#CD3131"
                Text {
                    text: qsTr("图片")
                    color: "#FFFFFF"
                    anchors.centerIn: parent
                }

               MouseArea {
                   anchors.fill: parent

                   onClicked: {
                       graphicsScene.addPixmap(0.0, 0.0, ":/007.jpg")
                   }
               }
            }

        }
    }
}
