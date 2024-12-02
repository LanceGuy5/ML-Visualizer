// headers
#include "main_window.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::Main) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}
