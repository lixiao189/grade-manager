//
// Created by Node Sans on 2022/6/29.
//

#ifndef GRADE_MANAGER_SRC_MAINWINDOW_H
#define GRADE_MANAGER_SRC_MAINWINDOW_H

#include <QWidget>

namespace grade_manager::ui {
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override;

private:
  Ui::MainWindow *ui;
};
} // grade_manager::ui

#endif //GRADE_MANAGER_SRC_MAINWINDOW_H
