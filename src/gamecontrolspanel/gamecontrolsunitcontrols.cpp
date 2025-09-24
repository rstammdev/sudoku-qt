/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "gamecontrolsunitcontrols.h"

#include <QHBoxLayout>
#include <QPushButton>

using namespace Qt::Literals::StringLiterals;


GameControlsUnitControls::GameControlsUnitControls(QWidget* parent)
    : QxPanelUnit{parent}
{
    QPushButton* buttonUndo = new QPushButton;
    buttonUndo->setObjectName("buttonUndo"_L1);
    buttonUndo->setIcon(QIcon::fromTheme("edit-undo"_L1, QIcon(":/icons/actions/16/edit-undo"_L1)));

    QHBoxLayout* layout = new QHBoxLayout;
    layout->setObjectName("layout"_L1);
    layout->addWidget(buttonUndo);
    setLayout(layout);

    connect(buttonUndo, &QPushButton::clicked, this, &GameControlsUnitControls::buttonUndoClicked);

    setUnitDisplayMode(QxPanelUnit::FrameBox);
    setUnitTitle(tr("Controls"));
}
