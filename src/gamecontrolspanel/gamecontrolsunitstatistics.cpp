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
#include <QPushButton>

using namespace Qt::Literals::StringLiterals;


GameControlsUnitStatistics::GameControlsUnitStatistics(QWidget* parent)
    : QxPanelUnit{parent}
{
    QLabel* labelMistakesLabel = new QLabel(tr("Mistakes"));
    labelMistakesLabel->setObjectName("labelMistakesLabel"_L1);

    QLabel* labelMistakesCounter = new QLabel(tr("0/3"));
    labelMistakesCounter->setObjectName("labelMistakesCounter"_L1);

    QPushButton* buttonTimer = new QPushButton(tr("Time"));
    buttonTimer->setObjectName("buttonTimer"_L1);
    buttonTimer->setCheckable(true);
    buttonTimer->setFlat(true);

    buttonTimer->toggle();
    connect(buttonTimer, &QPushButton::toggled, [=](const bool checked) {
        if (!checked)
            buttonTimer->setIcon(QIcon::fromTheme("media-playback-start"_L1, QIcon(":/icons/actions/16/media-playback-start"_L1)));
        else
            buttonTimer->setIcon(QIcon::fromTheme("media-playback-pause"_L1, QIcon(":/icons/actions/16/media-playback-pause"_L1)));
    });
    buttonTimer->toggle();

    QLabel* labelTimerTime = new QLabel(tr("00:00:00"));
    labelTimerTime->setObjectName("labelTimerTime"_L1);

    QGridLayout* layout = new QGridLayout;
    layout->setObjectName("layout"_L1);
    layout->addWidget(labelMistakesLabel, 0, 0);
    layout->addWidget(labelMistakesCounter, 1, 0);
    layout->addWidget(buttonTimer, 0, 1, Qt::AlignCenter);
    layout->addWidget(labelTimerTime, 1, 1, Qt::AlignCenter);
    setLayout(layout);

    connect(buttonTimer, &QPushButton::toggled, this, &GameControlsUnitStatistics::buttonTimerToggled);
    connect(this, &GameControlsUnitStatistics::updateMistakesCounterRequested, labelMistakesCounter, &QLabel::setText);
    connect(this, &GameControlsUnitStatistics::updateTimerTimeRequested, labelTimerTime, &QLabel::setText);

    setUnitDisplayMode(QxPanelUnit::FrameBox);
    setUnitTitle(tr("Statistics"));
}
