#ifndef BGRAPHICSSCENE_H
#define BGRAPHICSSCENE_H

#include <QQuickItem>
#include <QVector>
#include <QPointer>


class BGraphicsAbstractItem;
class BGraphicsScene : public QQuickItem
{
    Q_OBJECT
public:
    enum SceneMode
    {
        Unknown = -1,
        Normal = 0,
        Pen,
        Light,
        Eraser,
        Text,
        Line,
        Rect,
        Ellipse,
    };

public:
    BGraphicsScene(QQuickItem *parent = nullptr);

public:
    Q_INVOKABLE void setNormalMode();
    Q_INVOKABLE void setPenMode(int width, const QColor &color);
    Q_INVOKABLE void setLightMode();
    Q_INVOKABLE void setShapeMode(int type, int width, const QColor &color);
    Q_INVOKABLE void setTextMode(const QFont &font, const QColor &color);
    Q_INVOKABLE void setEraserMode();

private:
    void onDealEraser(const QPoint &pos);
    void setItemsAcceptedMouse(bool enabled);
    void setItemsNormal();

protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE Q_DECL_FINAL;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE Q_DECL_FINAL;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE Q_DECL_FINAL;
    void hoverMoveEvent(QHoverEvent *event) Q_DECL_OVERRIDE Q_DECL_FINAL;

private:
    SceneMode m_mode;
    QPointer<BGraphicsAbstractItem> m_pItem;
    QPoint m_posPressed;
    QColor m_penColor;
    int m_penWidth;
    QColor m_shapeColor;
    int m_shapeWidth;
};

#endif // BGRAPHICSSCENE_H
