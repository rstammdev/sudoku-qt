/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "aboutpagecontent.h"

#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>

using namespace Qt::Literals::StringLiterals;


//
// Credits

AboutPageContentTabCredits::AboutPageContentTabCredits(QWidget* parent)
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
    content->setFrameShape(QFrame::StyledPanel);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(content);
    layout->addStretch();

    QWidget* widget = new QWidget(parent);
    widget->setLayout(layout);

    setWidget(widget);
    setWidgetResizable(true);
    setFrameShape(QFrame::NoFrame);

    setPageTitle(tr("Credits"));
}


//
// License

AboutPageContentTabLicense::AboutPageContentTabLicense(QWidget* parent)
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
    content->setFrameShape(QFrame::StyledPanel);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(content);
    layout->addStretch();

    QWidget* widget = new QWidget(parent);
    widget->setLayout(layout);

    setWidget(widget);
    setWidgetResizable(true);
    setFrameShape(QFrame::NoFrame);

    setPageTitle(tr("License"));
}
