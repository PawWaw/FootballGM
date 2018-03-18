#include "subwindow3.h"
#include "ui_subwindow3.h"

SubWindow3::SubWindow3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SubWindow3)
{
    ui->setupUi(this);
}

SubWindow3::~SubWindow3()
{
    delete ui;
}
