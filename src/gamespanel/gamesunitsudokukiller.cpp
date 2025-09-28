/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "gamesunitsudokukiller.h"


GamesUnitSudokuKiller::GamesUnitSudokuKiller(QWidget* parent)
    : QxPanelUnit{parent}
{

    setUnitType(QxPanelUnit::GroupBox);
    setUnitTitle(tr("Sudoku Killer"));
}
