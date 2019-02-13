#include "BGraphicsPathItem.h"

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
        m_originPos.setX(pos.x() - pen().width()/2);
        m_originPos.setY(pos.y() - pen().width()/2);
        m_rect.setTopLeft(pos);
        m_bFirst = false;
    }

    if (pos.x() < m_rect.left())
    {
        m_rect.setLeft(pos.x());
        m_originPos.setX(pos.x() - pen().width()/2);
    }
    if (pos.y() < m_rect.top())
    {
        m_rect.setTop(pos.y());
        m_originPos.setY(pos.y() - pen().width()/2);
    }
    if (pos.x() > m_rect.right())
        m_rect.setRight(pos.x());
    if (pos.y() > m_rect.bottom())
        m_rect.setBottom(pos.y());
    setX(m_rect.x() - pen().width()/2);
    setY(m_rect.y() - pen().width()/2);
    setWidth(m_rect.width() +  pen().width());
    setHeight(m_rect.height() +  pen().width());

    m_points.push_back(pos);
    update();
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
        QPointF firstPoint = m_points.first() - m_originPos;
        painter->moveTo(firstPoint.x(), firstPoint.y()-1);
        painter->lineTo(firstPoint);
        for (int i=1; i<m_points.size(); ++i)
        {
            painter->lineTo(m_points.at(i) - m_originPos);
        }
        painter->stroke();
    }
}
