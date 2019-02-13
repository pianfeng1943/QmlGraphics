#include "BGraphicsRectItem.h"
#include <QCursor>
#include <QDebug>
#include <cmath>


BGraphicsRectItem::BGraphicsRectItem(QQuickItem *parent)
    : BGraphicsShapeItem(parent)
{
    setMouseHoverEventsEnabled(true);

    m_circleSize = 10;
    m_resizing = false;
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

bool BGraphicsRectItem::resizeItemAt(QPointF pos)
{
    QPointF p = boundingRect().bottomRight() - pos;
    if (p.manhattanLength() <= m_circleSize*2)
    {
        m_resizePos = RightDown;
        return true;
    }
    p = boundingRect().topRight() - pos;
    if (p.manhattanLength() <= m_circleSize*2)
    {
        m_resizePos = RightUp;
        return true;
    }

    p = boundingRect().topLeft() - pos;
    if (p.manhattanLength() <= m_circleSize*2)
    {
        m_resizePos = LeftUp;
        return true;
    }

    p = boundingRect().bottomLeft() - pos;
    if (p.manhattanLength() <= m_circleSize*2)
    {
        m_resizePos = LeftDown;
        return true;
    }

    return false;
}

void BGraphicsRectItem::mousePressEvent(QMouseEvent *event)
{
    if (resizeItemAt(event->pos()))
    {
        m_resizing = true;
        if (m_resizePos == RightUp)
        {
            m_beginPos = mapToItem(parentItem(), boundingRect().bottomLeft());
            m_beginPos.setX(m_beginPos.x());
            m_beginPos.setY(m_beginPos.y());
        }
        else if (m_resizePos == LeftUp)
        {
            m_beginPos = mapToItem(parentItem(), boundingRect().bottomRight());
            m_beginPos.setX(m_beginPos.x());
            m_beginPos.setY(m_beginPos.y());
        }
        else if (m_resizePos == LeftDown)
        {
            m_beginPos = mapToItem(parentItem(), boundingRect().topRight());
            m_beginPos.setX(m_beginPos.x());
            m_beginPos.setY(m_beginPos.y());
        }
        return;
    }
    return BGraphicsAbstractItem::mousePressEvent(event);
}

void BGraphicsRectItem::mouseReleaseEvent(QMouseEvent *event)
{
    m_beginPos = QPointF(x(), y());
    m_resizing = false;
    setCursor(QCursor(Qt::ArrowCursor));
    return BGraphicsAbstractItem::mouseReleaseEvent(event);
}

void BGraphicsRectItem::mouseMoveEvent(QMouseEvent *event)
{
    if (m_resizing)
    {
        drawRect(m_beginPos, mapToItem(parentItem(), event->pos()));
        return;
    }
    return BGraphicsAbstractItem::mouseMoveEvent(event);
}

void BGraphicsRectItem::hoverEnterEvent(QHoverEvent *event)
{
    Q_UNUSED(event)
}

void BGraphicsRectItem::hoverLeaveEvent(QHoverEvent *event)
{
    Q_UNUSED(event)
}

void BGraphicsRectItem::hoverMoveEvent(QHoverEvent *event)
{
    if (resizeItemAt(event->pos()))
    {
        switch (m_resizePos)
        {
        case RightDown:
            setCursor(QCursor(Qt::SizeFDiagCursor));
            break;
        case RightUp:
            setCursor(QCursor(Qt::SizeBDiagCursor));
            break;
        case LeftUp:
            setCursor(QCursor(Qt::SizeFDiagCursor));
            break;
        case LeftDown:
            setCursor(QCursor(Qt::SizeBDiagCursor));
            break;
        default:
            setCursor(QCursor(Qt::ArrowCursor));
            return;
        }
    }
    else
    {
        setCursor(QCursor(Qt::ArrowCursor));
    }
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
