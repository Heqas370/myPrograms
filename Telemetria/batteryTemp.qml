import QtQuick 2.0
import QtCharts 2.3
import QtQuick.Window 2.3
Window {
id:batteryTempWindow
width: 1080
height: 720
title: "Temparatura Baterii"
ChartView {
    id: line
    x: 0
    y: 0
    width: batteryTempWindow.width
    height: batteryTempWindow.height
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
    D{i:0;formeditorZoom:0.66}
}
##^##*/
