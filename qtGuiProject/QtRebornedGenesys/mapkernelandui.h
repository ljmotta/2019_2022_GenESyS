#ifndef MAPKERNELANDUI_H
#define MAPKERNELANDUI_H

#include <map>
#include "../RebornedGenESyS/Model.h"
#include "../RebornedGenESyS/ModelElement.h"
#include <QObject>

class MapKernelAndUI
{
public:
    MapKernelAndUI();
public:
    void map(Model* model, QObject* uiObj);
    void map(ModelElement* elem, QObject* uiObj);
    void unmap(Model* model, QObject* uiObj);
    void unmap(ModelElement* elem, QObject* uiObj);
    QObject* getUI(Model* model);
    QObject* getUI(ModelElement* elem);
    Model* getModel(QObject* uiObj);
    ModelElement* getElem(QObject* uiObj);
private:
    std::map<Model*, QObject*> _mapModelQObj;
    std::map<ModelElement*, QObject*> _mapElemQObj;
    std::map<QObject*, Model*> _mapQObjModel;
    std::map<QObject*, ModelElement*> _mapQObjElem;
};

#endif // MAPKERNELANDUI_H
