//
// Created by Node Sans on 2022/6/28.
//

#ifndef GRADE_MANAGER_SRC_GLOBAL_H
#define GRADE_MANAGER_SRC_GLOBAL_H

#include <QString>
namespace grade_manager {
class Global {
public:
  static QString MisDBName();
  static QString DBName();

  // SQL statement
  static QString QueryAllGradeStmt();
  static QString QueryRankStmt();
  static QString QueryAvgStmt();
};
}

#endif //GRADE_MANAGER_SRC_GLOBAL_H
