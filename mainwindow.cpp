#include "mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QPixmap>

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent)
{
  ui = new Ui::MainWindow();
  ui->setupUi(this);
  connect(ui->actionOpen_File, SIGNAL(triggered()), this, SLOT(openFile()));
}

void MainWindow::openFile()
{
    QPixmap pm;
    QString fn = QFileDialog::getOpenFileName(this, trUtf8("Открыть изображение"));
    if (fn != "")
    {
      if (!pm.load(fn))
        QMessageBox::critical(this, trUtf8("Ошибка"), trUtf8("Невозможно загрузить изображение из выбранного файла."));
      else
      {
        ui->label->setPixmap(pm);
        setWindowTitle(trUtf8("Просмотра изображений - ") + fn);
      }
    }
}
