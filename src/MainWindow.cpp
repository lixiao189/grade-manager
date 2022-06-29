//
// Created by Node Sans on 2022/6/29.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "MainWindow.h"
#include "ui_MainWindow.h"

namespace grade_manager::ui {
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}
} // grade_manager::ui
