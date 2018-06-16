#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <database.h>
#include <QQuickStyle>
#include <QMessageBox>
#include <QString>
#include <QTableWidget>

void MainWindow::setPlayerLabel(PlayerInfo& player){                    // wyświetlanie danych o konrektnym zawodniku
    ui->label->setText(player.name);
    ui->label_4->setText(player.position);
    ui->label_6->setText(QString::number(player.height));
    ui->label_8->setText(QString::number(player.age));
    ui->label_10->setText(player.nationality);
    ui->label_12->setText(QString::number(player.fitness));
    ui->label_14->setText(QString::number(player.quality));
    ui->label_16->setText(QString::number(player.price));
    ui->label_18->setText(QString::number(player.chemistry));
    ui->label_20->setText(QString::number(player.strength));
    if (player.position == "Goalkeeper")
    {
    ui->label_21->setText("Diving:");
    ui->label_23->setText("Reflexes:");
    ui->label_25->setText("Positioning:");
    ui->label_22->setText(QString::number(player.specificstat1));
    ui->label_24->setText(QString::number(player.specificstat2));
    ui->label_26->setText(QString::number(player.specificstat3));
    }
    if (player.position == "Defender")
    {
        ui->label_21->setText("Pace:");
        ui->label_23->setText("Defending:");
        ui->label_25->setText("Phisicality:");
        ui->label_22->setText(QString::number(player.specificstat1));
        ui->label_24->setText(QString::number(player.specificstat2));
        ui->label_26->setText(QString::number(player.specificstat3));
    }
    if (player.position == "Midfielder")
    {
        ui->label_21->setText("Passing:");
        ui->label_23->setText("Dribbling:");
        ui->label_25->setText("Shooting:");
        ui->label_22->setText(QString::number(player.specificstat1));
        ui->label_24->setText(QString::number(player.specificstat2));
        ui->label_26->setText(QString::number(player.specificstat3));
    }
    if (player.position == "Attacker")
    {
        ui->label_21->setText("Pace:");
        ui->label_23->setText("Shooting:");
        ui->label_25->setText("Dribbling:");
        ui->label_22->setText(QString::number(player.specificstat1));
        ui->label_24->setText(QString::number(player.specificstat2));
        ui->label_26->setText(QString::number(player.specificstat3));
    }
}

void MainWindow::setTable()                                             // wywołanie pustej tablicy
{
    ui->tableWidget_2->setStyleSheet("background:rgb(254,254,200);");
    ui->tableWidget_2->setColumnWidth(0, 48);
    ui->tableWidget_2->setColumnWidth(1, 140);
    ui->tableWidget_2->setColumnWidth(2, 48);
    ui->tableWidget_2->setColumnWidth(3, 48);
    ui->tableWidget_2->setColumnWidth(4, 48);
    ui->tableWidget_2->setColumnWidth(5, 48);
    ui->tableWidget_2->setVisible(true);
    for(int i = 0; i < 20; i++)
    {
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(QString::number(i+1)));
    }
}

void MainWindow::printtable()                                           // wypełnienie tabeli aktualnymi danymi
{
    for(int i = 0; i < 20; i++)
    {
        ui->tableWidget_2->setItem(i, 1, new QTableWidgetItem(DataBase::Clone[i].name));
        ui->tableWidget_2->setItem(i, 2, new QTableWidgetItem(QString::number(DataBase::Clone[i].wins)));
        ui->tableWidget_2->setItem(i, 3, new QTableWidgetItem(QString::number(DataBase::Clone[i].draws)));
        ui->tableWidget_2->setItem(i, 4, new QTableWidgetItem(QString::number(DataBase::Clone[i].losses)));
        ui->tableWidget_2->setItem(i, 5, new QTableWidgetItem(QString::number(DataBase::Clone[i].points)));
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setStyleSheet("background:rgb(252,238,225)");
    QQuickStyle::setStyle("Material");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_2_triggered()                            // zamknięcie okna po naciśnięciu Exit
{
    this->close();
}

void MainWindow::on_actionAbout_triggered()                             // reakcja na opcję "About"
{
    QMessageBox::information(this, "About", "Author: Pawel Wawszczyk\n\nAll rights reserved\n\nGliwice, 2018");

}

void MainWindow::setTableVisible(bool vis)                              // zmiana widzialności tabeli
{
    ui->tableWidget_2->setVisible(vis);
}
