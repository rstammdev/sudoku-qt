/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAction>
#include <QActionGroup>
#include <QCloseEvent>
#include <QMainWindow>

#include "sudokumodel.h"
#include "sudokuview.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum NumberStyle {
        NoStyles = 0x00,
        Bold = 0x01,
        Italic = 0x02,
        StrikeOut = 0x04,
    };
    Q_ENUM(NumberStyle)
    Q_DECLARE_FLAGS(NumberStyles, NumberStyle)
    Q_FLAG(NumberStyles)

    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void applySudokuGame(QAction* action);

    void updateActionsNumbers();

    void applyZoomFactor(const qreal factor);
    void toggleFullScreen(const bool checked);

    void showLanguageSettingsDialog();
    void showShortcutSettingsDialog();
    void showPanelSettingsDialog();
    void showToolbarSettingsDialog();
    void showSettingsDialog();

    void showComponentsDialog();
    void showAboutDialog();

private:
    SudokuModel* m_sudokuModel;
    SudokuView* m_sudokuView;

    void setupUi();

    QActionGroup* m_actionsNumbers;

    QAction* m_actionShowNotes;

    QAction* m_actionSchemeTheme;
    QAction* m_actionShowMenubar;
    QAction* m_actionShowStatusbar;

    void loadSettings();
    void saveSettings();
};

Q_DECLARE_OPERATORS_FOR_FLAGS(MainWindow::NumberStyles)

#endif // MAINWINDOW_H
