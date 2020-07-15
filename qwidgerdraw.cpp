#include "qwidgerdraw.h"
#include <QPainter>
#include <QtMath>


QWidgerDraw::QWidgerDraw(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("哈尔滨吴彦组");
    this->resize(760,540);
}


void QWidgerDraw::paintEvent (QPaintEvent *event)
{
    QPainter *painter = new QPainter();
    //启动绘图
    painter->begin(this);
    this->draw(painter);//调用draw函数
    //画图结束
    painter->end();
}

void QWidgerDraw:: draw(QPainter *painter)
{
    int step;//小格尺寸
    //配置画笔参数
    painter->setPen(QPen(Qt::black,Qt::DashLine));
    painter->drawRect(50,50,660,440);
    //水平垂直2等分
    painter->drawLine(50,270,710,270);
    painter->drawLine(380,50,380,490);
    //左上角10*15等分
    this->drawDivide(painter,50,50,330,220,15,10);
    //绘制大圆
    step=330/15;
    painter->drawEllipse(50+2*330/15,50+2*220/10,22*6,22*6);
    //画小圆
    painter->drawEllipse(50+9*step,50+1*step,step*2,step*2);
    painter->drawEllipse(50+11*step,50+3*step,step*2,step*2);
    painter->drawEllipse(50+11*step,50+6*step,step*2,step*2);
    painter->drawEllipse(50+9*step,50+8*step,step*2,step*2);
    //画五角星
    //画大五角星
    painter->translate(50+5*step,50+5*step);
    QPoint points[3] = {QPoint(0, -3*step), QPoint(-(3*step)*tan(0.1*M_PI), 0),QPoint(+(3*step)*tan(0.1*M_PI), 0)};
    painter->setRenderHint(QPainter::Antialiasing);
        for(int i = 0; i < 5; i ++)
        {
            //画三角形构成五角星
            painter->rotate(72);
            painter->drawConvexPolygon(points, 3);
        }

}

void QWidgerDraw:: drawDivide(QPainter *painter, int startX, int startY, int width, int hight, int wCnt ,int hCnt)
{
    int step =width/wCnt;
    int cnt=0;

    //水平方向等分（画竖线）
    for(cnt=0;cnt<wCnt;cnt++)
        painter->drawLine(startX+step*cnt,startY,startX+step*cnt,startY+hight);
    //垂直方向等分（画横线）
    step=hight/hCnt;
    for(cnt=0;cnt<hCnt;cnt++)
        painter->drawLine(startX,startY+step*cnt,startX+width,startY+step*cnt);

}


