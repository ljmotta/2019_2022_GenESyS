#ifndef MAPKERNELANDUI_H
#define MAPKERNELANDUI_H

#include <map>
#include "../../../RebornedGenESyS/Model.h"
#include "../../../RebornedGenESyS/ModelElement.h"
#include <QObject>
#include <QGraphicsItem>

class MapKernelAndUI
{
public:
	MapKernelAndUI();
public:
	void map(Model* model, QObject* uiObj);
	void unmap(Model* model, QObject* uiObj);
	void map(ModelElement* elem, QGraphicsItem* uiObj);
	void unmap(ModelElement* elem, QGraphicsItem* uiObj);
	QObject* getUI(Model* model);
	Model* getModel(QObject* uiObj);
	QGraphicsItem* getUI(ModelElement* elem);
	ModelElement* getElem(QGraphicsItem* uiObj);
private:
	std::map<Model*, QObject*> _mapModelQObj;
	std::map<QObject*, Model*> _mapQObjModel;
	std::map<ModelElement*, QGraphicsItem*> _mapElemQObj;
	std::map<QGraphicsItem*, ModelElement*> _mapQObjElem;
};

#endif // MAPKERNELANDUI_H
