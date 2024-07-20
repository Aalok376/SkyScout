// MapView.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtLocation 5.15
import QtPositioning 5.15

Rectangle {
    anchors.fill: parent
    property double latitude: 27.7172
    property double longitude: 85.3240

    Map {
        id: mapview
        anchors.fill: parent
        plugin: Plugin {
            id: googlemapview
            name: "osm"
        }
        center: QtPositioning.coordinate(latitude, longitude)
        zoomLevel: 12
      //  gesture.enabled: true
        // MapQuickItem {
        //     id: marker
        //     anchorPoint.x: sourceItem.width / 2  // Center the marker horizontally
        //     anchorPoint.y: sourceItem.height / 2  // Center the marker vertically
        //     sourceItem: Rectangle {
        //         width: parent.width * 0.05  // 5% of the parent width
        //         height: parent.width * 0.05  // 5% of the parent width
        //         color: "red"
        //         border.color: "black"
        //         border.width: 2
        //         radius: width / 2
        //     }
        //     coordinate {
        //         latitude: 27.7172
        //         longitude: 85.3240
        //     }
        // }
        MouseArea {
                   anchors.fill: parent
                   onClicked: {
                       mapview.center = map.toCoordinate(Qt.point(mouse.x, mouse.y));
                   }
                   onPressed: {
                       mapview.setProperty("dragging", true);
                       mapview.setProperty("startPan", Qt.point(mouse.x, mouse.y));
                   }
                   onReleased: {
                       mapview.setProperty("dragging", false);
                   }
                   onPositionChanged: {
                       if (mapview.dragging) {
                           var delta = Qt.point(mouse.x - mapview.startPan.x, mouse.y - mapview.startPan.y);
                           var newCenter = map.toCoordinate(Qt.point(width / 2 - delta.x, height / 2 - delta.y));
                           mapview.center = newCenter;
                       }
                   }
                   onWheel: {
                       if (wheel.angleDelta.y > 0) {
                           mapview.zoomLevel += 1;  // Zoom in
                       } else {
                           mapview.zoomLevel -= 1;  // Zoom out
                       }
                   }
               }
           }
       }
