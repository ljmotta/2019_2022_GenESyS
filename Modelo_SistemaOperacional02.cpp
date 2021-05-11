/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Modelo_SistemasOperacionais02.cpp
 * Author: rlcancian
 *
 * Created on 12 de abril de 2021, 21:54
 */

#include "Modelo_SistemaOperacional02.h"

#include "Simulator.h"
#include "Model.h"
//#include "Route.h"
#include "Enter.h"

//#include "EntityType.h"
//#include "Queue.h"
#include "SeizableItemRequest.h"
//#include "Station.h"
#include "Attribute.h"

Modelo_SistemaOperacional02::Modelo_SistemaOperacional02() {
}

int Modelo_SistemaOperacional02::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();

	PluginManager* pluginManager = genesys->getPlugins();

	pluginManager->insert("enter.so");
	pluginManager->insert("station.so");
	
	StaticComponentConstructor create = pluginManager->insert("create.so")->getPluginInfo()->GetComponentConstructor();
	StaticComponentConstructor assign = pluginManager->insert("assign.so")->getPluginInfo()->GetComponentConstructor();
	StaticComponentConstructor decide = pluginManager->insert("decide.so")->getPluginInfo()->GetComponentConstructor();
	StaticComponentConstructor seize = pluginManager->insert("seize.so")->getPluginInfo()->GetComponentConstructor();
	StaticComponentConstructor delay = pluginManager->insert("delay.so")->getPluginInfo()->GetComponentConstructor();
	StaticComponentConstructor release = pluginManager->insert("release.so")->getPluginInfo()->GetComponentConstructor();
	StaticComponentConstructor dispose = pluginManager->insert("dispose.so")->getPluginInfo()->GetComponentConstructor();
	StaticComponentConstructor route = pluginManager->insert("route.so")->getPluginInfo()->GetComponentConstructor();

	StaticElementConstructor queue = pluginManager->insert("queue.so")->getPluginInfo()->getElementConstructor();
	StaticElementConstructor resource = pluginManager->insert("resource.so")->getPluginInfo()->getElementConstructor();
	StaticElementConstructor set = pluginManager->insert("set.so")->getPluginInfo()->getElementConstructor();

	this->setDefaultTraceHandlers(genesys->getTracer());
	Model* model = genesys->getModels()->newModel();
	//
	// CREATE Processo é criado no computador
	EntityType* et = new EntityType(model, "processo");
	Create* createProc = (Create*) create(model, "");
	createProc->setDescription("Processo é criado no computador");
	createProc->setEntityType(et);
	createProc->setTimeBetweenCreationsExpression("expo(10)");
	createProc->setTimeUnit(Util::TimeUnit::milisecond);
	//
	// ASSIGN Define tempo de execução e memória ocupada
	Assign* assignProc = (Assign*) assign(model, "");
	assignProc->setDescription("Define tempo de execução e memória ocupada");
	assignProc->getAssignments()->insert(new Assign::Assignment("memoriaOcupada", "TRUNC(UNIF(2,32))"));
	assignProc->getAssignments()->insert(new Assign::Assignment("tempoExecucao", "NORM(5,1) * memoriaOcupada/10"));
	// atributos (não precisa guardar objetos se não for usar)
	new Attribute(model, "memoriaOcupada");
	new Attribute(model, "tempoExecucao");

	createProc->getNextComponents()->insert(assignProc);
	//
	// SEIZE memoria
	Resource* memoria = (Resource*) resource(model, "memoria");
	memoria->setCapacity(64);
	Queue* queueMem = (Queue*) queue(model, "Fila_Alocacao_Memoria");
	Seize* seizeMem = (Seize*) seize(model, "");
	seizeMem->setDescription("Processo aloca memória");
	seizeMem->setQueue(queueMem);
	seizeMem->getSeizeRequests()->insert(new SeizableItemRequest(memoria, "memoriaOcupada"));

	assignProc->getNextComponents()->insert(seizeMem);
	//
	// ROUTE Processo é enviado para execução na CPU
	Station* stationExecucao = new Station(model, "Estacao_de_Execucao");
	Route* routeExecucao1 = (Route*) route(model, "");
	routeExecucao1->setDescription("Processo é enviado para execução na CPU");
	routeExecucao1->setStation(stationExecucao);

	seizeMem->getNextComponents()->insert(routeExecucao1);
	//
	// ENTER Processo chega para ser executado
	Enter* enterStationExecucao = new Enter(model);
	enterStationExecucao->setDescription("Processo chega para ser executado");
	enterStationExecucao->setStation(stationExecucao);
	//
	// SEIZE Processo aloca CPU
	Resource* cpu = (Resource*) resource(model, "CPU");
	Queue* queueCPU = (Queue*) queue(model, "Fila_CPU");
	Seize* seizeCPU = (Seize*) seize(model, "");
	seizeCPU->setDescription("Processo aloca CPU");
	seizeCPU->setQueue(queueCPU);
	seizeCPU->getSeizeRequests()->insert(new SeizableItemRequest(cpu, "1"));

	enterStationExecucao->getNextComponents()->insert(seizeCPU);
	//
	// DECIDE Define tempo de execução da fatia de tempo atual
	Decide* decideFatiaTempo = (Decide*) decide(model, "");
	decideFatiaTempo->setDescription("Define tempo de execução da fatia de tempo atual");
	decideFatiaTempo->getConditions()->insert("tempoExecucao >= 1");

	seizeCPU->getNextComponents()->insert(decideFatiaTempo);
	//
	// ASSIGN Define execucao por um quantum de tempo
	Assign* assignExecFatia = (Assign*) assign(model, "");
	assignExecFatia->setDescription("Define execucao por um quantum de tempo");
	assignExecFatia->getAssignments()->insert(new Assign::Assignment("fatiaTempo", "1"));
	assignExecFatia->getAssignments()->insert(new Assign::Assignment("tempoExecucao", "tempoExecucao-fatiaTempo"));
	new Attribute(model, "fatiaTempo");

	decideFatiaTempo->getNextComponents()->insert(assignExecFatia);
	//
	// ASSIGN Executa até o final
	Assign* assignExecAteFinal = (Assign*) assign(model, "");
	assignExecAteFinal->setDescription("Executa até o final");
	assignExecAteFinal->getAssignments()->insert(new Assign::Assignment("fatiaTempo", "tempoExecucao"));
	assignExecAteFinal->getAssignments()->insert(new Assign::Assignment("tempoExecucao", "tempoExecucao - fatiaTempo"));

	decideFatiaTempo->getNextComponents()->insert(assignExecAteFinal);
	//
	// DELAY Processo executa na CPU
	Delay* delayProcExecCPU = (Delay*) delay(model, "");
	delayProcExecCPU->setDescription("Processo executa na CPU");
	delayProcExecCPU->setDelayExpression("fatiaTempo");
	delayProcExecCPU->setDelayTimeUnit(Util::TimeUnit::milisecond);

	assignExecFatia->getNextComponents()->insert(delayProcExecCPU);
	assignExecAteFinal->getNextComponents()->insert(delayProcExecCPU);
	//
	// RELEASE Processo libera CPU
	Release* releaseCPU = (Release*) release(model, "");
	releaseCPU->setDescription("Processo libera CPU");
	releaseCPU->getReleaseRequests()->insert(new SeizableItemRequest(cpu, "1"));

	delayProcExecCPU->getNextComponents()->insert(releaseCPU);
	//
	// DECIDE Se processo ainda precisa executar então vai para estação de execução
	Decide* decideAindaExec = (Decide*) decide(model, "");
	decideAindaExec->setDescription("Se processo ainda precisa executar então vai para estação de execução");
	decideAindaExec->getConditions()->insert("tempoExecucao > 0");

	releaseCPU->getNextComponents()->insert(decideAindaExec);
	//
	// ROUTE Processo é enviado de volta para execução
	Route* routeExecucao2 = (Route*) route(model, "");
	routeExecucao2->setDescription("Processo é enviado de volta para execução");
	routeExecucao2->setStation(stationExecucao);

	decideAindaExec->getNextComponents()->insert(routeExecucao2);
	// ROUTE Processo é enviado para liberar memória
	Station* stationLiberaMem = new Station(model, "Estacao_de_liberacao_de_memoria");
	Route* routeLiberaMem = (Route*) route(model, "");
	routeLiberaMem->setDescription("Processo é enviado para liberar memória");
	routeLiberaMem->setStation(stationLiberaMem);

	decideAindaExec->getNextComponents()->insert(routeLiberaMem);
	//
	// ENTER Processo chega para liberar memória
	Enter* enterStationLibera = new Enter(model);
	enterStationLibera->setDescription("Processo chega para liberar memória");
	enterStationLibera->setStation(stationLiberaMem);
	//
	// RELEASE 	Processo libera memória
	Release* releaseMem = (Release*) release(model, "");
	releaseMem->setDescription("Processo libera memória");
	releaseMem->getReleaseRequests()->insert(new SeizableItemRequest(memoria, "memoriaOcupada"));

	enterStationLibera->getNextComponents()->insert(releaseMem);
	//
	// DISPOSE Processo é encerrado
	Dispose* disp1 = (Dispose*) dispose(model, "");
	disp1->setDescription("Processo é encerrado");

	releaseMem->getNextComponents()->insert(disp1);

	//
	// AJUSTA EXPERIMENTO (MODEL SIMULATION)
	ModelSimulation* sim = model->getSimulation();
	sim->setReplicationLength(1e3);
	sim->setReplicationLengthTimeUnit(Util::TimeUnit::milisecond);
	sim->setNumberOfReplications(30);
	sim->setPauseOnReplication(true);
	// AJUSTA NÍVEL DE TRACE
	genesys->getTracer()->setTraceLevel(Util::TraceLevel::L3_results);
	// SALVA MODELO
	model->save("./models/SistemaOperacional02.txt");
	// EXECUTA CADA REPLICAÇÃO, RECOMEÇANDO APÓS CADA PAUSA
	do {
		sim->start();
	} while (sim->isPaused());
	return 0;
}
