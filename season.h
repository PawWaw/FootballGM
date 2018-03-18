#ifndef SEASON_H
#define SEASON_H

#include <QMainWindow>

namespace Ui {
class Season;
}

class Season : public QMainWindow
{
    Q_OBJECT

public:
    explicit Season(QWidget *parent = 0);
    ~Season();

private:
    Ui::Season *ui;
};

#endif // SEASON_H
