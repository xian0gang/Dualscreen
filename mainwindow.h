#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "form.h"
#include <QMainWindow>
#include <QDesktopWidget>
#include "showpiclab.h"
#include <QTimer>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



public slots:
//    void xg();

private:
    Ui::MainWindow *ui;
    Form widdget;
    Form widdget2;
    QDesktopWidget W;
    showpiclab S1;
    showpiclab S2;

    QTimer *tm;

    bool xxxx;
    QTcpServer *server;
    QTcpSocket *socket;

    quint32 screen_num;

    char  buff[4096];
         FILE *fp;

private slots:
    void server_New_Connect();
    void socket_Disconnect();
    void socket_Read_Data();
};

#endif // MAINWINDOW_H
