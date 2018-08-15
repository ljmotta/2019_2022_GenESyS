/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AttributeValue.h
 * Author: cancian
 *
 * Created on 21 de Junho de 2018, 16:36
 */

#ifndef ATTRIBUTEVALUE_H
#define ATTRIBUTEVALUE_H

class AttributeValue {
public:
	AttributeValue();
	AttributeValue(const AttributeValue& orig);
	virtual ~AttributeValue();
    void setValue(double value);
    double getValue() const;
private:
	/* TODO +-: not all atrributes are double. It shoud be 'templatezided'? */
	double value = 0.0; 
};

#endif /* ATTRIBUTEVALUE_H */

