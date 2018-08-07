/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plugin.h
 * Author: cancian
 *
 * Created on 21 de Junho de 2018, 12:58
 */

#ifndef PLUGIN_H
#define PLUGIN_H

#include "Util.h"
#include <string>

class Plugin {
public:
	Plugin(std::string name, bool source, bool drain);
	Plugin(const Plugin& orig);
	virtual ~Plugin();
    bool isDrain() const;
    bool isSource() const;
public: // get & set

private: // read only
	std::string _fullfilename;
	bool _source;
	bool _drain;
};

#endif /* PLUGIN_H */

