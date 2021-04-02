/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Write.h
 * Author: rlcancian
 *
 * Created on 11 de Setembro de 2019, 13:06
 */

#ifndef WRITE_H
#define WRITE_H

#include "ModelComponent.h"

class WriteElement {
public:

	WriteElement(std::string text, bool isExpression = false, bool newline = false) {
		this->text = text;
		this->isExpression = isExpression;
		this->newline = newline;
	}
	std::string text;
	bool isExpression;
	bool newline;
};

/*!
 This component ...
 */
class Write : public ModelComponent {
public:

	enum class WriteToType : int {
		SCREEN = 1, FILE = 2
	};



public: // constructors
	Write(Model* model, std::string name = "");
	virtual ~Write() = default;
public: // virtual
	virtual std::string show();
public: // static
	static PluginInformation* GetPluginInformation();
	static ModelComponent* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
public:
	List<WriteElement*>* writeElements() const;
	void setFilename(std::string _filename);
	std::string filename() const;
	void setWriteToType(WriteToType _writeToType);
	Write::WriteToType writeToType() const;

protected: // virtual
	virtual void _execute(Entity* entity);
	virtual void _initBetweenReplications();
	virtual bool _loadInstance(std::map<std::string, std::string>* fields);
	virtual std::map<std::string, std::string>* _saveInstance();
	virtual bool _check(std::string* errorMessage);
private: // methods
	//std::string _buildText();
private: // attributes 1:1
	WriteToType _writeToType = Write::WriteToType::SCREEN;
	std::string _filename = "";
private: // attributes 1:n
	List<WriteElement*>* _writeElements = new List<WriteElement*>();
};

typedef Write* create_write_t(Model* model, std::string name);
typedef void destroy_write_t(Write* write);

typedef WriteElement* create_write_element_t(std::string text, bool isExpression, bool newline);
typedef void destroy_write_element_t(WriteElement* writeElement);


#endif /* WRITE_H */

