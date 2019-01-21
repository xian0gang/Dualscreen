#include "showpiclab.h"
#include <QImage>
#include <QDebug>
showpiclab::showpiclab(QWidget *parent) : QLabel(parent)
{

}

void showpiclab::showpic(QString filename)
{
    QImage *img = new QImage;
    while(! (img->load(filename)))
    {
        delete img;
        qDebug()<<"not open "<<filename;
//        continue;


    }
    QPixmap pixmap = QPixmap::fromImage(*img);
    int width = /*1440*/this->size().width();
    int height = /*900*/this->size().height();

    QPixmap fitpixmap = pixmap.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);


    qDebug()<<this->size().width();
    qDebug()<<this->size().height();
    img->scaled(this->size(), Qt::KeepAspectRatio);
//    setPixmap(QPixmap::fromImage(*img));
    setPixmap(fitpixmap);
    qDebug()<<filename;

}
