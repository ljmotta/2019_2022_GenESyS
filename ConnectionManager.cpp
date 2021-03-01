/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConnectionManager.cpp
 * Author: rlcancian
 * 
 * Created on 1 de Julho de 2019, 18:39
 */

#include "ConnectionManager.h"

//using namespace GenesysKernel;

ConnectionManager::ConnectionManager() {
}

unsigned int ConnectionManager::size() {
	return _nextConnections->size();
}

ModelComponent* ConnectionManager::front() {
	return _nextConnections->front()->first;
}

ModelComponent* ConnectionManager::atRank(unsigned int rank) {
	return _nextConnections->getAtRank(rank)->first;
}

Connection* ConnectionManager::frontConnection() {
	return _nextConnections->front();
}

Connection* ConnectionManager::connectionAtRank(unsigned int rank) {
	return _nextConnections->getAtRank(rank);
}

void ConnectionManager::insert(ModelComponent* component, unsigned int inputNumber) {
	_nextConnections->insert(new Connection(component, inputNumber));
	_currentOutputConnections++;
}

void ConnectionManager::insertAtRank(unsigned int rank, Connection* connection) {
	_nextConnections->setAtRank(rank, connection); // \TODO: it does not work if there is less then rank connections
	_currentOutputConnections++;
}

std::list<Connection*>* ConnectionManager::list() const {
	return _nextConnections->list();
}

//void ConnectionManager::setCurrentOutputConnections(unsigned int _currentOutputConnections) {
//    this->_currentOutputConnections = _currentOutputConnections;
//}

unsigned int ConnectionManager::currentOutputConnections() const {
	return _currentOutputConnections;
}

void ConnectionManager::setMaxOutputConnections(unsigned int _maxOutputConnections) {
	this->_maxOutputConnections = _maxOutputConnections;
}

unsigned int ConnectionManager::maxOutputConnections() const {
	return _maxOutputConnections;
}

void ConnectionManager::setMinOutputConnections(unsigned int _minOutputConnections) {
	this->_minOutputConnections = _minOutputConnections;
}

unsigned int ConnectionManager::minOutputConnections() const {
	return _minOutputConnections;
}

//void ConnectionManager::setCurrentInputConnections(unsigned int _currentInputConnections) {
//    this->_currentInputConnections = _currentInputConnections;
//}

unsigned int ConnectionManager::currentInputConnections() const {
	return _currentInputConnections;
}

void ConnectionManager::setMaxInputConnections(unsigned int _maxInputConnections) {
	this->_maxInputConnections = _maxInputConnections;
}

unsigned int ConnectionManager::maxInputConnections() const {
	return _maxInputConnections;
}

void ConnectionManager::setMinInputConnections(unsigned int _minInputConnections) {
	this->_minInputConnections = _minInputConnections;
}

unsigned int ConnectionManager::minInputConnections() const {
	return _minInputConnections;
}
