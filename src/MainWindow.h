//
// Created by Node Sans on 2022/6/28.
//

#ifndef GRADE_MANAGER_SRC_MAINWINDOW_H
#define GRADE_MANAGER_SRC_MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>

namespace grade_manager::ui {
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override;

private:
  Ui::MainWindow *ui;
};
} // grade_manager::ui

#endif //GRADE_MANAGER_SRC_MAINWINDOW_H
