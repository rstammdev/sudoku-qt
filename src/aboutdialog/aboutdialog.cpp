/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "aboutdialog.h"

#include <QApplication>
#include <QDialogButtonBox>
#include <QTabWidget>
#include <QVBoxLayout>

#include "aboutpage.h"
#include "aboutpagecontents.h"


AboutDialog::AboutDialog(QWidget* parent)
    : QDialog{parent}
{

    QTabWidget* tabBox = new QTabWidget;

    const QList<AboutPage*> pages{
        new AboutPageGeneral,
        new AboutPageComponents,
        new AboutPageAuthors,
    };

    for (const auto page : pages)
        tabBox->addTab(page, page->pageTitle());

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Close);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(tabBox);
    layout->addWidget(buttonBox);
    setLayout(layout);

    connect(buttonBox, &QDialogButtonBox::rejected, this, &AboutDialog::close);

    setWindowTitle(tr("About %1").arg(QApplication::applicationName()));
    setMinimumSize(640, 480);
}
