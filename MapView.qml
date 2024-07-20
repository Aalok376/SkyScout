// MapView.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtLocation 5.15
import QtPositioning 5.15

Rectangle {
    width: 800
    height: 600

    Map {
        anchors.fill: parent
        plugin: Plugin {
            name: "osm"  // Use OpenStreetMap plugin, you can change it to another provider
        }
        center {
            latitude: 27.7172  // Example: Kathmandu latitude
            longitude: 85.3240  // Example: Kathmandu longitude
        }
        zoomLevel: 12
    }
}
