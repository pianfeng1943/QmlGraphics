#include "BGraphicsAbstractPainter.h"
#include "BGraphicsAbstractItem.h".h"



BGraphicsAbstractPainter::BGraphicsAbstractPainter()
{

}

BGraphicsAbstractPainter::~BGraphicsAbstractPainter()
{

}

void BGraphicsAbstractPainter::synchronize(QNanoQuickItem *item)
{
    BGraphicsAbstractItem *pItem = static_cast<BGraphicsAbstractItem*>(item);
    if (pItem)
    {
        m_isSelected = pItem->isSelected();
        m_pen = pItem->pen();
        m_font = pItem->font();
    }
}
