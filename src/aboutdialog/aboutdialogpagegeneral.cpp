/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "aboutdialogpagegeneral.h"

#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>


AboutDialogPageGeneral::AboutDialogPageGeneral(QWidget* parent)
    : QWidget{parent}
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

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(content);
    layout->addStretch();
    setLayout(layout);
}
