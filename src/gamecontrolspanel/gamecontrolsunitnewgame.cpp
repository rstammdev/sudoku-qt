/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "gamecontrolsunitnewgame.h"

#include <QPushButton>
#include <QVBoxLayout>

using namespace Qt::Literals::StringLiterals;


GameControlsUnitNewGame::GameControlsUnitNewGame(QWidget* parent)
    : QxPanelUnit{parent}
{
    QPushButton* buttonNewGame = new QPushButton(tr("&New Game"));
    buttonNewGame->setObjectName("buttonNewGame"_L1);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->setObjectName("layout"_L1);
    layout->addWidget(buttonNewGame);
    setLayout(layout);

    connect(buttonNewGame, &QPushButton::clicked, this, &GameControlsUnitNewGame::buttonNewGameClicked);

    setUnitType(QxPanelUnit::FlatBox);
    setUnitTitle(tr("New Game"));
}
