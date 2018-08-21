/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Resource.cpp
 * Author: cancian
 * 
 * Created on 21 de Agosto de 2018, 16:52
 */

#include "Resource.h"

Resource::Resource() : ModelInfrastructure(typeid (this).name()) {
}

Resource::Resource(const Resource& orig) : ModelInfrastructure(orig) {
}

Resource::~Resource() {
}

