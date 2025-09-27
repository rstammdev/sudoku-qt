/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef SUDOKU_H
#define SUDOKU_H

#include <QList>
#include <QObject>
#include <QStringList>


class Sudoku : public QObject
{
    Q_OBJECT

public:
    static const QList<QStringList> gamesClassic();
    static const QList<QStringList> gamesKiller();

private:
    explicit Sudoku(QObject* parent = nullptr);
};

#endif // SUDOKU_H
