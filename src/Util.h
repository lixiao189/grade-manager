//
// Created by Node Sans on 2022/6/28.
//

#ifndef GRADE_MANAGER_SRC_UTIL_H
#define GRADE_MANAGER_SRC_UTIL_H

#include <QString>
#include <QMessageBox>

namespace grade_manager {

class Util {
public:
  static void SuccessMessageBox(const QString &msg);
  static void ErrorMessageBox(const QString &msg);
};

} // grade_manager

#endif //GRADE_MANAGER_SRC_UTIL_H
