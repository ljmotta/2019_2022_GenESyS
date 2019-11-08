
#include "mapkernelandui.h"

MapKernelAndUI::MapKernelAndUI()
{

}

void MapKernelAndUI::map(Model* model, QObject* uiObj){
    _mapModelQObj.insert({model,uiObj});
    _mapQObjModel.insert({uiObj,model});
}
void MapKernelAndUI::map(ModelElement* elem, QObject* uiObj){
    _mapElemQObj.insert({elem,uiObj});
    _mapQObjElem.insert({uiObj,elem});
}
void MapKernelAndUI::unmap(Model* model, QObject* uiObj){
    std::map<Model*,QObject*>::iterator it = _mapModelQObj.find(model);
    if (it!=_mapModelQObj.end())
        _mapModelQObj.erase(it);
    std::map<QObject*,Model*>::iterator it2 = _mapQObjModel.find(uiObj);
    if (it2!=_mapQObjModel.end())
        _mapQObjModel.erase(it2);
}
void MapKernelAndUI::unmap(ModelElement* elem, QObject* uiObj){
    std::map<ModelElement*,QObject*>::iterator it = _mapElemQObj.find(elem);
    if (it!=_mapElemQObj.end())
        _mapElemQObj.erase(it);
    std::map<QObject*,ModelElement*>::iterator it2 = _mapQObjElem.find(uiObj);
    if (it2!=_mapQObjElem.end())
        _mapQObjElem.erase(it2);
}

QObject* MapKernelAndUI::getUI(Model* model){
    std::map<Model*,QObject*>::iterator it = _mapModelQObj.find(model);
    if (it!=_mapModelQObj.end())
        return (*it).second;
    return nullptr;
}
QObject* MapKernelAndUI::getUI(ModelElement* elem){
    std::map<ModelElement*,QObject*>::iterator it = _mapElemQObj.find(elem);
    if (it!=_mapElemQObj.end())
        return (*it).second;
    return nullptr;
}
Model* MapKernelAndUI::getModel(QObject* uiObj){
    std::map<QObject*,Model*>::iterator it = _mapQObjModel.find(uiObj);
    if (it!=_mapQObjModel.end())
        return (*it).second;
    return nullptr;
}
ModelElement* MapKernelAndUI::getElem(QObject* uiObj){
    std::map<QObject*,ModelElement*>::iterator it = _mapQObjElem.find(uiObj);
    if (it!=_mapQObjElem.end())
        return (*it).second;
    return nullptr;
}
