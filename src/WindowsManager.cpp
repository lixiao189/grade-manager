//
// Created by Node Sans on 2022/6/28.
//

#include "WindowsManager.h"

namespace grademanager {

WindowsManager::WindowsManager() {
  // 添加窗口
  router["/login"] = new grade_manager::ui::Login;

  // 默认启动登录窗口
  currentRoute = "/login";
  router["/login"]->show();
}

void WindowsManager::LeaveToWindow(const QString &route) {
  router[currentRoute]->close();
  router[route]->show();
  currentRoute = route;
}

WindowsManager::~WindowsManager() {
  // 关闭数据库
  auto mis_db = QSqlDatabase::database(grade_manager::Global::MisDBName());
  mis_db.close();
};

} // grademanager