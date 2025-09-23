/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "gamecontrolsunitscoreboard.h"

#include <QFont>
#include <QLabel>
#include <QHBoxLayout>

using namespace Qt::Literals::StringLiterals;


GameControlsUnitScoreBoard::GameControlsUnitScoreBoard(QWidget* parent)
    : QxPanelUnit{parent}
{
    QLabel* labelScores = new QLabel(tr("0"));
    labelScores->setObjectName("labelScores"_L1);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->setObjectName("layout"_L1);
    layout->addWidget(labelScores, 0, Qt::AlignCenter);
    setLayout(layout);

    connect(this, &GameControlsUnitScoreBoard::updateScoresRequested, labelScores, &QLabel::setText);

    setUnitDisplayMode(QxPanelUnit::FrameBox);
    setUnitTitle(tr("Scores"));

    QFont fontScores = labelScores->font();
    fontScores.setBold(true);
    labelScores->setFont(fontScores);
}
