/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "aboutpagecontents.h"

#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>

using namespace Qt::Literals::StringLiterals;


//
// Authors

AboutPageAuthors::AboutPageAuthors(QWidget* parent)
    : AboutPage{parent}
{
    const QList<QStringList> items = {
        {
            tr("Ralf Stamm"),
            tr("Created and developed by <a href=\"https://rstammdev.github.io\" title=\"Visit contributor's homepage\">Ralf Stamm</a>.")
        }
    };

    QString text = tr("<dl>");
    for (QStringList item : items) {
        text += tr("<dt><strong>%1</strong></dt>").arg(item[0]);
        text += tr("<dd>%1</dd>").arg(item[1]);
    }
    text += tr("</dl>");

    QLabel* content = new QLabel;
    content->setText(text);
    content->setTextFormat(Qt::RichText);
    content->setTextInteractionFlags(Qt::TextBrowserInteraction);
    content->setOpenExternalLinks(true);
    content->setWordWrap(true);
    content->setFrameShape(QFrame::StyledPanel);

    QWidget* widget = new QWidget(parent);

    QVBoxLayout* layout = new QVBoxLayout(widget);
    layout->addWidget(content);
    layout->addStretch();

    setWidget(widget);
    setWidgetResizable(true);
    setFrameShape(QFrame::NoFrame);

    setPageTitle(tr("Authors"));
}


//
// Components

AboutPageComponents::AboutPageComponents(QWidget* parent)
    : AboutPage{parent}
{
    const QList<QStringList> items = {
        {
            tr("Application"),
            tr("%1").arg(QApplication::applicationVersion())
        },
        {
            tr("Qt for C++"),
            tr("Using %1 and built against %2").arg(qVersion(), QT_VERSION_STR)
        },
        {
            tr("Operation System"),
            tr("%4 (%5)<br>Running on %6 and compiled for %7<br>Kernel %8 %9").arg(QSysInfo::prettyProductName(), prettyPlatformName(), QSysInfo::currentCpuArchitecture(), QSysInfo::buildAbi(), QSysInfo::kernelType(), QSysInfo::kernelVersion())
        }
    };

    QString text = tr("<dl>");
    for (QStringList item : items) {
        text += tr("<dt><strong>%1</strong></dt>").arg(item[0]);
        text += tr("<dd>%1</dd>").arg(item[1]);
    }
    text += tr("</dl>");

    QLabel* content = new QLabel;
    content->setText(text);
    content->setTextFormat(Qt::RichText);
    content->setTextInteractionFlags(Qt::TextBrowserInteraction);
    content->setOpenExternalLinks(true);
    content->setWordWrap(true);
    content->setFrameShape(QFrame::StyledPanel);

    QWidget* widget = new QWidget(parent);

    QVBoxLayout* layout = new QVBoxLayout(widget);
    layout->addWidget(content);
    layout->addStretch();

    setWidget(widget);
    setWidgetResizable(true);
    setFrameShape(QFrame::NoFrame);

    setPageTitle(tr("Components"));
}


QString AboutPageComponents::prettyPlatformName() const
{
    const QString& platformName = QApplication::platformName();
    if (platformName == "wayland"_L1) {
        return tr("Wayland");
    } else if (platformName == "xcb"_L1) {
        return tr("X11");
    }

    return tr("Unknown (%1)").arg(platformName);
}


//
// Credits

AboutPageCredits::AboutPageCredits(QWidget* parent)
    : AboutPage{parent}
{
    const QList<QStringList> items = {
        {
            tr("Bootstrap Icons project"),
            tr("Application logo made by <a href=\"https://icons.getbootstrap.com\" title=\"Visit project's homepage\">Bootstrap Icons</a> from <a href=\"https://getbootstrap.com\" title=\"Visit organization's homepage\">Bootstrap</a> is licensed under <a href=\"https://opensource.org/license/mit\" title=\"Visit license's homepage\">MIT</a>.")
        },
        {
            tr("Breeze Icons project"),
            tr("Application icons made by <a href=\"https://api.kde.org/frameworks/breeze-icons/html/\" title=\"Visit project's homepage\">Breeze Icons</a> from <a href=\"https://kde.org\" title=\"Visit organization's homepage\">KDE</a> are licensed under <a href=\"https://www.gnu.org/licenses/lgpl-3.0.en.html\" title=\"Visit license's homepage\">LGPLv3</a>.")
        }
    };

    QString text = tr("<dl>");
    for (QStringList item : items) {
        text += tr("<dt><strong>%1</strong></dt>").arg(item[0]);
        text += tr("<dd>%1</dd>").arg(item[1]);
    }
    text += tr("</dl>");

    QLabel* content = new QLabel;
    content->setText(text);
    content->setTextFormat(Qt::RichText);
    content->setTextInteractionFlags(Qt::TextBrowserInteraction);
    content->setOpenExternalLinks(true);
    content->setWordWrap(true);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(content);
    layout->addStretch();
    setLayout(layout);

    setPageTitle(tr("Credits"));
}


