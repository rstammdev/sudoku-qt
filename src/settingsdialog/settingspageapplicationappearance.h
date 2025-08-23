/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef SETTINGSPAGEAPPLICATIONAPPEARANCE_H
#define SETTINGSPAGEAPPLICATIONAPPEARANCE_H

#include <QTabWidget>
#include <QWidget>

#include "settingspage.h"


class SettingsPageApplicationAppearance : public SettingsPage
{
    Q_OBJECT

public:
    explicit SettingsPageApplicationAppearance(QWidget* parent = nullptr);
    ~SettingsPageApplicationAppearance() = default;

public slots:
    void save() override;
    void restoreDefaults(bool current) override;

private:
    QTabWidget* m_tabBox;
};


//
// Zoom Button

class SettingsPageApplicationAppearanceTabZoomButton : public SettingsPage
{
    Q_OBJECT

public:
    explicit SettingsPageApplicationAppearanceTabZoomButton(QWidget* parent = nullptr);
    ~SettingsPageApplicationAppearanceTabZoomButton() = default;

public slots:
    void save() override;
    void restoreDefaults(bool current) override;
};


//
// Scheme & Theme Button

class SettingsPageApplicationAppearanceTabSchemeThemeButton : public SettingsPage
{
    Q_OBJECT

public:
    explicit SettingsPageApplicationAppearanceTabSchemeThemeButton(QWidget* parent = nullptr);
    ~SettingsPageApplicationAppearanceTabSchemeThemeButton() = default;

public slots:
    void save() override;
    void restoreDefaults(bool current) override;
};


//
// Toolbars

class SettingsPageApplicationAppearanceTabToolbars : public SettingsPage
{
    Q_OBJECT

public:
    explicit SettingsPageApplicationAppearanceTabToolbars(QWidget* parent = nullptr);
    ~SettingsPageApplicationAppearanceTabToolbars() = default;
};

#endif // SETTINGSPAGEAPPLICATIONAPPEARANCE_H
