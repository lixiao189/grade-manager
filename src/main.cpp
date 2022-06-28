#include <QApplication>
#include <QPushButton>
#include "GradeManager.h"


int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  grademanager::GradeManager gradeManager;

  return QApplication::exec();
}
