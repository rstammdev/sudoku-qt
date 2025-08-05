/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "mainwindow.h"

using namespace Qt::Literals::StringLiterals;


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{

    setWindowIcon(QIcon::fromTheme("sudoku-qt"_L1, QIcon(":/icons/apps/16/sudoku-qt"_L1)));
    setMinimumSize(854, 480);

}

MainWindow::~MainWindow() {}
