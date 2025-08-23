/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef SETTINGSPAGECONFIRMATIONS_H
#define SETTINGSPAGECONFIRMATIONS_H

#include <QWidget>

#include "settingspage.h"


class SettingsPageConfirmations : public SettingsPage
{
    Q_OBJECT

public:
    explicit SettingsPageConfirmations(QWidget* parent = nullptr);
    ~SettingsPageConfirmations() = default;
};

#endif // SETTINGSPAGECONFIRMATIONS_H
