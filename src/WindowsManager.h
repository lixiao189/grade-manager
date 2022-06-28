//
// Created by Node Sans on 2022/6/28.
//

#ifndef GRADE_MANAGER_SRC_WINDOWSMANAGER_H
#define GRADE_MANAGER_SRC_WINDOWSMANAGER_H

#include <QtCore>
#include <QWidget>
#include <map>
#include <QSqlDatabase>
#include "Login.h"

namespace grademanager {

class WindowsManager {
private:
  std::map<QString, QWidget *> router;
  QString currentRoute;

public slots:
  void LeaveToWindow(const QString &route);

public:
  explicit WindowsManager();
  virtual ~WindowsManager();
};

} // grademanager

#endif //GRADE_MANAGER_SRC_WINDOWSMANAGER_H
