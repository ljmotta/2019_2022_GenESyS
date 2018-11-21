/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatisticsCancianImpl.cpp
 * Author: cancian
 * 
 * Created on 2 de Outubro de 2018, 17:33
 */

#include "StatisticsCancianImpl.h"

StatisticsCancianImpl::StatisticsCancianImpl() {
}

StatisticsCancianImpl::StatisticsCancianImpl(const StatisticsCancianImpl& orig) {
}

StatisticsCancianImpl::~StatisticsCancianImpl() {
}

Collector_if* StatisticsCancianImpl::getCollector() {
}

void StatisticsCancianImpl::setCollector(Collector_if* collector) {
	this->_collector = collector;
}

unsigned int StatisticsCancianImpl::numElements() {
}

double StatisticsCancianImpl::min() {
}

double StatisticsCancianImpl::max() {
}

double StatisticsCancianImpl::average() {
}

double StatisticsCancianImpl::mode() {
}

double StatisticsCancianImpl::mediane() {
}

double StatisticsCancianImpl::variance() {
}

double StatisticsCancianImpl::stddeviation() {
}

double StatisticsCancianImpl::variationCoef() {
}

double StatisticsCancianImpl::halfWidthConfidenceInterval(double confidencelevel) {
}

unsigned int StatisticsCancianImpl::newSampleSize(double confidencelevel, double halfWidth) {
}

double StatisticsCancianImpl::quartil(unsigned short num) {
}

double StatisticsCancianImpl::decil(unsigned short num) {
}

double StatisticsCancianImpl::centil(unsigned short num) {
}

void StatisticsCancianImpl::setHistogramNumClasses(unsigned short num) {
}

unsigned short StatisticsCancianImpl::histogramNumClasses() {
	return 0;
}

double StatisticsCancianImpl::histogramClassLowerLimit(unsigned short classNum) {
}

unsigned int StatisticsCancianImpl::histogramClassFrequency(unsigned short classNum) {
}