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

} // grademanager