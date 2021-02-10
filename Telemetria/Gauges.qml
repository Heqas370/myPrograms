import QtQuick 2.0
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.0
import QtQuick.Controls 2.5
import QtQuick.Shapes 1.12
import QtCharts 2.3
import QtGraphicalEffects 1.0
Window{
    id: gaugesWindow
    visible: true
    width: 1920
    height: 1080
    title: "Wskaźniki"
    Image {
        id: background
        source: "Images/dialogBackground.jpg"
        scale: 1
        baselineOffset: -49
        antialiasing: true
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        anchors.bottomMargin: 0
        anchors.topMargin: 0
        fillMode: Image.Stretch
        asynchronous: false
        mirror: false
        visible: true
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        smooth: true

        Item {
            id: container
        width: root.width
        height: Math.min(root.width, root.height)
        anchors.centerIn: parent



            CircularGauge {
                id: speedometer
                x: 246
                value: valueSource.kph
                maximumValue: 180
                width: 730
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.bottomMargin: -12
                anchors.topMargin: -527
                antialiasing: true
                anchors.rightMargin: -976

                style: Dashboard_Gauge_Style{}

                Text {
                    id: textSpeedometer
                    x: 333
                    y: 374
                    text: qsTr("km/h")
                    font.pixelSize: 28
                }
            }


    }

        Rectangle {
            id: angleGauge
            x: 211
            width: 566
            height: 529
            color: "#d4d4d5"
            radius: 264.5
            border.width: 1
            anchors.left: rectangle_2.right
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.rightMargin: 1143
            anchors.leftMargin: -291
            anchors.topMargin: 11
            Item {
                id: semiCircle
                    y: 0
                    width: 540
                    height: 265
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.leftMargin: 13
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.topMargin: 10
                    anchors.horizontalCenterOffset: 0
                    rotation: 0
                    clip:true

                    Rectangle{
                        id: semiCircle1
                        width: parent.width
                        height: parent.width
                        border.width: 2
                        rotation: 36.688
                        radius:1000
                        border.color: "blue"
                        color: "blue"
                    }
                }
            Shape {
                width: 200
                height: 150
                anchors.top: parent.top
                anchors.topMargin: -233
                anchors.verticalCenterOffset: -289
                anchors.horizontalCenterOffset: -69
                rotation: -180
                anchors.centerIn: parent
                ShapePath {
                    strokeWidth: 2
                    strokeColor: "black"
                    fillColor: "black"

                    startX: 20; startY: 20
                    PathLine { x: 30; y: 40 }
                    PathLine { x: 40; y: 20 }
                    PathLine { x: 20; y: 20 }
                }
            }

            Rectangle {
                id: rectangle2
                x: 554
                y: 273
                width: 12
                height: 2
                color: "#020202"
            }

            Rectangle {
                id: rectangle3
                x: 0
                y: 273
                width: 12
                height: 2
                color: "#020202"
            }


        }

        Rectangle {
            id: rectangle_3
            y: 16
            width: 11
            height: 2
            color: "#020202"
            anchors.left: rectangle.right
            anchors.top: rectangle_2.bottom
            anchors.leftMargin: -288
            anchors.topMargin: -198
            rotation: 90
        }
        Rectangle {
            id: rectangle_4
            x: 277
            width: 17
            height: 2
            color: "#020202"
            anchors.top: parent.top
            anchors.bottom: rectangle.top
            anchors.bottomMargin: -60
            anchors.topMargin: 105
            rotation: 45
        }
        Rectangle {
            id: rectangle_5
            x: 694
            width: 17
            height: 2
            color: "#020202"
            anchors.top: parent.top
            anchors.topMargin: 105
            rotation: -45
        }

        Rectangle {
            id: rectangle1
            x: 28
            y: 628
            width: 932
            height: 52
            color: "#d4d4d5"
            radius: 10

            Text {
                id: text1
                x: 40
                y: 8
                width: 100
                height: 25
                color: "#000000"
                text: qsTr("Balance Bar")
                font.pixelSize: 35
            }

            Text {
                id: text3
                x: 306
                y: 8
                width: 100
                height: 25
                color: "#000000"
                text: qsTr("Telemetria")
                font.pixelSize: 36
            }

            Text {
                id: text4
                x: 536
                y: 8
                width: 100
                height: 25
                color: "#000000"
                text: qsTr("Falownik L")
                font.pixelSize: 36
            }

            Text {
                id: text5
                x: 749
                y: 8
                width: 100
                height: 25
                color: "#000000"
                text: qsTr("Falownik P")
                font.pixelSize: 36
            }
        }

        Rectangle {
            id: rectangle4
            x: 1345
            y: 686
            width: 494
            height: 266
            color: "#d4d4d5"
            radius: 24

            Text {
                id: textBalanceBar
                x: 154
                y: 23
                color: "#060606"
                text: qsTr("Balance Bar")
                font.pixelSize: 36
            }

            TextInput {
                id: textInput
                x: 224
                y: 100
                width: 80
                height: 20
                color: "#000000"
                text: qsTr("0%")
                font.pixelSize: 30
            }

            Text {
                id: textFrontTyrePressure
                x: 21
                y: 172
                color: "#000000"
                text: qsTr("Cinienie Przód")
                font.pixelSize: 25
            }

            Text {
                id: textBackTyrePressure
                x: 314
                y: 172
                color: "#000000"
                text: qsTr("Ciśnienie Tył")
                font.pixelSize: 25
            }

            TextInput {
                id: textInputFrontTyrePressure
                x: 98
                y: 226
                width: 80
                height: 20
                color: "#000000"
                text: qsTr("0")
                font.pixelSize: 30
            }

            TextInput {
                id: textInputBackTyrePressure
                x: 363
                y: 220
                width: 80
                height: 20
                color: "#000000"
                text: qsTr("0")
                font.pixelSize: 30
            }
        }

        Rectangle {
            id: rectangle6
            x: 394
            y: 554
            width: 200
            height: 54
            color: "#d4d4d5"
            radius: 15

            Text {
                id: text10
                x: 87
                y: 12
                width: 46
                height: 31
                text: qsTr("0")
                font.pixelSize: 26
            }
        }

        Rectangle {
            id: rectangle7
            x: 1492
            y: 554
            width: 200
            height: 54
            color: "#d4d4d5"
            radius: 15

            Text {
                id: textSpeed
                x: 87
                y: 12
                width: 46
                height: 31
                text: qsTr("0")
                font.pixelSize: 26
            }
        }

        Rectangle {
            id: rectangle8
            x: 931
            y: 349
            width: 225
            height: 119
            color: "#d4d4d5"
            radius: 15

            Text {
                id: textBatterry
                x: 13
                y: 8
                text: qsTr("Pojemnoć baterii")
                font.pixelSize: 27
            }

            TextInput {
                id: textInputBattery
                x: 88
                y: 65
                width: 80
                height: 20
                text: qsTr("0%")
                font.pixelSize: 26
            }
        }

        Text {
            id: textDRS
            x: 1009
            width: 99
            height: 82
            text: qsTr("DRS")
            anchors.top: parent.top
            font.pixelSize: 45
            anchors.topMargin: 235
        }

        ChartView {
            id: line
            x: 57
            y: 694
            width: 888
            height: 280
            plotAreaColor: "#ffffff"
            backgroundColor: "#d4d4d5"
            legend.visible: false

            LineSeries {

                id:batteryTemperature
                }
        }
        Component.onCompleted: {
            for (var i = 0; i <= 100; i++) {
                batteryTemperature.append(i, Math.random());

            }
        }



    }
/*##^##
Designer {
    D{i:0;formeditorZoom:0.33}D{i:3}D{i:15}D{i:21}D{i:22}D{i:23}D{i:24}D{i:26}D{i:28}
D{i:30}D{i:32}D{i:34}D{i:36}D{i:38}D{i:40}D{i:42}D{i:44}D{i:46}D{i:48}D{i:50}D{i:52}
D{i:54}D{i:60}D{i:62}D{i:63}D{i:65}D{i:67}D{i:72}D{i:71}
}
##^##*/
}
