/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Resource.h
 * Author: cancian
 *
 * Created on 21 de Agosto de 2018, 16:52
 */

#ifndef RESOURCE_H
#define RESOURCE_H

#include "ModelInfrastructure.h"
#include "LinkedBy.h"

class Resource : public ModelInfrastructure, public LinkedBy {
public:

	enum ResourceType {
		rtSET, rtRESOURCE
	};

	enum ResourceRule {
		rrRANDOM, rrCICLICAL, rrESPECIFIC, rrSMALLESTBUSY, rrLARGESTREMAININGCAPACITY
	};

public:
	Resource();
	Resource(const Resource& orig);
	virtual ~Resource();
private:

};

#endif /* RESOURCE_H */

