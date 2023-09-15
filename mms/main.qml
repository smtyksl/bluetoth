import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    // Grid
    Grid {
        id: grid
        anchors.fill: parent
        columns: 2
        rows: 3

        // Baðlantý düðmesi
        Button {
            text: "Baglan"
        }

        // Baðlantýyý koparma düðmesi
        Button {
            text: "Baglantiyi Kopar"
        }

        // Spotify düðmesi
        Button {
            text: "Spotify"
        }

        // YouTube düðmesi
        Button {
            text: "YouTube"
        }

        // Amazon Video düðmesi
        Button {
            text: "Amazon Video"
        }

        // Netflix düðmesi
        Button {
            // AI fotoðrafý
            Image {
                anchors.fill: parent
                source: "file:///" + applicationDirPath + "/Netflix_Logo_RGB.png"
            }
        }
    }
}
