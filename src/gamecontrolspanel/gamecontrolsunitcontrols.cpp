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

    QPushButton* buttonErase = new QPushButton;
    buttonErase->setObjectName("buttonErase"_L1);
    buttonErase->setIcon(QIcon::fromTheme("draw-eraser"_L1, QIcon(":/icons/actions/16/draw-eraser"_L1)));

    QPushButton* buttonNotes = new QPushButton;
    buttonNotes->setObjectName("buttonNotes"_L1);
    buttonNotes->setIcon(QIcon::fromTheme("edit-entry"_L1, QIcon(":/icons/actions/16/edit-entry"_L1)));
    buttonNotes->setCheckable(true);

    QPushButton* buttonHint = new QPushButton;
    buttonHint->setObjectName("buttonHint"_L1);
    buttonHint->setIcon(QIcon::fromTheme("games-hint"_L1, QIcon(":/icons/actions/16/games-hint"_L1)));

    QHBoxLayout* layout = new QHBoxLayout;
    layout->setObjectName("layout"_L1);
    layout->addWidget(buttonUndo);
    layout->addWidget(buttonErase);
    layout->addWidget(buttonNotes);
    layout->addWidget(buttonHint);
    setLayout(layout);

    connect(buttonUndo, &QPushButton::clicked, this, &GameControlsUnitControls::buttonUndoClicked);
    connect(buttonErase, &QPushButton::clicked, this, &GameControlsUnitControls::buttonEraseClicked);
    connect(buttonNotes, &QPushButton::toggled, this, &GameControlsUnitControls::buttonNotesToggled);
    connect(buttonHint, &QPushButton::clicked, this, &GameControlsUnitControls::buttonHintClicked);

    setUnitType(QxPanelUnit::FlatBox);
    setUnitTitle(tr("Controls"));
}
