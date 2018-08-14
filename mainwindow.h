#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_MainWindow.h"
// #include <QDialog>

class MainWindow : public QMainWindow
{
  Q_OBJECT
private:
  Ui::MainWindow * ui;
public:
  explicit MainWindow(QWidget * parent = 0);

signals:
private slots:
  void openFile();
};

#endif //MAINWINDOW_H
