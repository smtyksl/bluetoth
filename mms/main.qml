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

        // Ba�lant� d��mesi
        Button {
            text: "Baglan"
        }

        // Ba�lant�y� koparma d��mesi
        Button {
            text: "Baglantiyi Kopar"
        }

        // Spotify d��mesi
        Button {
            text: "Spotify"
        }

        // YouTube d��mesi
        Button {
            text: "YouTube"
        }

        // Amazon Video d��mesi
        Button {
            text: "Amazon Video"
        }

        // Netflix d��mesi
        Button {
            // AI foto�raf�
            Image {
                anchors.fill: parent
                source: "file:///" + applicationDirPath + "/Netflix_Logo_RGB.png"
            }
        }
    }
}
