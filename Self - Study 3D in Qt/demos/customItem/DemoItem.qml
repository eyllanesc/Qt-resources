import QtQuick 2.4
import QtQuick.Controls 1.4
import QtMultimedia 5.5

Item {
    Column {
        SpinBox {

        }
        Slider {

        }
        ProgressBar {

        }
        VideoOutput {
            width: parent.width
            height: 200
            source: camera
        }
    }
    Camera {
        id: camera

    }
}
