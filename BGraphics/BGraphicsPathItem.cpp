#include "BGraphicsPathItem.h"
#include "bspline.h"

#define USE_BSPLINE


BGraphicsPathItem::BGraphicsPathItem(QQuickItem *parent)
    : BGraphicsShapeItem(parent)
    , m_bFirst(true)
{

}

QNanoQuickItemPainter* BGraphicsPathItem::createItemPainter() const
{
    return new BGraphicsPathPainter();;
}

void BGraphicsPathItem::drawPath(const QPointF &pos)
{
    if (m_bFirst)
    {
        m_originPos.setX(pos.x() - m_penWidth/2);
        m_originPos.setY(pos.y() - m_penWidth/2);
        m_rect.setTopLeft(pos);
        m_bFirst = false;
    }

    m_tPos.push_back(pos);

#ifdef USE_BSPLINE
    bspline::spline(m_tPos, m_points);
    for (const auto &p : m_points)
        setItemSize(p);
#else
    m_points = m_tPos;
    setItemSize(pos);
#endif
    update();
}

void BGraphicsPathItem::setItemSize(const QPointF &pos)
{
    if (pos.x() < m_rect.left())
    {
        m_rect.setLeft(pos.x());
        m_originPos.setX(pos.x() - m_penWidth/2);
    }
    if (pos.y() < m_rect.top())
    {
        m_rect.setTop(pos.y());
        m_originPos.setY(pos.y() - m_penWidth/2);
    }
    if (pos.x() > m_rect.right())
        m_rect.setRight(pos.x());
    if (pos.y() > m_rect.bottom())
        m_rect.setBottom(pos.y());
    setX(m_rect.x() - m_penWidth/2);
    setY(m_rect.y() - m_penWidth/2);
    setWidth(m_rect.width() +  m_penWidth);
    setHeight(m_rect.height() +  m_penWidth);
}



//***************************************************************************//
BGraphicsPathPainter::BGraphicsPathPainter()
{

}

void BGraphicsPathPainter::synchronize(QNanoQuickItem *item)
{
    BGraphicsPathItem *realItem = static_cast<BGraphicsPathItem*>(item);
    if (realItem)
    {
        m_originPos = realItem->m_originPos;
        m_points = realItem->m_points;
    }
    return BGraphicsShapePainter::synchronize(item);
}

void BGraphicsPathPainter::paint(QNanoPainter *painter)
{
    BGraphicsShapePainter::paint(painter);
    if (m_points.count() > 0)
    {
        painter->beginPath();
        QPointF firstPoint = (m_points.first() - m_originPos) * m_scale;
        painter->moveTo(firstPoint.x(), firstPoint.y()-1);
        painter->lineTo(firstPoint);
        for (int i=1; i<m_points.size(); ++i)
        {
            painter->lineTo((m_points.at(i) - m_originPos) * m_scale);
        }
        painter->stroke();
    }
}
