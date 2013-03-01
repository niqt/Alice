import QtQuick 1.1
import Sailfish.Silica 1.0

Page {
    id: page
    property date birthday: new Date()

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
                id: birthdayButton
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
                        birthdayButton.text = "Birthday: " + dialog.dateText
                        birthday = dialog.date;
                    })
                }
            }

            ComboBox {
                id: groupSex
                 width: 480
                 label: "Sex: "

                 menu: ContextMenu {
                     MenuItem { text: "Male" }
                     MenuItem { text: "Female" }
                 }
             }

            TextField {
                placeholderText: "Current Weight (Kg)"
                width: 480
                id: weightEdit
                x: theme.paddingLarge
                validator: DoubleValidator {
                    bottom: 1
                    top: 30
                }

                onTextChanged: {

                }
            }
            TextField {
                placeholderText: "Current Height (cm)"
                id: heightEdit
                x: theme.paddingLarge
                width: 480
                onTextChanged: {

                }
                validator: DoubleValidator {
                    bottom: 1
                    top: 100
                }
            }
            TextField {
                id: headEdit
                placeholderText: "Current Head circumference (cm)"
                width: 480
                x: theme.paddingLarge
                onTextChanged: {

                }
                validator: DoubleValidator {
                    bottom: 1
                    top: 100
                }
            }
            Button {
               text: "Percentile"
               //enabled: false
               x: theme.paddingLarge
               onClicked: {
                   var weightp = "Not available";
                   var heightp = "Not available";
                   var headp = "Not available";
                   if (groupSex.currentIndex === 1) {

                       if (weightEdit.text.length > 0)
                           weightp = logic.getFemaleWeight(birthday, weightEdit.text);
                       if (heightEdit.text.length > 0)
                           heightp = logic.getFemaleHeight(birthday, heightEdit.text);
                       if (headEdit.text.length > 0)
                           headp = logic.getFemaleHead(birthday, headEdit.text);
                   } else {

                       if (weightEdit.text.length > 0)
                           weightp = logic.getMaleWeight(birthday, weightEdit.text);
                       if (heightEdit.text.length > 0)
                           heightp = logic.getMaleHeight(birthday, heightEdit.text);
                       if (headEdit.text.length > 0)
                           headp = logic.getMaleHead(birthday, headEdit.text);
                   }
                   var page = Qt.resolvedUrl("Result.qml");
                   page.ageNumber = 2;
                   pageStack.push(page, {ageNumber: logic.getAge(birthday), weightPercentile: weightp, heightPercentile: heightp, headPercentile: headp})
                   console.log("clicked! " + weightp + " " + weightEdit.text);
               }
            }
        }
    }
}
