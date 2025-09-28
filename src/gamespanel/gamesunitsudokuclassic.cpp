/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "gamesunitsudokuclassic.h"

using namespace Qt::Literals::StringLiterals;


GamesUnitSudokuClassic::GamesUnitSudokuClassic(QWidget* parent)
    : QxPanelUnit{parent}
    , m_columnCount{2}
{

    setUnitType(QxPanelUnit::GroupBox);
    setUnitTitle(tr("Sudoku Classic"));
}


int GamesUnitSudokuClassic::columnCount() const
{
    return m_columnCount;
}

void GamesUnitSudokuClassic::setColumnCount(const int columns)
{
    if (columns == m_columnCount)
        return;

    m_columnCount = columns;
    emit columnCountChanged(m_columnCount);
}


void GamesUnitSudokuClassic::setToolButtons(const QList<QAction*> actions)
{
    QList<QToolButton*> buttons;

    for (QAction* action : actions) {

        QToolButton* button = new QToolButton(this);
        button->setObjectName("button_%1"_L1.arg(action->objectName()));
        button->setDefaultAction(action);
        button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

        buttons.append(button);
    }
}
