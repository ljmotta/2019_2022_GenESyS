#ifndef GRAPHICALMODELCOMPONENT_H
#define GRAPHICALMODELCOMPONENT_H

#include <QWidget>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QWidget>
#include "../../ModelComponent.h"
//"../../RebornedGenESyS/ModelComponent.h"

class GraphicalModelComponent : public QGraphicsItem {
public:
	GraphicalModelComponent(ModelComponent* modelComponent);
	ModelComponent* modelComponent() const;

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;
	QRectF boundingRect() const override;

protected:
	//virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
	//virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
private:

private:
	ModelComponent* _modelComponent;
	int recW = 400, recH = 200, connW = 5, connH = 5, penW = 2, margin = 5;
};

#endif // GRAPHICALMODELCOMPONENT_H
