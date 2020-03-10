#include "graphicalmodelcomponent.h"
#include <QPainter>
#include <QPen>
#include <QGradient>
#include <QFontMetrics>
#include <QLinearGradient>

GraphicalModelComponent::GraphicalModelComponent(ModelComponent* modelComponent)
{
	_modelComponent = modelComponent;
	this->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsFocusable);
	this->setOpacity(0.85);
}


ModelComponent* GraphicalModelComponent::modelComponent() const
{
	return _modelComponent;
}


void GraphicalModelComponent::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	int penW=2, recL=connW, recR=recW+connW, recT=connH, recB=recH+connH;
	float radround;
	// set general
	radround= recW>recH?recH*0.05:recW*0.05;
	QPen pen(QBrush(Qt::black, Qt::SolidPattern), penW);
	painter->setPen(pen);
	QLinearGradient lgrad(recL,recT,recR,recB);
	lgrad.setColorAt(0.0, Qt::yellow);
	lgrad.setColorAt(1.0, Qt::red);
	QBrush compBrush(lgrad);
	// boundingRect
	painter->drawRoundedRect(recL,recT,recR,recB, radround, radround);
	// comp name
	QFont font;
	font.setBold(true);
	int fpsize = font.pointSize();
	font.setPointSize(fpsize+2);
	painter->setFont(font);
	QFontMetrics fmet(font);
	int fH = fmet.height();
	int ypos = connH;
	painter->drawText(QRect(recL+margin,ypos,recR-margin,ypos+fH), Qt::AlignCenter|Qt::AlignTop, QString::fromStdString(_modelComponent->name()));
	ypos += fH+penW + margin;
	painter->drawLine(recL,ypos, recR,ypos);
	font.setBold(false);
	font.setPointSize(fpsize-2);
	painter->setFont(font);
	ypos += margin;
	// attributes
	painter->drawText(QRect(recL+margin,ypos,recR-margin,ypos+fH), Qt::AlignLeft|Qt::AlignTop, QString::fromStdString(_modelComponent->show()));
	// connectors
}

QRectF GraphicalModelComponent::boundingRect() const
{
	return QRectF(0,0,recW+2*connW,recH+2*connH);
}

// protected

/*
void GraphicalModelComponent::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
}

void GraphicalModelComponent::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{

}
*/
