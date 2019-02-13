#include "BGraphicsAbstractItem.h"



BGraphicsAbstractItem::BGraphicsAbstractItem(QQuickItem *parent)
    : QNanoQuickItem(parent)
    , m_isSelected(false)
{
}

void BGraphicsAbstractItem::setSelected(bool select)
{
    m_isSelected = select;
    update();
}

BGraphicsAbstractItem::~BGraphicsAbstractItem()
{
}

void BGraphicsAbstractItem::mousePressEvent(QMouseEvent *event)
{
    setSelected(true);
    m_pressPos = event->pos();
}

void BGraphicsAbstractItem::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
}

void BGraphicsAbstractItem::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isSelected)
    {
        QPointF offPos = mapToItem(parentItem(), event->pos()) -
                mapToItem(parentItem(), m_pressPos);
        QPointF newPos = position() + offPos;
        if (newPos.x() < 0)
            newPos.setX(0);
        if (newPos.y() < 0)
            newPos.setY(0);
        if (newPos.x() > parentItem()->width() - width())
            newPos.setX(parentItem()->width() - width());
        if (newPos.y() > parentItem()->height() - height())
            newPos.setY(parentItem()->height() - height());
        setPosition(newPos);
    }
}


