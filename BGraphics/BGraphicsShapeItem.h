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

};


//***************************************************************************//
class BGraphicsShapePainter : public BGraphicsAbstractPainter
{
    Q_OBJECT
public:
    BGraphicsShapePainter();
    virtual ~BGraphicsShapePainter() = 0;
    virtual void paint(QNanoPainter *painter);
};


#endif // BGRAPHICSSHAPEITEM_H
