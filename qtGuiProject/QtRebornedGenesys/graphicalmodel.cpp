#include "graphicalmodel.h"

GraphicalModel::GraphicalModel(Model* model)
{
	_model = model;
}

Model*GraphicalModel::model() const
{
	return _model;
}
