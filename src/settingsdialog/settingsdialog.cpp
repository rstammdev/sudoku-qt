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
#include <QVBoxLayout>


SettingsDialog::SettingsDialog(QWidget *parent)
    : QDialog{parent}
{

    // Buttons

    QDialogButtonBox* buttonBox = new QDialogButtonBox;

    buttonBox->addButton(QDialogButtonBox::Close);
    buttonBox->addButton(QDialogButtonBox::Ok);

    connect(buttonBox, &QDialogButtonBox::rejected, this, &SettingsDialog::close);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &SettingsDialog::saveAndClose);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(buttonBox);
    setLayout(layout);

    setWindowTitle(tr("Configure %1").arg(QApplication::applicationName()));
    setMinimumSize(1024, 576);

}


void SettingsDialog::saveAndClose()
{
    emit saveRequested();

    accept();
}
