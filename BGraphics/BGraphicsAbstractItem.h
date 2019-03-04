#ifndef BGRAPHICSABSTRACTITEM_H
#define BGRAPHICSABSTRACTITEM_H

#include "qnanoquickitem.h"
#include <QPen>
#include <QFont>


class BGraphicsAbstractItem : public QNanoQuickItem
{
    Q_OBJECT
    enum ResizePos
    {
        LeftUp,LeftDown,RightUp,RightDown
    };

public:
    BGraphicsAbstractItem(QQuickItem *parent = nullptr);
    virtual ~BGraphicsAbstractItem() = 0;

public:
    void setSelected(bool select);
    bool isSelected() const {return m_isSelected;}
    void setPen(const QPen &pen) {m_pen = pen;}
    QPen pen() const {return m_pen;}
    void setPenScale(qreal scale) {m_penScale = scale;}
    qreal penScale() const {return m_penScale;}
    void setFont(const QFont &font) {m_font = font;}
    QFont font() const {return m_font;}
    void setScaled();
    qreal scaled() const {return m_scale;}
    bool isResizing() const {return m_resizing;}
    void setCornerResizeSize(int size) {m_circleSize = size;}
    int cornerResizeSize() const {return m_circleSize;}

protected:
    void setResizeEnabled(bool enabled) {m_resizeEnable = enabled;}
    bool isResizeEnabled() const {return m_resizeEnable;}

private:
    bool resizeItemAt(const QPointF &pos);

protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void hoverEnterEvent(QHoverEvent *event);
    void hoverLeaveEvent(QHoverEvent *event);
    void hoverMoveEvent(QHoverEvent *event);

private:
    bool    m_isSelected;
    QPointF m_pressPos;
    // resize
    ResizePos m_resizePos;
    int m_circleSize;
    bool m_resizing;
    bool m_resizeEnable;
    QPointF m_resizeFixPos;
    // painting
    QPen    m_pen;
    QFont   m_font;
    // scale
    qreal   m_parentOldWidth = 0.0;
    qreal   m_parentOldHeight = 0.0;
    qreal   m_penScale = 1.0;
    qreal   m_scale = 1.0;

protected:
    friend class BGraphicsAbstractPainter;
    QPointF m_beginPos;
    QPointF m_endPos;
};

#endif // BGRAPHICSABSTRACTITEM_H
