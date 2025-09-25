/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "gamecontrolsunitnumberpad.h"

#include <QAbstractButton>
#include <QFont>
#include <QGridLayout>
#include <QPushButton>

using namespace Qt::Literals::StringLiterals;


GameControlsUnitNumberPad::GameControlsUnitNumberPad(QWidget* parent)
    : QxPanelUnit{parent}
{
    QPushButton* buttonNo1 = new QPushButton(tr("&1"));
    buttonNo1->setObjectName("buttonNo1"_L1);

    QPushButton* buttonNo2 = new QPushButton(tr("&2"));
    buttonNo2->setObjectName("buttonNo2"_L1);

    QPushButton* buttonNo3 = new QPushButton(tr("&3"));
    buttonNo3->setObjectName("buttonNo3"_L1);

    QPushButton* buttonNo4 = new QPushButton(tr("&4"));
    buttonNo4->setObjectName("buttonNo4"_L1);

    QPushButton* buttonNo5 = new QPushButton(tr("&5"));
    buttonNo5->setObjectName("buttonNo5"_L1);

    QPushButton* buttonNo6 = new QPushButton(tr("&6"));
    buttonNo6->setObjectName("buttonNo6"_L1);

    QPushButton* buttonNo7 = new QPushButton(tr("&7"));
    buttonNo7->setObjectName("buttonNo7"_L1);

    QPushButton* buttonNo8 = new QPushButton(tr("&8"));
    buttonNo8->setObjectName("buttonNo8"_L1);

    QPushButton* buttonNo9 = new QPushButton(tr("&9"));
    buttonNo9->setObjectName("buttonNo9"_L1);

    m_buttonsNumbers = new QButtonGroup;
    m_buttonsNumbers->setObjectName("buttonsNumbers"_L1);
    m_buttonsNumbers->addButton(buttonNo1, 1);
    m_buttonsNumbers->addButton(buttonNo2, 2);
    m_buttonsNumbers->addButton(buttonNo3, 3);
    m_buttonsNumbers->addButton(buttonNo4, 4);
    m_buttonsNumbers->addButton(buttonNo5, 5);
    m_buttonsNumbers->addButton(buttonNo6, 6);
    m_buttonsNumbers->addButton(buttonNo7, 7);
    m_buttonsNumbers->addButton(buttonNo8, 8);
    m_buttonsNumbers->addButton(buttonNo9, 9);

    QGridLayout* layout = new QGridLayout;
    layout->setObjectName("layout"_L1);
    layout->addWidget(buttonNo1, 0, 0);
    layout->addWidget(buttonNo2, 0, 1);
    layout->addWidget(buttonNo3, 0, 2);
    layout->addWidget(buttonNo4, 1, 0);
    layout->addWidget(buttonNo5, 1, 1);
    layout->addWidget(buttonNo6, 1, 2);
    layout->addWidget(buttonNo7, 2, 0);
    layout->addWidget(buttonNo8, 2, 1);
    layout->addWidget(buttonNo9, 2, 2);
    setLayout(layout);

    connect(m_buttonsNumbers, &QButtonGroup::idClicked, this, &GameControlsUnitNumberPad::buttonClicked);

    setUnitType(QxPanelUnit::FrameBox);
    setUnitTitle(tr("Number Pad"));
}


void GameControlsUnitNumberPad::updateButtonStyleRequested(const bool checked)
{
    for (QAbstractButton* button : m_buttonsNumbers->buttons()) {

        QFont font = button->font();
        font.setItalic(checked);
        button->setFont(font);
    }
}
