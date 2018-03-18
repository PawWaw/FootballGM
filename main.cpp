#include "mainwindow.h"
#include "subwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

  //MainWindow w;
  //w.show();
    SubWindow b;
    b.show();
    b.setVisibleGoalkeeper(false);
    return a.exec();
}
