/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/sudoku-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "mainwindow.h"

#include <QActionGroup>
#include <QApplication>
#include <QList>
#include <QMenu>
#include <QMenuBar>
#include <QSettings>
#include <QStatusBar>
#include <QToolBar>
#include <QToolButton>
#include <QVBoxLayout>

#include <qxcomponentsdialog.h>
#include <qxconfirmationbox.h>
#include <qxpanelpalette.h>
#include <qxtoolbarsdialog.h>
#include <qxtoollabel.h>
#include <qxzoombutton.h>

#include "aboutdialog/aboutdialog.h"
#include "gamecontrolspanel/gamecontrolsunitcontrols.h"
#include "gamecontrolspanel/gamecontrolsunitnewgame.h"
#include "gamecontrolspanel/gamecontrolsunitnumberpad.h"
#include "gamecontrolspanel/gamecontrolsunitscoreboard.h"
#include "gamecontrolspanel/gamecontrolsunitstatistics.h"
#include "settingsdialog/settingsdialog.h"
#include "sudoku.h"

using namespace Qt::Literals::StringLiterals;


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{

    setupUi();
    loadSettings();

    setCentralWidget(new QWidget);

    setWindowIcon(QIcon::fromTheme("sudoku-qt"_L1, QIcon(":/icons/apps/16/sudoku-qt"_L1)));
    setMinimumSize(854, 480);

}

MainWindow::~MainWindow() {}


