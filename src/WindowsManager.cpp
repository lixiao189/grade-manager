//
// Created by Node Sans on 2022/6/28.
//

#include "WindowsManager.h"

namespace grade_manager {

WindowsManager::WindowsManager() {
  // show login window by default
  login_window->show();

  // Bind signals and slots
  QObject::connect(login_window, &Login::accepted, main_window, &MainWindow::show);
}

WindowsManager::~WindowsManager() {
  // 关闭数据库
  auto mis_db = QSqlDatabase::database(grade_manager::Global::MisDBName());
  mis_db.close();
};

} // grademanager