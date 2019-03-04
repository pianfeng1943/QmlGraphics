#include "BGraphicsLineItem.h"

BGraphicsLineItem::BGraphicsLineItem(QQuickItem *parent)
    : BGraphicsShapeItem(parent)
{
}

QNanoQuickItemPainter *BGraphicsLineItem::createItemPainter() const
{
    return new BGraphicsLinePainter();
}

void BGraphicsLineItem::drawLine(const QPointF &begin, const QPointF &end)
{
    m_originPos.setX(begin.x() - pen().width()/2);
    m_originPos.setY(begin.y() - pen().width()/2);
    if (end.x() < m_originPos.x())
        m_originPos.setX(end.x() - pen().width()/2);
    if (end.y() < m_originPos.y())
        m_originPos.setY(end.y() - pen().width()/2);
    setGeometry(begin, end, pen().width()/2);
    update();
}


//***************************************************************************//

BGraphicsLinePainter::BGraphicsLinePainter()
{

}

void BGraphicsLinePainter::synchronize(QNanoQuickItem *item)
{
    BGraphicsLineItem *realItem = static_cast<BGraphicsLineItem*>(item);
    if (realItem)
    {
        m_originPos = realItem->m_originPos;
    }
    BGraphicsShapePainter::synchronize(item);
}

void BGraphicsLinePainter::paint(QNanoPainter *painter)
{
    BGraphicsShapePainter::paint(painter);

    painter->beginPath();
    painter->moveTo((m_beginPos - m_originPos)*m_scale);
    painter->lineTo((m_beginPos - m_originPos)*m_scale);
    painter->lineTo((m_endPos - m_originPos)*m_scale);
    painter->stroke();
}
