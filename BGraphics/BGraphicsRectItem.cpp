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
        painter->rect(m_penWidth / 2 + 2, m_penWidth / 2 + 2,
                      width() - m_penWidth - 4, height() - m_penWidth - 4);
    else
        painter->rect(m_penWidth / 2, m_penWidth / 2,
                      width() - m_penWidth, height() - m_penWidth);
    painter->stroke();
}
