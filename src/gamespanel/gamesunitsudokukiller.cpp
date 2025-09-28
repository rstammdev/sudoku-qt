/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "gamesunitsudokukiller.h"

#include <QGridLayout>
#include <QLayoutItem>

using namespace Qt::Literals::StringLiterals;


GamesUnitSudokuKiller::GamesUnitSudokuKiller(QWidget* parent)
    : QxPanelUnit{parent}
    , m_columnCount{2}
{
    QGridLayout* layout = new QGridLayout;
    layout->setObjectName("layout"_L1);
    setLayout(layout);

    setUnitType(QxPanelUnit::GroupBox);
    setUnitTitle(tr("Sudoku Killer"));
}


int GamesUnitSudokuKiller::columnCount() const
{
    return m_columnCount;
}

void GamesUnitSudokuKiller::setColumnCount(const int columns)
{
    if (columns == m_columnCount)
        return;

    m_columnCount = columns;

    rebuildLayout();

    emit columnCountChanged(m_columnCount);
}


void GamesUnitSudokuKiller::rebuildLayout()
{
    QLayout* layout = this->layout();
    if (!layout)
        return;

    QList<QWidget*> widgets;

    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr)
        if (item->widget())
            widgets.append(item->widget());

    buildGridLayout(layout, widgets);
}


void GamesUnitSudokuKiller::buildGridLayout(QLayout* layout, const QList<QWidget*> widgets)
{
    QGridLayout* gridLayout = qobject_cast<QGridLayout*>(layout);

    int row = 0, col = 0;
    for (QWidget* widget : widgets) {

        gridLayout->addWidget(widget, row, col);

        if (++col >= m_columnCount) {
            col = 0;
            ++row;
        }
    }
}
