/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatisticsDataFileDummyImpl.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 22 de Novembro de 2018, 01:24
 */

#include "StatisticsDataFileDefaultImpl.h"

#include "Traits.h"

StatisticsDataFileDummyImpl::StatisticsDataFileDummyImpl() {
	_collector = new Traits<Statistics_if>::CollectorImplementation();
}

unsigned int StatisticsDataFileDummyImpl::numElements() {
	return 0; // dummy
}

double StatisticsDataFileDummyImpl::min() {
	return 0.0; // dummy
}

double StatisticsDataFileDummyImpl::max() {
	return 0.0; // dummy
}

double StatisticsDataFileDummyImpl::average() {
	return 0.0; // dummy
}

double StatisticsDataFileDummyImpl::mode() {
	return 0.0; // dummy
}

double StatisticsDataFileDummyImpl::mediane() {
	return 0.0; // dummy
}

double StatisticsDataFileDummyImpl::variance() {
	return 0.0; // dummy
}

double StatisticsDataFileDummyImpl::stddeviation() {
	return 0.0; // dummy
}

double StatisticsDataFileDummyImpl::variationCoef() {
	return 0.0; // dummy
}

double StatisticsDataFileDummyImpl::halfWidthConfidenceInterval(double confidencelevel) {
	return 0.0; // dummy
}

unsigned int StatisticsDataFileDummyImpl::newSampleSize(double confidencelevel, double halfWidth) {
	return 0; // dummy
}

double StatisticsDataFileDummyImpl::quartil(unsigned short num) {
	return 0.0; // dummy
}

double StatisticsDataFileDummyImpl::decil(unsigned short num) {
	return 0.0; // dummy
}

double StatisticsDataFileDummyImpl::centil(unsigned short num) {
	return 0.0; // dummy
}

void StatisticsDataFileDummyImpl::setHistogramNumClasses(unsigned short num) {
}

unsigned short StatisticsDataFileDummyImpl::histogramNumClasses() {
	return 0; // dummy
}

double StatisticsDataFileDummyImpl::histogramClassLowerLimit(unsigned short classNum) {
	return 0.0; // dummy
}

unsigned int StatisticsDataFileDummyImpl::histogramClassFrequency(unsigned short classNum) {
	return 0; // dummy
}

Collector_if* StatisticsDataFileDummyImpl::getCollector() {
	return this->_collector;
}

void StatisticsDataFileDummyImpl::setCollector(Collector_if* collector) {

}