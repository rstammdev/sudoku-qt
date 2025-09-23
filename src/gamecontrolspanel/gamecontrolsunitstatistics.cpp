/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "gamecontrolsunitstatistics.h"

#include <QGridLayout>
#include <QLabel>

using namespace Qt::Literals::StringLiterals;


GameControlsUnitStatistics::GameControlsUnitStatistics(QWidget* parent)
    : QxPanelUnit{parent}
{
    QLabel* labelMistakesLabel = new QLabel(tr("Mistakes"));
    labelMistakesLabel->setObjectName("labelMistakesLabel"_L1);

    QLabel* labelMistakesCounter = new QLabel(tr("0/3"));
    labelMistakesCounter->setObjectName("labelMistakesCounter"_L1);

    QGridLayout* layout = new QGridLayout;
    layout->setObjectName("layout"_L1);
    layout->addWidget(labelMistakesLabel, 0, 0);
    layout->addWidget(labelMistakesCounter, 1, 0);
    setLayout(layout);

    connect(this, &GameControlsUnitStatistics::updateMistakesCounterRequested, labelMistakesCounter, &QLabel::setText);

    setUnitDisplayMode(QxPanelUnit::FrameBox);
    setUnitTitle(tr("Statistics"));
}
