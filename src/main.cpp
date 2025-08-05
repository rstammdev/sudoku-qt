/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <QApplication>
#include <QDebug>

#include "mainwindow.h"

using namespace Qt::Literals::StringLiterals;


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("Ralf Stamm"_L1);
    app.setOrganizationDomain("https://rstammdev.github.io"_L1);
    app.setApplicationName("Sudoku-Qt"_L1);
    app.setApplicationVersion("0.1.0"_L1);
    app.setApplicationDisplayName("Sudoku-Qt"_L1);
    app.setDesktopFileName("io.github.rstamm.sudoku_qt"_L1);

    MainWindow window;
    window.show();

    return app.exec();
}
