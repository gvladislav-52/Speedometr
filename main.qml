import QtQuick
import QtQuick.Window
import com.ulasdikme.speedometer 1.0
import QtQuick.Controls
import QtQuick.Layouts


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Speedometer
    {
        objectName: "speedoMeter"
        anchors.horizontalCenter: parent.horizontalCenter
        width: speedometerSize
        height: speedometerSize
        startAngle: startAngle
        alignAngle: alignAngle
        lowestRange: lowestRange
        highestRange: highestRange
        speed: speed
        arcWidth: arcWidth
        outerColor: outerColor
        innerColor: innerColor
        textColor: textColor
        backgroundColor: backgroundColor
    }
}
