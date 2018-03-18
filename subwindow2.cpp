#include "subwindow2.h"
#include "ui_subwindow2.h"

SubWindow2::SubWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SubWindow2)
{
    ui->setupUi(this);
}

SubWindow2::~SubWindow2()
{
    delete ui;
}
