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
  QObject::connect(this->ui->grade_all_button, &QPushButton::clicked, this, &MainWindow::ShowAllGrade);
  QObject::connect(this->ui->grade_rand_button, &QPushButton::clicked, this, &MainWindow::ShowRank);
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
} // grade_manager::ui
