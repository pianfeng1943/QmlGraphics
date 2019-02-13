#ifndef BGRAPHICSLINEITEM_H
#define BGRAPHICSLINEITEM_H
#include "BGraphicsShapeItem.h"



class BGraphicsLineItem : public BGraphicsShapeItem
{
    Q_OBJECT
public:
    BGraphicsLineItem(QQuickItem *parent = nullptr);

    // Reimplement
    QNanoQuickItemPainter *createItemPainter() const Q_DECL_OVERRIDE Q_DECL_FINAL;

public:
    void drawLine(const QPointF &begin, const QPointF &end);

private:
    friend class BGraphicsLinePainter;
    QPointF m_originPos;
};


//***************************************************************************//
class BGraphicsLinePainter : public BGraphicsShapePainter
{
    Q_OBJECT
public:
    BGraphicsLinePainter();

    // Reimplement
    void synchronize(QNanoQuickItem *item);
    void paint(QNanoPainter *painter);

private:
    QPointF m_originPos;
};


#endif // BGRAPHICSLINEITEM_H
