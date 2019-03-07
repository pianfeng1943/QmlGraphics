#include "bspline.h"

bspline::bspline()
{

}

void bspline::spline(const QVector<QPointF> &src, QVector<QPointF> &des)
{
    int order = 3;
    if (src.count() < 4) {
      des = calculate(src, order);
    }
    else
    {
        QVector<QPointF> v;
        QVector<QPointF> tail;
        v = calculate(src.mid(src.count() - 5, src.count() - 1), 3);
        tail = v.mid(v.count() - 25, v.count() - 1);
        des = (des.mid(0, des.count() - 16) + tail);
    }
}

QVector<QPointF> bspline::calculate(const QVector<QPointF> &vec, int order)
{
    if (order <= 0) {
      return vec;
    }
    return calculate(dual(dual(refine(vec))), order - 1);
}

QVector<QPointF> bspline::dual(const QVector<QPointF> &vec)
{
    QVector<QPointF> res;

    for (int i = 0; i < vec.count() -1; i++)
    {
        res.push_back(mid(vec[i], vec[i + 1]));
    }
    return res;
}

QPointF bspline::mid(const QPointF &a, const QPointF &b)
{
    QPointF mid;
    mid.setX(a.x() + (b.x() - a.x())/2);
    mid.setY(a.y() + (b.y() - a.y())/2);
    return mid;
}

QVector<QPointF> bspline::refine(const QVector<QPointF> &vec)
{
    QVector<QPointF> arr = vec;
    QVector<QPointF> res;
    arr.push_front(vec[0]);
    arr.push_back(vec[vec.count() - 1]);

    for (int i = 0; i < arr.count(); i++) {
      res.push_back(arr[i]);

      if (i < arr.count() -1) {
        res.push_back(mid(arr[i], arr[i + 1]));
      }
    }
    return res;
}
