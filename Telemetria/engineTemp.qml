import QtQuick 2.0
import QtCharts 2.3
import QtQuick.Window 2.3
Window {
id:engineTempWindow
width: 1080
height: 720
title: "Temperatura Silników"
ChartView {
    id: line
    x: 0
    y: 0
    width: engineTempWindow.width
    height: engineTempWindow.height
    plotAreaColor: "#ffffff"
    backgroundColor: "#d4d4d5"
    legend.visible: false
    LineSeries {
        name: "Temperatura Silników"
        XYPoint {
            x: 0
            y: 2
        }

        XYPoint {
            x: 1
            y: 1.2
        }

        XYPoint {
            x: 2
            y: 3.3
        }

        XYPoint {
            x: 5
            y: 2.1
        }
    }
}
}
