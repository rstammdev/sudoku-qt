/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "sudokuview.h"

#include <QColor>
#include <QPen>
#include <QRgb>
#include <QStyle>


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

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    setFixedSize(canvasSize());
}


int SudokuView::frameGridWidth() const
{
    return m_frameGridWidth;
}

void SudokuView::setFrameGridWidth(int width)
{
    if (width < 0)
        width = 0;

    if (width == m_frameGridWidth)
        return;

    m_frameGridWidth = width;

    setFixedSize(canvasSize());

    viewport()->update();
}


int SudokuView::blockGridWidth() const
{
    return m_blockGridWidth;
}

void SudokuView::setBlockGridWidth(int width)
{
    if (width < 0)
        width = 0;

    if (width == m_blockGridWidth)
        return;

    m_blockGridWidth = width;

    setFixedSize(canvasSize());

    viewport()->update();
}


int SudokuView::cellGridWidth() const
{
    return m_cellGridWidth;
}

void SudokuView::setCellGridWidth(int width)
{
    if (width < 0)
        width = 0;

    if (width == m_cellGridWidth)
        return;

    m_cellGridWidth = width;

    setFixedSize(canvasSize());

    viewport()->update();
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

    viewport()->update();
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

    viewport()->update();
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

    viewport()->update();
}


void SudokuView::setScaleFactor(const qreal factor)
{
    if (factor <= 0 || factor == m_scaleFactor)
        return;

    m_scaleFactor = factor;

    setFixedSize(canvasSize());

    viewport()->update();
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
    return canvasSize();
}


void SudokuView::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event)

    QStyleOptionViewItem option;
    initViewItemOption(&option);

    const QColor backgroundColor = option.palette.color(QPalette::Base);

    const bool showFrameGrid = m_showFrameGrid;
    const int frameGridWidth = m_frameGridWidth;
    const int frameGridHint = style()->styleHint(QStyle::SH_Table_GridLineColor, &option, this);
    const QColor frameGridColor = QColor::fromRgba(static_cast<QRgb>(frameGridHint));
    const QPen frameGridPen = QPen(showFrameGrid ? frameGridColor : backgroundColor, 1, Qt::SolidLine);

    const bool showBlockGrid = m_showBlockGrid;
    const int blockGridWidth = m_blockGridWidth;
    const int blockGridHint = style()->styleHint(QStyle::SH_Table_GridLineColor, &option, this);
    const QColor blockGridColor = QColor::fromRgba(static_cast<QRgb>(blockGridHint));
    const QPen blockGridPen = QPen(showBlockGrid ? blockGridColor : backgroundColor, 1, Qt::SolidLine);

    const bool showCellGrid = m_showCellGrid;
    const int cellGridWidth = m_cellGridWidth;
    const int cellGridHint = style()->styleHint(QStyle::SH_Table_GridLineColor, &option, this);
    const QColor cellGridColor = QColor::fromRgba(static_cast<QRgb>(cellGridHint));
    const QPen cellGridPen = QPen(cellGridColor, 1, Qt::SolidLine);

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
