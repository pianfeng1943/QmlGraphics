#ifndef BGRAPHICSELLIPSEITEM_H
#define BGRAPHICSELLIPSEITEM_H
#include "BGraphicsShapeItem.h"



class BGraphicsEllipseItem : public BGraphicsShapeItem
{
    Q_OBJECT
public:
    BGraphicsEllipseItem(QQuickItem *parent = nullptr);

    // Reimplement
    QNanoQuickItemPainter *createItemPainter() const Q_DECL_OVERRIDE Q_DECL_FINAL;

public:
    void drawEllipse(const QPointF &begin, const QPointF &end);

private:
    friend class BGraphicsEllipsePainter;
};


//***************************************************************************//
class BGraphicsEllipsePainter : public BGraphicsShapePainter
{
    Q_OBJECT
public:
    BGraphicsEllipsePainter();

    // Reimplement
    void synchronize(QNanoQuickItem *item);
    void paint(QNanoPainter *painter);
};


#endif // BGRAPHICSELLIPSEITEM_H
