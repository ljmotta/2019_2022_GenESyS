/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Record.h
 * Author: rafael.luiz.cancian
 *
 * Created on 9 de Agosto de 2018, 13:52
 */

#ifndef RECORD_H
#define RECORD_H

#include "../ModelComponent.h"
#include <string>

/*!
 Record module
DESCRIPTION
This module is used to collect statistics in the simulation model. Various types of
observational statistics are available, including time between exits through the
module, entity statistics (such as time or costing), general observations, and interval
statistics (from some time stamp to the current simulation time). A count type of
statistic is available as well. Tally and Counter sets can also be specified.
TYPICAL USES
 Collect the number of jobs completed each hour
 Count how many orders have been late being fulfilled
 Record the time spent by priority customers in the main check-out line
PROMPTS
Prompt Description
Name Unique module identifier displayed on the module shape.
Type Type of observational (tally) or count statistic to be generated.
Count will increase or decrease the value of the named statistic
by the specified value. Entity Statistics will generate general
entity statistics, such as time and costing/duration information.
Time Interval will calculate and record the difference between a
specified attribute’s value and current simulation time. Time
Between will track and record the time between entities entering
the module. Expression will record the value of the specified
expression.
Attribute Name Name of the attribute whose value will be used for the interval
statistics. Applies only when Type is Interval.
Value Value that will be recorded to the observational statistic when
Type is Expression or added to the counter when Type is Count.
Tally Name This field defines the symbol name of the tally into which the
observation is to be recorded. Applies only when Type is Time
Interval, Time Between, or Expression.
Counter This field defines the symbol name of the counter to Name
increment/decrement. Applies only when Type is Counter.
Record into Set Check box to specify whether or not a tally or counter set will be
used.
Tally Set Name Name of the tally set that will be used to record the
observational-type statistic. Applies only when Type is Time
Interval, Time Between, or Expression.
Counter Set Name Name of the counter set that will be used to record the count-type
statistic. Applies only when Type is Count.
Set Index Index into the tally or counter set.
 */
class Record : public ModelComponent {
public:
	Record(Model* model, std::string name = "");
	virtual ~Record();
public:
	void setFilename(std::string filename);
	std::string getFilename() const;
	void setExpression(std::string expression);
	std::string getExpression() const;
	void setExpressionName(std::string expressionName);
	std::string getExpressionName() const;
	StatisticsCollector* getCstatExpression() const;
public:
	virtual std::string show();
public:
	static PluginInformation* GetPluginInformation();
	static ModelComponent* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
	static ModelComponent* CreateInstance(Model* model, std::string name = "");
protected:
	virtual void _execute(Entity* entity);
	virtual bool _loadInstance(std::map<std::string, std::string>* fields);
	virtual void _initBetweenReplications();
	virtual std::map<std::string, std::string>* _saveInstance();
	virtual bool _check(std::string* errorMessage);
private:
	std::string _expression = "";
	std::string _expressionName = "";
	std::string _filename = "";
private:
	// not a child element
	StatisticsCollector* _cstatExpression; /* \todo: Cretae an internal class to agregate ExpressionStatisticsColelctor, and change Record to got a list of it, so Record cn record a set of expressions into a set of files */
};

#endif /* RECORD_H */