void MainWindow::setupUi()
{
    QActionGroup* actionsSudokuGames = new QActionGroup(this);
    actionsSudokuGames->setObjectName(QStringLiteral("actionsSudokuGames"));
    actionsSudokuGames->setExclusionPolicy(QActionGroup::ExclusionPolicy::ExclusiveOptional);

    connect(actionsSudokuGames, &QActionGroup::triggered, this, &MainWindow::applySudokuGame);

    // File menu & toolbar

    QAction* actionQuit = addAction(tr("&Quit"));
    actionQuit->setObjectName("actionQuit"_L1);
    actionQuit->setIcon(QIcon::fromTheme("application-exit"_L1, QIcon(":/icons/actions/16/application-exit"_L1)));
    actionQuit->setIconText(tr("Quit"));
    actionQuit->setShortcut(QKeySequence::Quit);
    actionQuit->setStatusTip(tr("Quit the application"));
    actionQuit->setToolTip(tr("Quit the application."));
    actionQuit->setMenuRole(QAction::QuitRole);

    QMenu* menuFile = menuBar()->addMenu(tr("&File"));
    menuFile->setObjectName("menuFile"_L1);
    menuFile->addAction(actionQuit);

    QToolBar* toolbarFile = addToolBar(tr("File Toolbar"));
    toolbarFile->setObjectName("toolbarFile"_L1);
    toolbarFile->addAction(actionQuit);

    connect(actionQuit, &QAction::triggered, this, &MainWindow::close);

    // Sudoku Classic menu & toolbar

    QList<QAction*> actionsSudokuClassic;

    for (const QStringList& game : Sudoku::gamesClassic()) {

        QAction* action = addAction(game[1]);
        action->setObjectName("action_%1"_L1.arg(game[0]));
        action->setIconText(game[2]);
        action->setToolTip(tr("Sudoku Classic<br><strong>%1</strong><br>%2.").arg(game[1], game[3]));
        action->setStatusTip(tr("Sudoku Classic %1: %2").arg(game[1], game[3]));
        action->setCheckable(true);
        action->setData(game[0]);

        actionsSudokuGames->addAction(action);
        actionsSudokuClassic.append(action);
    }

    QMenu* menuSudokuClassic = menuBar()->addMenu(tr("Sudoku &Classic"));
    menuSudokuClassic->setObjectName("menuSudokuClassic"_L1);
    menuSudokuClassic->addActions(actionsSudokuClassic);

    QxToolLabel* labelSudokuClassic = new QxToolLabel(tr("Classic"));
    labelSudokuClassic->setObjectName("labelSudokuClassic"_L1);
    labelSudokuClassic->setToolTip(tr("Sudoku Classic Games"));
    labelSudokuClassic->setFontBold(true);

    QToolBar* toolbarSudokuClassic = addToolBar(tr("Sudoku Classic Toolbar"));
    toolbarSudokuClassic->setObjectName("toolbarSudokuClassic"_L1);
    toolbarSudokuClassic->addWidget(labelSudokuClassic);
    toolbarSudokuClassic->addActions(actionsSudokuClassic);

    // Sudoku Killer menu & toolbar

    QMenu* menuSudokuKiller = menuBar()->addMenu(tr("Sudoku &Killer"));
    menuSudokuKiller->setObjectName("menuSudokuKiller"_L1);

    QToolBar* toolbarSudokuKiller = addToolBar(tr("Sudoku Killer Toolbar"));
    toolbarSudokuKiller->setObjectName("toolbarSudokuKiller"_L1);

    // View menu & toolbar



    QAction* actionEnlargeFont = addAction(tr("&Enlarge Font"));
    actionEnlargeFont->setObjectName("actionEnlargeFont"_L1);
    actionEnlargeFont->setIcon(QIcon::fromTheme("zoom-in"_L1, QIcon(":/icons/actions/16/zoom-in"_L1)));
    actionEnlargeFont->setIconText(tr("Zoom In"));
    actionEnlargeFont->setShortcut(QKeySequence::ZoomIn);
    actionEnlargeFont->setStatusTip(tr("This increases the display font size"));
    actionEnlargeFont->setToolTip(tr("This increases the display font size."));

    QAction* actionShrinkFont = addAction(tr("S&hrink Font"));
    actionShrinkFont->setObjectName("actionShrinkFont"_L1);
    actionShrinkFont->setIcon(QIcon::fromTheme("zoom-out"_L1, QIcon(":/icons/actions/16/zoom-out"_L1)));
    actionShrinkFont->setIconText(tr("Zoom Out"));
    actionShrinkFont->setShortcut(QKeySequence::ZoomOut);
    actionShrinkFont->setStatusTip(tr("This decreases the display font size"));
    actionShrinkFont->setToolTip(tr("This decreases the display font size."));

    QAction* actionResetFontSize = addAction(tr("&Reset Font Size"));
    actionResetFontSize->setObjectName("actionResetFontSize"_L1);
    actionResetFontSize->setIcon(QIcon::fromTheme("zoom-original"_L1, QIcon(":/icons/actions/16/zoom-original"_L1)));
    actionResetFontSize->setIconText(tr("Zoom Original"));
    actionResetFontSize->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_0));
    actionResetFontSize->setStatusTip(tr("This resets the display font size"));
    actionResetFontSize->setToolTip(tr("This resets the display font size."));

    QAction* actionFullScreen = addAction(tr("F&ull Screen"));
    actionFullScreen->setObjectName("actionFullScreen"_L1);
    actionFullScreen->setIconText(tr("Full Screen"));
    actionFullScreen->setShortcuts({ QKeySequence(Qt::Key_F11), QKeySequence::FullScreen });
    actionFullScreen->setCheckable(true);

    actionFullScreen->toggle();
    connect(actionFullScreen, &QAction::toggled, [=](){
        if (!actionFullScreen->isChecked()) {
            actionFullScreen->setText(tr("F&ull Screen Mode"));
            actionFullScreen->setIcon(QIcon::fromTheme("view-fullscreen"_L1, QIcon(":/icons/actions/16/view-fullscreen"_L1)));
            actionFullScreen->setStatusTip(tr("Display the window in full screen"));
            actionFullScreen->setToolTip(tr("Display the window in full screen."));
        }
        else {
            actionFullScreen->setText(tr("Exit F&ull Screen Mode"));
            actionFullScreen->setIcon(QIcon::fromTheme("view-restore"_L1, QIcon(":/icons/actions/16/view-restore"_L1)));
            actionFullScreen->setStatusTip(tr("Exit the full screen mode"));
            actionFullScreen->setToolTip(tr("Exit the full screen mode."));
        }
    });
    actionFullScreen->toggle();

    QMenu* menuView = menuBar()->addMenu(tr("&View"));
    menuView->setObjectName("menuView"_L1);
    menuView->addAction(actionEnlargeFont);
    menuView->addAction(actionShrinkFont);
    menuView->addAction(actionResetFontSize);
    menuView->addSeparator();
    menuView->addAction(actionFullScreen);

    QxZoomButton* buttonZoomControl = new QxZoomButton;
    buttonZoomControl->setObjectName("buttonZoomControl"_L1);
    buttonZoomControl->setDefaultAction(actionResetFontSize);
    buttonZoomControl->setText(tr("%1%"));
    buttonZoomControl->setToolButtonStyle(Qt::ToolButtonTextOnly);

    QToolBar* toolbarView = addToolBar(tr("View Toolbar"));
    toolbarView->setObjectName("toolbarView"_L1);
    toolbarView->addAction(actionShrinkFont);
    toolbarView->addWidget(buttonZoomControl);
    toolbarView->addAction(actionEnlargeFont);
    toolbarView->addSeparator();
    toolbarView->addAction(actionFullScreen);

    connect(actionEnlargeFont, &QAction::triggered, buttonZoomControl, &QxZoomButton::zoomIn);
    connect(actionShrinkFont, &QAction::triggered, buttonZoomControl, &QxZoomButton::zoomOut);
    connect(actionResetFontSize, &QAction::triggered, buttonZoomControl, &QxZoomButton::resetZoom);
    connect(buttonZoomControl, &QxZoomButton::zoomFactorChanged, this, &MainWindow::applyZoomFactor);
    connect(actionFullScreen, &QAction::toggled, this, &MainWindow::toggleFullScreen);

    // Settings menu & toolbar

    m_actionSchemeTheme = addAction(tr("&Scheme && Theme"));
    m_actionSchemeTheme->setObjectName("actionSchemeTheme"_L1);
    m_actionSchemeTheme->setIcon(QIcon::fromTheme("color-mode-black-white"_L1, QIcon(":/icons/actions/16/color-mode-black-white"_L1)));
    m_actionSchemeTheme->setIconText(tr("Scheme && Theme"));
    m_actionSchemeTheme->setStatusTip(tr("Enable the theme & scheme"));
    m_actionSchemeTheme->setToolTip(tr("Enable the theme & scheme."));
    m_actionSchemeTheme->setCheckable(true);

    m_actionShowMenubar = addAction(tr("Show &Menubar"));
    m_actionShowMenubar->setObjectName("actionShowMenubar"_L1);
    m_actionShowMenubar->setIcon(QIcon::fromTheme("show-menu"_L1, QIcon(":/icons/actions/16/show-menu"_L1)));
    m_actionShowMenubar->setIconText(tr("Menubar"));
    m_actionShowMenubar->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_M));
    m_actionShowMenubar->setStatusTip(tr("Show the menubar"));
    m_actionShowMenubar->setToolTip(tr("Show the menubar."));
    m_actionShowMenubar->setCheckable(true);
    m_actionShowMenubar->setChecked(true);

    m_actionShowStatusbar = addAction(tr("Show St&atusbar"));
    m_actionShowStatusbar->setObjectName("actionShowStatusbar"_L1);
    m_actionShowStatusbar->setIcon(QIcon::fromTheme("show-menu"_L1, QIcon(":/icons/actions/16/show-menu"_L1)));
    m_actionShowStatusbar->setIconText(tr("Statusbar"));
    m_actionShowStatusbar->setStatusTip(tr("Show the statusbar"));
    m_actionShowStatusbar->setToolTip(tr("Show the statusbar."));
    m_actionShowStatusbar->setCheckable(true);
    m_actionShowStatusbar->setChecked(true);

    QAction* actionConfigureLanguage = addAction(tr("Configure &Language..."));
    actionConfigureLanguage->setObjectName("actionConfigureLanguage"_L1);
    actionConfigureLanguage->setIcon(QIcon::fromTheme("language-chooser"_L1, QIcon(":/icons/actions/16/language-chooser"_L1)));
    actionConfigureLanguage->setIconText(tr("Language"));
    actionConfigureLanguage->setStatusTip(tr("Configure the application's language"));
    actionConfigureLanguage->setToolTip(tr("Configure the application's language."));

    QAction* actionConfigureKeyboardShortcuts = addAction(tr("Configure &Keyboard Shortcuts..."));
    actionConfigureKeyboardShortcuts->setObjectName("actionConfigureKeyboardShortcuts"_L1);
    actionConfigureKeyboardShortcuts->setIcon(QIcon::fromTheme("configure-shortcuts"_L1, QIcon(":/icons/actions/16/configure-shortcuts"_L1)));
    actionConfigureKeyboardShortcuts->setIconText(tr("Shortcuts"));
    actionConfigureKeyboardShortcuts->setShortcut(QKeySequence(Qt::CTRL | Qt::ALT | Qt::Key_Comma));
    actionConfigureKeyboardShortcuts->setStatusTip(tr("Configure the application's keyboard shortcut assignments"));
    actionConfigureKeyboardShortcuts->setToolTip(tr("Configure the application's keyboard shortcut assignments."));

    QAction* actionConfigurePanels = addAction(tr("Configure &Panels..."));
    actionConfigurePanels->setObjectName("actionConfigurePanels"_L1);
    actionConfigurePanels->setIcon(QIcon::fromTheme("configure"_L1, QIcon(":/icons/actions/16/configure"_L1)));
    actionConfigurePanels->setIconText(tr("Panels"));
    actionConfigurePanels->setStatusTip(tr("Configure which items should appear in the panels"));
    actionConfigurePanels->setToolTip(tr("Configure which items should appear in the panels."));

    QAction* actionConfigureToolbars = addAction(tr("Configure &Toolbars..."));
    actionConfigureToolbars->setObjectName("actionConfigureToolbars"_L1);
    actionConfigureToolbars->setIcon(QIcon::fromTheme("configure-toolbars"_L1, QIcon(":/icons/actions/16/configure-toolbars"_L1)));
    actionConfigureToolbars->setIconText(tr("Toolbars"));
    actionConfigureToolbars->setStatusTip(tr("Configure which items should appear in the toolbars"));
    actionConfigureToolbars->setToolTip(tr("Configure which items should appear in the toolbars."));

    QAction* actionConfigure = addAction(tr("&Configure..."));
    actionConfigure->setObjectName("actionConfigure"_L1);
    actionConfigure->setIcon(QIcon::fromTheme("configure"_L1, QIcon(":/icons/actions/16/configure"_L1)));
    actionConfigure->setShortcut(QKeySequence::Preferences);
    actionConfigure->setStatusTip(tr("Configure various aspects of this application"));
    actionConfigure->setToolTip(tr("Configure various aspects of this application."));
    actionConfigure->setMenuRole(QAction::PreferencesRole);

    QMenu* menuSettings = menuBar()->addMenu(tr("&Settings"));
    menuSettings->setObjectName("menuSettings"_L1);

    QMenu* menuShowPanels = new QMenu(tr("Panels Shown"), menuSettings);
    menuShowPanels->setObjectName("menuShowPanels"_L1);

    QMenu* menuShowToolbars = new QMenu(tr("Toolbars Shown"), menuSettings);
    menuShowToolbars->setObjectName("menuShowToolbars"_L1);

    menuSettings->addAction(m_actionSchemeTheme);
    menuSettings->addSeparator();
    menuSettings->addAction(m_actionShowMenubar);
    menuSettings->addMenu(menuShowPanels);
    menuSettings->addMenu(menuShowToolbars);
    menuSettings->addAction(m_actionShowStatusbar);
    menuSettings->addSeparator();
    menuSettings->addAction(actionConfigureLanguage);
    menuSettings->addAction(actionConfigureKeyboardShortcuts);
    menuSettings->addAction(actionConfigurePanels);
    menuSettings->addAction(actionConfigureToolbars);
    menuSettings->addAction(actionConfigure);

    QToolButton* buttonConfigurePanels = new QToolButton;
    buttonConfigurePanels->setObjectName("buttonConfigurePanels"_L1);
    buttonConfigurePanels->setDefaultAction(actionConfigurePanels);
    buttonConfigurePanels->setMenu(menuShowPanels);
    buttonConfigurePanels->setPopupMode(QToolButton::MenuButtonPopup);

    QToolButton* buttonConfigureToolbars = new QToolButton;
    buttonConfigureToolbars->setObjectName("buttonConfigureToolbars"_L1);
    buttonConfigureToolbars->setDefaultAction(actionConfigureToolbars);
    buttonConfigureToolbars->setMenu(menuShowToolbars);
    buttonConfigureToolbars->setPopupMode(QToolButton::MenuButtonPopup);

    QToolBar* toolbarSettings = addToolBar(tr("Settings Toolbar"));
    toolbarSettings->setObjectName("toolbarSettings"_L1);
    toolbarSettings->addAction(m_actionSchemeTheme);
    toolbarSettings->addSeparator();
    toolbarSettings->addAction(m_actionShowMenubar);
    toolbarSettings->addWidget(buttonConfigurePanels);
    toolbarSettings->addWidget(buttonConfigureToolbars);
    toolbarSettings->addAction(m_actionShowStatusbar);
    toolbarSettings->addSeparator();
    toolbarSettings->addAction(actionConfigureLanguage);
    toolbarSettings->addAction(actionConfigureKeyboardShortcuts);
    toolbarSettings->addAction(actionConfigure);

    connect(m_actionShowMenubar, &QAction::toggled, menuBar(), &QMenuBar::setVisible);
    connect(m_actionShowStatusbar, &QAction::toggled, statusBar(), &QStatusBar::setVisible);
    connect(actionConfigureLanguage, &QAction::triggered, this, &MainWindow::triggerConfigureLanguageDialog);
    connect(actionConfigureKeyboardShortcuts, &QAction::triggered, this, &MainWindow::triggerConfigureShortcutsDialog);
    connect(actionConfigurePanels, &QAction::triggered, this, &MainWindow::triggerConfigurePanelsDialog);
    connect(actionConfigureToolbars, &QAction::triggered, this, &MainWindow::triggerConfigureToolbarsDialog);
    connect(actionConfigure, &QAction::triggered, this, &MainWindow::triggerConfigureDialog);

    // Help menu & toolbar

    QAction* actionCopyComponents = addAction(tr("Copy &Components..."));
    actionCopyComponents->setObjectName("actionCopyComponents"_L1);
    actionCopyComponents->setIcon(QIcon::fromTheme("info"_L1, QIcon(":/icons/actions/16/info"_L1)));
    actionCopyComponents->setIconText(tr("Components"));
    actionCopyComponents->setStatusTip(tr("Copy application components to clipboard"));
    actionCopyComponents->setToolTip(tr("Copy application components to clipboard."));

    QAction* actionAbout = addAction(tr("&About %1").arg(QApplication::applicationName()));
    actionAbout->setObjectName("actionAbout"_L1);
    actionAbout->setIcon(QIcon::fromTheme("sudoku-qt"_L1, QIcon(":/icons/apps/16/sudoku-qt"_L1)));
    actionAbout->setIconText(tr("About"));
    actionAbout->setStatusTip(tr("Brief description of this application"));
    actionAbout->setToolTip(tr("Brief description of this application."));
    actionAbout->setMenuRole(QAction::AboutRole);

    QMenu* menuHelp = menuBar()->addMenu(tr("&Help"));
    menuHelp->setObjectName("menuHelp"_L1);
    menuHelp->addAction(actionCopyComponents);
    menuHelp->addSeparator();
    menuHelp->addAction(actionAbout);

    QToolBar* toolbarHelp = addToolBar(tr("Help Toolbar"));
    toolbarHelp->setObjectName("toolbarHelp"_L1);
    toolbarHelp->addAction(actionCopyComponents);
    toolbarHelp->addAction(actionAbout);

    connect(actionCopyComponents, &QAction::triggered, this, &MainWindow::triggerComponentsDialog);
    connect(actionAbout, &QAction::triggered, this, &MainWindow::triggerAboutDialog);

    // Show Toolbars menu

    menuShowToolbars->addSection(tr("Toolbars"));
    menuShowToolbars->addAction(toolbarFile->toggleViewAction());
    menuShowToolbars->addAction(toolbarSudokuClassic->toggleViewAction());
    menuShowToolbars->addAction(toolbarSudokuKiller->toggleViewAction());
    menuShowToolbars->addAction(toolbarView->toggleViewAction());
    menuShowToolbars->addAction(toolbarSettings->toggleViewAction());
    menuShowToolbars->addAction(toolbarHelp->toggleViewAction());

    // Game Controls panel

    GameControlsUnitScoreBoard* unitGameControlsScoreBoard = new GameControlsUnitScoreBoard;
    unitGameControlsScoreBoard->setObjectName("unitGameControlsScoreBoard"_L1);

    GameControlsUnitStatistics* unitGameControlsStatistics = new GameControlsUnitStatistics;
    unitGameControlsStatistics->setObjectName("unitGameControlsStatistics"_L1);

    GameControlsUnitControls* unitGameControlsControls = new GameControlsUnitControls;
    unitGameControlsControls->setObjectName("unitGameControlsControls"_L1);

    GameControlsUnitNumberPad* unitGameControlsNumberPad = new GameControlsUnitNumberPad;
    unitGameControlsNumberPad->setObjectName("unitGameControlsNumberPad"_L1);

    GameControlsUnitNewGame* unitGameControlsNewGame = new GameControlsUnitNewGame;
    unitGameControlsNewGame->setObjectName("unitGameControlsNewGame"_L1);

    QxPanelPalette* panelGameControls = new QxPanelPalette(tr("Game Controls Panel"), this);
    panelGameControls->setObjectName("panelGameControls"_L1);
    panelGameControls->addUnit(unitGameControlsScoreBoard);
    panelGameControls->addUnit(unitGameControlsStatistics);
    panelGameControls->addUnit(unitGameControlsControls);
    panelGameControls->addUnit(unitGameControlsNumberPad);
    panelGameControls->addUnit(unitGameControlsNewGame);
    addDockWidget(Qt::RightDockWidgetArea, panelGameControls);

    connect(unitGameControlsControls, &GameControlsUnitControls::buttonNotesToggled, unitGameControlsNumberPad, &GameControlsUnitNumberPad::updateButtonStyleRequested);

    // Show Panels menu

    menuShowPanels->addSection(tr("Panels"));
    menuShowPanels->addAction(panelGameControls->toggleViewAction());

}


