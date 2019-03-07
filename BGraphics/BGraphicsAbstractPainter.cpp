#include "BGraphicsAbstractPainter.h"
#include "BGraphicsAbstractItem.h"



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
        m_beginPos = pItem->m_beginPos;
        m_endPos = pItem->m_endPos;
        m_penWidth = pItem->m_penWidth;
        m_penScale = pItem->penScale();
        m_scale = pItem->scaled();
    }
}
