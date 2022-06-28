//
// Created by Node Sans on 2022/6/28.
//

#include "Util.h"

namespace grade_manager {
void Util::ErrorMessageBox(const QString &msg) {
  QMessageBox msg_box;
  msg_box.setText("Some errors have occurred.");
  msg_box.setIcon(QMessageBox::Critical);
  msg_box.setInformativeText(msg);
  msg_box.exec();
}
} // grade_manager