/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "sudokumodel.h"


SudokuModel::SudokuModel(QObject* parent)
    : QAbstractItemModel{parent}
{

}


QModelIndex SudokuModel::index(int row, int column, const QModelIndex& parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    return createIndex(row, column, nullptr);
}


QModelIndex SudokuModel::parent(const QModelIndex& index) const
{
    Q_UNUSED(index);

    return QModelIndex();
}


int SudokuModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return 0;

    return 9;
}


int SudokuModel::columnCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return 0;

    return 9;
}


QVariant SudokuModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || role == Qt::DisplayRole)
        return QVariant();

    return QVariant();
}
