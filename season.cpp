#include "season.h"
#include "ui_season.h"

Season::Season(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Season)
{
    ui->setupUi(this);

}

Season::~Season()
{
    delete ui;
}
