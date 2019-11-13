#ifndef GRAPHICALMODELCOMPONENT_H
#define GRAPHICALMODELCOMPONENT_H

#include <QWidget>
#include "../RebornedGenESyS/ModelComponent.h"

class GraphicalModelComponent
{
public:
	GraphicalModelComponent(ModelComponent* modelComponent);
	ModelComponent*modelComponent() const;

private:
	QWidget* _qtcomponent;
	ModelComponent* _modelComponent;
};

#endif // GRAPHICALMODELCOMPONENT_H
