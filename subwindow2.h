#ifndef SUBWINDOW2_H
#define SUBWINDOW2_H

#include <QMainWindow>

namespace Ui {
class SubWindow2;
}

class SubWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit SubWindow2(QWidget *parent = 0);
    ~SubWindow2();

private:
    Ui::SubWindow2 *ui;
};

#endif // SUBWINDOW2_H
