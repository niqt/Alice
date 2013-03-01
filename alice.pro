# The name of your app
TARGET = alice

# C++ sources
SOURCES += main.cpp \
    Percentile.cpp \
    Percentilemap.cpp

# C++ headers
HEADERS += \
    Percentilemap.h \
    Percentile.h

# QML files and folders
qml.files = *.qml pages cover main.qml

# The .desktop file
desktop.files = alice.desktop

# Please do not modify the following line.
include(sailfishapplication/sailfishapplication.pri)

OTHER_FILES = rpm/alice.yaml \
    pages/AboutPage.qml

RESOURCES += \
    percentile.qrc

