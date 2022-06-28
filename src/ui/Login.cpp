//
// Created by Node Sans on 2022/6/28.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Login.h" resolved

#include "Login.h"
#include "ui_Login.h"

namespace grade_manager::ui {
Login::Login(QWidget *parent) :
    QWidget(parent), ui(new Ui::Login) {
  ui->setupUi(this);
}

Login::~Login() {
  delete ui;
}
} // grade_manager::ui
