import QtQuick 2.15
import QtQuick.Controls 2.15
import QtLocation 5.15
import QtPositioning 5.15

Rectangle {
    anchors.fill: parent
    property double latitude: 27.7172
    property double longitude: 85.3240

    Plugin {
        id: googlemapview
        name: "osm"
    }

    Map {
        id: mapview
        plugin:googlemapview
        anchors.fill: parent
        center: QtPositioning.coordinate(latitude, longitude)
        zoomLevel: 12
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            mapview.center = mapview.toCoordinate(Qt.point(mouse.x, mouse.y));
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
                var newCenter = mapview.toCoordinate(Qt.point(width / 2 - delta.x, height / 2 - delta.y));
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

    function updateMap(lati, longi) {
        mapview.pan (latitude - lati , longitude - longi)
        latitude = lati
        longitude = longi
    }
}
