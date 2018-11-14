/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Seize.cpp
 * Author: cancian
 * 
 * Created on 21 de Agosto de 2018, 16:17
 */

#include "Seize.h"
#include "WaitingResource.h"

Seize::Seize(Model* model) : ModelComponent(model) {
	_name = "Seize " + std::to_string(Util::GenerateNewIdOfType<Seize>());
	// look for a resource with a default new name
	std::string defaultResourceName = "Resource " + std::to_string(Util::GenerateNewIdOfType<Resource>());
	_resource = (Resource*) _model->getInfraManager()->getInfrastructure(Util::TypeOf<Resource>(), defaultResourceName);
	if (_resource == nullptr) { // it does not exist. Simply creates a new resource infra
		_resource = new Resource(_model);
		_resource->setName(defaultResourceName);
		_model->getInfraManager()->insertInfrastructure(Util::TypeOf<Resource>(), _resource); // inserts the new resource as infrastructure
	}
	std::string queueName = _resource->getName() + "_Queue"; // resourceName + "_Queue";
	_queue = (Queue*) _model->getInfraManager()->getInfrastructure(Util::TypeOf<Queue>(), queueName);
	if (_queue == nullptr) {
		_queue = new Queue(model);
		_queue->setName(_name + "_Queue");
		_model->getInfraManager()->insertInfrastructure(Util::TypeOf<Queue>(), _queue);
	}
}

Seize::Seize(const Seize& orig) : ModelComponent(orig) {
}

std::string Seize::show() {
	return ModelComponent::show() +
			",resourceType=" + std::to_string(static_cast<int>(this->_resourceType)) +
			",resource=\"" + this->_resource->getName()+"\""+
			",quantity=" + this->_quantity;
}

void Seize::setLastMemberSeized(unsigned int _lastMemberSeized) {
	this->_lastMemberSeized = _lastMemberSeized;
}

unsigned int Seize::getLastMemberSeized() const {
	return _lastMemberSeized;
}

void Seize::setSaveAttribute(std::string _saveAttribute) {
	this->_saveAttribute = _saveAttribute;
}

std::string Seize::getSaveAttribute() const {
	return _saveAttribute;
}

void Seize::setRule(Resource::ResourceRule _rule) {
	this->_rule = _rule;
}

Resource::ResourceRule Seize::getRule() const {
	return _rule;
}

void Seize::setQuantity(std::string _quantity) {
	this->_quantity = _quantity;
}

std::string Seize::getQuantity() const {
	return _quantity;
}

void Seize::setResourceType(Resource::ResourceType _resourceType) {
	this->_resourceType = _resourceType;
}

Resource::ResourceType Seize::getResourceType() const {
	return _resourceType;
}

void Seize::setPriority(unsigned short _priority) {
	this->_priority = _priority;
}

unsigned short Seize::getPriority() const {
	return _priority;
}

void Seize::setAllocationType(unsigned int _allocationType) {
	this->_allocationType = _allocationType;
}

unsigned int Seize::getAllocationType() const {
	return _allocationType;
}

void Seize::setQueueName(std::string _queueName) {
	if (_queue->getName() != _queueName) {
		Queue* queueNewName = (Queue*) _model->getInfraManager()->getInfrastructure(Util::TypeOf<Queue>(), _queueName);
		if (queueNewName == nullptr) { // there is no queue with the new name
			if (!_queue->isLinked()) { // no one else uses it. Only change the name
				_queue->setName(_queueName);
			} else { // it is linked. Create a new one
				_queue = new Queue(_model);
				_queue->setName(_queueName);
			}
		} else { // there is another queue with the same name
			if (!_queue->isLinked()) { // no one else uses it. It can be removed
				_model->getInfraManager()->removeInfrastructure(Util::TypeOf<Queue>(), _queue);
				//_queue->~Queue();
			} else { // there is another one using the queue with old name. Let it there
				_queue->removeLink();
			}
			_queue = queueNewName;
			_queue->addLink();
		}
	}
}

