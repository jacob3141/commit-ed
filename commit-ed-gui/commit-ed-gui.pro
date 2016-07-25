QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = commit-ed-gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

# make install
unix {
        # variables
        OBJECTS_DIR = .obj
        MOC_DIR     = .moc
        UI_DIR      = .ui

        isEmpty(PREFIX) {
                PREFIX = /usr/local
        }

        BINDIR = $$PREFIX/bin
        DATADIR = $$PREFIX/share
        LOCALEDIR = $(localedir)

        DEFINES += DATADIR=\"$$DATADIR\"

        !isEmpty(LOCALEDIR) {
                DEFINES += LOCALEDIR=\"$$LOCALEDIR\"
        }

        # make install
        INSTALLS += target desktop icon

        target.path = $$BINDIR

        desktop.path = $$DATADIR/applications
        desktop.files += $${TARGET}.desktop

        icon.path = $$DATADIR/icons/hicolor/32x32/apps
        icon.files += images/$${TARGET}.png
}

RESOURCES += \
    resources.qrc
