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
#include <QCloseEvent>
#include <QMainWindow>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void applySudokuGame(QAction* action);

    void applyZoomFactor(const qreal factor);
    void toggleFullScreen(const bool checked);

    void triggerConfigureLanguageDialog();
    void triggerConfigureShortcutsDialog();
    void triggerConfigurePanelsDialog();
    void triggerConfigureToolbarsDialog();
    void triggerConfigureDialog();

    void triggerComponentsDialog();
    void triggerAboutDialog();

private:
    void setupUi();

    QAction* m_actionSchemeTheme;
    QAction* m_actionShowMenubar;
    QAction* m_actionShowStatusbar;

    void loadSettings();
    void saveSettings();
};

#endif // MAINWINDOW_H
