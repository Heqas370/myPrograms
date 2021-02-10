import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.2
import QtCharts 2.3

Window {
    id: mainWindow
    width: 1920
    height: 1080
    visible: true
    title: qsTr("Telemetria")
    property variant plotsWin;
    property variant gaugesWin;
    Image {
        width: mainWindow.width
        height: mainWindow.height
        id: background
        x: 0
        y: 0
        source: "Images/pojazdy.jpg"

        Button {
            id: buttonToOpenGauges
            y: 134
            width: 412
            height: 242
            text: "Wskaźniki"
            anchors.left: parent.left
            anchors.leftMargin: 259
            font.pointSize: 30
            onClicked:
            {
                var component = Qt.createComponent("Gauges.qml");
                gaugesWin=component.createObject(mainWindow);
                gaugesWin.show();
            }


        }

        Button {
            id: buttonToOpenPlots
            x: 1249
            y: 134
            width: 412
            height: 242
            text: "Wykresy"
            anchors.right: parent.right
            anchors.rightMargin: 259
            font.pointSize: 30;
            onClicked:
            {
                var component = Qt.createComponent("Plots.qml");
                plotsWin=component.createObject(mainWindow);
                plotsWin.show();
            }

        }

        Rectangle {
            id: rectangle
            x: 39
            y: 858
            width: 292
            height: 115
            color: "#dedcdc"
            radius: 100

            RadioButton {
                id: usbConnection
                x: 85
                y: 26
                text: qsTr("USB")
                font.pointSize: 25
            }
        }



    }



/*##^##
Designer {
    D{i:0;formeditorZoom:0.5}D{i:1}D{i:2}D{i:3}D{i:4}
}
##^##*/
}
