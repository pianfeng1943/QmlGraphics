#include "BGraphicsShapeItem.h"

BGraphicsShapeItem::BGraphicsShapeItem(QQuickItem *parent)
    : BGraphicsAbstractItem(parent)
{
    setHighQualityRendering(true);
}

BGraphicsShapeItem::~BGraphicsShapeItem()
{

}

void BGraphicsShapeItem::setGeometry(const QPointF &begin, const QPointF &end, int translate)
{
    m_beginPos =  begin;
    m_endPos = end;
    if (end.x() < begin.x())
        setX(end.x() - translate);
    else
        setX(begin.x() - translate);

    if (end.y() < begin.y())
        setY(end.y() - translate);
    else
        setY(begin.y() - translate);

    setWidth(abs(end.x() - begin.x()) + translate*2);
    setHeight(abs(end.y() - begin.y()) + translate*2);
}



//***************************************************************************//
BGraphicsShapePainter::BGraphicsShapePainter()
{

}

BGraphicsShapePainter::~BGraphicsShapePainter()
{

}

void BGraphicsShapePainter::paint(QNanoPainter *painter)
{
    painter->setLineCap(QNanoPainter::CAP_ROUND);
    painter->setLineJoin(QNanoPainter::JOIN_ROUND);
    painter->setAntialias(2.0);

    // border
    if (m_isSelected)
    {
        painter->beginPath();
        painter->setLineWidth(2);
        painter->setStrokeStyle("#FFFFFF");
        painter->rect(0, 0, width(), height());
        painter->stroke();
    }
    // item
    qreal penWidth;
    if (m_penScale == 1.0)
    {
        if (m_scale == 1.0)
            penWidth = m_pen.width();
        else
            penWidth = m_pen.width() * m_scale;
    }
    else
    {
        if (m_scale == 1.0)
            penWidth = m_pen.width() * m_penScale;
        else
            penWidth = m_pen.width() * m_penScale * m_scale;
    }
    painter->setLineWidth(penWidth);
    QNanoColor lineColor(QNanoColor::fromQColor(m_pen.color()));
    painter->setStrokeStyle(lineColor);
}