void Seize::setResourceName(std::string _resourceName) {
	if (_resource->getName() != _resourceName) {
		Resource* resourceWithTheNewName = (Resource*) _model->getInfraManager()->getInfrastructure(Util::TypeOf<Resource>(), _resourceName);
		if (resourceWithTheNewName == nullptr) { // there is no resource with the new name
			if (!_resource->isLinked()) { // no one else uses it. Only change the name
				_resource->setName(_resourceName);
			} else { // it is linked. Create a new one
				_resource = new Resource(_model);
				_resource->setName(_resourceName);
			}
		} else { // there is another resource with the same name
			if (!_resource->isLinked()) { // no one else uses it. It can be removed
				_model->getInfraManager()->removeInfrastructure(Util::TypeOf<Resource>(), _resource);
				//_resource->~Resource();
			} else { // there is another one using the resource with old name. Let it there
				_resource->removeLink();
			}
			_resource = resourceWithTheNewName;
			_resource->addLink();
		}
	}
}

std::string Seize::getResourceName() const {
	return _resource->getName();
}

std::string Seize::getQueueName() const {
	return _queue->getName();
}

Seize::~Seize() {
}

/*
procedure TModuleManagerSeize.UserExecute(var thisModule:TNewModuleSeize; entity:word);
var nomeRecurso: string;
	i: integer;
	umRecurso: TResource;
	umaFila: TQUEUE;
	setID, recID: word;
	memberIndex: integer;
	esperandoRec: TWaitingResource;
	umaQuantidade: word;
	minBusy, minIndex: integer;
begin
   {Place here the main code of your new component. This code will be executed every}
   {time an entity arrivals to modules of your component}
   {You can use "Genesys." to get access to the simulator's public methods}
   {It's important to verify the logic and consistency of your code to avoid unexpected}
   {behaviours in the simulator}
   {Example: (The following code just prints the ID of the entity and sends it to the}
   {next module in the model)}
   {Genesys.Model.TraceSimulation(cTLModuleIntern, thisModule.ID, entity, 'The entity ID '+IntToStr(entity) + 'is in this module');}
   {Genesys.Model.SIMAN.EntitySendToModuleNumber(entity, thisModule.NextID[0], 0);}
   {... YOUR CODE HERE ...}
   if thisModule.aResourceType = rtSET then begin
	  //pega o nome do recurso no set, conforme a regra estabelecida
	  // TResourceRule = (rrRANDOM, rrCICLICAL, rrESPECIFIC, rrSMALLESTBUSY);
	  setID := Genesys.Model.SIMAN.SetIndex(thisModule.aResourceName);
	  setID := Genesys.Model.SIMAN.SetNumber[setID];
	  case thisModule.aRule of
		 rrRandom: begin
			memberIndex := trunc(random * Genesys.Model.SIMAN.SetMemberCount(setID));
		 end;
		 rrCiclical: begin
			thisModule.aLastMemberSeized := thisModule.aLastMemberSeized + 1;
			if (thisModule.aLastMemberSeized) >= Genesys.Model.SIMAN.SetMemberCount(setID) then
			   thisModule.aLastMemberSeized := 0;
			memberIndex := thisModule.aLastMemberSeized;
		 end;
		 rrEspecific: begin
			memberIndex := trunc(Genesys.Model.SIMAN.StringEvaluateFormula(thisModule.aSaveAttribute));
		 end;
		 rrSmallestBusy: begin
			minBusy := 32535;
			for i := 0 to Genesys.Model.SIMAN.SetMemberCount(setID)-1 do begin
			   nomeRecurso := Genesys.Model.SIMAN.SetMemberName(setID, i);
			   recID := Genesys.Model.SIMAN.ResourceIndex(nomeRecurso);
			   umaQuantidade := Genesys.Model.SIMAN.Resource[recID].NumberBusy;
			   if umaQuantidade < minBusy then begin
				  minBusy := umaQuantidade;
				  minIndex := i;
			   end;
			end;
			memberIndex := minIndex;
		 end;
		 rrLARGESTREMAININGCAPACITY: begin
			minBusy := 0; {max remainging capacity}
			for i := 0 to Genesys.Model.SIMAN.SetMemberCount(setID)-1 do begin
			   nomeRecurso := Genesys.Model.SIMAN.SetMemberName(setID, i);
			   recID := Genesys.Model.SIMAN.ResourceIndex(nomeRecurso);
			   umaQuantidade := Genesys.Model.SIMAN.Resource[recID].Capacity - Genesys.Model.SIMAN.Resource[recID].NumberBusy;
			   if umaQuantidade > minBusy then begin
				  minBusy := umaQuantidade;
				  minIndex := i;
			   end;
			end;
			memberIndex := minIndex;
		 end;
	  end;
	  if (thisModule.aSaveAttribute <> '') and (thisModule.aRule <> rrEspecific) then begin
		 minIndex := Genesys.Model.SIMAN.AttributeIndex(thisModule.aSaveAttribute);
		 Genesys.Model.SIMAN.EntityAttribute[entity,minIndex] := memberIndex;
	  end;
	  nomeRecurso := Genesys.Model.SIMAN.SetMemberName(setID, memberIndex);
	  Genesys.Model.TraceSimulation(cTLModuleIntern, thisModule.ID, entity, 'Choosing member '+IntToStr(memberIndex)+' ('+nomeRecurso+') from set "'+thisModule.aResourceName+'"');
   end else begin
	  nomeRecurso := thisModule.aResourceName;
   end;
   i := Genesys.Model.SIMAN.ResourceIndex(nomeRecurso);
   if i >=0 then begin
	  umRecurso := Genesys.Model.SIMAN.Resource[i];
	  umaQuantidade := Trunc(Genesys.Model.SIMAN.StringEvaluateFormula(thisModule.aQuantity));
	  if (umRecurso.Capacity - umRecurso.NumberBusy) < umaQuantidade then begin
		 //não há instâncias livres suficientes. Coloca a entidade esperando na fila
		 esperandoRec := TWaitingResource.Create(entity, thisModule.ID, umaQuantidade);
		 Genesys.Model.TraceSimulation(cTLModuleIntern, thisModule.ID, entity, 'Entity will be waiting for resource "' +thisModule.aResourceName+ '" at queue "' + umRecurso.QueueName + '"');
		 i := Genesys.Model.SIMAN.QueueIndex(umRecurso.QueueName);
		 if i >= 0 then begin
			umaFila := Genesys.Model.SIMAN.Queue[i];
			umaFila.InsertElement(esperandoRec);
		 end else begin
			Genesys.Model.Trace(cTLError, 'Error: Queue "' + umRecurso.QueueName + '" not found');
		 end;
	  end else begin
		 //há instâncias livres suficientes. Marca a alocação e envia a entidade adiante
		 Genesys.Model.TraceSimulation(cTLModuleIntern, thisModule.ID, entity, 'Entity seizes ' +IntToStr(umaQuantidade)+ ' units of resource "' +thisModule.aResourceName+ '"');
		 umRecurso.Seize(umaQuantidade);
		 {envia adiante}
		 Genesys.Model.SIMAN.EntitySendToModuleNumber(entity, thisModule.NextID[0], 0);
	  end;
   end else begin
	  Genesys.Model.Trace(cTLError, 'Error: Resource "' + nomeRecurso + '" not found');
   end;
end;
 */
