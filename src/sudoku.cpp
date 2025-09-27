/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "sudoku.h"

using namespace Qt::Literals::StringLiterals;


Sudoku::Sudoku(QObject* parent)
    : QObject{parent}
{}


const QList<QStringList> Sudoku::gamesClassic()
{
    // Classic Games: Id, Name, Short Name, Brief Description

    return QList<QStringList> {
        { "sudoku_classic_easy"_L1, tr("Easy Level"), tr("Easy"), tr("Simple patterns, many hints, gentle") },
        { "sudoku_classic_medium"_L1, tr("Medium Level"), tr("Medium"), tr("Standard techniques, moderate logic challenge") },
        { "sudoku_classic_hard"_L1, tr("Hard Level"), tr("Hard"), tr("Fewer givens, advanced strategies required") },
        { "sudoku_classic_expert"_L1, tr("Expert Level"), tr("Expert"), tr("Complex deductions, minimal guidance, precision") },
        { "sudoku_classic_master"_L1, tr("Master Level"), tr("Master"), tr("Diabolical chains, scarce clues, relentless") },
        { "sudoku_classic_extreme"_L1, tr("Extreme Level"), tr("Extreme"), tr("Brutal logic, unforgiving puzzles, mastery") },
    };
}
