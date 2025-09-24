/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "gamecontrolsunitnewgame.h"


GameControlsUnitNewGame::GameControlsUnitNewGame(QWidget* parent)
    : QxPanelUnit{parent}
{

    setUnitDisplayMode(QxPanelUnit::FrameBox);
    setUnitTitle(tr("New Game"));
}
