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
    , m_frameGridWidth{3}
    , m_blockGridWidth{3}
    , m_cellGridWidth{1}
    , m_showFrameGrid{true}
    , m_showBlockGrid{true}
    , m_showCellGrid{true}
    , m_baseCellSize{0, 0}
    , m_scaleFactor{1.0}
{
    m_baseCellSize = {50, 50};
}


int SudokuView::frameGridWidth() const
{
    return m_frameGridWidth;
}

void SudokuView::setFrameGridWidth(const int width)
{
    if (width == m_frameGridWidth)
        return;

    m_frameGridWidth = width;
}


int SudokuView::blockGridWidth() const
{
    return m_blockGridWidth;
}

void SudokuView::setBlockGridWidth(const int width)
{
    if (width == m_blockGridWidth)
        return;

    m_blockGridWidth = width;
}


int SudokuView::cellGridWidth() const
{
    return m_cellGridWidth;
}

void SudokuView::setCellGridWidth(const int width)
{
    if (width == m_cellGridWidth)
        return;

    m_cellGridWidth = width;
}


bool SudokuView::showFrameGrid() const
{
    return m_showFrameGrid;
}

void SudokuView::setShowFrameGrid(const bool show)
{
    if (show == m_showFrameGrid)
        return;

    m_showFrameGrid = show;
}


bool SudokuView::showBlockGrid() const
{
    return m_showBlockGrid;
}

void SudokuView::setShowBlockGrid(const bool show)
{
    if (show == m_showBlockGrid)
        return;

    m_showBlockGrid = show;
}


bool SudokuView::showCellGrid() const
{
    return m_showCellGrid;
}

void SudokuView::setShowCellGrid(const bool show)
{
    if (show == m_showCellGrid)
        return;

    m_showCellGrid = show;
}


void SudokuView::setScaleFactor(const qreal factor)
{
    if (factor <= 0 || factor == m_scaleFactor)
        return;

    m_scaleFactor = factor;

    resize(sizeHint());

    updateGeometry();
}


QSize SudokuView::cellSize() const
{
    const int width = qCeil(m_baseCellSize.width() * m_scaleFactor);
    const int height = qCeil(m_baseCellSize.height() * m_scaleFactor);

    return QSize(width, height);
}


QSize SudokuView::canvasSize() const
{
    const int lineWidths = 2 * m_frameGridWidth + 2 * m_blockGridWidth + 6 * m_cellGridWidth;

    const int width = 9 *cellSize().width() + lineWidths;
    const int height = 9 *cellSize().height() + lineWidths;

    return QSize(width, height);
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
