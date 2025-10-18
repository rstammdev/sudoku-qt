/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef ABOUTPAGECONTENT_H
#define ABOUTPAGECONTENT_H

#include <QWidget>

#include "aboutpage.h"


//
// Authors

class AboutPageContentTabAuthors : public AboutPage
{
    Q_OBJECT

public:
    explicit AboutPageContentTabAuthors(QWidget* parent = nullptr);
    ~AboutPageContentTabAuthors() = default;
};


//
// Credits

class AboutPageContentTabCredits : public AboutPage
{
    Q_OBJECT

public:
    explicit AboutPageContentTabCredits(QWidget* parent = nullptr);
    ~AboutPageContentTabCredits() = default;
};


//
// License

class AboutPageContentTabLicense : public AboutPage
{
    Q_OBJECT

public:
    explicit AboutPageContentTabLicense(QWidget* parent = nullptr);
    ~AboutPageContentTabLicense() = default;
};

#endif // ABOUTPAGECONTENT_H
