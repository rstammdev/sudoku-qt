/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "sudokuview.h"


SudokuView::SudokuView(QWidget* parent)
    : QAbstractItemView{parent}
    , m_scaleFactor{1.0}
{

}


void SudokuView::setScaleFactor(const qreal factor)
{
    if (factor <= 0)
        return;

    m_scaleFactor = factor;

    resize(sizeHint());

    updateGeometry();
}


QSize SudokuView::sizeHint() const
{
    return QSize(500, 500) * m_scaleFactor;
}


QRect SudokuView::visualRect(const QModelIndex& index) const
{
    if (!index.isValid())
        return QRect();

    return QRect();
}


void SudokuView::scrollTo(const QModelIndex& index, ScrollHint hint)
{
    Q_UNUSED(index)
    Q_UNUSED(hint)
}


QModelIndex SudokuView::indexAt(const QPoint& point) const
{
    Q_UNUSED(point)

    return QModelIndex();
}


QModelIndex SudokuView::moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers)
{
    Q_UNUSED(cursorAction)
    Q_UNUSED(modifiers)

    return QModelIndex();
}


int SudokuView::horizontalOffset() const
{
    return 0;
}


int SudokuView::verticalOffset() const
{
    return 0;
}


bool SudokuView::isIndexHidden(const QModelIndex& index) const
{
    Q_UNUSED(index)

    return false;
}


void SudokuView::setSelection(const QRect& rect, QItemSelectionModel::SelectionFlags command)
{
    Q_UNUSED(rect)
    Q_UNUSED(command)
}


QRegion SudokuView::visualRegionForSelection(const QItemSelection& selection) const
{
    Q_UNUSED(selection)

    return QRegion();
}
