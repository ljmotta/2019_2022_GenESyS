/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Util.cpp
 * Author: cancian
 * 
 * Created on 21 de Junho de 2018, 13:02
 */

#include "Util.h"

Util::identitifcation Util::_S_lastId = 0;

Util::identitifcation Util::generateNewId() {
	Util::_S_lastId++;
	return Util::_S_lastId;
}
