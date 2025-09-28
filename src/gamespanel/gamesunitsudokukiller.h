/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef GAMESUNITSUDOKUKILLER_H
#define GAMESUNITSUDOKUKILLER_H

#include <qxpanelunit.h>


class GamesUnitSudokuKiller : public QxPanelUnit
{
    Q_OBJECT
    Q_PROPERTY(int columnCount READ columnCount WRITE setColumnCount NOTIFY columnCountChanged)

public:
    explicit GamesUnitSudokuKiller(QWidget* parent = nullptr);

    [[nodiscard]] int columnCount() const;

public slots:
    void setColumnCount(const int columns);

signals:
    void columnCountChanged(const int columns);

private:
    int m_columnCount;
};

#endif // GAMESUNITSUDOKUKILLER_H
