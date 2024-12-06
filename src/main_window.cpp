#include "main_window.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <QLabel>
#include <QLayout>
#include <QPushButton>

// Constructor
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
  /* TITLE */
  this->title = new QLabel("ML-Visualizer", this);
  this->title->setAlignment(Qt::AlignCenter);
  QFont font = this->title->font();
  font.setPointSize(64);
  this->title->setFont(font);

  /* SUBTITLE */
  this->subTitle = new QLabel("❤️ from lance hartman");
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

  /* CENTRAL WIDGET */
  QWidget *centralWidget = new QWidget(this);
  this->setCentralWidget(centralWidget);

  /* POPULATE CW LAYOUT */
  QVBoxLayout *layout = new QVBoxLayout(centralWidget);
  layout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

  // title
  layout->addWidget(this->title);
  layout->setAlignment(this->title, Qt::AlignHCenter | Qt::AlignTop);

  // subtitle
  layout->addWidget(this->subTitle);
  layout->setAlignment(this->subTitle, Qt::AlignHCenter | Qt::AlignTop);

  // vertical spacer
  layout->addSpacing(100);

  // new button
  layout->addWidget(this->newButton);
  layout->setAlignment(this->newButton, Qt::AlignHCenter | Qt::AlignTop);

  layout->setSpacing(3);

  setupMenu(); // Set up the menu layout
}

// Destructor
MainWindow::~MainWindow() {}

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
  connect(newButton, &QPushButton::clicked, this, &MainWindow::newButtonPressed);
  
  setMenuBar(menuBar);
}

// Slot to show an "About" dialog
void MainWindow::showAboutDialog() {
  QMessageBox::about(this, "About", "This is a simple menu-based application.");
}

void MainWindow::newButtonPressed() {
  QMessageBox::information(this, "New Button", "You pressed the new button!");
}