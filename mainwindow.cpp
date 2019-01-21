#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int count = W.screenCount();
    qDebug("count : %d", count);
    qDebug("now:%d",W.primaryScreen());

//此处需提前准备图片1 2，否则运行失败，需进一步优化
    S1.setGeometry(W.screenGeometry(1));
    S1.show();
    S1.showpic("2.jpg");
    S1.showFullScreen();
    S1.setCursor(Qt::BlankCursor);

    S2.setGeometry(W.screenGeometry(0));
    S2.show();
    S2.showpic("1.jpg");
    S2.showFullScreen();
    S2.setCursor(Qt::BlankCursor);

    server = new QTcpServer();
    socket = new QTcpSocket();
    server->listen(QHostAddress::Any, 9000);
    connect(server,SIGNAL(newConnection()),this,SLOT(server_New_Connect()));
//    connect(server2,SIGNAL(newConnection()),this,SLOT(server_New_Connect2()));

}


//连接1
void MainWindow::server_New_Connect()
{
    qDebug()<<"new connect";
    socket = server->nextPendingConnection();
    connect(socket,SIGNAL(readyRead()),this,SLOT(socket_Read_Data()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(socket_Disconnect()));

}


void MainWindow::socket_Disconnect()
{

}



//接收图片
void MainWindow::socket_Read_Data()
{
    QByteArray array;
    quint32 data_len = 0;
    FILE* fq;
    int index;
    int outint;
    int nnnnn = 0;

    while(socket->waitForReadyRead(3000))
    {
        data_len += socket->bytesAvailable();

        if(data_len == 0)
        {
            break;
        }
        array.append((QByteArray)socket->readAll());
        if(nnnnn == 0)
        {
            QByteArray aa;
            aa[0] = array.at(0);
            int head;
            memcpy(&head, aa.data(), 1);

            QByteArray headd;
            headd[0] = 0x68;
            if(aa == headd)
            {
                QByteArray bb;
                bb[0] = array.at(1);
                bb[1] = array.at(2);
                bb[2] = array.at(3);
                bb[3] = array.at(4);

                memcpy(&outint, bb.data(), 4);

                QByteArray cc;
                cc[0] = array.at(5);
                memcpy(&index, cc.data(), 1);

                QByteArray indexhex;
                indexhex[0] = 0x01;
                QByteArray indexhex2;
                indexhex2[0] = 0x02;
                qDebug()<<"cc:"<<cc.toHex();
                if(cc.toHex() == indexhex.toHex())
                    index = 1;
                if(cc.toHex() == indexhex2.toHex())
                    index = 2;
                else
                    index = 1;
            }
            else
                break;
        }
        nnnnn++;

        if(outint == data_len - 6)
        {
            QString pic_name = QString::number(index) + ".jpg";
            QByteArray ba = pic_name.toLatin1();
            char *name = ba.data();
            if((fq = fopen(name , "wb")) == NULL)
            {

            }
            array.remove(0,6);
            fwrite(array.data(), outint, 1, fq);
            fclose(fq);
            break;
        }
    }


    {
        QString pic_name;
        pic_name = QString::number(screen_num) + ".jpg";

        if(index == 1)
        {
            S2.showpic("1.jpg");
        }
        if(index == 2)
        {
            S1.showpic("2.jpg");
        }
        if(index == 3)
        {
            S1.showpic("3.jpg");
            S2.showpic("3.jpg");
        }
    }

}


MainWindow::~MainWindow()
{
    delete ui;
}
