#ifndef BGRAPHICSPATHITEM_H
#define BGRAPHICSPATHITEM_H
#include "BGraphicsShapeItem.h"
#include <QVector>



class BGraphicsPathItem : public BGraphicsShapeItem
{
    Q_OBJECT
public:
    BGraphicsPathItem(QQuickItem *parent = nullptr);

    // Reimplement
    QNanoQuickItemPainter *createItemPainter() const Q_DECL_OVERRIDE Q_DECL_FINAL;

public:
    void drawPath(const QPointF &pos);

private:
    void setItemSize(const QPointF &pos);


private:
    friend class BGraphicsPathPainter;
    QVector<QPointF> m_points;
    QVector<QPointF> m_tPos;
    QPointF m_originPos;
    QRectF m_rect;
    bool m_bFirst;
};

//***************************************************************************//
class BGraphicsPathPainter: public BGraphicsShapePainter
{
    Q_OBJECT
public:
    BGraphicsPathPainter();

    // Reimplement
    void synchronize(QNanoQuickItem *item);
    void paint(QNanoPainter *painter);

private:
    QVector<QPointF> m_points;
    QPointF m_originPos;
};

#endif // BGRAPHICSPATHITEM_H
