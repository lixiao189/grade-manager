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
  return "SELECT lx_students.id as 学号,"
         "lx_students.`name` AS '姓名',"
         "lx_courses.`name` AS '课程名',"
         "lx_reports.`year` AS '学年',"
         "lx_reports.grade AS '总分' "
         "FROM lx_reports "
         "INNER JOIN lx_students ON lx_students.id=lx_reports.student_id "
         "INNER JOIN lx_courses ON lx_courses.id=lx_reports.course_id "
         "WHERE lx_reports.`year` = :year "
         "limit 10 offset :start_pos;";
}

QString Global::QueryRankStmt() {
  return "SELECT student_id as '学号',"
         "lx_students.`name` as '姓名',"
         "grade_sum as 总分,"
         "`year` as 学年,"
         "(@rowNum :=@rowNum+1) AS 排名 "
         "FROM lx_sum_grade,"
         "lx_students,(SELECT (@rowNum :=0)) b WHERE lx_sum_grade.`year` = :year "
         "AND lx_students.id=lx_sum_grade.student_id ORDER BY grade_sum DESC "
         "limit 10 offset :start_pos;";
}

QString Global::QueryAvgStmt() {
  return "SELECT lx_reports.course_id as 班级编号,"
         "lx_courses.`name` as 课程名,"
         "lx_reports.`year` as 学年,"
         "AVG(lx_reports.grade) AS 平均分 "
         "FROM lx_reports "
         "INNER JOIN lx_courses ON lx_reports.course_id=lx_courses.id "
         "GROUP BY lx_reports.course_id,lx_reports.`year` "
         "HAVING lx_reports.`year` = :year "
         "limit 10 offset :start_pos;";
}

QString Global::QueryStudentCreditStmt() {
  return "SELECT student_id as 学生编号,"
         "lx_students.`name` as 学生姓名,"
         "lx_report_passed.`year` as 学年,"
         "GROUP_CONCAT(lx_courses.`name`) AS 所学课程,"
         "SUM(lx_courses.credit) AS 总学分 "
         "FROM lx_report_passed INNER JOIN lx_courses ON lx_report_passed.course_id=lx_courses.id "
         "INNER JOIN lx_students ON lx_report_passed.student_id=lx_students.id "
         "GROUP BY lx_report_passed.student_id,lx_report_passed.`year` "
         "HAVING lx_report_passed.`year` = :year AND lx_report_passed.student_id = :id "
         "limit 10 offset :start_pos;";
}

QString Global::QueryStudentGradeStmt() {
  return "SELECT lx_courses.`name` as 课程名,"
         "lx_reports.`year` as 学年,"
         "lx_reports.grade as 分数 "
         "FROM lx_reports "
         "INNER JOIN lx_courses ON lx_reports.course_id=lx_courses.id "
         "WHERE student_id = :id AND `year` = :year "
         "limit 10 offset :start_pos;";
}

QString Global::QueryTeacherLessonStmt() {
  return "SELECT lx_courses.id as 课程编号,"
         "lx_courses.name as 课程名,"
         "period as 学时, "
         "credit as 学分, "
         "need_test as '是否需要考试[1为需要]' "
         "FROM lx_teach "
         "INNER JOIN lx_teachers ON lx_teach.teacher_id=lx_teachers.id "
         "INNER JOIN lx_courses ON lx_teach.course_id=lx_courses.id "
         "WHERE lx_teachers.`name` = :name "
         "limit 10 offset :start_pos;";
}

QString Global::QueryScheduleStmt() {
  return "SELECT lx_majors.`name` as 专业名,"
         "lx_classes.`name` as 班级名,"
         "lx_courses.`name` as 课程名 "
         "FROM lx_schedule INNER JOIN lx_majors ON major_id=lx_majors.id "
         "INNER JOIN lx_classes ON class_id=lx_classes.id "
         "INNER JOIN lx_courses ON course_id=lx_courses.id "
         "WHERE major_id = :major_id "
         "AND class_id = :class_id "
         "AND `year` = :year "
         "AND term = :term "
         "limit 10 offset :start_pos;";
}
QString Global::InsertGradeStmt() {
  return "INSERT INTO lx_reports "
         "(lx_reports.student_id,"
         "lx_reports.course_id,"
         "lx_reports.`year`,"
         "lx_reports.grade) VALUES "
         "(:student_id, :course_id, :year, :grade);";
}

}

