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

  QObject::connect(ui->login_button, &QPushButton::clicked, this, &Login::LoginHandler);
}

Login::~Login() {
  delete ui;
}

void Login::LoginHandler() {
  const auto user_input = ui->user_input->text();
  const auto pass_input = ui->pass_input->text();
  const auto host_input = ui->host_input->text();
  const auto port_input = ui->port_input->text();

  qDebug() << user_input << " " << pass_input << " " << host_input << " " << port_input;
}

} // grade_manager::ui
