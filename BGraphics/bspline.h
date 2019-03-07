#ifndef BSPLINE_H
#define BSPLINE_H
#include <QVector>
#include <QPointF>


class bspline
{
public:
    bspline();

public:
    static void spline(const QVector<QPointF> &src, QVector<QPointF> &des);

private:
    static QVector<QPointF> calculate(const QVector<QPointF> &vec, int order);
    static QVector<QPointF> dual(const QVector<QPointF> &vec);
    static QVector<QPointF> refine(const QVector<QPointF> &vec);
    static QPointF mid(const QPointF &a, const QPointF &b);
};

#endif // BSPLINE_H
