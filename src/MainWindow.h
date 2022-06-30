//
// Created by Node Sans on 2022/6/29.
//

#ifndef GRADE_MANAGER_SRC_MAINWINDOW_H
#define GRADE_MANAGER_SRC_MAINWINDOW_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlError>
#include <QMap>
#include "Global.h"
#include "Util.h"

namespace grade_manager::ui {
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override;
  QSqlQueryModel *currentModel = new QSqlQueryModel;

public slots:
  // Grade Info
  void ShowAllGrade();
  void ShowRank();
  void ShowAvg();

  // Student Info
  void ShowCredits();
  void ShowStudentsGrade();

  // Teacher info
  void ShowTeacherLessons();

  // Schedule info
  void ShowClassSchedule();

  // Insert grade info
  void InsertGrade();

  // Page jump function
  void JumpToPage();

private:
  Ui::MainWindow *ui;
};
} // grade_manager::ui

#endif //GRADE_MANAGER_SRC_MAINWINDOW_H
