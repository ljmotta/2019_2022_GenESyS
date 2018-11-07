/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OnEventManager.cpp
 * Author: cancian
 * 
 * Created on 7 de Novembro de 2018, 12:28
 */

#include "OnEventManager.h"

OnEventManager::OnEventManager() {
}

OnEventManager::OnEventManager(const OnEventManager& orig) {
}

OnEventManager::~OnEventManager() {
}

void OnEventManager::addOnReplicationStartListener(replicationEventListener eventListener) {
	this->_onReplicationStartListeners->insert(this->_onReplicationStartListeners->end(), eventListener);
}

void OnEventManager::addOnReplicationEndListener(replicationEventListener eventListener) {
	this->_onReplicationEndListeners->insert(this->_onReplicationEndListeners->end(), eventListener);
}
