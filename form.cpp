#include "form.h"
#include "ui_form.h"
#include <QImage>
#include <QDebug>
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}


void Form::init(int a)
{
    ui->label->setText(QString::number(a,10));
}

void Form::showpic(QString filename)
{
    QImage *img = new QImage;
    if(! (img->load(filename)))
    {
        delete img;
        qDebug()<<"not open "<<filename;
        return;

    }
    ui->label->setPixmap(QPixmap::fromImage(*img));
    qDebug()<<filename;
//    int Ow = img->width();
//    int Oh = img->height();
//    int Lw = ui->label->width();
//    int Lh = ui->label->height();
//    int Mul;
//    if(Ow / Lw >= Oh / Lh)
//        Mul = Ow / Lw;
//    else
//        Oh / Lh;
//    int Fw,Fh;
//    Fw = Ow / Mul;
//    Fh = Oh / Mul;
}

Form::~Form()
{
    delete ui;
}
