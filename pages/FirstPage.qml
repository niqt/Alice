import QtQuick 1.1
import Sailfish.Silica 1.0

Page {
    id: page

    // To enable PullDownMenu, place our content in a SilicaFlickable
    SilicaFlickable {
        anchors.fill: parent

        // PullDownMenu and PushUpMenu must be declared in SilicaFlickable, SilicaListView or SilicaGridView
        PullDownMenu {
            MenuItem {
                text: "Show Page 2"
                onClicked: pageStack.push(Qt.resolvedUrl("AboutPage.qml"))
            }
        }

        // Tell SilicaFlickable the height of its content.
        contentHeight: childrenRect.height

        // Place our content in a Column.  The PageHeader is always placed at the top
        // of the page, followed by our content.
        Column {
            width: page.width
            spacing: theme.paddingLarge
            PageHeader {
                title: "Insert Baby's Data"
            }

            Button {
                id: button
                x: theme.paddingLarge
                text: "Birthday: "
                onClicked: {
                    var dialog = pageStack.openDialog(
                                "Sailfish.Silica.DatePickerDialog", {
                                    year: 2012,
                                    month: 11,
                                    day: 23
                                })

                    dialog.accepted.connect(function () {
                        button.text = "Birthday: " + dialog.dateText
                    })
                }
            }

            TextField {
                placeholderText: "Weight"
                width: 480
                x: theme.paddingLarge
                validator: DoubleValidator {
                    bottom: 1
                    top: 30
                }

                onTextChanged: {

                }
            }
            TextField {
                placeholderText: "Height"
                x: theme.paddingLarge
                width: 480
                onTextChanged: {

                }
                validator: DoubleValidator {
                    bottom: 1
                    top: 30
                }
            }
            TextField {
                placeholderText: "Head circumference"
                width: 480
                x: theme.paddingLarge
                onTextChanged: {

                }
                validator: DoubleValidator {
                    bottom: 1
                    top: 30
                }
            }
            Button {
               text: "Percentile"
               //enabled: false
               x: theme.paddingLarge
               onClicked: {
                   var page = Qt.resolvedUrl("Result.qml");
                   page.ageNumber = 2;
                   pageStack.push(page, {ageNumber:"2", weightPercentile: "32"})
                   console.log("clicked! ");
               }
            }
        }
    }
}
