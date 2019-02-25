#ifndef BGRAPHICSRECTITEM_H
#define BGRAPHICSRECTITEM_H
#include "BGraphicsShapeItem.h"

class BGraphicsRectItem : public BGraphicsShapeItem
{
    Q_OBJECT

public:
    BGraphicsRectItem(QQuickItem *parent = nullptr);

    // Reimplement
    QNanoQuickItemPainter *createItemPainter() const Q_DECL_OVERRIDE Q_DECL_FINAL;

public:
    void drawRect(const QPointF &begin, const QPointF &end);

};


//***************************************************************************//
class BRectItemPainter: public BGraphicsShapePainter
{
    Q_OBJECT
public:
    BRectItemPainter();

    // Reimplement
    void synchronize(QNanoQuickItem *item);
    void paint(QNanoPainter *painter);

};

#endif // BGRAPHICSRECTITEM_H
