#ifndef DOUBLESCREEN_H
#define DOUBLESCREEN_H

#include <QMainWindow>

namespace Ui {
class DoubleScreen;
}

class DoubleScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit DoubleScreen(QWidget *parent = 0);
    ~DoubleScreen();
    void initLab(QRect rect);

private:
    Ui::DoubleScreen *ui;
};

#endif // DOUBLESCREEN_H
