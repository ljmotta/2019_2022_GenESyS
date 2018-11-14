/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SamplerDanielBoso.h
 * Author: Daniel Boso
 * 
 * Created on October 18, 2018 at 23:06
 */

#include <stdlib.h>
#include "fstream"
#include <math.h>
#include <string>
#include <iostream>
#include <stdio.h>

#include "StatisticsDanielBoso.h"

StatisticsDanielBoso::StatisticsDanielBoso() { }

StatisticsDanielBoso::StatisticsDanielBoso(const StatisticsDanielBoso& orig) { }

StatisticsDanielBoso::~StatisticsDanielBoso() { }

int compare(const void *a, const void *b) {
    if(*(double*)a > *(double*)b) {
        return 1;
    } else if (*(double*)a < *(double*)b) {
        return -1;
    } else {
        return 0;
    }
 }

void StatisticsDanielBoso::getSamplesAndSort(std::list<double>* listSamples) {    
    std::ifstream ifstream;
   
    ifstream.open(((CollectorDatafile_if*)_collector)->getDataFilename(), std::ifstream::in);
    std::string value;
    
     while(std::getline(ifstream, value)) {
        listSamples->push_back(std::stod(value));
    }
    
    ifstream.close();
    
    listSamples->sort();
}

unsigned int StatisticsDanielBoso::numElements() {
    _collector->numElements();
}

double StatisticsDanielBoso::min() {
    std::ifstream ifstream;
    ifstream.open(((CollectorDatafile_if*)_collector)->getDataFilename(), std::ios::out | std::ios::app);
    std::string value;
    std::getline(ifstream, value); 
    double min = std::stod(value);
    
    while(std::getline(ifstream, value)) {
        if(min > std::stod(value)) {
            min = std::stod(value);
        }
    }
    return min;
}

double StatisticsDanielBoso::max() {
    std::ifstream ifstream;
    ifstream.open(((CollectorDatafile_if*)_collector)->getDataFilename(), std::ios::out | std::ios::app);
    std::string value;
    std::getline(ifstream, value);
    double max = std::stod(value);
    
    while(std::getline(ifstream, value)) {
        if(max < std::stod(value)) {
            max = std::stod(value);
        }
    }
    return max;
}

double calculate_average(std::ifstream &input, unsigned int nValue, unsigned int nElements) {
//    return (averageBefore+ nextNumber)/2;
    std::string value;
    std::getline(input, value);
    double sample = std::stod(value);
    if (nValue == nElements) {
        return sample;
    }
    
    if (nValue == 1) {
        return (2*calculate_average(input, ++nValue,nElements) + sample)/3;
    } else {
        double result = ((nValue-1)*(calculate_average(input, nValue+1,nElements)) + sample)/(nValue);
        return result;
    }
}

//double calculate_average(std::ifstream &input, unsigned int nValue, unsigned int nElements) {
////    return (averageBefore+ nextNumber)/2;
//    std::string value;
//    std::getline(input, value);
//    double sample = std::stod(value);
//    if (nValue == nElements) {
//        return sample;
//    }
//    
//    if (nValue == 1) {
//        return (((nValue+1) * (calculate_average(input, ++nValue,nElements))) + sample)/(nValue+1);
//    } else {
//        double result = ((nElements-nValue)*(calculate_average(input, ++nValue,nElements)) + sample)/(nValue-1);
//        return result;
//    }
//}

double StatisticsDanielBoso::average() {
    std::ifstream ifstream;
    ifstream.open(((CollectorDatafile_if*)_collector)->getDataFilename(), std::ifstream::in);
    
    unsigned int nElements = _collector->numElements();

    return calculate_average(ifstream, 1, nElements);
}

double StatisticsDanielBoso::mode() {
    std::list<double>* listDoubles = new std::list<double>;
    
    getSamplesAndSort(listDoubles);

    double modeValue = listDoubles->front();
    unsigned int numberValues = 1;

    double tempModeValue = modeValue;
    unsigned int tempValues = numberValues;

    while(!listDoubles->empty()) {
        double value = listDoubles->front();
        listDoubles->pop_front();
        if(value == tempValues) {
            tempValues++;
        } else {
            if (numberValues < tempValues) {
                modeValue = tempModeValue;
                numberValues = tempValues;
                tempModeValue = value;
                tempValues = 1;
            }
        }
    }
    return modeValue;
}

double StatisticsDanielBoso::mediane() {
    std::list<double>* listDoubles = new std::list<double>;
    
    getSamplesAndSort(listDoubles);

    std::list<double>::iterator it = listDoubles->begin();
    
    if(listDoubles->size() % 2 == 0) {
        double number1;
        double number2;
        std::advance(it, (listDoubles->size())/2);
        number1 = *it;
        std::advance(it, ((listDoubles->size())/2)+1);
        number2 = *it;
        return number1 + number2 / 2;
    } else {
        std::advance(it, (listDoubles->size()+1)/2);
        return *it;
    }
}

