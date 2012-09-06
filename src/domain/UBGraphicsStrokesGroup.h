#ifndef UBGRAPHICSSTROKESGROUP_H
#define UBGRAPHICSSTROKESGROUP_H

#include <QGraphicsItemGroup>
#include <QGraphicsSceneMouseEvent>

#include "core/UB.h"
#include "UBItem.h"

class UBGraphicsStrokesGroup : public QObject, public QGraphicsItemGroup, public UBItem, public UBGraphicsItem
{
    Q_OBJECT
public:
    enum colorType {
        currentColor = 0
        , colorOnLightBackground
        , colorOnDarkBackground
    };

    UBGraphicsStrokesGroup(QGraphicsItem* parent = 0);
    ~UBGraphicsStrokesGroup();
    virtual UBItem* deepCopy() const;
    virtual void copyItemParameters(UBItem *copy) const;
    enum { Type = UBGraphicsItemType::StrokeItemType };
    virtual int type() const
    {
        return Type;
    }
    virtual void setUuid(const QUuid &pUuid);
    void setColor(const QColor &color, colorType pColorType = currentColor);
    QColor color(colorType pColorType = currentColor) const;

protected:

    virtual QPainterPath shape () const;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);
};

#endif // UBGRAPHICSSTROKESGROUP_H
