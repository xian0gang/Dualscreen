#ifndef SHOWPICLAB_H
#define SHOWPICLAB_H

#include <QObject>
#include <QLabel>
#include <QWidget>

class showpiclab : public QLabel
{
    Q_OBJECT
public:
    explicit showpiclab(QWidget *parent = 0);
    void showpic(QString filename);

signals:

public slots:
};

#endif // SHOWPICLAB_H
