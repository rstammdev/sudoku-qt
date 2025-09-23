/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef GAMECONTROLSUNITSCOREBOARD_H
#define GAMECONTROLSUNITSCOREBOARD_H

#include <qxpanelunit.h>


class GameControlsUnitScoreBoard : public QxPanelUnit
{
    Q_OBJECT

public:
    explicit GameControlsUnitScoreBoard(QWidget* parent = nullptr);
};

#endif // GAMECONTROLSUNITSCOREBOARD_H
