//
// Created by Node Sans on 2022/6/28.
//

#include "GradeManager.h"

namespace grademanager {

GradeManager::GradeManager() {
  // 添加窗口
  router["/login"] = new grade_manager::ui::Login;

  // 默认启动登录窗口
  currentRoute = "/login";
  router["/login"]->show();
}

void GradeManager::LeaveToWindow(const QString &route) {
  router[currentRoute]->close();
  router[route]->show();
  currentRoute = route;
}

void GradeManager::initDB(const QString &user, const QString &pass, const QString &host, const QString &port) {
  db.setUserName(user);
  db.setPassword(pass);
  db.setHostName(host);
  db.setPort(port.toInt());
  db.open();
}

GradeManager::~GradeManager() {
  if (db.isOpen()) {
    db.close();
  }
}

} // grademanager