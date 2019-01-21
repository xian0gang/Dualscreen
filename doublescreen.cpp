#include "doublescreen.h"
#include "ui_doublescreen.h"

DoubleScreen::DoubleScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DoubleScreen)
{
    ui->setupUi(this);
}

DoubleScreen::~DoubleScreen()
{
    delete ui;
}
