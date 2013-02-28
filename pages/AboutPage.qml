import QtQuick 1.1
import Sailfish.Silica 1.0

Page {
    id: aboutpage
    Column {
        width: aboutpage.width
        spacing: theme.paddingLarge
        PageHeader {
            title: "About"
        }

        Label {
            id: author
            text: "Author: " + "Nicola De Filippo"
        }
        Label {

            text: "E-mail: " + "nicola@nicoladefilippo.it"
        }
        Label {

            text: "Version: "
        }
        Label {

            text: "Purpose: "
        }
        Label {

            text: "License: "
        }
    }
}





