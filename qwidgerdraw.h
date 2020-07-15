#ifndef QWIDGERDRAW_H
#define QWIDGERDRAW_H

#include <QWidget>

class QWidgerDraw : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgerDraw(QWidget *parent = nullptr);
    void draw (QPainter *painter);  //声明使用的draw函数
    void drawDivide(QPainter *painter, int startX, int startY, int width, int hight, int wCnt ,int hCnt);
    void drawstar(QPainter *painter,int x,int y, int radius,int rotate);

private:
    void paintEvent(QPaintEvent *event) override;

signals:

};

#endif // QWIDGERDRAW_H
