#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QMainWindow>

namespace Ui {
class SubWindow;
}

class SubWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SubWindow(QWidget *parent = 0);
    ~SubWindow();
    void setVisibleGoalkeeper(bool vis)
    {
        ui->GoalkeeperWidget->setVisible(vis);
    }

private:
    Ui::SubWindow *ui;
};

#endif // SUBWINDOW_H
