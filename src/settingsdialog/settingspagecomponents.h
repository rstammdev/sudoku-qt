/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef SETTINGSPAGECOMPONENTS_H
#define SETTINGSPAGECOMPONENTS_H

#include <QTabWidget>
#include <QWidget>

#include "settingspage.h"


class SettingsPageComponents : public SettingsPage
{
    Q_OBJECT

public:
    explicit SettingsPageComponents(QWidget* parent = nullptr);
    ~SettingsPageComponents() = default;

public slots:
    void save() override;
    void restoreDefaults(bool current) override;

private:
    QTabWidget* m_tabBox;
};


//
// Editor

class SettingsPageComponentsTabEditor : public SettingsPage
{
    Q_OBJECT

public:
    explicit SettingsPageComponentsTabEditor(QWidget* parent = nullptr);
    ~SettingsPageComponentsTabEditor() = default;

public slots:
    void save() override;
};

#endif // SETTINGSPAGECOMPONENTS_H
