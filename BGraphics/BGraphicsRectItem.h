#ifndef BGRAPHICSRECTITEM_H
#define BGRAPHICSRECTITEM_H
#include "BGraphicsShapeItem.h"

class BGraphicsRectItem : public BGraphicsShapeItem
{
    Q_OBJECT

    enum ResizePos
    {
        LeftUp,LeftDown,RightUp,RightDown
    };

public:
    BGraphicsRectItem(QQuickItem *parent = nullptr);

    // Reimplement
    QNanoQuickItemPainter *createItemPainter() const Q_DECL_OVERRIDE Q_DECL_FINAL;

public:
    void drawRect(const QPointF &begin, const QPointF &end);

private:
    bool resizeItemAt(QPointF pos);

protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE Q_DECL_FINAL;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE Q_DECL_FINAL;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE Q_DECL_FINAL;
    void hoverEnterEvent(QHoverEvent *event);
    void hoverLeaveEvent(QHoverEvent *event);
    void hoverMoveEvent(QHoverEvent *event);

private:
    friend class BRectItemPainter;
    ResizePos m_resizePos;
    int m_circleSize;
    bool m_resizing;
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