//
// General

AboutPageGeneral::AboutPageGeneral(QWidget* parent)
    : AboutPage{parent}
{
    const QStringList paragraphs = {
        tr("Sudoku is a logic-based, combinatorial number-placement puzzle."),
        tr("In <a href=\"https://en.wikipedia.org/wiki/Sudoku\" title=\"Visit Sudoku's wikipedia page\">Classic Sudoku</a>, the objective is to fill a 9 × 9 grid with digits so that each column, each row, and each of the nine 3 × 3 subgrids that compose the grid (also called \"boxes\", \"blocks\", or \"regions\") contains all of the digits from 1 to 9."),
        tr("The <a href=\"https://en.wikipedia.org/wiki/Killer_sudoku\" title=\"Visit Killer Sudoku's wikipedia page\">Killer Sudoku</a> variant combines elements of Sudoku and Kakuro. A killer sudoku puzzle is made up of 'cages', typically depicted by boxes outlined with dashes or colours. The sum of the numbers in a cage is written in the top left corner of the cage, and numbers cannot be repeated in a cage."),
        tr("The puzzle setter provides a partially completed grid, which for a well-posed puzzle has a single solution."),
        tr("<a href=\"https://rstammdev.github.io/sudoku-qt\" title=\"Visit project's homepage\">Sudoku-Qt</a> is a free open-source game for these Sudoku games written in C++ using the Qt framework."),
        tr("Copyright &copy; 2025 <a href=\"%2\" title=\"Visit organization's homepage\">%1</a>.").arg(QApplication::organizationName(), QApplication::organizationDomain()),
        tr("This program is distributed under the terms of the <a href=\"https://www.gnu.org/licenses/gpl-3.0.en.html\" title=\"Visit license's homepage\">GNU General Public License</a>, either version 3 of the License, or any later version.")
    };

    QString text;
    for (const QString& paragraph : paragraphs) {
        text += tr("<p>%1</p>\n").arg(paragraph);
    }

    QLabel* content = new QLabel;
    content->setText(text);
    content->setTextFormat(Qt::RichText);
    content->setTextInteractionFlags(Qt::TextBrowserInteraction);
    content->setOpenExternalLinks(true);
    content->setWordWrap(true);
    content->setFrameShape(QFrame::StyledPanel);

    QWidget* widget = new QWidget(parent);

    QVBoxLayout* layout = new QVBoxLayout(widget);
    layout->addWidget(content);
    layout->addStretch();

    setWidget(widget);
    setWidgetResizable(true);
    setFrameShape(QFrame::NoFrame);

    setPageTitle(tr("General"));
}


//
// License

AboutPageLicense::AboutPageLicense(QWidget* parent)
    : AboutPage{parent}
{
    const QStringList paragraphs = {
        tr("This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version."),
        tr("This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details."),
        tr("You should have received a copy of the GNU General Public License along with this program. If not, see <a href=\"https://www.gnu.org/licenses/\" title=\"Visit license's homepage\">https://www.gnu.org/licenses/</a>.")
    };

    QString text;
    for (const QString& paragraph : paragraphs) {
        text += tr("<p>%1</p>\n").arg(paragraph);
    }

    QLabel* content = new QLabel;
    content->setText(text);
    content->setTextFormat(Qt::RichText);
    content->setTextInteractionFlags(Qt::TextBrowserInteraction);
    content->setOpenExternalLinks(true);
    content->setWordWrap(true);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(content);
    layout->addStretch();
    setLayout(layout);

    setPageTitle(tr("License"));
}
