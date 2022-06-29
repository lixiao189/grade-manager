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
  query.exec();
  qDebug() << query.lastQuery() << "\n" << query.lastError().text(); // debug
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
  query.exec();
  qDebug() << query.lastQuery() << "\n" << query.lastError().text(); // debug
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
  query.exec();
  qDebug() << query.lastQuery() << "\n" << query.lastError().text(); // debug
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
  query.exec();
  qDebug() << query.lastQuery() << "\n" << query.lastError().text(); // debug
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
  query.exec();
  qDebug() << query.lastQuery() << "\n" << query.lastError().text(); // debug
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
  query.exec();
  qDebug() << query.lastQuery() << "\n" << query.lastError().text(); // debug
  currentQueryStmt = sqlStmt;
  model->setQuery(std::move(query));
  table_view->setModel(model);
}
} // grade_manager::ui
