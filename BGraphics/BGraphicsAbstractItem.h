#ifndef BGRAPHICSABSTRACTITEM_H
#define BGRAPHICSABSTRACTITEM_H

#include "qnanoquickitem.h"
#include <QPen>
#include <QFont>


class BGraphicsAbstractItem : public QNanoQuickItem
{
    Q_OBJECT
public:
    BGraphicsAbstractItem(QQuickItem *parent = nullptr);
    virtual ~BGraphicsAbstractItem() = 0;

public:
    void setSelected(bool select);
    bool isSelected() const {return m_isSelected;}
    void setPen(const QPen &pen) {m_pen = pen;}
    QPen pen() const {return m_pen;}
    void setFont(const QFont &font) {m_font = font;}
    QFont font() const {return m_font;}

protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

private:
    bool    m_isSelected;
    QPointF m_pressPos;
    QPen    m_pen;
    QFont   m_font;

};

#endif // BGRAPHICSABSTRACTITEM_H
