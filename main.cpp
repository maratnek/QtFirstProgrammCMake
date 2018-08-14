#include <QApplication>
#include "mainwindow.h"

int main(int ac, char**av)
{
  QApplication app(ac, av);
  MainWindow w;
  w.show();
  app.exec();
}
