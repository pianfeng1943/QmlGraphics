#include "BGraphicsPixmapItem.h"

BGraphicsPixmapItem::BGraphicsPixmapItem(QQuickItem *parent)
    : BGraphicsAbstractItem(parent)
{

}

QNanoQuickItemPainter *BGraphicsPixmapItem::createItemPainter() const
{
    return new BGraphicsPixmapPainter();
}

void BGraphicsPixmapItem::drawPixmap(float x, float y, const QString &pixmap)
{
    m_strPixmap = pixmap;
    setX(x);
    setY(y);
    QPixmap pix(pixmap);

    if (!pix.isNull())
    {
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
}

void BGraphicsPixmapPainter::paint(QNanoPainter *painter)
{
    if (m_strPixmap.isEmpty())
        return;
    QNanoImage image(m_strPixmap);
    painter->drawImage(image, 0.0, 0.0);

    if (m_isSelected)
    {

    }
}