double calculate_variance(std::ifstream &input, unsigned int nValue, double average) {
    std::string value;
    if(std::getline(input, value)) {
        return  pow(average - std::stod(value), 2) + calculate_variance(input, nValue--, average);
    } else {
        return 0;
    }
}


double StatisticsDanielBoso::variance() {
    double average = StatisticsDanielBoso::average();
    unsigned int nValue = _collector->numElements();
    
    std::ifstream ifstream;
    ifstream.open(((CollectorDatafile_if*)_collector)->getDataFilename(), std::ifstream::in);
    
    return calculate_variance(ifstream, nValue, average);
}

double StatisticsDanielBoso::stddeviation() {
    return sqrt(StatisticsDanielBoso::variance()/_collector->numElements());
}

double StatisticsDanielBoso::variationCoef() {
    return sqrt(StatisticsDanielBoso::variance())/StatisticsDanielBoso::average();
}

double StatisticsDanielBoso::halfWidthConfidenceInterval(double confidencelevel) {
    return /*average() +*/ confidencelevel * (sqrt(variance())/sqrt(_collector->numElements()));
}

unsigned int StatisticsDanielBoso::newSampleSize(double confidencelevel, double halfWidth) {
    return pow(confidencelevel, 2) * variance()/ pow(halfWidth, 2);
}

double StatisticsDanielBoso::quartil(unsigned short num) {
     
    unsigned int position = num * (0.25 * (_collector->numElements() + 1));
    
    std::list<double>* listDoubles = new std::list<double>;
    
    getSamplesAndSort(listDoubles);
    
    std::list<double>::iterator it = listDoubles->begin();
    std::advance(it, position);
    
    return *it;
}

double StatisticsDanielBoso::decil(unsigned short num) {
    unsigned int position = num * (0.1 * (_collector->numElements() + 1));
    
    std::list<double>* listDoubles = new std::list<double>;
    
    getSamplesAndSort(listDoubles);

    std::list<double>::iterator it = listDoubles->begin();
    std::advance(it, (int)position);
    
    return *it;
}

double StatisticsDanielBoso::centil(unsigned short num) {
    unsigned int position = num * (0.01 * (_collector->numElements() + 1));
    
    std::list<double>* listDoubles = new std::list<double>;
    
    getSamplesAndSort(listDoubles);

    std::list<double>::iterator it = listDoubles->begin();
    std::advance(it, (int)position);
    
    return *it;
}

void StatisticsDanielBoso::setHistogramNumClasses(unsigned short num) {
   _histogramNumClasses = num;
}

unsigned short StatisticsDanielBoso::histogramNumClasses() {
    unsigned int numSamples = _collector->numElements();
    
    if(numSamples < 30) {
        // Root
        _histogramNumClasses = sqrt(numSamples);
        return _histogramNumClasses;
    } else {
        // Sturges
        _histogramNumClasses = 3.322 * log(numSamples)+1;
        return _histogramNumClasses;
    }
}

double StatisticsDanielBoso::histogramClassLowerLimit(unsigned short classNum) {
    double value_min = min();
    
    if(classNum == 0) {
        return value_min;
    } else {
        return value_min + (classNum) * ((max() - value_min)/_histogramNumClasses);
    }
}

unsigned int StatisticsDanielBoso::histogramClassFrequency(unsigned short classNum) {
    double lowerLimitClass = StatisticsDanielBoso::histogramClassLowerLimit(classNum);
    double upperLimitClass = lowerLimitClass + ((max() - min())/_histogramNumClasses);
    unsigned int frequency = 0;

    std::list<double>* listDoubles = new std::list<double>;;

    std::ifstream ifstream;
    ifstream.open(((CollectorDatafile_if*)_collector)->getDataFilename(), std::ifstream::in);

    std::string value;

    while(std::getline(ifstream, value)) {
        listDoubles->push_back(std::stod(value));
    }
    
    ifstream.close();

//    listDoubles->sort();
    double a1 = *listDoubles->end();
    std::list<double>::iterator it = listDoubles->begin();

    unsigned int numberSamples = _collector->numElements();
    for(int i = 0; i < numberSamples; i++) {
        double size = listDoubles->size();
        std::advance(it, i);
        if(*it >= lowerLimitClass && *it <= upperLimitClass) {
            frequency++;
        }
    }
    return frequency;
}

Collector_if* StatisticsDanielBoso::getCollector() {
	return this->_collector;
}

void StatisticsDanielBoso::setCollector(Collector_if* collector) {
    _collector = collector;
}