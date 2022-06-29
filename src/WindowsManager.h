//
// Created by Node Sans on 2022/6/28.
//

#ifndef GRADE_MANAGER_SRC_WINDOWSMANAGER_H
#define GRADE_MANAGER_SRC_WINDOWSMANAGER_H

#include <QtCore>
#include <QWidget>
#include <map>
#include <QSqlDatabase>
#include <QObject>
#include "Login.h"
#include "MainWindow.h"
#include "Global.h"

using namespace grade_manager::ui;

namespace grade_manager {

class WindowsManager : public QObject {
private:
  Login *login_window = new Login;
  MainWindow *main_window = new MainWindow;

public slots:

public:
  explicit WindowsManager();
  ~WindowsManager() override;
};

} // grademanager

#endif //GRADE_MANAGER_SRC_WINDOWSMANAGER_H
