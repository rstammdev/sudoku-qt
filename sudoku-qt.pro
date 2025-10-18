#
# SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
#
# SPDX-FileCopyrightText: 2025 Ralf Stamm
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

TEMPLATE = app
TARGET = sudoku-qt

!versionAtLeast(QT_VERSION, 6.5): error("Requires at least Qt 6.5")

QT += core gui widgets

CONFIG += c++23
CONFIG += lrelease
CONFIG += embed_translations

DEFINES += QT_DEPRECATED_WARNINGS

include(3rdparty/qtxt/qtxt.pri)

HEADERS += \
    src/aboutdialog/aboutdialog.h \
    src/aboutdialog/aboutdialogpageauthors.h \
    src/aboutdialog/aboutdialogpagecomponents.h \
    src/aboutdialog/aboutdialogpagecredits.h \
    src/aboutdialog/aboutdialogpagegeneral.h \
    src/aboutdialog/aboutdialogpagelicense.h \
    src/aboutdialog/aboutpage.h \
    src/aboutdialog/aboutpagecontent.h \
    src/gamecontrolspanel/gamecontrolsunitcontrols.h \
    src/gamecontrolspanel/gamecontrolsunitnewgame.h \
    src/gamecontrolspanel/gamecontrolsunitnumberpad.h \
    src/gamecontrolspanel/gamecontrolsunitscoreboard.h \
    src/gamecontrolspanel/gamecontrolsunitstatistics.h \
    src/gamespanel/gamesunitsudokuclassic.h \
    src/gamespanel/gamesunitsudokukiller.h \
    src/mainwindow.h \
    src/settingsdialog/settingsdialog.h \
    src/settingsdialog/settingspage.h \
    src/settingsdialog/settingspageapplication.h \
    src/settingsdialog/settingspageapplicationappearance.h \
    src/settingsdialog/settingspagecomponents.h \
    src/settingsdialog/settingspageconfirmations.h \
    src/sudoku.h \
    src/sudokumodel.h \
    src/sudokuview.h

SOURCES += \
    src/aboutdialog/aboutdialog.cpp \
    src/aboutdialog/aboutdialogpageauthors.cpp \
    src/aboutdialog/aboutdialogpagecomponents.cpp \
    src/aboutdialog/aboutdialogpagecredits.cpp \
    src/aboutdialog/aboutdialogpagegeneral.cpp \
    src/aboutdialog/aboutdialogpagelicense.cpp \
    src/aboutdialog/aboutpage.cpp \
    src/aboutdialog/aboutpagecontent.cpp \
    src/gamecontrolspanel/gamecontrolsunitcontrols.cpp \
    src/gamecontrolspanel/gamecontrolsunitnewgame.cpp \
    src/gamecontrolspanel/gamecontrolsunitnumberpad.cpp \
    src/gamecontrolspanel/gamecontrolsunitscoreboard.cpp \
    src/gamecontrolspanel/gamecontrolsunitstatistics.cpp \
    src/gamespanel/gamesunitsudokuclassic.cpp \
    src/gamespanel/gamesunitsudokukiller.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/settingsdialog/settingsdialog.cpp \
    src/settingsdialog/settingspage.cpp \
    src/settingsdialog/settingspageapplication.cpp \
    src/settingsdialog/settingspageapplicationappearance.cpp \
    src/settingsdialog/settingspagecomponents.cpp \
    src/settingsdialog/settingspageconfirmations.cpp \
    src/sudoku.cpp \
    src/sudokumodel.cpp \
    src/sudokuview.cpp

RESOURCES += \
    res/icons.qrc

TRANSLATIONS += \
    i18n/sudoku-qt_en_001.ts

DISTFILES += \
    README.md

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
