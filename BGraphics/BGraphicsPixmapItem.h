#ifndef BGRAPHICSPIXMAPITEM_H
#define BGRAPHICSPIXMAPITEM_H
#include "BGraphicsAbstractItem.h"
#include "BGraphicsAbstractPainter.h"


class BGraphicsPixmapItem : public BGraphicsAbstractItem
{
    Q_OBJECT
public:
    BGraphicsPixmapItem(QQuickItem *parent = nullptr);

    // Reimplement
    QNanoQuickItemPainter *createItemPainter() const Q_DECL_OVERRIDE Q_DECL_FINAL;

public:
    void drawPixmap(float x, float y, const QString &pixmap);

private:
    friend class BGraphicsPixmapPainter;
    QString m_strPixmap;
};

//***************************************************************************//
class BGraphicsPixmapPainter: public BGraphicsAbstractPainter
{
    Q_OBJECT
public:
    BGraphicsPixmapPainter();

    // Reimplement
    void synchronize(QNanoQuickItem *item);
    void paint(QNanoPainter *painter);

private:
    QString m_strPixmap;
};

#endif // BGRAPHICSPIXMAPITEM_H
