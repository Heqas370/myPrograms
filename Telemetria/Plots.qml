import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.3
Window{
    id:plotsWindow
    width: 1920
    height: 1080
    property variant engTempWin;
    property variant invertTempWin;
    property variant batteryTempWin;
    property variant powerConsWin;
    Image {
        id: background
        source: "Images/dialogBackground.jpg"
        scale: 1
        baselineOffset: -49
        antialiasing: true
        anchors.rightMargin: 8
        anchors.leftMargin: -8
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
    }
       MenuBar{
           id:menubar

    Menu{
        id:plots
        title:qsTr("&wykresy")
        MenuItem {
            text: qsTr('&Temperatura Silników')
            onTriggered:  {
                var component = Qt.createComponent("engineTemp.qml");
                engTempWin=component.createObject(plotsWindow);
                engTempWin.show();

        }
        }
        MenuItem {
            text: qsTr('&Temperatura Falowników')
            onTriggered:  {
                var component = Qt.createComponent("inverterTemp.qml");
                invertTempWin=component.createObject(plotsWindow);
               invertTempWin.show();
        }
        }
        MenuItem {
            text: qsTr('Temperatura Baterii')
            onTriggered:  {
                var component = Qt.createComponent("batteryTemp.qml");
                batteryTempWin=component.createObject(plotsWindow);
               batteryTempWin.show();

        }
        }
        MenuItem {
            text: qsTr('&Pobór Prądu')
            onTriggered:  {
                var component = Qt.createComponent("powerConsumption.qml");
                powerConsWin=component.createObject(plotsWindow);
               powerConsWin.show();

        }
      }
      }
    Menu{
        id:table
        title:qsTr("&tabele")
        MenuItem {
            text: qsTr('&Temperatura Silników')

        }
        MenuItem {
            text: qsTr('&Temperatura Falowników')}
        MenuItem {
            text: qsTr('Temperatura Baterii')}
        MenuItem {
            text: qsTr('&Pobór Prądu')}
    }
    }

}

