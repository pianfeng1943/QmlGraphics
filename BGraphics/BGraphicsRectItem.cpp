#include "BGraphicsRectItem.h"
#include <QDebug>



BGraphicsRectItem::BGraphicsRectItem(QQuickItem *parent)
    : BGraphicsShapeItem(parent)
{
    setMouseHoverEventsEnabled(true);
    setResizeEnabled(true);
}

QNanoQuickItemPainter *BGraphicsRectItem::createItemPainter() const
{
    return new BRectItemPainter();
}

void BGraphicsRectItem::drawRect(const QPointF &begin, const QPointF &end)
{
    setGeometry(begin, end);
    update();
}



//***************************************************************************//
BRectItemPainter::BRectItemPainter()
{

}

void BRectItemPainter::synchronize(QNanoQuickItem *item)
{
    return BGraphicsShapePainter::synchronize(item);
}

void BRectItemPainter::paint(QNanoPainter *painter)
{
    BGraphicsShapePainter::paint(painter);

    painter->beginPath();
    if (m_isSelected)
        painter->rect(m_pen.width() / 2 + 2, m_pen.width() / 2 + 2,
                      width() - m_pen.width() - 4, height() - m_pen.width() - 4);
    else
        painter->rect(m_pen.width() / 2, m_pen.width() / 2,
                      width() - m_pen.width(), height() - m_pen.width());
    painter->stroke();
}
