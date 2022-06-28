//
// Created by Node Sans on 2022/6/28.
//

#ifndef GRADE_MANAGER_SRC_GRADEMANAGER_H
#define GRADE_MANAGER_SRC_GRADEMANAGER_H

#include <QtCore>
#include <QWidget>
#include <map>
#include "ui/Login.h"

namespace grademanager {

class GradeManager {
private:
  std::map<QString, QWidget *> router;
  QString currentRoute;

public slots:
  void LeaveToWindow(const QString &route);

public:
  explicit GradeManager();
};

} // grademanager

#endif //GRADE_MANAGER_SRC_GRADEMANAGER_H
