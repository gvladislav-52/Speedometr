#include "speedometr.h"
#include <QPainter>

Speedometr::Speedometr(QQuickItem * parent): QQuickPaintedItem(parent),
    m_SpeedometerSize(500),
    m_StartAngle(50),
    m_AlignAngle(260),
    m_LowestRange(0),
    m_HighestRange(4000),
    m_Speed(1230),
    m_ArcWidth(10),
    m_OuterColor(QColor(126,255,0)),
    m_InnerColor(QColor(51,88,255)),
    m_TextColor(QColor(255,255,255)),
    m_BackgroundColor(Qt::transparent)

{


}

void Speedometr::paint(QPainter *painter)
{
    QRectF rect = this->boundingRect();
    painter->setRenderHint(QPainter::Antialiasing);
    QPen pen = painter->pen();
    pen.setCapStyle(Qt::FlatCap);

    double startAngle;
    double spanAngle;

    startAngle = m_StartAngle - 40;
    spanAngle = 0 - m_AlignAngle;

    //all arc
    painter->save();
    pen.setWidth(m_ArcWidth);
    pen.setColor(m_InnerColor);
    painter->setPen(pen);
    //painter->drawRect(rect);
    painter->drawArc(rect.adjusted(m_ArcWidth,m_ArcWidth,-m_ArcWidth, -m_ArcWidth),startAngle * 16, spanAngle * 16);
    painter->restore();

    //inner pie
    int pieSize = m_SpeedometerSize/5;
    painter->save();
    pen.setWidth(m_ArcWidth/2);
    pen.setColor(m_OuterColor);
    painter->setBrush(m_InnerColor);
    painter->setPen(pen);
    painter->drawPie(rect.adjusted(pieSize,pieSize,-pieSize,-pieSize),startAngle*16,spanAngle*16);
    painter->restore();

    //text which shows the value
    painter->save();
    QFont font("Halvetica",52, QFont::Bold);
    painter->setFont(font);
    pen.setColor(m_TextColor);
    painter->setPen(pen);
    painter->drawText(rect.adjusted(m_SpeedometerSize/30,m_SpeedometerSize/30,-m_SpeedometerSize/30, -m_SpeedometerSize/4),
                      Qt::AlignCenter,QString::number ((m_Speed/40),'f',1));
    painter->restore();

    //current active process
    painter->save();
    pen.setWidth(m_ArcWidth);
    pen.setColor(m_OuterColor);
    qreal valueToAngle = ((m_Speed - m_LowestRange)/(m_HighestRange - m_LowestRange)) * spanAngle;
    painter->setPen(pen);
    painter->drawArc(rect.adjusted(m_ArcWidth, m_ArcWidth, -m_ArcWidth, -m_ArcWidth),startAngle * 16, valueToAngle * 16);
    painter->restore();

}

qreal Speedometr::getSpeedometerSize()
{
    return m_SpeedometerSize;
}

qreal Speedometr::getStartAngle()
{
    return m_StartAngle;
}

qreal Speedometr::getAlignAngle()
{
    return m_AlignAngle;
}

qreal Speedometr::getLowestRange()
{
    return m_LowestRange;
}

qreal Speedometr::getHighestRange()
{
    return m_HighestRange;
}

qreal Speedometr::getSpeed()
{
    return m_Speed;
}

int Speedometr::getArcWidth()
{
    return m_ArcWidth;
}

QColor Speedometr::getOuterColor()
{
    return m_OuterColor;
}

QColor Speedometr::getInnerColor()
{
    return m_InnerColor;
}

QColor Speedometr::getTextColor()
{
    return m_TextColor;
}

QColor Speedometr::getBackgroundColor()
{
    return m_BackgroundColor;
}

void Speedometr::setSpeedometerSize(qreal size)
{
    if(m_SpeedometerSize == size)
        return;

    m_SpeedometerSize = size;
    emit speedometerSizeChanged();      //this will call the qml part
}

void Speedometr::setStartAngle(qreal startAngle)
{
    if(m_StartAngle == startAngle)
        return;

    m_StartAngle = startAngle;
    emit startAngleChanged();
}

void Speedometr::setAlignAngle(qreal angle)
{
    if(m_StartAngle == angle)
        return;

    m_StartAngle = angle;
    emit alignAngleChanged();
}

void Speedometr::setLowestRange(qreal lowestRange)
{
    if(m_LowestRange == lowestRange)
        return;

    m_LowestRange = lowestRange;
    emit lowestRangeChanged();
}

void Speedometr::setHighestRange(qreal highestRange)
{
    if(m_HighestRange == highestRange)
        return;

    m_HighestRange = highestRange;
    emit highestRangeChanged();
}

void Speedometr::setSpeed(qreal speed)
{
    if(m_Speed == speed)
        return;

    m_Speed = speed;
    update();
    emit speedChanged();
}

void Speedometr::setArcWidth(int arcWidth)
{
    if(m_ArcWidth == arcWidth)
        return;

    m_ArcWidth = arcWidth;
    emit arcWidthChanged();
}

void Speedometr::setOuterColor(QColor outerColor)
{
    if(m_OuterColor == outerColor)
        return;

    m_OuterColor = outerColor;
    emit outerColorChanged();
}

void Speedometr::setInnerColor(QColor innerColor)
{
    if(m_InnerColor == innerColor)
        return;

    m_InnerColor = innerColor;
    emit innerColorChanged();
}

void Speedometr::setTextColor(QColor textColor)
{
    if(m_TextColor == textColor)
        return;

    m_TextColor = textColor;
    emit textColorChanged();
}

void Speedometr::setBackgroundColor(QColor backgroundColor)
{
    if(m_BackgroundColor == backgroundColor)
        return;

    m_BackgroundColor = backgroundColor;
    emit backgroundColorChanged();
}



