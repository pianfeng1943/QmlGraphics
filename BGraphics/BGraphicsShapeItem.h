#ifndef BGRAPHICSSHAPEITEM_H
#define BGRAPHICSSHAPEITEM_H
#include "BGraphicsAbstractItem.h"
#include "BGraphicsAbstractPainter.h"

class BGraphicsShapeItem : public BGraphicsAbstractItem
{
    Q_OBJECT
public:
    BGraphicsShapeItem(QQuickItem *parent = nullptr);
    virtual ~BGraphicsShapeItem() = 0;

public:
    void setGeometry(const QPointF &begin, const QPointF &end, int translate = 0);

protected:
    friend class BGraphicsShapePainter;
    QPointF m_beginPos;
    QPointF m_endPos;
};


//***************************************************************************//
class BGraphicsShapePainter : public BGraphicsAbstractPainter
{
    Q_OBJECT
public:
    BGraphicsShapePainter();
    virtual ~BGraphicsShapePainter() = 0;
    virtual void synchronize(QNanoQuickItem *item);
    virtual void paint(QNanoPainter *painter);

protected:
    QPointF m_beginPos;
    QPointF m_endPos;
};


#endif // BGRAPHICSSHAPEITEM_H
