/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef SUDOKU_H
#define SUDOKU_H

#include <QObject>


class Sudoku : public QObject
{
    Q_OBJECT

private:
    explicit Sudoku(QObject* parent = nullptr);
};

#endif // SUDOKU_H
