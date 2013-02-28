import QtQuick 1.1
import Sailfish.Silica 1.0

Page {
    id: pageResult
    property string ageNumber: ""
    property string weightPercentile: ""
    property string heightPercentile: ""
    property string headPercentile: ""
    Column {
        width: pageResult.width
        spacing: theme.paddingLarge
        PageHeader {
            title: "Result"
        }

        Label {
            id: age
            text: "Age: " + ageNumber
        }
        Label {
            id: weightp
            text: "Weight: " + weightPercentile
        }
        Label {
            id: heightp
            text: "Height:" + heightPercentile
        }
        Label {
            id: headp
            text: "Head circumference: " + headPercentile;
        }
    }
}

