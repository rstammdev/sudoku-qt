/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "settingsdialog.h"

#include <QApplication>
#include <QDialogButtonBox>
#include <QTreeWidget>
#include <QVBoxLayout>

#include "settingspage.h"
#include "settingspageapplication.h"
#include "settingspageapplicationappearance.h"


SettingsDialog::SettingsDialog(QWidget* parent)
    : QDialog{parent}
{
    // Pages

    const QList<SettingsPage*> pages{
        new SettingsPageApplication(this),
        new SettingsPageApplicationAppearance(this),
    };

    QTreeWidget* treePages = new QTreeWidget;
    treePages->setHeaderHidden(true);
    treePages->setRootIsDecorated(false);

    QTreeWidgetItem* treeItemRoot = nullptr;
    QTreeWidgetItem* treeItemBranch = nullptr;

    for (auto page : pages) {

        QTreeWidgetItem* treeItem = nullptr;

        if (page->pageType() == SettingsPage::PageTypeRoot) {
            treeItem = treeItemRoot = new QTreeWidgetItem(treePages);
            treePages->expandItem(treeItem);
        }
        else if (page->pageType() == SettingsPage::PageTypeBranch) {
            treeItem = treeItemBranch = new QTreeWidgetItem(treeItemRoot);
        }
        else if (page->pageType() == SettingsPage::PageTypeLeaf) {
            treeItem = new QTreeWidgetItem(treeItemBranch);
        }

        if (treeItem) {
            treeItem->setText(0, page->pageTitle());
            treeItem->setToolTip(0, page->pageDescription());

            connect(this, &SettingsDialog::saveRequested, page, &SettingsPage::save);
            connect(this, &SettingsDialog::restoreDefaultsRequested, page, &SettingsPage::restoreDefaults);
        }
    }

    QHBoxLayout* layoutPages = new QHBoxLayout;
    layoutPages->addWidget(treePages, 1);

    // Buttons

    QDialogButtonBox* buttonBox = new QDialogButtonBox;

    buttonBox->addButton(QDialogButtonBox::Close);
    buttonBox->addButton(QDialogButtonBox::Ok);
    m_buttonApply = buttonBox->addButton(QDialogButtonBox::Apply);

    connect(buttonBox, &QDialogButtonBox::rejected, this, &SettingsDialog::close);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &SettingsDialog::saveAndClose);
    connect(m_buttonApply, &QPushButton::clicked, this, &SettingsDialog::saveAndContinue);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addLayout(layoutPages);
    layout->addWidget(buttonBox);
    setLayout(layout);

    setWindowTitle(tr("Configure %1").arg(QApplication::applicationName()));
    setMinimumSize(1024, 576);

    treePages->setCurrentItem(treePages->topLevelItem(0));

    m_buttonApply->setEnabled(false);
}


void SettingsDialog::saveAndClose()
{
    emit saveRequested();

    accept();
}


void SettingsDialog::saveAndContinue()
{
    emit saveRequested();

    m_buttonApply->setEnabled(false);
}
