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
    , m_columnCount{2}
{

    setUnitType(QxPanelUnit::GroupBox);
    setUnitTitle(tr("Sudoku Killer"));
}


int GamesUnitSudokuKiller::columnCount() const
{
    return m_columnCount;
}

void GamesUnitSudokuKiller::setColumnCount(const int columns)
{
    if (columns == m_columnCount)
        return;

    m_columnCount = columns;
    emit columnCountChanged(m_columnCount);
}
