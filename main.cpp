#include <QApplication>
#include "mainwindow.h"
#include <QTranslator>
#include <qdebug.h>

int main(int ac, char**av)
{
  QApplication app(ac, av);

  QTranslator translator;
  translator.load("demo_fr");
  app.installTranslator(&translator);
  //qApp->installTranslator(&translator);
  qDebug() << "Local name: " << QLocale().name();

  //if (translator.load(QLocale(), QLatin1String("demo"), QLatin1String("_"), QLatin1String(":/translations")))
  //{
	 // qDebug() << "Load qm translation";

	 // app.installTranslator(&translator);
  //}

  MainWindow w;
  w.show();
  app.exec();
}
