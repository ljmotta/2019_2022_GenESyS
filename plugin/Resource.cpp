/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Resource.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Agosto de 2018, 16:52
 */

#include "Resource.h"


extern "C" StaticGetPluginInformation getPluginInformation() {
	return &Resource::GetPluginInformation;
}
