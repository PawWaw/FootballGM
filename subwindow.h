#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QMainWindow>

namespace Ui {
class SubWindow;
}

class SubWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::SubWindow *ui;

public:
    explicit SubWindow(QWidget *parent = 0);
    ~SubWindow();
    void setVisibleGoalkeeper(bool vis);
    void setVisibleDefender(bool vis);
    void setVisibleMidfielder(bool vis);
    void setVisibleAttacker(bool vis);

private slots:

    void on_Goalkeeper1_ChB_clicked();


};

#endif // SUBWINDOW_H