void MainWindow::closeEvent(QCloseEvent* event)
{
    const QMessageBox::StandardButton clicked = QxConfirmationBox::continueCancelWarning(this,
        tr("Quit the application"),
        tr("This will quit the application.\n"
           "Are you sure you want to continue?"),
        QString(),
        "Confirmations/Application/ApplicationQuit"_L1);

    if (clicked == QMessageBox::Cancel) {
        event->ignore();
        return;
    }

    // TODO
    if (isFullScreen())
        toggleFullScreen(false);

    saveSettings();
    event->accept();
}


void MainWindow::loadSettings()
{
    QSettings settings;

    const QByteArray geometry = settings.value("Application/Geometry"_L1).toByteArray();
    if (!geometry.isEmpty())
        restoreGeometry(geometry);
    else
        resize(1280, 720);

    const QByteArray state = settings.value("Application/State"_L1).toByteArray();
    if (!state.isEmpty())
        restoreState(state);

    const bool schemeTheme = settings.value("Application/SchemeTheme"_L1, false).toBool();
    m_actionSchemeTheme->setChecked(schemeTheme);

    const bool menubar = settings.value("Application/Menubar"_L1, true).toBool();
    m_actionShowMenubar->setChecked(menubar);

    const bool statusbar = settings.value("Application/Statusbar"_L1, true).toBool();
    m_actionShowStatusbar->setChecked(statusbar);
}


