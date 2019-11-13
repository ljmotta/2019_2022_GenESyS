#ifndef GRAPHICALMODEL_H
#define GRAPHICALMODEL_H

#include "../RebornedGenESyS/Model.h"

class GraphicalModel
{
public:
	GraphicalModel(Model* model);
	Model*model() const;

private:
	Model* _model;
};

#endif // GRAPHICALMODEL_H
