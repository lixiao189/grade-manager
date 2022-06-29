//
// Created by Node Sans on 2022/6/29.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "MainWindow.h"
#include "ui_MainWindow.h"

namespace grade_manager::ui {
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // connect signals and slots
  // Grade bindings
  QObject::connect(this->ui->grade_all_button, &QPushButton::clicked, this, &MainWindow::ShowAllGrade);
  QObject::connect(this->ui->grade_rand_button, &QPushButton::clicked, this, &MainWindow::ShowRank);
  QObject::connect(this->ui->grade_avg_button, &QPushButton::clicked, this, &MainWindow::ShowAvg);

  // Student bindings
  QObject::connect(this->ui->student_credit_button, &QPushButton::clicked, this, &MainWindow::ShowCredits);
  QObject::connect(this->ui->student_grade_button, &QPushButton::clicked, this, &MainWindow::ShowStudentsGrade);

  // Teacher binding
  QObject::connect(this->ui->teacher_info_button, &QPushButton::clicked, this, &MainWindow::ShowTeacherLessons);

  // Schedule binding
  QObject::connect(this->ui->schedule_lesson_button, &QPushButton::clicked, this, &MainWindow::ShowClassSchedule);

  // Insert binding
  QObject::connect(this->ui->insertgrade_insert_button, &QPushButton::clicked, this, &MainWindow::InsertGrade);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::ShowAllGrade() {
  const auto year = this->ui->grade_year_input->text().toInt();
  const auto start_pos = ((this->ui->page_num_input->text().toInt()) - 1) * 10;

  auto mis_db = QSqlDatabase::database(Global::MisDBName());
  auto table_view = this->ui->result_table_view;
  auto *model = new QSqlQueryModel;

  // Prepare sql query
  const QString &sqlStmt = Global::QueryAllGradeStmt();
  QSqlQuery query(mis_db);
  query.prepare(sqlStmt);
  query.bindValue(":year", year);
  query.bindValue(":start_pos", start_pos);
  if (!query.exec()) {
    Util::ErrorMessageBox("查询失败，请仔细检查输入数据");
    qDebug() << query.lastQuery() << "\n" << query.lastError().text(); // debug
  }
  currentQueryStmt = sqlStmt;
  model->setQuery(std::move(query));
  table_view->setModel(model);
}

void MainWindow::ShowRank() {
  const auto year = this->ui->grade_year_input->text().toInt();
  const auto start_pos = ((this->ui->page_num_input->text().toInt()) - 1) * 10;

  auto mis_db = QSqlDatabase::database(Global::MisDBName());
  auto table_view = this->ui->result_table_view;
  auto *model = new QSqlQueryModel;

  // Prepare sql query
  const QString &sqlStmt = Global::QueryRankStmt();
  QSqlQuery query(mis_db);
  query.prepare(sqlStmt);
  query.bindValue(":year", year);
  query.bindValue(":start_pos", start_pos);
  if (!query.exec()) {
    Util::ErrorMessageBox("查询失败，请仔细检查输入数据");
    qDebug() << query.lastQuery() << "\n" << query.lastError().text(); // debug
  }
  currentQueryStmt = sqlStmt;
  model->setQuery(std::move(query));
  table_view->setModel(model);
}

void MainWindow::ShowAvg() {
  const auto year = this->ui->grade_year_input->text().toInt();
  const auto start_pos = ((this->ui->page_num_input->text().toInt()) - 1) * 10;

  auto mis_db = QSqlDatabase::database(Global::MisDBName());
  auto table_view = this->ui->result_table_view;
  auto *model = new QSqlQueryModel;

  // Prepare sql query
  const QString &sqlStmt = Global::QueryAvgStmt();
  QSqlQuery query(mis_db);
  query.prepare(sqlStmt);
  query.bindValue(":year", year);
  query.bindValue(":start_pos", start_pos);
  if (!query.exec()) {
    Util::ErrorMessageBox("查询失败，请仔细检查输入数据");
    qDebug() << query.lastQuery() << "\n" << query.lastError().text(); // debug
  }
  currentQueryStmt = sqlStmt;
  model->setQuery(std::move(query));
  table_view->setModel(model);
}

void MainWindow::ShowCredits() {
  const auto year = this->ui->student_year_input->text().toInt();
  const auto id = this->ui->student_id_input->text();
  const auto start_pos = ((this->ui->page_num_input->text().toInt()) - 1) * 10;

  auto mis_db = QSqlDatabase::database(Global::MisDBName());
  auto table_view = this->ui->result_table_view;
  auto *model = new QSqlQueryModel;

  // Prepare sql query
  const QString &sqlStmt = Global::QueryStudentCreditStmt();
  QSqlQuery query(mis_db);
  query.prepare(sqlStmt);
  query.bindValue(":year", year);
  query.bindValue(":id", id);
  query.bindValue(":start_pos", start_pos);
  if (!query.exec()) {
    Util::ErrorMessageBox("查询失败，请仔细检查输入数据");
    qDebug() << query.lastQuery() << "\n" << query.lastError().text(); // debug
  }
  currentQueryStmt = sqlStmt;
  model->setQuery(std::move(query));
  table_view->setModel(model);
}

void MainWindow::ShowStudentsGrade() {
  const auto year = this->ui->student_year_input->text().toInt();
  const auto id = this->ui->student_id_input->text();
  const auto start_pos = ((this->ui->page_num_input->text().toInt()) - 1) * 10;

  auto mis_db = QSqlDatabase::database(Global::MisDBName());
  auto table_view = this->ui->result_table_view;
  auto *model = new QSqlQueryModel;

  // Prepare sql query
  const QString &sqlStmt = Global::QueryStudentGradeStmt();
  QSqlQuery query(mis_db);
  query.prepare(sqlStmt);
  query.bindValue(":year", year);
  query.bindValue(":id", id);
  query.bindValue(":start_pos", start_pos);
  if (!query.exec()) {
    Util::ErrorMessageBox("查询失败，请仔细检查输入数据");
    qDebug() << query.lastQuery() << "\n" << query.lastError().text(); // debug
  }
  currentQueryStmt = sqlStmt;
  model->setQuery(std::move(query));
  table_view->setModel(model);
}

void MainWindow::ShowTeacherLessons() {
  const auto teacher_name = this->ui->teacher_name_input->text();
  const auto start_pos = ((this->ui->page_num_input->text().toInt()) - 1) * 10;

  auto mis_db = QSqlDatabase::database(Global::MisDBName());
  auto table_view = this->ui->result_table_view;
  auto *model = new QSqlQueryModel;

  // Prepare sql query
  const QString &sqlStmt = Global::QueryTeacherLessonStmt();
  QSqlQuery query(mis_db);
  query.prepare(sqlStmt);
  query.bindValue(":name", teacher_name);
  query.bindValue(":start_pos", start_pos);
  if (!query.exec()) {
    Util::ErrorMessageBox("查询失败，请仔细检查输入数据");
    qDebug() << query.lastQuery() << "\n" << query.lastError().text(); // debug
  }
  currentQueryStmt = sqlStmt;
  model->setQuery(std::move(query));
  table_view->setModel(model);
}

void MainWindow::ShowClassSchedule() {
  QMap<QString, int> TermNumber;
  TermNumber["上学期"] = 1;
  TermNumber["下学期"] = 2;
  TermNumber["短学期"] = 3;

  const auto major_id = this->ui->schedule_majorid_input->text();
  const auto class_id = this->ui->schedule_classid_input->text();
  const auto year = this->ui->schedule_year_input->text();
  const auto term = TermNumber[this->ui->schedule_term_input->currentText()];
  const auto start_pos = ((this->ui->page_num_input->text().toInt()) - 1) * 10;

  auto mis_db = QSqlDatabase::database(Global::MisDBName());
  auto table_view = this->ui->result_table_view;
  auto *model = new QSqlQueryModel;

  // Prepare sql query
  const QString &sqlStmt = Global::QueryScheduleStmt();
  QSqlQuery query(mis_db);
  query.prepare(sqlStmt);
  query.bindValue(":major_id", major_id);
  query.bindValue(":class_id", class_id);
  query.bindValue(":year", year);
  query.bindValue(":term", term);
  query.bindValue(":start_pos", start_pos);
  if (!query.exec()) {
    Util::ErrorMessageBox("查询失败，请仔细检查输入数据");
    qDebug() << query.lastQuery() << "\n" << query.lastError().text(); // debug
  }
  currentQueryStmt = sqlStmt;
  model->setQuery(std::move(query));
  table_view->setModel(model);
}

void MainWindow::InsertGrade() {
  const auto student_id = this->ui->insertgrade_studentid_input->text();
  const auto course_id = this->ui->insertgrade_courseid_input->text();
  const auto year = this->ui->insertgrade_year_input->text();
  const auto grade = this->ui->insertgrade_grade_input->text();

  auto mis_db = QSqlDatabase::database(Global::MisDBName());

  // Prepare sql query
  const QString &sqlStmt = Global::InsertGradeStmt();
  QSqlQuery query(mis_db);
  query.prepare(sqlStmt);
  query.bindValue(":student_id", student_id);
  query.bindValue(":course_id", course_id);
  query.bindValue(":year", year);
  query.bindValue(":grade", grade);
  if (query.exec()) {
    Util::SuccessMessageBox("插入成功");
  } else {
    qDebug() << query.lastQuery() << "\n" << query.lastError().text(); // debug
    Util::ErrorMessageBox(query.lastError().text());
  }
}
} // grade_manager::ui
