#include "BGraphicsEllipseItem.h"

BGraphicsEllipseItem::BGraphicsEllipseItem(QQuickItem *parent)
    : BGraphicsShapeItem(parent)
{
}

QNanoQuickItemPainter *BGraphicsEllipseItem::createItemPainter() const
{
    return new BGraphicsEllipsePainter();
}

void BGraphicsEllipseItem::drawEllipse(const QPointF &begin, const QPointF &end)
{
    setGeometry(begin, end, m_penWidth/2);
    update();
}


//***************************************************************************//

BGraphicsEllipsePainter::BGraphicsEllipsePainter()
{

}

void BGraphicsEllipsePainter::synchronize(QNanoQuickItem *item)
{
    BGraphicsShapePainter::synchronize(item);
}

void BGraphicsEllipsePainter::paint(QNanoPainter *painter)
{
    BGraphicsShapePainter::paint(painter);

    painter->beginPath();
    painter->ellipse(QRect(m_penWidth / 2, m_penWidth / 2,
                           width()- m_penWidth, height() - m_penWidth));
    painter->stroke();
}
