// MapView.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtLocation 5.15
import QtPositioning 5.15

Rectangle {
    width: 100
    height: 30
    property double latitude:27.7172
    property double longitude:85.3240
    property Component locationmarker : marker
    Map {
        id:mapview
        anchors.fill: parent
        plugin: Plugin {
            id: googlemapview
            name:"osm"
        }
        center : QtPositioning.coordinate(latitude,longitude)
        zoomLevel: 12

        MapQuickItem {
            id: marker
            anchorPoint.x: 5  // Center the marker horizontally
            anchorPoint.y: 5  // Center the marker vertically
            sourceItem: Rectangle {
                width: 10
                height: 10
                color: "red"
                border.color: "black"
                border.width: 2
                radius: 12
            }
            coordinate {
                latitude: 27.7172
                longitude: 85.3240
            }
        }
    }
}
