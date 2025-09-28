/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef GAMESUNITSUDOKUCLASSIC_H
#define GAMESUNITSUDOKUCLASSIC_H

#include <qxpanelunit.h>


class GamesUnitSudokuClassic : public QxPanelUnit
{
    Q_OBJECT

public:
    explicit GamesUnitSudokuClassic(QWidget* parent = nullptr);
};

#endif // GAMESUNITSUDOKUCLASSIC_H