void MainWindow::saveSettings()
{
    QSettings settings;

    const QByteArray geometry = saveGeometry();
    settings.setValue("Application/Geometry"_L1, geometry);

    const QByteArray state = saveState();
    settings.setValue("Application/State"_L1, state);

    const bool schemeTheme = m_actionSchemeTheme->isChecked();
    settings.setValue("Application/SchemeTheme"_L1, schemeTheme);

    const bool menubar = m_actionShowMenubar->isChecked();
    settings.setValue("Application/Menubar"_L1, menubar);

    const bool statusbar = m_actionShowStatusbar->isChecked();
    settings.setValue("Application/Statusbar"_L1, statusbar);
}


void MainWindow::applySudokuGame(QAction* action)
{
    Q_UNUSED(action);
}


void MainWindow::applyZoomFactor(const qreal factor)
{

}


void MainWindow::toggleFullScreen(const bool checked)
{
    if (checked)
        if (QApplication::platformName() == "xcb"_L1)
            setWindowState(windowState() | Qt::WindowFullScreen);
        else
            showFullScreen();
    else
        if (QApplication::platformName() == "xcb"_L1)
            setWindowState(windowState() & ~Qt::WindowFullScreen);
        else
            showNormal();
}


void MainWindow::triggerConfigureLanguageDialog()
{

}


void MainWindow::triggerConfigureShortcutsDialog()
{

}


void MainWindow::triggerConfigurePanelsDialog()
{

}


void MainWindow::triggerConfigureToolbarsDialog()
{
    QxToolbarsDialog dialog(this);
    dialog.exec();
}


void MainWindow::triggerConfigureDialog()
{
    SettingsDialog dialog(this);
    dialog.exec();
}


void MainWindow::triggerComponentsDialog()
{
    QxComponentsDialog dialog(this);
    dialog.exec();
}


void MainWindow::triggerAboutDialog()
{
    AboutDialog dialog(this);
    dialog.exec();
}
