#include <QApplication>
#include "GradeManager.h"
#include "ui/Login.h"


int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  grademanager::GradeManager gradeManager;

  return QApplication::exec();
}
