/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "mainwindow.h"

#include <QMenuBar>
#include <QSettings>

using namespace Qt::Literals::StringLiterals;


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{

    setupUi();
    loadSettings();

    setWindowIcon(QIcon::fromTheme("sudoku-qt"_L1, QIcon(":/icons/apps/16/sudoku-qt"_L1)));
    setMinimumSize(854, 480);

}

MainWindow::~MainWindow() {}


void MainWindow::setupUi()
{
    // File menu

    QMenu* menuFile = menuBar()->addMenu(tr("&File"));
    menuFile->setObjectName("menuFile"_L1);

}


void MainWindow::closeEvent(QCloseEvent* event)
{

    saveSettings();
    event->accept();

}


void MainWindow::loadSettings()
{
    QSettings settings;

    const QByteArray geometry = settings.value("Application/Geometry"_L1).toByteArray();
    if (!geometry.isEmpty())
        restoreGeometry(geometry);
    else
        resize(1280, 720);

    const QByteArray state = settings.value("Application/State"_L1).toByteArray();
    if (!state.isEmpty())
        restoreState(state);

}


void MainWindow::saveSettings()
{
    QSettings settings;

    const QByteArray geometry = saveGeometry();
    settings.setValue("Application/Geometry"_L1, geometry);

    const QByteArray state = saveState();
    settings.setValue("Application/State"_L1, state);

}
