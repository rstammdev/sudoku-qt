/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef GAMECONTROLSUNITNEWGAME_H
#define GAMECONTROLSUNITNEWGAME_H

#include <qxpanelunit.h>


class GameControlsUnitNewGame : public QxPanelUnit
{
    Q_OBJECT

public:
    explicit GameControlsUnitNewGame(QWidget* parent = nullptr);

signals:
    void buttonNewGameClicked();
};

#endif // GAMECONTROLSUNITNEWGAME_H
