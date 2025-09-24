/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "gamecontrolsunitnumberpad.h"


GameControlsUnitNumberPad::GameControlsUnitNumberPad(QWidget* parent)
    : QxPanelUnit{parent}
{

    setUnitDisplayMode(QxPanelUnit::FrameBox);
    setUnitTitle(tr("Number Pad"));
}
