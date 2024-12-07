#include "main_window.h"
#include <QAction>
#include <QLabel>
#include <QLayout>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QPushButton>

// Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), state(State::MENU) {
  render_state();
}

// Destructor
MainWindow::~MainWindow() {}

// Set state of application
void MainWindow::set_state(State s) {
  if (this->state == s)
    return;
  this->state = s;
  render_state();
}

void MainWindow::render_state() {
  // Clear the central widget's layout
  QWidget *centralWidget = this->centralWidget();
  if (!centralWidget) {
    centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
  }

  QLayout *layout = centralWidget->layout();
  if (layout) {
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
      delete item->widget(); // Delete any widgets in the layout
      delete item;
    }
    delete layout;
  }

  QVBoxLayout *newLayout = new QVBoxLayout(centralWidget);
  newLayout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

  switch (state) {
  case State::MENU: {
    /* TITLE */
    this->title = new QLabel("ML-Visualizer", this);
    this->title->setAlignment(Qt::AlignCenter);
    QFont font = this->title->font();
    font.setPointSize(64);
    this->title->setFont(font);

    /* SUBTITLE */
    this->subTitle = new QLabel("❤️ from Lance Hartman");
    this->subTitle->setAlignment(Qt::AlignCenter);
    QFont subTitleFont = this->subTitle->font();
    subTitleFont.setPointSize(16);
    this->subTitle->setFont(subTitleFont);

    /* NEW BUTTON */
    this->newButton = new QPushButton("New", this);
    QFont newButtonFont = this->newButton->font();
    newButtonFont.setPointSize(24);
    this->newButton->setFont(newButtonFont);
    this->newButton->setFixedWidth(150);
    this->newButton->setFixedHeight(50);

    connect(this->newButton, &QPushButton::clicked, this,
            [this]() { this->set_state(State::NEW); });

    // Add widgets to the layout
    newLayout->addWidget(this->title);
    newLayout->setAlignment(this->title, Qt::AlignHCenter | Qt::AlignTop);

    newLayout->addWidget(this->subTitle);
    newLayout->setAlignment(this->subTitle, Qt::AlignHCenter | Qt::AlignTop);

    newLayout->addSpacing(100);

    newLayout->addWidget(this->newButton);
    newLayout->setAlignment(this->newButton, Qt::AlignHCenter | Qt::AlignTop);
    break;
  }

  case State::NEW: {
    QLabel *newLabel = new QLabel("Welcome to the NEW state!");
    newLabel->setAlignment(Qt::AlignCenter);
    QFont newLabelFont = newLabel->font();
    newLabelFont.setPointSize(24);
    newLabel->setFont(newLabelFont);

    QPushButton *backButton = new QPushButton("Back to Menu");
    connect(backButton, &QPushButton::clicked, this,
            [this]() { this->set_state(State::MENU); });

    newLayout->addWidget(newLabel);
    newLayout->setAlignment(newLabel, Qt::AlignHCenter | Qt::AlignTop);

    newLayout->addWidget(backButton);
    newLayout->setAlignment(backButton, Qt::AlignHCenter | Qt::AlignTop);

    break;
  }
  }
  centralWidget->setLayout(newLayout);
}

// Set up the menu layout
void MainWindow::setupMenu() {
  menuBar = new QMenuBar(this);

  this->fileMenu = new QMenu("File", this);
  this->editMenu = new QMenu("Edit", this);
  this->helpMenu = new QMenu("Help", this);

  menuBar->addMenu(fileMenu);
  menuBar->addMenu(editMenu);
  menuBar->addMenu(helpMenu);

  newAction = new QAction("New", this);
  openAction = new QAction("Open", this);
  exitAction = new QAction("Exit", this);

  fileMenu->addAction(newAction);
  fileMenu->addAction(openAction);
  fileMenu->addSeparator();
  fileMenu->addAction(exitAction);

  cutAction = new QAction("Cut", this);
  copyAction = new QAction("Copy", this);
  pasteAction = new QAction("Paste", this);

  editMenu->addAction(cutAction);
  editMenu->addAction(copyAction);
  editMenu->addAction(pasteAction);

  aboutAction = new QAction("About", this);

  helpMenu->addAction(aboutAction);

  connect(exitAction, &QAction::triggered, this, &QMainWindow::close);
  connect(aboutAction, &QAction::triggered, this, &MainWindow::showAboutDialog);

  // connect new-button
  connect(newButton, &QPushButton::clicked, this,
          &MainWindow::newButtonPressed);

  setMenuBar(menuBar);
}

// Slot to show an "About" dialog
void MainWindow::showAboutDialog() {
  QMessageBox::about(this, "About", "This is a simple menu-based application.");
}

void MainWindow::newButtonPressed() {
  QMessageBox::information(this, "New Button", "You pressed the new button!");
}