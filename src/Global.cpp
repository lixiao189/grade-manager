//
// Created by Node Sans on 2022/6/28.
//

#include "Global.h"

namespace grade_manager {
QString Global::MisDBName() {
  return "mis";
}

QString Global::DBName() {
  return "202001_LX_MIS";
}

QString Global::QueryAllGradeStmt() {
  return "SELECT lx_students.id,"
         "lx_students.`name` AS 'student_name',"
         "lx_courses.`name` AS 'course_name',"
         "lx_reports.`year`,lx_reports.grade "
         "FROM lx_reports "
         "INNER JOIN lx_students ON lx_students.id=lx_reports.student_id "
         "INNER JOIN lx_courses ON lx_courses.id=lx_reports.course_id "
         "WHERE lx_reports.`year` = :year "
         "limit 10 offset :start_pos;";
}

QString Global::QueryRankStmt() {
  return "SELECT student_id,"
         "lx_students.`name`,"
         "grade_sum,"
         "`year`,"
         "(@rowNum :=@rowNum+1) AS rowNum "
         "FROM lx_sum_grade,"
         "lx_students,(SELECT (@rowNum :=0)) b WHERE lx_sum_grade.`year` = :year "
         "AND lx_students.id=lx_sum_grade.student_id ORDER BY grade_sum DESC "
         "limit 10 offset :start_pos;";
}

QString Global::QueryAvgStmt() {
  return "SELECT lx_reports.course_id,"
         "lx_courses.`name`,"
         "lx_reports.`year`,"
         "AVG(lx_reports.grade) AS average_grade "
         "FROM lx_reports "
         "INNER JOIN lx_courses ON lx_reports.course_id=lx_courses.id "
         "GROUP BY lx_reports.course_id,lx_reports.`year` "
         "HAVING lx_reports.`year` = :year "
         "limit 10 offset :start_pos;";
}

QString Global::QueryStudentCreditStmt() {
  return "SELECT student_id,"
         "lx_students.`name`,"
         "lx_reports.`year`,"
         "GROUP_CONCAT(lx_courses.`name`) AS courses,"
         "SUM(lx_courses.credit) AS sum_credit "
         "FROM lx_reports INNER JOIN lx_courses ON lx_reports.course_id=lx_courses.id "
         "INNER JOIN lx_students ON lx_reports.student_id=lx_students.id "
         "GROUP BY lx_reports.student_id,lx_reports.`year` "
         "HAVING lx_reports.`year` = :year AND lx_reports.student_id= :id "
         "limit 10 offset :start_pos;";
}
}

