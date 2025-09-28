/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef GAMESUNITSUDOKUCLASSIC_H
#define GAMESUNITSUDOKUCLASSIC_H

#include <qxpanelunit.h>


class GamesUnitSudokuClassic : public QxPanelUnit
{
    Q_OBJECT
    Q_PROPERTY(int columnCount READ columnCount WRITE setColumnCount NOTIFY columnCountChanged)

public:
    explicit GamesUnitSudokuClassic(QWidget* parent = nullptr);

    [[nodiscard]] int columnCount() const;

public slots:
    void setColumnCount(const int columns);

signals:
    void columnCountChanged(const int columns);

private:
    int m_columnCount;
};

#endif // GAMESUNITSUDOKUCLASSIC_H
