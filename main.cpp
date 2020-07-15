#include <QApplication>
#include <QWidget>
#include <QPainter>
#include "stdio.h"
#include <QLabel>
#include <QDebug>
#include <QDateTime>
#include <QTimer>
#include <QMouseEvent>
#include "qwidgerdraw.h"

class QLabelClock:public QLabel
{
private:
    QString now();
public:
    QTimer *timer;
    int refreshEnable=1;
    QLabelClock(QWidget *parent);
    void refresh();

    void mousePressEvent(QMouseEvent *ev);
    void refreshToggle();

};



QLabelClock::QLabelClock(QWidget *parent):QLabel(parent) //将parent输送给它继承的QLabel
{
    this->setText(this->now());
    this->setStyleSheet("color:black;font-family:Microsoft YaHei;font-size: 30px");
    this->setGeometry(50,500,760,30);


    timer =new QTimer(parent);//创建新的定时器
    timer->start(1);//后台执行定时器，毫秒，向下进行，以1ms开始计时
    //信号与槽
    connect(timer,&QTimer::timeout, this,&QLabelClock::refresh );//建立连接，一旦timeout 执行QLabelClock下的函数refresh
}


QString QLabelClock:: now()
{
    return(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd"));
}
void QLabelClock:: refresh()
{
    if(1==refreshEnable)
    this->setText(this->now());//显示现在时间
}



//按下鼠标
void QLabelClock::mousePressEvent(QMouseEvent *ev)
{
    if (ev->buttons()==Qt::LeftButton) //左键按下
    {
        if(refreshEnable) //等于1
           refreshEnable =0;
        else
           refreshEnable =1;
    }
}





int main (int argc,char *argv[])
{
    QApplication a(argc,argv);

    QWidget *widgetMain = new QWidget();
    //修改参数
    widgetMain->setWindowTitle("哈尔滨吴彦组");
    widgetMain->resize(760,540);
    //创建姓名标签
    QLabel *labelname = new QLabel(widgetMain);
    labelname->setText("1170500417 柏森");
    labelname->setGeometry(50,10,760,30);
    labelname->setStyleSheet("color:black;font-family:Microsoft YaHei;font-size: 30px");
    //调用函数
    QWidgerDraw *drawWin = new QWidgerDraw(widgetMain);
    QLabelClock *labelClock =new QLabelClock(widgetMain);





    widgetMain->show();
    return a.exec();
}




