#ifndef SUBWINDOW3_H
#define SUBWINDOW3_H

#include <QMainWindow>

namespace Ui {
class SubWindow3;
}

class SubWindow3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit SubWindow3(QWidget *parent = 0);
    ~SubWindow3();

private:
    Ui::SubWindow3 *ui;
};

#endif // SUBWINDOW3_H
