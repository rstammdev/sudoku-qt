/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef GAMECONTROLSUNITSTATISTICS_H
#define GAMECONTROLSUNITSTATISTICS_H

#include <qxpanelunit.h>


class GameControlsUnitStatistics : public QxPanelUnit
{
    Q_OBJECT

public:
    explicit GameControlsUnitStatistics(QWidget* parent = nullptr);

signals:
    void updateMistakesCounterRequested(const QString& text);
};

#endif // GAMECONTROLSUNITSTATISTICS_H
