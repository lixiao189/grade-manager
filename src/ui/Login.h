//
// Created by Node Sans on 2022/6/28.
//

#ifndef GRADE_MANAGER_SRC_UI_LOGIN_H
#define GRADE_MANAGER_SRC_UI_LOGIN_H

#include <QWidget>

namespace grade_manager::ui {
QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget {
Q_OBJECT

public:
  explicit Login(QWidget *parent = nullptr);
  ~Login() override;

private:
  Ui::Login *ui;
};
} // grade_manager::ui

#endif //GRADE_MANAGER_SRC_UI_LOGIN_H
