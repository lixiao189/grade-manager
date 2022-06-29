//
// Created by Node Sans on 2022/6/28.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Login.h" resolved

#include "Login.h"
#include "ui_Login.h"
#include "Global.h"

namespace grade_manager::ui {
Login::Login(QWidget *parent) :
    QDialog(parent), ui(new Ui::Login) {
  ui->setupUi(this);

  QObject::connect(ui->login_button, &QPushButton::clicked, this, &Login::LoginHandler);
  QObject::connect(ui->exit_button, &QPushButton::clicked, this, &Login::reject);
}

Login::~Login() {
  delete ui;
}

void Login::LoginHandler() {
  const auto user_input = ui->user_input->text();
  const auto pass_input = ui->pass_input->text();
  const auto host_input = ui->host_input->text();
  const auto port_input = ui->port_input->text();

  // Add database into qt framework
  auto mis_db = QSqlDatabase::addDatabase("QMYSQL", grade_manager::Global::MisDBName());
  mis_db.setUserName(user_input);
  mis_db.setPassword(pass_input);
  mis_db.setHostName(host_input);
  mis_db.setDatabaseName(grade_manager::Global::DBName());
  mis_db.setPort(port_input.toInt());

  auto ok = mis_db.open();
  if (!ok) {
    const QString &err_text = mis_db.lastError().text();
    Util::ErrorMessageBox(err_text);
  } else {
    this->close();
    emit accepted();
  }
}

} // grade_manager::ui
