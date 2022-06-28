#include <QApplication>
#include "WindowsManager.h"


int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  grademanager::WindowsManager window_manager;

  return QApplication::exec();
}
