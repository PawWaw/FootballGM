#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

struct PlayerInfo;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

public:
    void setPlayerLabel(PlayerInfo& player);
    void setTable();
    void setTableVisible(bool vis);
    void printtable();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_2_triggered();
    void on_actionAbout_triggered();
};

#endif // MAINWINDOW_H
