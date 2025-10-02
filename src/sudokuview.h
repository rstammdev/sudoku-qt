/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef SUDOKUVIEW_H
#define SUDOKUVIEW_H

#include <QAbstractItemView>
#include <QItemSelection>
#include <QItemSelectionModel>
#include <QModelIndex>
#include <QPoint>
#include <QRect>
#include <QRegion>


class SudokuView : public QAbstractItemView
{
    Q_OBJECT
    Q_PROPERTY(int frameGridWidth READ frameGridWidth WRITE setFrameGridWidth FINAL)
    Q_PROPERTY(int blockGridWidth READ blockGridWidth WRITE setBlockGridWidth FINAL)
    Q_PROPERTY(int cellGridWidth READ cellGridWidth WRITE setCellGridWidth FINAL)
    Q_PROPERTY(bool showFrameGrid READ showFrameGrid WRITE setShowFrameGrid FINAL)
    Q_PROPERTY(bool showBlockGrid READ showBlockGrid WRITE setShowBlockGrid FINAL)
    Q_PROPERTY(bool showCellGrid READ showCellGrid WRITE setShowCellGrid FINAL)

public:
    explicit SudokuView(QWidget* parent = nullptr);

    [[nodiscard]] int frameGridWidth() const;
    [[nodiscard]] int blockGridWidth() const;
    [[nodiscard]] int cellGridWidth() const;

    [[nodiscard]] bool showFrameGrid() const;
    [[nodiscard]] bool showBlockGrid() const;
    [[nodiscard]] bool showCellGrid() const;

    QRect visualRect(const QModelIndex& index) const override;
    void scrollTo(const QModelIndex& index, ScrollHint hint = EnsureVisible) override;
    QModelIndex indexAt(const QPoint& point) const override;

public slots:
    void setFrameGridWidth(const int width);
    void setBlockGridWidth(const int width);
    void setCellGridWidth(const int width);

    void setShowFrameGrid(const bool show);
    void setShowBlockGrid(const bool show);
    void setShowCellGrid(const bool show);

    void setScaleFactor(const qreal factor);

protected:
    QSize sizeHint() const override;

    QModelIndex moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers) override;

    int horizontalOffset() const override;
    int verticalOffset() const override;

    bool isIndexHidden(const QModelIndex& index) const override;

    void setSelection(const QRect& rect, QItemSelectionModel::SelectionFlags flags) override;
    QRegion visualRegionForSelection(const QItemSelection& selection) const override;

private:
    int m_frameGridWidth;
    int m_blockGridWidth;
    int m_cellGridWidth;

    bool m_showFrameGrid;
    bool m_showBlockGrid;
    bool m_showCellGrid;

    QSize m_baseCellSize;

    qreal m_scaleFactor;

    QSize cellSize() const;
    QSize canvasSize() const;
};

#endif // SUDOKUVIEW_H
