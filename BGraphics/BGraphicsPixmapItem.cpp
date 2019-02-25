#include "BGraphicsPixmapItem.h"

BGraphicsPixmapItem::BGraphicsPixmapItem(QQuickItem *parent)
    : BGraphicsAbstractItem(parent)
{
    setMouseHoverEventsEnabled(true);
    setResizeEnabled(true);
}

QNanoQuickItemPainter *BGraphicsPixmapItem::createItemPainter() const
{
    return new BGraphicsPixmapPainter();
}

void BGraphicsPixmapItem::drawPixmap(float x, float y, const QString &pixmap)
{
    m_strPixmap = pixmap;
    QPixmap pix(pixmap);
    if (!pix.isNull())
    {
        setX(x);
        setY(y);
        setWidth(pix.width());
        setHeight(pix.height());
    }
    update();
}




//***************************************************************************//
BGraphicsPixmapPainter::BGraphicsPixmapPainter()
{

}

void BGraphicsPixmapPainter::synchronize(QNanoQuickItem *item)
{
    BGraphicsPixmapItem *realItem = static_cast<BGraphicsPixmapItem*>(item);
    if (realItem)
    {
        m_strPixmap = realItem->m_strPixmap;
    }
    return BGraphicsAbstractPainter::synchronize(item);
}

void BGraphicsPixmapPainter::paint(QNanoPainter *painter)
{
    if (m_strPixmap.isEmpty())
        return;
    QNanoImage image(m_strPixmap);
    painter->drawImage(image, QRectF(2,2,width()-4,height()-4));

    if (m_isSelected)
    {
        painter->beginPath();
        painter->setLineWidth(2);
        painter->setStrokeStyle("#FFFFFF");
        painter->rect(0, 0, width(), height());
        painter->stroke();
    }
}
