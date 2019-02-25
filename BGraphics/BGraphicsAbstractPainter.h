#ifndef BGRAPHICSABSTRACTPAINTER_H
#define BGRAPHICSABSTRACTPAINTER_H

#include "qnanoquickitempainter.h"
#include "qnanopainter.h"
#include <QPen>
#include <QFont>



class BGraphicsAbstractPainter : public QObject, public QNanoQuickItemPainter
{
    Q_OBJECT
public:
    BGraphicsAbstractPainter();
    virtual ~BGraphicsAbstractPainter() = 0;

    virtual void synchronize(QNanoQuickItem *item);

protected:
    bool    m_isSelected;
    QPen    m_pen;
    QFont   m_font;
    QPointF m_beginPos;
    QPointF m_endPos;
};

#endif // BGRAPHICSABSTRACTPAINTER_H
