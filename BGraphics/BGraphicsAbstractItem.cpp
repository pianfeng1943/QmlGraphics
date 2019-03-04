#include "BGraphicsAbstractItem.h"
#include <QCursor>
#include <cmath>

#define DEF_ITEM_MIN_WIDTH  50.0
#define DEF_ITEM_MIN_HEIGHT 50.0

BGraphicsAbstractItem::BGraphicsAbstractItem(QQuickItem *parent)
    : QNanoQuickItem(parent)
    , m_isSelected(false)
    , m_resizeEnable(false)
    , m_circleSize(10)
    , m_resizing(false)
{
    setTransformOrigin(QQuickItem::TopLeft);
    if (parent)
    {
        m_parentOldWidth = parent->width();
        m_parentOldHeight = parent->height();
    }
}

BGraphicsAbstractItem::~BGraphicsAbstractItem()
{
}

void BGraphicsAbstractItem::setSelected(bool select)
{
    m_isSelected = select;
    update();
}

void BGraphicsAbstractItem::setScaled()
{
    if (parentItem())
    {
        if (parentItem()->width() == m_parentOldWidth || parentItem()->height() == m_parentOldHeight)
            m_scale = 1.0;
        else
            m_scale = qMin(parentItem()->width()/m_parentOldWidth, parentItem()->height()/m_parentOldHeight);
        update();
    }
}

void BGraphicsAbstractItem::mousePressEvent(QMouseEvent *event)
{
    if (m_resizeEnable && resizeItemAt(event->pos()))
    {
        m_resizing = true;
        if (LeftDown == m_resizePos)
        {
            m_resizeFixPos.setX(position().x() + width());
            m_resizeFixPos.setY(0);
        }
        else if (RightUp == m_resizePos)
        {
            m_resizeFixPos.setX(0);
            m_resizeFixPos.setY(position().y() + height());
        }
        else if (LeftUp == m_resizePos)
        {
            m_resizeFixPos.setX(position().x() + width());
            m_resizeFixPos.setY(position().y() + height());
        }
    }
    else
    {
        setSelected(true);
        m_pressPos = event->pos();
    }
}

void BGraphicsAbstractItem::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)

    if (m_resizing)
    {
        m_resizing = false;
        setCursor(QCursor(Qt::ArrowCursor));
    }
}

void BGraphicsAbstractItem::mouseMoveEvent(QMouseEvent *event)
{
    if (m_resizing) //change size
    {
        QPointF pos = mapToItem(parentItem(), event->pos());
        qreal tWidth;
        qreal tHeight;
        if (event->pos().x() > DEF_ITEM_MIN_WIDTH)
            tWidth = event->pos().x();
        else
            tWidth = DEF_ITEM_MIN_WIDTH;
        if (event->pos().y() > DEF_ITEM_MIN_HEIGHT)
            tHeight = event->pos().y();
        else
            tHeight = DEF_ITEM_MIN_HEIGHT;
        qreal widthMove = position().x() - pos.x();
        qreal heightMove = position().y() - pos.y();
        if (m_resizePos == RightUp)
        {
            if (height() + heightMove > DEF_ITEM_MIN_HEIGHT)
            {
                setY(position().y() - heightMove);
                setHeight(height() + heightMove);
            }
            else
            {
                setY(m_resizeFixPos.y() - DEF_ITEM_MIN_HEIGHT);
                setHeight(DEF_ITEM_MIN_HEIGHT);
            }
            setWidth(tWidth);
        }
        else if (m_resizePos == LeftUp)
        {
            if (width() + widthMove > DEF_ITEM_MIN_WIDTH)
            {
                setX(position().x() - widthMove);
                setWidth(width() + widthMove);
            }
            else
            {
                setX(m_resizeFixPos.x() - DEF_ITEM_MIN_WIDTH);
                setWidth(DEF_ITEM_MIN_WIDTH);
            }
            if (height() + heightMove > DEF_ITEM_MIN_HEIGHT)
            {
                setY(position().y() - heightMove);
                setHeight(height() + heightMove);
            }
            else
            {
                setY(m_resizeFixPos.y() - DEF_ITEM_MIN_HEIGHT);
                setHeight(DEF_ITEM_MIN_HEIGHT);
            }
        }
        else if (m_resizePos == LeftDown)
        {
            if (width() + widthMove > DEF_ITEM_MIN_WIDTH)
            {
                setX(position().x() - widthMove);
                setWidth(width() + widthMove);
            }
            else
            {
                setX(m_resizeFixPos.x() - DEF_ITEM_MIN_WIDTH);
                setWidth(DEF_ITEM_MIN_WIDTH);
            }
            setHeight(tHeight);
        }
        else if (m_resizePos == RightDown)
        {
            setWidth(tWidth);
            setHeight(tHeight);
        }
    }
    else
    {
        // change position
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
}

void BGraphicsAbstractItem::hoverEnterEvent(QHoverEvent *event)
{
    Q_UNUSED(event)
}

void BGraphicsAbstractItem::hoverLeaveEvent(QHoverEvent *event)
{
    Q_UNUSED(event)
}

void BGraphicsAbstractItem::hoverMoveEvent(QHoverEvent *event)
{
    if (m_resizeEnable)
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
}

bool BGraphicsAbstractItem::resizeItemAt(const QPointF &pos)
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


