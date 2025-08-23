/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "settingspagecomponents.h"

#include <QLabel>
#include <QVBoxLayout>


SettingsPageComponents::SettingsPageComponents(QWidget* parent)
    : SettingsPage{parent}
{
    QLabel* title = new QLabel(tr("<strong style=\"font-size: large;\">%1</strong>").arg(tr("Components")));
    QLabel* description = new QLabel(tr("Specify which information in the components dialog is shown."));

    // Tabs

    const QList<SettingsPage*> pages{
    };

    m_tabBox = new QTabWidget;

    for (const auto page : pages) {

        m_tabBox->addTab(page, page->pageTitle());

        connect(page, &SettingsPage::stateChanged, this, &SettingsPage::stateChanged);
        connect(this, &SettingsPage::saveRequested, page, &SettingsPage::save);
    }

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->setContentsMargins(-1, -1, 0, 0);
    layout->addWidget(title);
    layout->addWidget(description);
    layout->addWidget(m_tabBox);

    QWidget* widget = new QWidget(parent);
    widget->setLayout(layout);

    setWidget(widget);
    setWidgetResizable(true);
    setFrameShape(QFrame::NoFrame);

    setPageType(SettingsPage::PageTypeRoot);
    setPageTitle(tr("Components"));
    setPageDescription(tr("Specify which information in the Components dialog is shown."));
}


void SettingsPageComponents::save()
{
    emit saveRequested();
}