void Seize::_execute(Entity* entity) {
	/* TODO +: not implemented yet */
	Resource* resource = nullptr;
	if (this->_resourceType == Resource::ResourceType::SET) {
		/* TODO +: not implemented yet */
	} else {
		resource = this->_resource;
	}
	unsigned int quantity = _model->parseExpression(this->_quantity);
	if (resource->getCapacity() - resource->getNumberBusy() < quantity) { // not enought free quantity to allocate. Entity goes to the queue
		WaitingResource* waitingRec = new WaitingResource(entity, this, _model->getSimulation()->getSimulatedTime(), quantity);
		_model->getTracer()->traceSimulation(Util::TraceLevel::blockInternal, _model->getSimulation()->getSimulatedTime(), entity, this, "Entity starts to wait for resource");
		this->_queue->insertElement(waitingRec); // ->getList()->insert(waitingRec);

	} else { // alocate the resource
		_model->getTracer()->traceSimulation(Util::TraceLevel::blockInternal, _model->getSimulation()->getSimulatedTime(), entity, this, "Entity seizes " + std::to_string(quantity) + " elements of resource \"" + resource->getName() + "\"");
		resource->seize(quantity, _model->getSimulation()->getSimulatedTime());
		_model->sendEntityToComponent(entity, this->getNextComponents()->first(), 0.0);
	}
}

void Seize::_loadInstance(std::list<std::string> words) {

}

std::list<std::string>* Seize::_saveInstance() {
	std::list<std::string>* words = ModelComponent::_saveInstance(Util::TypeOf<Seize>());
	return words;
}

bool Seize::_verifySymbols(std::string* errorMessage) {
	return true;
}