#include "BGraphicsScene.h"
#include "BGraphicsPathItem.h"
#include "BGraphicsLineItem.h"
#include "BGraphicsRectItem.h"
#include "BGraphicsEllipseItem.h"
#include <QDebug>


BGraphicsScene::BGraphicsScene(QQuickItem *parent)
    : QQuickItem(parent)
    , m_pItem(0)
{
    setAcceptHoverEvents(true);
    setAcceptedMouseButtons(Qt::AllButtons);
    setFlag(ItemAcceptsInputMethod, true);
    setAntialiasing(true);

    setNormalMode();
}

void BGraphicsScene::setNormalMode()
{
    m_mode = Normal;
    setItemsAcceptedMouse(true);
    setItemsNormal();
}

void BGraphicsScene::setPenMode(int width, const QColor &color)
{
    m_mode = Pen;
    m_penWidth = width;
    m_penColor = color;
    setItemsAcceptedMouse(false);
    setItemsNormal();
}

void BGraphicsScene::setLightMode()
{

}

void BGraphicsScene::setShapeMode(int type, int width, const QColor &color)
{
    m_mode = (SceneMode)type;
    m_shapeWidth = width;
    m_shapeColor = color;
    setItemsAcceptedMouse(false);
    setItemsNormal();
}

void BGraphicsScene::setTextMode(const QFont &font, const QColor &color)
{
    m_mode = Text;
}

void BGraphicsScene::setEraserMode()
{
    m_mode = Eraser;
    setItemsAcceptedMouse(false);
    setItemsNormal();
}

void BGraphicsScene::setItemsAcceptedMouse(bool enabled)
{
    foreach (QQuickItem* item, childItems())
    {
        if (enabled)
            item->setAcceptedMouseButtons(Qt::AllButtons);
        else
            item->setAcceptedMouseButtons(Qt::NoButton);
    }
}

void BGraphicsScene::setItemsNormal()
{
    foreach (QQuickItem* item, childItems())
    {
        BGraphicsAbstractItem *pItem = static_cast<BGraphicsAbstractItem*>(item);
        if (pItem)
            pItem->setSelected(false);
    }
}

void BGraphicsScene::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_posPressed = event->pos();
        switch (m_mode)
        {
        case Normal:
        {
            setItemsNormal();
            break;
        }
        case Pen:
        {
            BGraphicsPathItem *item = new BGraphicsPathItem(this);
            m_pItem = item;
            item->setPen(QPen(m_penColor, m_penWidth));
            item->drawPath(event->pos());
            break;
        }
        case Line:
        {
            BGraphicsLineItem *item = new BGraphicsLineItem(this);
            m_pItem = item;
            item->setPen(QPen(m_shapeColor, m_shapeWidth));
            item->drawLine(event->pos(), event->pos());
            break;
        }
        case Rect:
        {
            BGraphicsRectItem *item = new BGraphicsRectItem(this);
            item->setPen(QPen(m_shapeColor, m_shapeWidth));
            m_pItem = item;
            item->drawRect(event->pos(), event->pos());
            break;
        }
        case Ellipse:
        {
            BGraphicsEllipseItem *item = new BGraphicsEllipseItem(this);
            item->setPen(QPen(m_shapeColor, m_shapeWidth));
            m_pItem = item;
            item->drawEllipse(event->pos(), event->pos());
            break;
        }
        case Text:
        {
            break;
        }
        default:
            return;
        }
    }
}

void BGraphicsScene::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
}

void BGraphicsScene::mouseMoveEvent(QMouseEvent *event)
{
    switch (m_mode)
    {
    case Pen:
    {
        if (m_pItem.isNull())
            return;
        BGraphicsPathItem *pathItem = dynamic_cast<BGraphicsPathItem*>(m_pItem.data());
        if (pathItem)
            pathItem->drawPath(event->pos());
        break;
    }
    case Line:
    {
        if (m_pItem.isNull())
            return;
        BGraphicsLineItem *lineItem = dynamic_cast<BGraphicsLineItem*>(m_pItem.data());
        if (lineItem)
            lineItem->drawLine(m_posPressed, event->pos());
        break;
    }
    case Rect:
    {
        if (m_pItem.isNull())
            return;
        BGraphicsRectItem *rectItem = dynamic_cast<BGraphicsRectItem*>(m_pItem.data());
        if (rectItem)
            rectItem->drawRect(m_posPressed, event->pos());
        break;
    }
    case Ellipse:
    {
        if (m_pItem.isNull())
            return;
        BGraphicsEllipseItem *ellipseItem = dynamic_cast<BGraphicsEllipseItem*>(m_pItem.data());
        if (ellipseItem)
            ellipseItem->drawEllipse(m_posPressed, event->pos());
        break;
    }
    case Eraser:
    {
        onDealEraser(event->pos());
        break;
    }
    default:
        break;
    }

}

void BGraphicsScene::onDealEraser(const QPoint &pos)
{
    QList<QQuickItem*> list = childItems();
    foreach (QQuickItem* item, list)
    {
        QRectF tR = item->mapRectToItem(this, item->boundingRect());
        if (tR.contains(pos))
        {
            item->setParent(nullptr);
            item->setParentItem(nullptr);
            item->deleteLater();
        }
    }
}

void BGraphicsScene::hoverMoveEvent(QHoverEvent *event)
{
    QQuickItem::hoverMoveEvent(event);
}
