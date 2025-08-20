/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QPushButton>


class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget* parent = nullptr);
    ~SettingsDialog() = default;

signals:
    void saveRequested();
    void restoreDefaultsRequested(bool current);

private slots:
    void saveAndClose();
    void saveAndContinue();

private:
    QPushButton* m_buttonApply;
};

#endif // SETTINGSDIALOG_H
