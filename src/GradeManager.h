//
// Created by Node Sans on 2022/6/28.
//

#ifndef GRADE_MANAGER_SRC_GRADEMANAGER_H
#define GRADE_MANAGER_SRC_GRADEMANAGER_H

#include <QtCore>
#include <QWidget>
#include <map>
#include <QSqlDatabase>
#include "ui/Login.h"

namespace grademanager {

class GradeManager {
private:
  std::map<QString, QWidget *> router;
  QString currentRoute;
  QSqlDatabase db;

public slots:
  void LeaveToWindow(const QString &route);

public:
  explicit GradeManager();
  virtual ~GradeManager();
  void initDB(const QString &user, const QString &pass, const QString &host, const QString &port);
};

} // grademanager

#endif //GRADE_MANAGER_SRC_GRADEMANAGER_H
