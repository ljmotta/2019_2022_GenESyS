/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestMatricesOfAttributesAndVariables.cpp
 * Author: rlcancian
 * 
 * Created on 1 de Novembro de 2019, 18:10
 */

#include "TestMatricesOfAttributesAndVariables.h"
#include "Simulator.h"
#include "SourceModelComponent.h"
#include "Assign.h"
#include "Attribute.h"
#include "Variable.h"
#include "Create.h"
#include "Dispose.h"
#include "Separate.h"

TestMatricesOfAttributesAndVariables::TestMatricesOfAttributesAndVariables() {
}

TestMatricesOfAttributesAndVariables::TestMatricesOfAttributesAndVariables(const TestMatricesOfAttributesAndVariables& orig) {
}

TestMatricesOfAttributesAndVariables::~TestMatricesOfAttributesAndVariables() {
}

int TestMatricesOfAttributesAndVariables::main(int argc, char** argv) {
    Simulator* sim = new Simulator();
    setDefaultTraceHandlers(sim->tracer());
    sim->tracer()->setTraceLevel(Util::TraceLevel::mostDetailed);
    insertFakePluginsByHand(sim);
    Model* m = new Model(sim);
    sim->models()->insert(m);
    Create* create1 = new Create(m);
    Assign* assign1 = new Assign(m);
    //Separate* sep1 = new Separate(m);
    Dispose* dispose1 = new Dispose(m);
    create1->nextComponents()->insert(assign1);
    assign1->nextComponents()->insert(assign1);
    assign1->nextComponents()->insert(dispose1);
    //sep1->nextComponents()->insert(dispose1);
    //sep1>->nextComponents()->insert(assign1);
    create1->setEntityType(new EntityType(m));
    create1->setMaxCreations("1");
    new Attribute(m, "attr1");
    Variable* var1 = new Variable(m, "var1");
    std::string expression, index;
    for (int i = 1; i < 3; i++) {
	for (int j = 1; j < 3; j++) {
	    index = std::to_string(i) + "," + std::to_string(j);
	    var1->setInitialValue(index, 1.0*i + j / 10.0);
	    expression = "attr1[" + index + "] + var1[" + index + "]";
	    assign1->assignments()->insert(new Assign::Assignment("attr1[" + index + "]", expression));
	}
    }
    m->simulation()->start();
    return 0;
}