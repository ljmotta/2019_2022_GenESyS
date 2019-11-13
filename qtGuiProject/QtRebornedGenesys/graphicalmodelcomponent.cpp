#include "graphicalmodelcomponent.h"

GraphicalModelComponent::GraphicalModelComponent(ModelComponent* modelComponent)
{
	_modelComponent = modelComponent;
}

ModelComponent*GraphicalModelComponent::modelComponent() const
{
	return _modelComponent;
}
