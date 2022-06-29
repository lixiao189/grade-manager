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
  // Grade query statement
  static QString QueryAllGradeStmt();
  static QString QueryRankStmt();
  static QString QueryAvgStmt();

  // Student query statement
  static QString QueryStudentCreditStmt();
};
}

#endif //GRADE_MANAGER_SRC_GLOBAL_H
