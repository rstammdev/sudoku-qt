/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef GAMECONTROLSUNITNUMBERPAD_H
#define GAMECONTROLSUNITNUMBERPAD_H

#include <qxpanelunit.h>

#include <QButtonGroup>


class GameControlsUnitNumberPad : public QxPanelUnit
{
    Q_OBJECT

public:
    explicit GameControlsUnitNumberPad(QWidget* parent = nullptr);

signals:
    void buttonClicked(const int number);

private:
    QButtonGroup* m_buttonsNumbers;
};

#endif // GAMECONTROLSUNITNUMBERPAD_H
