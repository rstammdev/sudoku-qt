/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef GAMESUNITSUDOKUKILLER_H
#define GAMESUNITSUDOKUKILLER_H

#include <qxpanelunit.h>


class GamesUnitSudokuKiller : public QxPanelUnit
{
    Q_OBJECT

public:
    explicit GamesUnitSudokuKiller(QWidget* parent = nullptr);
};

#endif // GAMESUNITSUDOKUKILLER_H
